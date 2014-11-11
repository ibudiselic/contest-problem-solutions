//# implementation, intervals, intersection
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

inline bool intersects(int a, int b, int c, int d) {
    return a<=d && c<=b;
}
class ShoutterDiv2 {
public:
    int count(vector <int> s, vector <int> t) {
        int n = s.size();
        int sol = 0;
        for (int i=0; i<n; ++i) {
            for (int j=i+1; j<n; ++j) {
                if (intersects(s[i], t[i], s[j], t[j])) {
                    ++sol;
                }
            }
        }
        return sol;
    }
};
