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

bool G[100][100];
inline int complete(int n) {
    return n*(n-1)/2*(n-2)/3;
}
int main() {
    int k;
    cin >> k;
    int n = 3;
    while (complete(n) <= k) {
        ++n;
    }
    --n;
    for (int i=0; i<n; ++i) {
        for (int j=i+1; j<n; ++j) {
            G[i][j] = G[j][i] = 1;
        }
    }
    k -= complete(n);
    int m = n;
    while (k > 0) {
        ++n;
        int t = m - 1;
        while (t*(t-1)/2 > k) {
            --t;
        }
        k -= t*(t-1)/2;
        for (int i=0; i<t; ++i) {
            G[i][n-1] = G[n-1][i] = 1;
        }
    }
    cout << n << '\n';
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            cout << int(G[i][j]);
        }
        cout << '\n';
    }

    return 0;
}
