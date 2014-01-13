//# implementation
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

class ValueHistogram {
public:
    vector <string> build(vector <int> values) {
        vector<int> cnts(10);
        for (int i=0; i<(int)values.size(); ++i) {
            ++cnts[values[i]];
        }
        int h = *max_element(cnts.begin(), cnts.end()) + 1;
        vector<string> sol;
        for (int v=0; v<10; ++v) {
            int k = cnts[v];
            sol.push_back(string(k, 'X') + string(h-k, '.'));
        }
        int m = sol.size();
        int n = sol[0].size();
        vector<string> ret(n, string(m, ' '));
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                ret[n-1-j][i] = sol[i][j];
            }
        }
        return ret;
    }
};
