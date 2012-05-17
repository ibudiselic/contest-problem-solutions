#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <utility>

using namespace std;

const int MEMOSZ = 12;
map< pair< vector<string>, int>, long long > dp;
int get(int i, int j, const vector<string> &field) {
    --i;
    --j;
    if (i<0 || j<0 || i>=(int)field.size() || j>=(int)field[0].size()) {
        return 0;
    }
    return field[i][j] == 'o';
}
long long go(vector<string> &field, int K) {
    int m = field.size();
    int n = field[0].size();
    /*cerr << K << '\n';
    for (int i=0; i<m; ++i) {
        cerr << field[i] << '\n';
    }
    cerr << '\n';*/
    const pair< vector<string>, int> state = make_pair(field, K);
    if (m*n<=MEMOSZ && dp.count(state)) {
        return dp[state];
    }

    long long ret = 0;
    if (K == 0) {
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                ret += (field[i][j] == 'o');
            }
        }
    } else if (K & 1) {
        vector<string> next(m+2, string(n+2, ' '));
        for (int i=0; i<=m+1; ++i) {
            for (int j=0; j<=n+1; ++j) {
                int cnt = 0;
                for (int di=-1; di<2; ++di) {
                    for (int dj=-1; dj<2; ++dj) {
                        if (di==0 || dj==0) {
                            cnt += get(i+di, j+dj, field);
                        }
                    }
                }
                next[i][j] = (cnt&1) ? 'o' : '.';
            }
        }
        ret = go(next, K-1);
    } else {
        if (m & 1) {
            field.push_back(string(n, '.'));
            ++m;
        }
        if (n & 1) {
            for (int i=0; i<m; ++i) {
                field[i] += ' ';
            }
            ++n;
        }
        for (int si=0; si<2; ++si) {
            for (int sj=0; sj<2; ++sj) {
                vector<string> next(m/2, string(n/2, ' '));
                for (int i=si; i<m; i+=2) {
                    for (int j=sj; j<n; j+=2) {
                        next[i/2][j/2] = field[i][j];
                    }
                }
                ret += go(next, K/2);
            }
        }
    }

    if (m*n <= MEMOSZ) {
        dp[state] = ret;
    }
    return ret;
}
class XorLife {
public:
    long long countAliveCells(vector <string> field, int K) {
        dp.clear();
        return go(field, K);
    }
};
