//# math, robot, robot movement, cycles
//# => After at most 4 moves, there is a cycle in the starting direction so we simulate the 4 moves, apply that T/4 times and finally simulate another T%4 moves.
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

int di[] = { -1, 0, 1, 0 };
int dj[] = { 0, 1, 0, -1 };

class RobotHerb {
public:
    long long getdist(int T, vector <int> a) {
        long long x = 0;
        long long y = 0;
        int d = 0;
        for (int i=0; i<min(T, 4); ++i) {
            for (int j=0; j<(int)a.size(); ++j) {
                x += di[d]*a[j];
                y += dj[d]*a[j];
                d = (d+a[j])%4;
            }
        }
        if (T <= 4) {
            return abs(x) + abs(y);
        }
        x *= T/4;
        y *= T/4;
        d = int(((long long)d*(T/4))%4);
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
