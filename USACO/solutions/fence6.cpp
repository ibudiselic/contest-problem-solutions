/*
ID: ivan.bu1
PROG: fence6
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
#include <map>

using namespace std;

int G[101][101], G2[101][101];
map< vector<int>, int > vind;
const int inf = 987654321;
int get_vertex(const vector<int> &v) {
    if (!vind.count(v)) {
        int tmp = vind.size();
        vind[v] = tmp;
    }
    return vind[v];
}
int main() {
	ifstream fin("fence6.in");
    int E;
    fin >> E;
    for (int i=0; i<E; ++i) {
        int seg, len, n1, n2;
        fin >> seg >> len >> n1 >> n2;
        vector<int> v1, v2;
        int s;
        for (int j=0; j<n1; ++j) {
            fin >> s;
            v1.push_back(s);   
        }
        for (int j=0; j<n2; ++j) {
            fin >> s;
            v2.push_back(s);   
        }
        v1.push_back(seg);
        v2.push_back(seg);
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        int u = get_vertex(v1);
        int v = get_vertex(v2);
        G[u][v] = G[v][u] = len;
    }
    fin.close();
    
    int n = vind.size();
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            G[i][j] = (G[i][j] ? G[i][j] : inf);
        }
        G[i][i] = 0;
    }
    int sol = inf;
    for (int i=0; i<n; ++i) {
        for (int j=i+1; j<n; ++j) {
            if (G[i][j] < inf) {
                memcpy(G2, G, sizeof G2);
                G2[i][j] = G2[j][i] = inf;
                for (int c=0; c<n; ++c) {
                    for (int a=0; a<n; ++a) {
                        for (int b=0; b<n; ++b) {
                            G2[a][b] = min(G2[a][b], G2[a][c] + G2[c][b]);
                        }
                    }
                }
                sol = min(sol, G2[i][j] + G[i][j]);
            }
        }
    }
    ofstream fout("fence6.out");
    fout << sol << '\n';
    fout.close();

	return 0;
}
