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

const int MAXN = 10000;
int A[MAXN], B[MAXN];
int main() {
    int n, m;
    scanf("%d", &n);
    for (int i=0; i<n; ++i) {
        scanf("%d", A + i);
    }
    scanf("%d", &m);
    for (int i=0; i<m; ++i) {
        scanf("%d", B + i);
    }
    int cnt = 0;
    int bestnum = 0;
    int bestdenom = 1;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            if (B[j]%A[i] == 0) {
                const int x = B[j]*bestdenom;
                const int y = A[i]*bestnum;
                if (x == y) {
                    ++cnt;
                } else if (x > y) {
                    cnt = 1;
                    bestnum = B[j];
                    bestdenom = A[i];
                }
            }
        }
    }
    printf("%d\n", cnt);
    return 0;
}
