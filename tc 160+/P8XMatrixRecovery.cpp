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

vector<string> R, C;
int m, n;
bool can(int ccol, int realcol) {
    for (int i=0; i<m; ++i) {
        if (C[ccol][i]=='?' || R[i][realcol]=='?') {
            continue;
        }
        if (C[ccol][i] != R[i][realcol]) {
            return false;
        }
    }
    return true;
}
bool G[30][30];
int match[30];
int rmatch[30];
bool done[30];
bool augment(int ccol) {
    done[ccol] = 1;
    for (int i=0; i<n; ++i) {
        if (G[ccol][i] && (rmatch[i]==-1 || !done[rmatch[i]] && augment(rmatch[i]))) {
            match[ccol] = i;
            rmatch[i] = ccol;
            return true;
        }
    }
    return false;
}
int bimatch() {
    memset(match, 0xff, sizeof match);
    memset(rmatch, 0xff, sizeof rmatch);
    int sz = 0;
    for (int i=0; i<n; ++i) {
        if (match[i] == -1) {
            memset(done, 0, sizeof done);
            sz += augment(i);
        }
    }
    return sz;
}
bool ok() {
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            G[i][j] = can(i, j);
        }
    }
    
    return bimatch() == n;
}
class P8XMatrixRecovery {
public:
    vector <string> solve(vector <string> rows, vector <string> columns) {
        R = rows;
        C = columns;
        m = rows.size();
        n = columns.size();
        
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (R[i][j] == '?') {
                    R[i][j] = '0';
                    if (ok()) {
                        continue;
                    }
                    R[i][j] = '1';
                    assert(ok());
                }
            }
        }
        
        return R;
    }
};
