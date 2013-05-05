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

const int MAXN = 100;
int x[MAXN], y[MAXN];
int C[MAXN];
int n;
void go(int i, int comp) {
    C[i] = comp;
    for (int j=0; j<n; ++j) {
        if (C[j]==0 && (x[i]==x[j] || y[i]==y[j])) {
            go(j, comp);
        }
    }
}
int main() {
    cin.sync_with_stdio(false);
    cin >> n;
    for (int i=0; i<n; ++i) {
        cin >> x[i] >> y[i];
    }
    int comps = 0;
    for (int i=0; i<n; ++i) {
        if (C[i] == 0) {
            go(i, ++comps);
        }
    }
    cout << comps - 1 << '\n';

    return 0;
}
