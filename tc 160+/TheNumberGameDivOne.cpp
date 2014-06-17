//# game, impartial game, divisors, observation
//# => Observe a pattern in the brute force solution and possibly prove by induction.
#include <algorithm>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

bool fast(long long n) {
    if (n&1) return false;
    long long p2 = 1;
    bool even = true;
    while (p2 < n) {
        p2 <<= 1;
        even = !even;
    }
    if (p2 == n) {
        return even;
    }
    return true;
}
class TheNumberGameDivOne {
public:
    string find(long long n) {
        return fast(n) ? "John" : "Brus";
    }
};
