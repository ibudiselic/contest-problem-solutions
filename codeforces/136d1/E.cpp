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

struct FenwickTree {
    int n;
    vector<int> T;
    FenwickTree(int n_): n(n_), T(n_+1, 0) {}
    void change(int at, int by) {
        for (; at<=n; at+=at&-at) T[at] += by;
    }
    int sum(int l, int r) { // [l, r]
        int ret = 0;
        for (; r>0; r-=r&-r) ret += T[r];
        for (--l; l>0; l-=l&-l) ret -= T[l];
        return ret;
    }
    int gt(int x) {
        return sum(x+1, n);
    }
    int lt(int x) {
        return sum(1, x-1);
    }
};
const int MAXN = 100000;
int A[MAXN];
int ordered[MAXN];
int n;
int index(int x) {
    return (lower_bound(ordered, ordered+n, x) - ordered) + 1;
}
int main() {
    long long K;
    scanf("%d %I64d", &n, &K);
    for (int i=0; i<n; ++i) {
        scanf("%d", A + i);
        ordered[i] = A[i];
    }
    sort(ordered, ordered + n);

    FenwickTree left(n), right(n);
    long long have = 0;
    for (int i=0; i+1<n; ++i) {
        int idx = index(A[i]);
        have += left.gt(idx);
        left.change(idx, 1);
    }
    for (int i=n-1; i<n; ++i) {
        int idx = index(A[i]);
        have += left.gt(idx);
        right.change(idx, 1);
    }
    int l = n-2;
    int r = n-1;
    long long sol = 0;
    while (r > 0) {
        if (have <= K) {
            ++sol;
        }
        assert(l < r);
        if ((have<=K && l+1<r) || l==0) {
            sol += l;
            int idx = index(A[--r]);
            have += left.gt(idx) + right.lt(idx);
            right.change(idx, 1);
        } else {
            int idx = index(A[l--]);
            have -= left.gt(idx) + right.lt(idx);
            left.change(idx, -1);
        }
    }

    printf("%I64d\n", sol);
    return 0;
}
