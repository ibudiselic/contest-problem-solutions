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

bool cant[16][16];
bool done[16][16][1<<14];
double dp[16][16][1<<14];
int n;
double go(int at, int last, int avail) {
    if (done[at][last][avail]) {
        return dp[at][last][avail];
    }
    done[at][last][avail] = 1;
    double &ret = dp[at][last][avail];
    if (avail == 0) {
        ret = 1.0;
    } else {
        ret = 0.0;
        int opts = 0;
        for (int i=0; i<n; ++i) {
            if (avail & (1<<i)) {
                ++opts;
                if (!cant[last][i]) {
                    ret += go(at+1, i, avail^(1<<i));
                }
            }
        }
        ret /= opts;
    }
    return ret;
}
class RandomOption {
public:
    double getProbability(int n, vector <int> badLane1, vector <int> badLane2) {
        ::n = n;
        memset(cant, 0, sizeof cant);
        for (int i=0; i<(int)badLane1.size(); ++i) {
            cant[badLane1[i]][badLane2[i]] = 1;
            cant[badLane2[i]][badLane1[i]] = 1;
        }
        memset(done, 0, sizeof done);
        return go(0, n, (1<<n)-1);
    }
};
