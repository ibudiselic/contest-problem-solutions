//# greedy, teams, rank, implementation
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

class TeamContest {
public:
    int worstRank(vector <int> strength) {
        if (strength.size() == 3) {
            return 1;
        }
        vector<int> x(begin(strength)+3, end(strength));
        vector<int> me(begin(strength), begin(strength)+3);
        sort(begin(me), end(me));
        int val = me[0] + me.back();
        int sol = 1;
        sort(begin(x), end(x));
        while (x.size()>0 && x.back()+x[x.size()-3]>val) {
            int t = x.back();
            x.pop_back();
            ++sol;
            int i = lower_bound(begin(x), end(x), val-t+1) - begin(x);
            rotate(begin(x)+i, begin(x)+i+2, end(x));
            x.resize(x.size()-2);
        }
        return sol;
    }
};
