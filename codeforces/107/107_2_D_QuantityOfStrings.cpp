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

const long long mod = 1000000007ll;
long long pow_mod(long long n, long long k) {
    long long ret = 1;
    while (k > 0) {
        if (k & 1) {
            ret = ret*n % mod;
        }
        n = n*n % mod;
        k >>= 1;
    }
    return ret;
}
int main() {
    int n, m, k;
    cin >> n >> m >> k;
    
    long long sol = -1;
    if (k==1 || k>n) {
        sol = pow_mod(m, n);
    } else if (k == n) {
        sol = pow_mod(m, n/2);
        if (n & 1) {
            sol = sol*m % mod;
        }
    } else if (k & 1) {
        sol = m*m % mod;
    } else {
        sol = m;
    }
    cout << sol << '\n';
    return 0;
}
