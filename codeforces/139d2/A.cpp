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

bool used[7];
int main() {
    int n, x;
    cin >> n >> x;
    for (int i=0; i<n; ++i) {
        int a, b;
        cin >> a >> b;
        memset(used, 0, sizeof used);
        used[a] = used[b] = used[7-a] = used[7-b] = 1;
        int bot = 7 - x;
        if (used[bot]) {
            cout << "NO\n";
            return 0;
        }
        used[bot] = 1;
        for (int j=1; j<7; ++j) {
            if (!used[j]) {
                x = j;
                break;
            }
        }
    }
    cout << "YES\n";
    return 0;
}
