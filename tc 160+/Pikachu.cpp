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

const int mod = 1000000009;
int C[31][31];
int F[31];
int ways[31][31]; // [l][r] to pick words from l to r inclusive with "free right side"
int partial[31];
int N;

inline int get(int i, int j) {
    assert(i>=0);
    assert(i<=j);
    assert(j<N);
    return partial[j+1] - partial[i];
}
inline int get(int i) {
    return get(i, i);
}

bool done[31][31][31][31];
int cnt[31][31][31][31];
int best[31][31][31][31];

inline void mul(int &a, int b) {
    a = int((long long)a*b%mod);
}

vector<int> greedy(int first, int n0, int n1, int n2) {
    vector<int> ret(2, 0);
    int rem = N - first;
    int c0 = min(n0, rem);
    int c1 = min(n1, rem - c0);
    int c2 = min(n2, rem - c0 - c1);
    // c0 are free (already paid for)
    if (c1 > 0) {
        ret[0] += get(first+c0, first+c0+c1-1);
    }
    if (c2 > 0) {
        ret[0] += 2*get(first+c0+c1, first+c0+c1+c2-1);
    }
    ret[1] = 1;
    if (c0 > 0) {
        mul(ret[1], int((long long)ways[first][first+c0-1]*F[c0]%mod*C[n0][c0]%mod));
    }
    if (c1 > 0) {
        mul(ret[1], int((long long)ways[first+c0][first+c0+c1-1]*F[c1]%mod*C[n1][c1]%mod));
    }
    if (c2 > 0) {
        mul(ret[1], int((long long)ways[first+c0+c1][first+c0+c1+c2-1]*F[c2]%mod*C[n2][c2]%mod));
    }
    return ret;
}
const int inf = 1234567890;
vector<int> go(int first, int n0, int n1, int n2) {
    if (n0+n1+n2 >= N-first) {
        return greedy(first, n0, n1, n2);
    }
    vector<int> ret(2, 0);
    if (n0+n1+n2 == 0) {
        ret[0] = inf;
        ret[1] = 1;
        return ret;
    }
    if (done[first][n0][n1][n2]) {
        ret[0] = best[first][n0][n1][n2];
        ret[1] = cnt[first][n0][n1][n2];
        return ret;
    }
    
    done[first][n0][n1][n2] = 1;
    ret[0] = inf;
    int rem = N - first;
    int lim = min(rem, n0);
    for (int take=0; take<=lim; ++take) {
        vector<int> next = go(first+take, n1, n2+2*(n0-take), n0-take);
        next[0] += get(first+take, N-1);
        if (take > 0) {
            mul(next[1], int((long long)ways[first][first+take-1]*F[take]%mod*C[n0][take]%mod));
        }
        if (next[0] == ret[0]) {
            ret[1] = (ret[1] + next[1]) % mod;
        } else if (next[0] < ret[0]) {
            ret.swap(next);
        }
    }

    best[first][n0][n1][n2] = ret[0];
    cnt[first][n0][n1][n2] = ret[1];
    return ret;
}
class Pikachu {
public:
    vector <int> bestEncoding(vector <int> freq) {
        if (freq.size() == 1) {
            vector<int> ret(2, 0);
            ret[0] = freq[0] * 2;
            ret[1] = 2;
            return ret;
        }
        N = freq.size();
        sort(freq.begin(), freq.end());
        reverse(freq.begin(), freq.end());
        F[0] = 1;
        for (int i=1; i<31; ++i) {
            F[i] = int((long long)F[i-1]*i%mod);
        }
        C[0][0] = 1;
        for (int i=1; i<31; ++i) {
            C[i][0] = 1;
            for (int j=1; j<=i; ++j) {
                C[i][j] = (C[i-1][j-1] + C[i-1][j])%mod;
            }
        }
        
        for (int l=0; l<N; ++l) {
            for (int r=l; r<N; ++r) {
                int i = r + 1;
                while (i<N && freq[i]==freq[r]) {
                    ++i;
                }
                --i;
                int j = r - 1;
                while (j>=l && freq[j]==freq[r]) {
                    --j;
                }
                ++j;
                ways[l][r] = C[i-j+1][r-j+1];
            }
        }
        partial[0] = 0;
        for (int i=0; i<N; ++i) {
            partial[i+1] = partial[i] + freq[i];
        }
        
        memset(done, 0, sizeof done);
        memset(cnt, 0, sizeof cnt);
        memset(best, 0, sizeof best);
        vector<int> ret = go(0, 2, 1, 0);
        ret[0] += 2 * get(0, N-1);
        return ret;
    }
};
