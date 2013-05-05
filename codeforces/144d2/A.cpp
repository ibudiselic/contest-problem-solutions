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

int main() {
    int n;
    cin >> n;
    if (n & 1) {
        cout << "-1\n";
    } else {
        for (int i=0; i<n; i+=2) {
            if (i) cout << ' ';
            cout << i+2 << ' ' << i+1;
        }
        cout << '\n';
    }
    return 0;
}
