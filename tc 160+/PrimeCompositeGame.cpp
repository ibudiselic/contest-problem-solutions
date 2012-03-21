#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

const int INF = 1234567890;
struct MinIntervalTree {
    MinIntervalTree(int n_): n(n_), M(2*(n_+1), INF) {
        init(0, 0, n);
    }
    int init(int node, int l, int r) {
        while (node >= (int)M.size()) {
            M.push_back(INF);
        }
        if (l == r) {
            return (M[node] = INF);
        } else {
            int mid = l + (r-l)/2;
            int val = min(init(2*node+1, l, mid), init(2*node+2, mid+1, r));
            return (M[node] = val);
        }
    }
    int insert_internal(int node, int l, int r, int val, int at) {
        assert(node < (int)M.size());
        if (at<l || r<at) {
            return M[node];
        }
        if (l == r) {
            return (M[node] = min(M[node], val));
        } else {
            int mid = l + (r-l)/2;
            return (M[node] = min(insert_internal(2*node+1, l, mid, val, at), insert_internal(2*node+2, mid+1, r, val, at)));
        }
    }
    void insert(int val, int at) {
        insert_internal(0, 0, n, val, at);
    }
    int get_min_internal(int node, int l, int r, int a, int b) {
        a = max(a, l);
        b = min(b, r);
        if (a==l && r==b) {
            return M[node];
        }
        int mid = l + (r-l)/2;
        int ret = INF;
        if (a <= mid) {
            ret = get_min_internal(2*node+1, l, mid, a, b);
        }
        if (b > mid) {
            ret = min(ret, get_min_internal(2*node+2, mid+1, r, a, b));
        }
        return ret;
    }
    int get_min(int a, int b) { // [a, b]
        return get_min_internal(0, 0, n, a, b);
    }
    int n;
    vector<int> M;
};
bool not_prime[500000];
class PrimeCompositeGame {
public:
    int theOutcome(int N, int K) {
        if (N == 1) {
            return 0;
        }
        vector<MinIntervalTree> W(2, MinIntervalTree(N)), L(2, MinIntervalTree(N));
        memset(not_prime, 0, sizeof not_prime);
        for (int i=2; i<N; ++i) {
            int a, b;
            if (!not_prime[i]) {
                for (long long x=(long long)i*i; x<N; x+=i) {
                    not_prime[x] = true;
                }
                a = 1;
                b = 0;
            } else {
                a = 0;
                b = 1;
            }
            int rounds = L[b].get_min(i-K, i-1);
            if (rounds < INF) {
                W[a].insert(-rounds-1, i);
            } else {
                rounds = W[b].get_min(i-K, i-1);
                if (rounds < INF) {
                    L[a].insert(-rounds+1, i);
                } else {
                    L[a].insert(0, i);
                }
            }
        }
        int rounds = L[1].get_min(N-K, N-1);
        if (rounds < INF) {
            return rounds + 1;
        } else {
            rounds = W[1].get_min(N-K, N-1);
            if (rounds < INF) {
                return rounds-1;
            } else {
                return 0;
            }
        }
    }
};
