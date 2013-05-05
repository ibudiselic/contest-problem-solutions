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
int B[MAXN];
int main() {
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; ++i) {
        scanf("%d", A + i);
        B[i] = A[i];
    }
    sort(A, A+n);
    int diff = 0;
    for (int i=0; i<n && diff<=2; ++i) {
        if (A[i] != B[i]) {
            ++diff;
        }
    }
    puts((diff<=2) ? "YES" : "NO");
    return 0;
}
