#include <cassert>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstring>
#include <map>

using namespace std;

const int MAXN = 100000;
int A[MAXN+1];

struct query {
    int ind, l, r;
    query(int ind_, int l_, int r_): ind(ind_), l(l_), r(r_) {}
};
bool operator<(const query &a, const query &b) {
    if (a.r != b.r) {
        return a.r < b.r;
    } else if (a.l != b.l) {
        return a.l < b.l;
    } else {
        return a.ind < b.ind;
    }
}

struct FenwickTree {
    FenwickTree(int n_): n(n_), T(n_+1, 0) {}
    void change(int at, int by) {
        while (at <= n) {
            T[at] += by;
            at += at&-at;
        }
    }
    int sum(int from, int to) { // [from, to]
        int ret = 0;
        for (; to>0; to-=to&-to) ret += T[to];
        for (--from; from>0; from-=from&-from) ret -= T[from];
        return ret;
    }
    int n;
    vector<int> T;
};
int sol[MAXN];
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i=1; i<=n; ++i) {
        scanf("%d", A+i);
    }

    vector<query> Q;
    for (int i=0; i<m; ++i) {
        int l, r;
        scanf("%d %d", &l, &r);
        Q.push_back(query(i, l, r));
    }
    sort(Q.begin(), Q.end());

    FenwickTree T(n);
    map<int, vector<int> > pos;
    int q = 0;
    for (int i=1; i<=n; ++i) {
        vector<int> &v = pos[A[i]];
        v.push_back(i);
        if ((int)v.size() >= A[i]) {
            T.change(v[(int)v.size()-A[i]], 1);
            if ((int)v.size() > A[i]) {
                T.change(v[(int)v.size()-1-A[i]], -2);
                if ((int)v.size()-1 > A[i]) {
                    T.change(v[(int)v.size()-2-A[i]], 1);
                }
            }
        }

        while (q<m && Q[q].r==i) {
            sol[Q[q].ind] = T.sum(Q[q].l, Q[q].r);
            ++q;
        }
    }

    for (int i=0; i<m; ++i) {
        printf("%d\n", sol[i]);
    }
    
    return 0;
}
