//# wolves, grid, dp
//# => Compute the number of ways to do a certain move using dp, then brute force all possible end positions.
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
const int mod = 1000000007;
int ways[2][52][52];
inline void inc(int &a, int b) {
    a += b;
    if (a >= mod) a -= mod;
}
inline int modmul(long long a, long long b) {
    a *= b;
    return int(a>=mod ? a%mod : a);
}
class WolfPackDivTwo {
public:
    int calc(vector <int> x, vector <int> y, int m) {
        memset(ways, 0, sizeof ways);
        ways[0][0][0] = 1;
        for (int i=0; i<m; ++i) {
            int prev = i&1;
            int cur = 1-prev;
            for (int a=0; a<=50; ++a) {
                for (int b=0; b<=50; ++b) {
                    ways[cur][a][b] = 0;
                    for (int d=0; d<4; ++d) {
                        int r = abs(a + di[d]);
                        int c = abs(b + dj[d]);
                        inc(ways[cur][a][b], ways[prev][r][c]);
                    }
                }
            }
        }

        int sol = 0;
        for (int a=-50; a<=100; ++a) {
            for (int b=-50; b<=100; ++b) {
                int add = 1;
                for (int i=0; i<(int)x.size(); ++i) {
                    int aa = abs(a-x[i]);
                    int bb = abs(b-y[i]);
                    if (aa>50 || bb>50) {
                        add = 0;
                        break;
                    }
                    add = modmul(add, ways[m&1][aa][bb]);
                }
                inc(sol, add);
            }
        }
        return sol;
    }
};
