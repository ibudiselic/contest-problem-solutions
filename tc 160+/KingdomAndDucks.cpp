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
#include <map>

using namespace std;

class KingdomAndDucks {
public:
    int minDucks(vector <int> duckTypes) {
        map<int, int> M;
        int cnt = 0;
        for (int i=0; i<(int)duckTypes.size(); ++i) {
            cnt = max(cnt, ++M[duckTypes[i]]);
        }
        return cnt * int(M.size());
    }
};
