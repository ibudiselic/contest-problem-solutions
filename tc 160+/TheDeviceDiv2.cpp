//# xor, case analysis
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

class TheDeviceDiv2 {
public:
    string identify(vector <string> plates) {
        int n = plates.size();
        int b = plates[0].size();
        vector< vector<int> > cnt(b, vector<int>(2));
        for (int i=0; i<n; ++i) {
            for (int j=0; j<b; ++j) {
                ++cnt[j][plates[i][j]-'0'];
            }
        }
        for (int i=0; i<b; ++i) {
            if (cnt[i][0]<1 || cnt[i][1]<2) {
                return "NO";
            }
        }
        return "YES";
    }
};
