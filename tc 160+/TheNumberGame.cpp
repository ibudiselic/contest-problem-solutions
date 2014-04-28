//# bfs, strings, transformation
//# => trivial
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
#include <sstream>

using namespace std;

int X[15][15];
int Y[15][15];
bool w[15][15][15];
string tostr(int x) {
    ostringstream os;
    os << x;
    return os.str();
}
void proc(const string &s, int (*v)[15]) {
    for (int i=0; i<(int)s.size(); ++i) {
        for (int j=0; j<i; ++j) {
            v[i][j] = 0;
            for (int k=i; k>=j; --k) {
                v[i][j] = v[i][j]*10 + (s[k]-'0');
            }
        }
        for (int j=i; j<(int)s.size(); ++j) {
            v[i][j] = 0;
            for (int k=i; k<=j; ++k) {
                v[i][j] = v[i][j]*10 + (s[k]-'0');
            }
        }
    }
}
char dp[1001][15][15][15][15];
char go(int move, int x0, int x1, int y0, int y1) {
    char &ret = dp[move][x0][x1][y0][y1];
    if (ret != -1) {
        return ret;
    }
    if (X[x0][x1] == Y[y0][y1]) {
        ret = 1;
    } else if (move == 1000) {
        ret = 2;
    } else if (move&1) {
        ret = 1;
        if (go(move+1, x0, x1, y1, y0) == 2) {
            ret = 2;
        } else if (y0 < y1) {
            if (go(move+1, x0, x1, y0+1, y1) == 2
                ||
                go(move+1, x0, x1, y0, y1-1) == 2) {
                    ret = 2;
            }   
        } else if (y1 < y0) {
            if (go(move+1, x0, x1, y0-1, y1) == 2
                ||
                go(move+1, x0, x1, y0, y1+1) == 2) {
                    ret = 2;
            }   
        } else {
            ret = (w[min(x0, x1)][max(x0, x1)][y0] ? 1 : 2);
        }
    } else {
        ret = 2;
        if (go(move+1, x1, x0, y0, y1) == 1) {
            ret = 1;
        } else if (x0 < x1) {
            if (go(move+1, x0+1, x1, y0, y1) == 1
                ||
                go(move+1, x0, x1-1, y0, y1) == 1) {
                    ret = 1;
            }
        } else if (x1 < x0) {
            if (go(move+1, x0-1, x1, y0, y1) == 1
                ||
                go(move+1, x0, x1+1, y0, y1) == 1) {
                    ret = 1;
            }
        }
    }
    return ret;
}
class TheNumberGame {
public:
    string determineOutcome(int A, int B) {
        string a = tostr(A);
        string b = tostr(B);
        proc(a, X);
        proc(b, Y);
        for (int i=0; i<(int)a.size(); ++i) {
            for (int j=i; j<(int)a.size(); ++j) {
                for (int k=0; k<(int)b.size(); ++k) {
                    w[i][j][k] = (a.substr(i, j-1+1).find(b[k]) != string::npos);
                }
            }
        }
        memset(dp, 0xff, sizeof dp);
        if (go(0, 0, (int)a.size()-1, 0, (int)b.size()-1) == 1) {
            return "Manao wins";
        } else {
            return "Manao loses";
        }
    }
};
