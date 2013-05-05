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

long long n;
int s(long long x) {
    int ret = 0;
    while (x > 0) {
        ret += int(x%10);
        x /= 10;
    }
    return ret;
}
long long f(long long x) {
    return x*x + s(x)*x - n;
}
int main() {
    cin >> n;

    long long lo = 0;
    long long hi = 10000000;
    while (lo < hi) {
        long long mid = lo + (hi-lo)/2;
        if (f(mid*100) >= 0) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }

    hi = lo*100 + 1000;
    lo = lo*100 - 1000;
    for (long long x=max(0ll, lo); x<=hi; ++x) {
        if (f(x) == 0) {
            cout << x << '\n';
            return 0;
        }
    }
    cout << "-1\n";
    return 0;
}
