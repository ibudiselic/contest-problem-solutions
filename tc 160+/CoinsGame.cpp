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

const int MAXN = 40;
int m, n;
bool iswin[MAXN][MAXN][MAXN][MAXN];
inline bool valid(int i, int j) {
    return i>=0 && j>=0 && i<m && j<n;
}
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };
struct State {
    int i, j, r, c;
};

const int mod = 1000000009;
inline int modadd(int a, int b) {
    a += b;
    return a>=mod ? a-mod : a;
}
inline int modsub(int a, int b) {
    a -= b;
    return a<0 ? a+mod : a;
}
inline int modmul(long long a, long long b) {
    a *= b;
    return int(a>=mod ? a%mod : a);
}

int C[1601][1601];
int modinv[1601];
class CoinsGame {
public:
    int ways(vector <string> board) {
        C[0][0] = 1;
        for (int i=1; i<1601; ++i) {
            C[i][0] = 1;
            for (int j=1; j<=i; ++j) {
                C[i][j] = modadd(C[i-1][j-1], C[i-1][j]);
            }
        }
        modinv[1] = 1;
        for (int i=2; i<1601; ++i) {
            modinv[i] = modmul(modinv[mod%i], mod-mod/i);
            assert(modmul(i, modinv[i]) == 1);
        }

        m = board.size();
        n = board[0].size();
        
        vector<pair<int, int> > avail;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (board[i][j] == '.') {
                    avail.push_back(make_pair(i, j));
                }
            }
        }

        memset(iswin, 0, sizeof iswin);
        queue<State> Q;
        for (int i=0; i<m; ++i) {
            for (int k=0; k<(int)avail.size(); ++k) {
                Q.push((State){i, -1, avail[k].first, avail[k].second});
                Q.push((State){i, n, avail[k].first, avail[k].second});
            }
        }
        for (int j=0; j<n; ++j) {
            for (int k=0; k<(int)avail.size(); ++k) {
                Q.push((State){-1, j, avail[k].first, avail[k].second});
                Q.push((State){m, j, avail[k].first, avail[k].second});
            }
        }
        while (!Q.empty()) {
            State at = Q.front();
            Q.pop();
            for (int d=0; d<4; ++d) {
                for (int stay0=0; stay0<2; ++stay0) {
                    for (int stay1=0; stay1<2; ++stay1) {
                        State next = (State){at.i+stay0*di[d], at.j+stay0*dj[d], at.r+stay1*di[d], at.c+stay1*dj[d]};
                        if (!stay0 && (!valid(at.i-di[d], at.j-dj[d]) || board[at.i-di[d]][at.j-dj[d]]!='#')) continue;
                        if (!stay1 && (!valid(at.r-di[d], at.c-dj[d]) || board[at.r-di[d]][at.c-dj[d]]!='#')) continue;
                        if (!valid(next.i, next.j) || !valid(next.r, next.c)) continue;
                        if (board[next.i][next.j]=='#' || board[next.r][next.c]=='#') continue;
                        if (iswin[next.i][next.j][next.r][next.c]) continue;
                        iswin[next.i][next.j][next.r][next.c] = true;
                        iswin[next.r][next.c][next.i][next.j] = true;
                        Q.push(next);
                    }
                }
            }
        }

        
        int navail = avail.size();
        vector<int> persz(navail+1);
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (board[i][j] != '.') continue;
                int ncands = 0;
                for (int r=0; r<m; ++r) {
                    for (int c=0; c<n; ++c) {
                        if (i==r && j==c) continue;
                        if (iswin[i][j][r][c]) {
                            ++ncands;
                        }
                    }
                }
                for (int sz=2; sz<=navail; ++sz) {
                    int add = modsub(C[navail-1][sz-1], C[navail-1-ncands][sz-1]);
                    persz[sz] = modadd(persz[sz], add);
                }
            }
        }
        int sol = 0;
        for (int sz=2; sz<=navail; ++sz) {
            sol = modadd(sol, modmul(persz[sz], modinv[sz]));
        }

        return sol;
    }
};
