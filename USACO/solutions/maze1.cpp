/*
ID: ivan.bu1
PROG: maze1
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
#include <queue>
#include <utility>

using namespace std;

char A[256][256];
bool done[256][256];
int D[256][256];
int best[256][256];
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };
int main() {
	ifstream fin("maze1.in");
    int m, n;
    fin >> n >> m;
    m = 2*m + 1;
    n = 2*n + 1;
    char c;
    fin >> noskipws;
    fin >> c;
    for (int i=0; i<m; ++i) {
        for (int j=0; j<n; ++j) {
            fin >> A[i][j];
        }
        fin >> c;
    }
    fin.close();
    
    for (int i=0; i<m; ++i) {
        for (int j=0; j<n; ++j) {
            best[i][j] = 1234567890;
        }
    }
    for (int i=0; i<m; ++i) {
        for (int j=0; j<n; ++j) {
            if (A[i][j] == ' ') {
                bool is_exit = false;
                for (int d=0; d<4; ++d) {
                    int r = i + di[d];
                    int c = j + dj[d];
                    if (r<0 || c<0 || r>=m || c>=n) {
                        is_exit = true;
                        break;
                    }
                }
                if (is_exit) {
                    memset(done, 0, sizeof done);
                    queue< pair<int, int> > Q;
                    Q.push(make_pair(i, j));
                    int dist = 1;
                    int t = 0;
                    done[i][j] = true;
                    D[i][j] = 1;
                    while (!Q.empty()) {
                        if (t == 0) {
                            t = Q.size();
                            ++dist;
                        }
                        --t;
                        const pair<int, int> tmp = Q.front();
                        Q.pop();
                        int a = tmp.first;
                        int b = tmp.second;
                        
                        for (int d=0; d<4; ++d) {
                            int r = a + di[d];
                            int c = b + dj[d];
                            if (r<0 || c<0 || r>=m || c>=n || A[r][c]!=' ' || done[r][c]) {
                                continue;
                            }
                            done[r][c] = true;
                            D[r][c] = dist;
                            Q.push(make_pair(r, c));
                        }
                    }
                    for (int a=0; a<m; ++a) {
                        for (int b=0; b<n; ++b) {
                            best[a][b] = min(best[a][b], D[a][b]);
                        }
                    }
                }
            }
        }
    }
    
    int sol = 0;
    for (int i=0; i<m; ++i) {
        for (int j=0; j<n; ++j) {
            if (A[i][j] == ' ') {
                sol = max(sol, best[i][j]);
            }
        }
    }

    ofstream fout("maze1.out");
    fout << sol/2 << '\n';
    fout.close();

	return 0;
}

