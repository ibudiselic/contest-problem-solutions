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

const long long mod = 1000000007;
long long wX[20001];
long long wY[20001];
void calc(int X, int lim, long long *ways) {
    for (int l=0; l<X; ++l) {
        for (int r=l+2; r<X; ++r) {
            if (2*(r-l) > lim) {
                break;
            }
            ways[2*(r-l)] += r-l-1;
        }
    }
}
class PatrolRoute {
public:
    int countRoutes(int X, int Y, int minT, int maxT) {
        memset(wX, 0, sizeof wX);
        memset(wY, 0, sizeof wY);
        calc(X, maxT, wX);
        calc(Y, maxT, wY);

        for (int i=1; i<=maxT; ++i) {
            wY[i] = (wY[i] + wY[i-1]) % mod;
        }
        long long sol = 0;
        for (int x=4; x<=maxT; x+=2) {
            int maxY = maxT - x;
            int minY = max(4, minT-x);
            if (minY <= maxY) {
                sol = (sol + wX[x]*(wY[maxY] - wY[minY-1])) % mod;
            }
        }

        return int((sol + mod)*6%mod);
    }
};
