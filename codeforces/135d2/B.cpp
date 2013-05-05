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
    long long p, d;
    cin >> p >> d;
    long long lost = 0;
    long long p10 = 1;
    while (p10 <= p/10) {
        int dig = int(p/p10%10);
        p10 *= 10;
        if (dig == 9) {
            continue;
        }
        lost += (dig+1)*(p10/10);
        if (lost > d) {
            break;
        }
        p -= (dig+1)*(p10/10);
    }
    cout << p << '\n';
    return 0;
}
