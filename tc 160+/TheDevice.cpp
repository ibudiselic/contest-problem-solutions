//# xor, case analysis
//# => notice that you can discern a bit device like this iff you have at least one 0 and at least two 1 bits in each position
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

class TheDevice {
public:
    int minimumAdditional(vector <string> plates) {
        int n = plates.size();
        int sz = plates[0].size();
        vector<vector<int> > cnt(sz, vector<int>(2, 0));
        for (int i=0; i<n; ++i) {
            for (int j=0; j<sz; ++j) {
                ++cnt[j][plates[i][j]-'0'];
            }
        }
        int sol = 0;
        for (int i=0; i<sz; ++i) {
            sol = max(sol, 3 - min(1, cnt[i][0]) - min(2, cnt[i][1]));
        }
        return sol;
    }
};
