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
int A[MAXN+1], B[MAXN+1];
int N, X;
int calc(int a, int b) {
    multiset<int> r2;
    for (int i=0; i<N; ++i) {
        if (i != b) {
            r2.insert(B[i]);
        }
    }
    int ret = 0;
    for (int i=0; i<N; ++i) {
        if (i != a) {
            multiset<int>::iterator it = r2.lower_bound(X - A[i]);
            if (it != r2.end()) {
                ++ret;
                r2.erase(it);
            }
        }
    }
    return ret;
}
int main() {
    scanf("%d %d", &N, &X);
    for (int i=0; i<N; ++i) {
        scanf("%d", A + i);
    }
    for (int i=0; i<N; ++i) {
        scanf("%d", B + i);
    }
    sort(A, A+N);
    sort(B, B+N);

    int i = 0;
    int j = N-1;
    int besti = -1;
    int bestj = -1;
    int bestval = 1234567890;
    while (i<N && j>=0) {
        int val = A[i] + B[j];
        if (val >= X) {
            if (val < bestval) {
                bestval = val;
                besti = i;
                bestj = j;
            }
            --j;
        } else {
            ++i;
        }
    }
    X = bestval;

    assert(besti != -1);
    printf("1 %d\n", calc(besti, bestj) + 1);

    return 0;
}
