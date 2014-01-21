//# math, simple, factorization
//# => the required property is that the product of the numbers is a square i.e. it has only even exponents on all its prime factors... therefore, given a number x, y must have the same set of odd-exponent prime factors as x so this set of odd-exponent prime factors is some kind of signature for a number...
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

vector<int> getsgn(int n) {
    int d = 2;
    vector<int> ret;
    while (d*d <= n) {
        if (n%d == 0) {
            int cnt = 0;
            do {
                ++cnt;
                n /= d;
            } while (n%d == 0);
            if (cnt & 1) {
                ret.push_back(d);
            }
        }
        ++d;
    }
    if (n > 1) {
        ret.push_back(n);
    }
    return ret;
}
class TheSquareRootDilemma {
public:
    int countPairs(int N, int M) {
        map<vector<int>, int> cnt;
        cnt[vector<int>()] = 1;
        for (int a=2; a<=N; ++a) {
            vector<int> sgn = getsgn(a);
            ++cnt[sgn];
        }
        int sol = cnt[vector<int>()];
        for (int a=2; a<=M; ++a) {
            vector<int> sgn = getsgn(a);
            sol += cnt[sgn];
        }
        return sol;
    }
};
