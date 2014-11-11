//# implementation, intervals, intersection, critical points
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

int bc(long long x) {
    int ret = 0;
    while (x > 0) {
        ++ret;
        x &= x-1;
    }
    return ret;
}
class EelAndRabbit {
public:
    int getmax(vector <int> l, vector <int> t) {
        vector<int> times(begin(t), end(t));
        for (int i=0; i<(int)l.size(); ++i) {
            times.push_back(t[i]+l[i]);
        }
        vector<long long> masks;
        for (int i=0; i<(int)times.size(); ++i) {
            long long mask = 0;
            for (int j=0; j<(int)l.size(); ++j) {
                if (t[j]<=times[i] && times[i]<=t[j]+l[j]) {
                    mask |= 1ll<<j;
                }
            }
            masks.push_back(mask);
        }

        int sol = 0;
        for (int i=0; i<(int)masks.size(); ++i) {
            for (int j=0; j<(int)masks.size(); ++j) {
                sol = max(sol, bc(masks[i]|masks[j]));
            }
        }
        return sol;
    }
};
