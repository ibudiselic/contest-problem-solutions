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
#include <map>
#include <queue>
#include <utility>

using namespace std;

vector<char> colors;
map<char, int> idx;
int get(char c) {
    if (!idx.count(c)) {
        idx[c] = int(colors.size());
        colors.push_back(c);
    }
    return idx[c];
}

int B[50][50];
int G[100][100];
int indeg[100];
class TopView {
public:
    string findOrder(vector <string> grid) {
        colors.clear();
        idx.clear();
        int m = grid.size();
        int n = grid[0].size();
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                B[i][j] = (grid[i][j]=='.' ? -1 : get(grid[i][j]));
            }
        }

        memset(G, 0, sizeof G);
        for (int v=0; v<(int)colors.size(); ++v) {
            int x = 100;
            int X = -1;
            int y = 100;
            int Y = -1;
            for (int i=0; i<m; ++i) {
                for (int j=0; j<n; ++j) {
                    if (B[i][j] == v) {
                        x = min(x, i);
                        X = max(X, i);
                        y = min(y, j);
                        Y = max(Y, j);
                    }
                }
            }
            for (int i=x; i<=X; ++i) {
                for (int j=y; j<=Y; ++j) {
                    if (B[i][j] == v) continue;
                    if (B[i][j] == -1) return "ERROR!";
                    G[v][B[i][j]] = 1;
                }
            }
        }

        memset(indeg, 0, sizeof indeg);
        for (int u=0; u<(int)colors.size(); ++u) {
            for (int v=0; v<(int)colors.size(); ++v) {
                if (G[u][v]) {
                    ++indeg[v];
                }
            }
        }

        priority_queue<int> PQ;
        for (int u=0; u<(int)colors.size(); ++u) {
            if (indeg[u] == 0) {
                PQ.push(-int(colors[u]));
            }
        }
        
        string sol;
        while (PQ.size() > 0) {
            char c = char(-PQ.top());
            PQ.pop();
            sol += c;
            int u = idx[c];
            for (int v=0; v<(int)colors.size(); ++v) {
                if (G[u][v]) {
                    if (--indeg[v] == 0) {
                        PQ.push(-int(colors[v]));
                    }
                }
            }
        }

        return sol.size()==colors.size() ? sol : "ERROR!";
    }
};
