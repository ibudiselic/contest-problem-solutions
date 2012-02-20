#include <cassert>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstring>
#include <map>

using namespace std;

map<long long, long long> dp;
long long go(long long q) {
    if (dp.count(q)) {
        return dp[q];
    }
    long long &ret = dp[q];
    bool found = false;
    for (int d=2; d<=q/d; ++d) {
        if (q%d == 0) {
            found = true;
            if (go(d) < 0) {
                return (ret = d);
            }
            if (go(q/d) < 0) {
                return (ret = q/d);
            }
        }
    }
    return (ret = found ? -1 : 0);
}
int main() {
    long long q;
    cin >> q;
    long long t = go(q);
    if (t < 0) {
        cout << "2\n";
    } else {
        cout << "1\n" << t << '\n';
    }
    return 0;
}
