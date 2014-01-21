//# binary search, simple
//# => trivial
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

int cnt(int N, int K) {
    return N/K*3 + N/3;
}
class NinjaTurtles {
public:
    int countOpponents(int P, int K) {
        int lo = 1;
        int hi = 2;
        while (cnt(hi, K) < P) {
            lo = hi;
            hi *= 2;
        }
        while (lo < hi) {
            int mid = lo + (hi-lo)/2;
            if (cnt(mid, K) >= P) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return cnt(lo, K)==P ? lo : -1;
    }
};
