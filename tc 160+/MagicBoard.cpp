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

bool G[50][50];
int r_deg[50];
int c_deg[50];
bool rv[50];
bool cv[50];
int m, n;
void goc(int);
void gor(int r) {
    rv[r] = 1;
    for (int j=0; j<n; ++j) {
        if (!cv[j] && G[r][j]) {
            goc(j);
        }
    }
}
void goc(int c) {
    cv[c] = 1;
    for (int i=0; i<m; ++i) {
        if (!rv[i] && G[i][c]) {
            gor(i);
        }
    }
}
class MagicBoard {
public:
    string ableToUnlock(vector <string> board) {
        m = board.size();
        n = board[0].size();
        memset(G, 0, sizeof G);
        memset(r_deg, 0, sizeof r_deg);
        memset(c_deg, 0, sizeof c_deg);
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (board[i][j] == '#') {
                    ++r_deg[i];
                    ++c_deg[j];
                    G[i][j] = 1;
                }
            }
        }
        
        int r_odd = 0;
        for (int i=0; i<m; ++i) {
            if (r_deg[i] & 1) {
                ++r_odd;
            }
        }
        if (r_odd > 1) {
            return "NO";
        }

        int c_odd = 0;
        for (int i=0; i<n; ++i) {
            if (c_deg[i] & 1) {
                ++c_odd;
            }
        }
        if (r_odd+c_odd > 2) {
            return "NO";
        }
        memset(rv, 0, sizeof rv);
        memset(cv, 0, sizeof cv);
        for (int i=0; i<n; ++i) {
            if (c_deg[i] > 0) {
                goc(i);
                for (int j=0; j<m; ++j) {
                    if (r_deg[j]>0 && !rv[j]) {
                        return "NO";
                    }
                }
                for (int j=0; j<n; ++j) {
                    if (c_deg[j]>0 && !cv[j]) {
                        return "NO";
                    }
                }
                break;
            }
        }
        return "YES";
    }
};
