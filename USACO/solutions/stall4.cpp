/*
ID: ivan.bu1
PROG: stall4
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

using namespace std;

bool G[200][200];
int M, N;
int match[200], rmatch[200];
bool tried[200];
bool augment(int u) {
    if (tried[u]) {
        return false;
    }
    tried[u] = true;
    for (int v=0; v<N; ++v) {
        if (G[u][v] && (rmatch[v]==-1 || augment(rmatch[v]))) {
            match[u] = v;
            rmatch[v] = u;
            return true;
        }
    }
    return false;
}
int max_bimatch() {
    memset(match, 0xff, sizeof match);
    memset(rmatch, 0xff, sizeof rmatch);
    
    int sz = 0;
    for (int i=0; i<M; ++i) {
        if (match[i] == -1) {
            memset(tried, 0, sizeof tried);
            sz += augment(i);
        }
    }
    return sz;
}
int main() {
	ifstream fin("stall4.in");
    fin >> M >> N;
    for (int i=0; i<M; ++i) {
        int t, u;
        fin >> t;
        for (int j=0; j<t; ++j) {
            fin >> u;
            G[i][u-1] = 1;
        }
    }
    fin.close();

    ofstream fout("stall4.out");
    fout << max_bimatch() << '\n';
    fout.close();

	return 0;
}
