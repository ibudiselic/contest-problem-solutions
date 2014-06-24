//# implementation, probability
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
#include <sstream>

using namespace std;

class EllysRoomAssignmentsDiv2 {
public:
    double getProbability(vector <string> ratings) {
        string s = accumulate(begin(ratings), end(ratings), string());
        istringstream is(s);
        vector<int> v;
        copy(istream_iterator<int>(is), istream_iterator<int>(), back_inserter(v));
        int elly = v[0];
        sort(begin(v), end(v));
        elly = (end(v) - lower_bound(begin(v), end(v), elly)) - 1;
        reverse(begin(v), end(v));

        int n = v.size();
        int R = (n+19)/20;
        if (elly==0 || R==1) {
            return 1.0;
        } else if (elly < R) {
            return 0.0;
        } else {
            return 1.0/R;
        }
    }
};
