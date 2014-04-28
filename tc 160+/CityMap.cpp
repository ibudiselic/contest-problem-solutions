//# grid, counting, trivial
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

int cnt[256];
char v[3000];
class CityMap {
public:
    string getLegend(vector <string> M, vector <int> POIs) {
        int m = M.size();
        int n = M[0].size();
        memset(cnt, 0, sizeof cnt);
        for (int c='A'; c<='Z'; ++c) {
            for (int i=0; i<m; ++i) {
                cnt[c] += count(M[i].begin(), M[i].end(), c);
            }
            v[cnt[c]] = c;
        }
        string sol;
        for (int i=0; i<(int)POIs.size(); ++i) {
            sol += v[POIs[i]];
        }
        return sol;
    }
};
