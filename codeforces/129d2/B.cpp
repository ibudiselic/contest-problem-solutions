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

int A[100000];
int main() {
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; ++i) {
        scanf("%d", A + i);
    }
    long long sol = 0;
    int val = A[n-1];
    for (int i=n-2; i>=0; --i) {
        if (A[i] > val) {
            sol += A[i] - val;
            val = A[i];
        }
        val = min(val, A[i]);
    }
    printf("%I64d\n", sol);
    return 0;
}
