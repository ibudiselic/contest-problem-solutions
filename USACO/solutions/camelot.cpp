/*
ID: ivan.bu1
PROG: camelot
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
#include <utility>
#include <queue>

using namespace std;

int D[30][26][30][26];
int kr, kc;
int R, C;
inline bool valid(int i, int j) {
    return i>=0 && j>=0 && i<R && j<C;
}
int king_dist(int i, int j) {
    return max(abs(kr-i), abs(kc-j));
}
const int di[] = { -2, -2, -1, 1, 2, 2, 1, -1 };
const int dj[] = { -1, 1, 2, 2, 1, -1, -2, -2 };
int main() {
    vector< pair<int, int> > v;
	ifstream fin("camelot.in");
    fin >> R >> C;
    char c;
    int r;
    fin >> c >> r;
    kr = r-1;
    kc = c-'A';
    while (fin >> c >> r) {
        v.push_back(make_pair(r-1, c-'A'));
    }
    fin.close();
    
    memset(D, 0xff, sizeof D);
    for (int sr=0; sr<R; ++sr) {
        for (int sc=0; sc<C; ++sc) {
            D[sr][sc][sr][sc] = 0;
            queue< pair<int, int> > Q;
            Q.push(make_pair(sr, sc));
            int layer_sz = 0;
            int dist = 0;
            while (!Q.empty()) {
                if (layer_sz == 0) {
                    layer_sz = Q.size();
                    ++dist;
                }
                --layer_sz;
                int i = Q.front().first;
                int j = Q.front().second;
                Q.pop();
                for (int d=0; d<8; ++d) {
                    const int ii = i + di[d];
                    const int jj = j + dj[d];
                    if (valid(ii, jj) && D[sr][sc][ii][jj]==-1) {
                        D[sr][sc][ii][jj] = dist;
                        Q.push(make_pair(ii, jj));
                    }
                }
            }
        }
    }

    int sol = 1234567890;
    for (int i=0; i<R; ++i) {
        for (int j=0; j<C; ++j) {
            int king, total;
            int cost = 0;
            for (int k=0; k<(int)v.size(); ++k) {
                if (D[i][j][v[k].first][v[k].second] == -1) {
                    goto FAILED;
                }
                cost += D[i][j][v[k].first][v[k].second];
            }
            king = king_dist(i, j);
            total = cost + king;
            for (int mi=0; mi<R; ++mi) {
                for (int mj=0; mj<C; ++mj) {
                    int cand = king_dist(mi, mj);
                    if (cand >= king) {
                        continue;
                    }
                    for (int k=0; k<(int)v.size(); ++k) {
                        const int orig = D[i][j][v[k].first][v[k].second];
                        if (D[i][j][mi][mj]==-1 || D[mi][mj][v[k].first][v[k].second]==-1) {
                            continue;
                        }
                        int alt = D[i][j][mi][mj] + D[mi][mj][v[k].first][v[k].second];
                        if (alt == orig) {
                            total = min(total, cost + cand);
                            break;
                        } else {
                            total = min(total, cost + cand + alt - orig);
                        }
                    }
                }
            }
            sol = min(sol, total);
FAILED: ;
        }
    }

    ofstream fout("camelot.out");
    fout << sol << '\n';
    fout.close();

	return 0;
}
