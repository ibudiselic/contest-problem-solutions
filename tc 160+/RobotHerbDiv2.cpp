//# math, robot, robot movement, cycles, implementation
//# => This can be simulated, but can also be solved with the approach in the div1 version.
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

int di[] = {-1, 0, 1, 0};
int dj[] = {0, 1, 0, -1};
class RobotHerbDiv2 {
public:
    int getdist(int T, vector <int> a) {
        int x = 0;
        int y = 0;
        int d = 0;
        for (int i=0; i<4; ++i) {
            for (int j=0; j<(int)a.size(); ++j) {
                x += di[d]*a[j];
                y += dj[d]*a[j];
                d = (d+a[j])%4;
            }
        }
        x *= T/4;
        y *= T/4;
        for (int i=0; i<T%4; ++i) {
            for (int j=0; j<(int)a.size(); ++j) {
                x += di[d]*a[j];
                y += dj[d]*a[j];
                d = (d+a[j])%4;
            }
        }
        return abs(x) + abs(y);
    }
};
