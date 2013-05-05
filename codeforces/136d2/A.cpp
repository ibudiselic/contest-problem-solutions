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
    cout << n;
    for (int i=1; i<n; ++i) {
        cout << ' ' << i;
    }
    cout << '\n';
    return 0;
}
