//# implementation, easy, sorting
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

class PrimalUnlicensedCreatures {
public:
    int maxWins(int cur, vector <int> grezPower) {
        sort(grezPower.begin(), grezPower.end());
        int sol = 0;
        for (int i=0; i<(int)grezPower.size(); ++i) {
            if (cur > grezPower[i])  {
                ++sol;
                cur += grezPower[i]/2;
            }
        }
        return sol;
    }
};
