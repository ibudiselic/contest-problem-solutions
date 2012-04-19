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

int N;
vector<int> P;
bool G[50][50];
bool start[50];
double fact(int n) {
    double ret = 1.0;
    for (int i=1; i<=n; ++i) {
        ret *= i;
    }
    return ret;
}
void dfs(int u, int len, double &sol) {
    sol += 1.0/fact(len + 1);
    for (int i=0; i<N; ++i) {
        if (G[u][i]) {
            dfs(i, len+1, sol);
        }
    }
}
class PrinceXToastbook {
public:
    double eat(vector <int> prerequisite) {
        P = prerequisite;
        N = P.size();
        memset(G, 0, sizeof G);
        for (int i=0; i<N; ++i) {
            start[i] = (P[i] == -1);
            if (!start[i]) {
                G[P[i]][i] = true;
            }
        }
        double sol = 0.0;
        for (int i=0; i<N; ++i) {
            if (start[i]) {
                dfs(i, 0, sol);
            }
        }
        return sol;
    }
};
