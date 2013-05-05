#include <cassert>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    long long sol = 0;
    for (int i=0; i<n; ++i) {
        int t, T, x, cost;
        scanf("%d %d %d %d", &t, &T, &x, &cost);
        long long add = cost;
        if (t+m > T) {
            add += (long long)m*x;
        }
        if (T > t) {
            add = min(add, (long long)(m+(T-t)-1)/(T-t) * cost);
        }
        sol += add;
    }

    printf("%I64d\n", sol);
    return 0;
}
