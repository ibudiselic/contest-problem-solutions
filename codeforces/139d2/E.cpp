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

int e[] = {2,3,5,7,13,17,19,31,61,89,107,127,521,607,1279,2203,2281,3217,4253,4423,9689,9941,11213,19937,21701,23209,44497, 86243,110503,132049,216091,756839,859433,1257787,1398269,2976221,3021377,6972593,13466917,20996011};
const long long mod = 1000000007;
int main() {
    int n;
    cin >> n;
    long long x = 1;
    long long p2 = 2;
    int k = e[n-1] - 1;
    while (k > 0) {
        if (k & 1) {
            x = x*p2%mod;
        }
        p2 = p2*p2%mod;
        k >>= 1;
    }
    cout << (x-1+mod)%mod << '\n';
    return 0;
}
