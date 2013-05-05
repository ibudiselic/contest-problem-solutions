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

bool has[10];
int f(int x) {
    while (x > 0) {
        if (has[x%10]) {
            return 1;
        }
        x /= 10;
    }
    return 0;
}
int main() {
    int n;
    cin >> n;
    int tmp = n;
    while (tmp > 0) {
        has[tmp%10] = 1;
        tmp /= 10;
    }
    int sol = 0;
    for (int d=1; d*d<=n; ++d) {
        if (n%d == 0) {
            sol += f(d) + (d*d<n ? f(n/d) : 0);
        }
    }
    cout << sol << '\n';
    return 0;
}
