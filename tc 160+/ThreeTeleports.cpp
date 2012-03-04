#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

long long my_abs(long long x) {
    return x<0 ? -x : x;
}
long long dist(long long a, long long b, long long c, long long d) {
    return my_abs(a-c) + my_abs(b-d);
}
int a[3], b[3], c[3], d[3];
class ThreeTeleports {
public:
    int shortestDistance(int xMe, int yMe, int xHome, int yHome, vector <string> teleports) {
        for (int i=0; i<3; ++i) {
            sscanf(teleports[i].c_str(), "%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
        }
        int lim = 27;
        long long sol = dist(xMe, yMe, xHome, yHome);
        for (int mask=1; mask<lim; ++mask) {
            vector<int> order;
            vector<int> fwd(3, 0);
            int tmp = mask;
            for (int i=0; i<3; ++i) {
                int t = tmp%3;
                tmp /= 3;
                if (t) {
                    order.push_back(i);
                    fwd[i] = (t==1);
                }
            }
            do {
                long long cand = 0;
                int x = xMe;
                int y = yMe;
                for (int i=0; i<(int)order.size(); ++i) {
                    int t = order[i];
                    if (fwd[t]) {
                        cand += dist(x, y, a[t], b[t]) + 10;
                        x = c[t];
                        y = d[t];
                    } else {
                        cand += dist(x, y, c[t], d[t]) + 10;
                        x = a[t];
                        y = b[t];
                    }
                }
                sol = min(sol, cand + dist(x, y, xHome, yHome));
            } while (next_permutation(order.begin(), order.end()));
        }
        
        return sol;
    }
};
