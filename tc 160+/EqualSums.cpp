//# matrix, dfs, sums
//# => the key thing is to realize that the cell (i, j) contains a number that is the sum of a row number and a column number (0-9) and that the matrix is uniquely determined by the choice of row/column numbers if at least one row number is 0... when a row value is picked, it forces some colum rows which force some column values ... (use a dfs for that part)
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

const int MAXN = 55;
int Rval[MAXN];
int Cval[MAXN];
bool Rdone[MAXN];
bool Cdone[MAXN];
vector< vector<int> > B;
int n;
const int mod = 1000000007;
inline int modmul(long long a, long long b) {
    a *= b;
    return int(a>=mod ? a%mod : a);
}
inline int modadd(int a, int b) {
    a += b;
    return (a>=mod ? a-mod : a);
}

enum {
    NZ, ANY, FAIL
};
int colcheck(int);
int rowcheck(int r) {
    Rdone[r] = 1;
    int ret = (Rval[r]==0 ? ANY : NZ);
    for (int j=0; j<n; ++j) {
        if (B[r][j] != -1) {
            int cval = B[r][j] - Rval[r];
            if (cval < 0) return FAIL;
            if (Cval[j] == -1) {
                Cval[j] = cval;
                ret = max(ret, colcheck(j));
            } else if (cval != Cval[j]) {
                return FAIL;
            }
        }
    }
    return ret;
}
int colcheck(int c) {
    Cdone[c] = 1;
    int ret = NZ;
    for (int i=0; i<n; ++i) {
        if (B[i][c] != -1) {
            int rval = B[i][c] - Cval[c];
            if (rval < 0) return FAIL;
            if (Rval[i] == -1) {
                Rval[i] = rval;
                ret = max(ret, rowcheck(i));
            } else if (rval != Rval[i]) {
                return FAIL;
            }
        }
    }
    return ret;
}
class EqualSums {
public:
    int count(vector <string> board) {
        n = board.size();
        B.assign(n, vector<int>(n));
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                B[i][j] = (board[i][j]=='-' ? -1 : board[i][j]-'0');
            }
        }
        memset(Rdone, 0, sizeof Rdone);
        memset(Cdone, 0, sizeof Cdone);
        int ways = 1;
        int waysnz = 1;
        for (int i=0; i<n; ++i) {
            if (!Rdone[i]) {
                int any = 0;
                int nz = 0;
                for (int val=0; val<10; ++val) {
                    memset(Rval, 0xff, sizeof Rval);
                    memset(Cval, 0xff, sizeof Cval);
                    Rval[i] = val;
                    int res = rowcheck(i);
                    if (res == 0) {
                        ++any;
                        ++nz;
                    } else if (res == 1) {
                        ++any;
                    }
                }
                ways = modmul(ways, any);
                waysnz = modmul(waysnz, nz);
            }
        }
        return modadd(ways, mod-waysnz);
    }
};
