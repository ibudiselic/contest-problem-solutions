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

class RectangularSum {
public:
    long long minimalArea(int H, int W, long long S) {
        vector<long long> D;
        long long lim = max(H, W);
        S *= 2;
        for (long long d=1; d<=lim && d*d<=S; ++d) {
            if (S%d == 0) {
                D.push_back(d);
            }
        }
        const long long inf = 12345689123456789LL;
        long long sol = inf;
        for (int i=0; i<(int)D.size(); ++i) {
            long long w = D[i];
            if (w > W) {
                break;
            }
            for (int j=0; j<(int)D.size(); ++j) {
                long long h = D[j];
                if (h > H) {
                    break;
                }
                if (h*w>=sol || S/w%h!=0) {
                    continue;
                }
                long long t = S/w/h - (long long)W*(h-1) - (w-1);
                if (t < 0) {
                    break;
                }
                if (t%2 != 0) {
                    continue;
                }
                t /= 2;
                long long i = t/W;
                long long j = t - i*W;
                if (i+h>H || j+w>W) {
                    continue;
                }
                sol = h*w;
            }
        }

        return sol==inf ? -1 : sol;
    }
};
