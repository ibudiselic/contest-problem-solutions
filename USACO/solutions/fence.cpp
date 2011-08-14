/*
ID: ivan.bu1
PROG: fence
LANG: C++
*/
#include <iostream>
#include <iterator>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cassert>

using namespace std;

int A[1024], B[1024];
int deg[500];
bool dead[1024];
int m;
vector< vector<int> > G(500);
bool v[500];
int conn_internal(int at) {
    int ret = 1;
    v[at] = true;
    for (int i=0; i<(int)G[at].size(); ++i) {
        const int edge = G[at][i];
        if (!dead[edge]) {
            const int to = (A[edge]==at ? B[edge] : A[edge]);
            if (!v[to]) {
                ret += conn_internal(to);
            }
        }
    }
    return ret;
}
int conn(int at, int to, int edge) {
    memset(v, 0, sizeof v);
    dead[edge] = true;
    int ret = conn_internal(to);
    dead[edge] = false;
    return ret + (deg[at]==1);
}
int main() {
    int cnt_alive = 0;
	ifstream fin("fence.in");
    fin >> m;
    for (int i=0; i<m; ++i) {
        int a, b;
        fin >> a >> b;
        A[i] = --a; 
        B[i] = --b;
        ++deg[a];
        ++deg[b];
        cnt_alive += (G[a].size() == 0);
        cnt_alive += (G[b].size() == 0);
        G[a].push_back(i);
        G[b].push_back(i);
    }
    fin.close();

    vector<int> sol;
    for (int i=0; i<500; ++i) {
        if (deg[i] & 1) {
            sol.push_back(i);
            break;
        }
    }
    if (sol.size() == 0) {
        sol.push_back(0);
    }
    
    int at = sol[0];
    while (cnt_alive > 0) {
        int min_next = 500;
        int edge_choice = -1;
        for (int i=0; i<(int)G[at].size(); ++i) {
            const int edge = G[at][i];
            if (!dead[edge]) {
                const int next = (A[edge]==at ? B[edge] : A[edge]);
                if (next<min_next && (deg[next]>1 || cnt_alive==2) && conn(at, next, edge)==cnt_alive) {
                    min_next = next;
                    edge_choice = edge;
                }
            }
        }
        assert(min_next < 500);
        dead[edge_choice] = true;
        if (--deg[at] == 0) {
            --cnt_alive;
        }
        if (--deg[min_next] == 0) {
            --cnt_alive;
        }
        sol.push_back(min_next);
        at = min_next;
    }
    

    ofstream fout("fence.out");
    for (int i=0; i<(int)sol.size(); ++i) {
        fout << sol[i]+1 << '\n';
    }
    fout.close();

	return 0;
}

