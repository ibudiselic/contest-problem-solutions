//# board, shortest paths, 0-1 bfs, bfs, game
//# => Do a bfs from every starting node...
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
const int MAXN = 40+2;
int D[MAXN][MAXN][MAXN][MAXN];
const int inf = 123456;
using pii = pair<int, int>;
class GameOnABoard {
public:
    int optimalChoice(vector <string> cost) {
        int m = cost.size();
        int n = cost[0].size();

        int sol = inf;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                for (int a=0; a<m; ++a) {
                    for (int b=0; b<n; ++b) {
                        D[i][j][a][b] = inf;
                    }
                }

                int best = 0;
                deque<pii> Q{{i, j}};
                int (*dist)[MAXN] = D[i][j];
                int layer_sz = 1;
                int d = cost[i][j]-'0';
                while (!Q.empty()) {
                    if (layer_sz == 0) {
                        layer_sz = Q.size();
                        ++d;
                    }
                    pii tmp = Q.front();
                    Q.pop_front();
                    --layer_sz;
                    int u = tmp.first;
                    int v = tmp.second;
                    if (d > dist[u][v]) continue;

                    best = d;
                    for (int dir=0; dir<4; ++dir) {
                        int r = u + di[dir];
                        int c = v + dj[dir];
                        if (r<0 || c<0 || r>=m || c>=n) continue;
                        if (cost[r][c] == '0') {
                            if (dist[r][c] > d) {
                                dist[r][c] = d;
                                Q.push_front({r, c});
                                ++layer_sz;
                            }
                        } else {
                            if (dist[r][c] > d+1) {
                                dist[r][c] = d+1;
                                Q.push_back({r, c});
                            }
                        }
                    }
                }

                sol = min(sol, best);
            }
        }

        return sol;
    }
};
