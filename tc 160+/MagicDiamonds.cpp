#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

bool is_prime(long long n) {
    if (n%2 == 0) {
        return false;
    }
    for (long long d=3; d*d<=n; d+=2) {
        if (n%d == 0) {
            return false;
        }
    }
    return true;
}
class MagicDiamonds {
public:
    long long minimalTransfer(long long n) {
        if (n < 4) {
            return n;
        }
        return 1 + is_prime(n);
    }
};
