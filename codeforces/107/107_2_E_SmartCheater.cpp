#include <cassert>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;

struct node {
    double left, any, right, all;
};

void extend(node &a, const node &b) {
    a.any = max(a.any, b.any);
    a.any = max(a.any, a.right + b.left);
    a.left = max(a.left, a.all + b.left);
    a.right = max(b.right, b.all + a.right);
    a.all += b.all;
}

double V[150000];
struct SegmentTree {
    SegmentTree(int n): T(2*n+1) {
        init(0, 0, n-1);
    }
    void init(int n, int l, int r) {
        while (n >= (int)T.size()) {
            T.push_back(node());
        }
        if (l == r) {
            T[n].left = T[n].any = T[n].right = T[n].all = V[l];
        } else {
            int mid = l + (r-l)/2;
            init(2*n + 1, l, mid);
            init(2*n + 2, mid+1, r);
            T[n] = T[2*n + 1];
            extend(T[n], T[2*n + 2]);
        }
    }
    
    void update(int n, int at_l, int at_r, int need_l, int need_r, node &accumulator) {
        need_l = max(need_l, at_l);
        need_r = min(need_r, at_r);
        if (need_l==at_l && need_r==at_r) {
            extend(accumulator, T[n]);
        } else {
            int mid = at_l + (at_r-at_l)/2;
            if (need_l <= mid) {
                update(2*n + 1, at_l, mid, need_l, need_r, accumulator);
            }
            if (need_r >= mid+1) {
                update(2*n + 2, mid+1, at_r, need_l, need_r, accumulator);
            }
        }
    }
    vector<node> T;
};

int X[150000];
int P[150000];
int main() {
    int n, m, c;
    cin >> n >> m >> c;
    for (int i=0; i<n; ++i) {
        cin >> X[i];
    }
    for (int i=0; i+1<n; ++i) {
        cin >> P[i];
    }

    for (int i=0; i+1<n; ++i) {
        V[i] = 0.5*(X[i+1]-X[i]) - 0.01*P[i]*c;
    }
    SegmentTree T(n-1);

    double sol = 0;
    node A;
    for (int i=0; i<m; ++i) {
        int a, b;
        cin >> a >> b;
        A.left = A.any = A.right = A.all = 0.0;
        T.update(0, 0, n-2, a-1, b-2, A);
        sol += A.any;
    }
    printf("%f\n", sol);
    
    return 0;
}
