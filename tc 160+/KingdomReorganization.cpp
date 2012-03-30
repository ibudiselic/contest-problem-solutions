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

int n;
bool G[50][50];
int B[50][50];
int D[50][50];
int value(char c) {
    if (c <= 'Z') {
        return c-'A';
    } else {
        return c-'a'+26;
    }
}

struct edge {
    int a, b, c;
    edge(int a_, int b_, int c_): a(a_), b(b_), c(c_) {}
};
bool operator<(const edge &x, const edge &y) {
    if (x.c != y.c) {
        return x.c < y.c;
    } else if (x.a != y.a) {
        return x.a < y.a;
    } else {
        return x.b < y.b;
    }
}
bool done[50];
bool dfs(int u, int v) {
    done[u] = true;
    if (u == v) {
        return true;
    }
    for (int i=0; i<n; ++i) {
        if (!done[i] && G[u][i] && dfs(i, v)) {
            return true;
        }
    }
    return false;
}
class KingdomReorganization {
public:
    int getCost(vector <string> kingdom, vector <string> build, vector <string> destroy) {
        memset(G, 0, sizeof G);
        n = kingdom.size();
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                B[i][j] = value(build[i][j]);
            }
        }
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                D[i][j] = value(destroy[i][j]);
            }
        }

        vector<edge> edges;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                G[i][j] = (kingdom[i][j] == '1');
                if (i>j && G[i][j]) {
                    edges.push_back(edge(i, j, D[i][j]));
                }
            }
        }
        
        sort(edges.begin(), edges.end());
        int sol = 0;
        for (int i=0; i<(int)edges.size(); ++i) {
            const edge &e = edges[i];
            G[e.a][e.b] = G[e.b][e.a] = 0;
            memset(done, 0, sizeof done);
            if (dfs(e.a, e.b)) {
                sol += e.c;
            } else {
                G[e.a][e.b] = G[e.b][e.a] = 1;
            }
        }
        
        edges.clear();
        for (int i=0; i<n; ++i) {
            for (int j=i+1; j<n; ++j) {
                if (G[i][j] == 0) {
                    memset(done, 0, sizeof done);
                    if (dfs(i, j)) {
                        continue;
                    } else {
                        edges.push_back(edge(i, j, B[i][j]));
                    }
                }
            }
        }
        sort(edges.begin(), edges.end());
        for (int i=0; i<(int)edges.size(); ++i) {
            const edge &e = edges[i];
            memset(done, 0, sizeof done);
            if (!dfs(e.a, e.b)) {
                G[e.a][e.b] = G[e.b][e.a] = 1;
                sol += e.c;
            }
        }
        return sol;
    }
};
