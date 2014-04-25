//# dijkstra, ski, graph, peaks, minimal cost
//# => Notice that there's never a point to change the height to a value that is not the height of some other peak.
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

struct State {
    int at, h;
    long long d;
};
bool operator<(const State &a, const State &b) {
    if (a.d != b.d) return a.d > b.d;
    if (a.at != b.at) return a.at < b.at;
    return a.h < b.h;
}

const long long inf = 1234567891234567ll;
long long best[55][55];
bool done[55][55];
class SkiResorts {
public:
    long long minCost(vector <string> road, vector <int> altitude) {
        vector<int> A(begin(altitude), end(altitude));
        sort(begin(A), end(A));
        A.resize(unique(begin(A), end(A)) - begin(A));
        for (int i=0; i<(int)altitude.size(); ++i) {
            altitude[i] = lower_bound(begin(A), end(A), altitude[i]) - begin(A);
        }
        int numalt = A.size();

        int n = road.size();
        for (int i=0; i<n; ++i) {
            for (int j=0; j<numalt; ++j) {
                best[i][j] = inf;
            }
        }
        memset(done, 0, sizeof done);
        for (int h=0; h<numalt; ++h) {
            best[0][h] = abs(A[h]-A[altitude[0]]);
        }
        while (1) {
            State tmp = (State){0, 0, inf};
            for (int i=0; i<n; ++i) {
                for (int h=0; h<numalt; ++h) {
                    if (!done[i][h] && best[i][h]<tmp.d) {
                        tmp.at = i;
                        tmp.h = h;
                        tmp.d = best[i][h];
                    }
                }
            }
            if (tmp.d == inf) {
                return -1;
            }
            if (tmp.at == n-1) {
                return tmp.d;
            }
            done[tmp.at][tmp.h] = 1;
            for (int i=0; i<n; ++i) {
                if (road[tmp.at][i] == 'N') continue;
                for (int h=0; h<=tmp.h; ++h) {
                    long long cost = tmp.d + abs(A[h]-A[altitude[i]]);
                    if (cost < best[i][h]) {
                        best[i][h] = cost;
                    }
                }
            }
        }

        return -1;
    }
};
