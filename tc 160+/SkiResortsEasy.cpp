//# ski, greedy, peaks, minimal cost
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

class SkiResortsEasy {
public:
    int minCost(vector <int> altitude) {
        int sol = 0;
        for (int i=1; i<(int)altitude.size(); ++i) {
            if (altitude[i] > altitude[i-1]) {
                sol += altitude[i]-altitude[i-1];
                altitude[i] = altitude[i-1];
            }
        }
        return sol;
    }
};
