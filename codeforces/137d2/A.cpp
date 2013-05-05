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

const int MAXN = 100000;
int A[MAXN];
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i=0; i<n; ++i) {
        scanf("%d", A+i);
    }
    bool ok = true;
    for (int i=k; i<n; ++i) {
        if (A[i] != A[i-1]) {
            ok = false;
            break;
        }
    }
    if (!ok) {
        puts("-1");
    } else {
        --k;
        while (k>0 && A[k-1]==A[k]) {
            --k;
        }
        printf("%d\n", k);
    }
    return 0;
}
