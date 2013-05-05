#include <cassert>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstring>
#include <set>

using namespace std;

const int MAXN = 100000;
int A[MAXN];
int B[MAXN];
int revA[MAXN];
int revB[MAXN];
int query(int x, const multiset<int> &S) {
    int ret = 1<<30;
    multiset<int>::const_iterator it = S.lower_bound(x);
    if (it != S.end()) {
        ret = *it - x;
    }
    if (it != S.begin()) {
        --it;
        ret = min(ret, x - *it);
    }
    return ret;
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; ++i) {
        scanf("%d", A + i);
    }
    for (int i=0; i<n; ++i) {
        scanf("%d", B + i);
    }
    for (int i=0; i<n; ++i) {
        --A[i];
        --B[i];
    }
    for (int i=0; i<n; ++i) {
        revA[A[i]] = i;
        revB[B[i]] = i;
    }

    multiset<int> D;
    for (int i=0; i<n; ++i) {
        D.insert(revA[i] - revB[i]);
    }

    for (int i=0; i<n; ++i) {
        printf("%d\n", query(-i, D));
        int val = revA[B[i]] - revB[B[i]];
        D.erase(D.find(val));
        D.insert(val - n);
    }
    
    return 0;
}
