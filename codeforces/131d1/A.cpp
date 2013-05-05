#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

#define MAXN 200

int next[3] = { 1, 2, 0 };
int C[MAXN];
int n;
int calc(int at, vector<int> indeg, const vector< vector<int> > &adj) {
    queue<int> Q[3];
    for (int i=0; i<n; ++i) {
        if (indeg[i] == 0) {
            Q[C[i]].push(i);
        }
    }

    int done = 0;
    int sol = 0;
    while (done < n) {
        if (Q[at].size() == 0) {
            ++sol;
            at = next[at];
        }
        while (Q[at].size() > 0) {
            int u = Q[at].front();
            Q[at].pop();
            ++sol;
            ++done;
            for (int i=0; i<(int)adj[u].size(); ++i) {
                int v = adj[u][i];
                if (--indeg[v] == 0) {
                    Q[C[v]].push(v);
                }
            }
        }
    }
    
    return sol;
}
int main() {
    cin >> n;
    for (int i=0; i<n; ++i) {
        int c;
        cin >> c;
        C[i] = c - 1;
    }
    vector< vector<int> > adj(n, vector<int>());
    vector<int> indeg(n, 0);
    for (int i=0; i<n; ++i) {
        int k;
        cin >> k;
        for (int j=0; j<k; ++j) {
            int a;
            cin >> a;
            --a;
            adj[a].push_back(i);
            ++indeg[i];
        }
    }
    
    int sol = min(calc(0, indeg, adj), calc(1, indeg, adj));
    sol = min(sol, calc(2, indeg, adj));
    cout << sol << '\n';

    return 0;
}
