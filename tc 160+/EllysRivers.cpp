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

double best[2][100001];
vector<int> W, S;
inline double calc(int a, int b, int i, int prev) {
    double dist = sqrt(double(a-b)*(a-b) + double(W[i])*W[i]);
    double sail_time = dist/S[i];
//    cerr << i << ": " << a << ' ' << b << ' ' << sail_time << '\n';
    return best[prev][a] + sail_time;
}
class EllysRivers {
public:
    double getMin(int length, int walk, vector <int> width, vector <int> speed) {
        W = width;
        S = speed;
        int n = width.size();
        double kilometer_walk_time = 1.0/walk;
        best[1][0] = 0.0;
        for (int i=1; i<=length; ++i) {
            best[1][i] = best[1][i-1] + kilometer_walk_time;
        }
        for (int i=0; i<n; ++i) {
            int cur = i&1;
            int last = 1-cur;
            best[cur][0] = best[last][0] + double(width[i])/speed[i];
            int pos = 0;
            for (int j=1; j<=length; ++j) {
                best[cur][j] = best[cur][j-1] + kilometer_walk_time;
                double pos_val = calc(pos, j, i, last);
                while (pos < j) {
                    double next_val = calc(pos+1, j, i, last);
                    if (next_val < pos_val) {
                        ++pos;
                        pos_val = next_val;
                    } else {
                        break;
                    }
                }
                best[cur][j] = min(best[cur][j], pos_val);
            }
        }
        return best[(n+1)&1][length];
    }
};
