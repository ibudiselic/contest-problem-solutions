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
    int m, n, a;
    cin >> m >> n >> a;
    cout << (long long)(m+a-1)/a * ((n+a-1)/a) << '\n';

    return 0;
}
