#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class RollingDiceDivTwo {
public:
    int minimumFaces(vector <string> rolls) {
        int m = rolls.size();
        int n = rolls[0].size();
        for (int i=0; i<m; ++i) {
            sort(rolls[i].begin(), rolls[i].end());
        }
        int sol = 0;
        for (int j=0; j<n; ++j) {
            int val = 0;
            for (int i=0; i<m; ++i) {
                val = max(val, rolls[i][j]-'0');
            }
            sol += val;
        }
        return sol;
    }
};
