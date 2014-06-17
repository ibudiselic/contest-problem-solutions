//# tiles, chessboard, dp, brute force, implementation
//# => Process the board by columns and maintain a mask of blocked squares in the previous row. Then brute force the Mx2 board and move on.
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

vector<string> B;
int m, n;
int dp[51][1<<4];
int getblocked(const vector<string> &part) {
    int mask = 0;
    for (int i=0; i<m; ++i) {
        if (part[i][1] == 'X') {
            mask |= 1<<i;
        }
    }
    return mask;
}
int go(int, int);
int go(int j, vector<string> part) {
    int ret = go(j+1, getblocked(part));
    for (int r=0; r<m; ++r) {
        for (int c=j-1; c<=j; ++c) {
            if (part[r][c-j+1]!='X' && (r+c)%2==0) {
                for (int dr=-1; dr<=1; dr+=2) {
                    int rr = r + dr;
                    if (rr < 0) continue;
                    if (rr >= m) break;
                    if (part[rr][c-j+1] == 'X') continue;
                    for (int dc=-1; dc<=1; dc+=2) {
                        int cc = c + dc;
                        if (cc<j-1 || cc>j) continue;
                        if (part[r][cc-j+1] == 'X') continue;
                        part[r][c-j+1] = 'X';
                        part[rr][c-j+1] = 'X';
                        part[r][cc-j+1] = 'X';
                        ret = max(ret, 1+go(j, part));
                        part[r][c-j+1] = ' ';
                        part[rr][c-j+1] = ' ';
                        part[r][cc-j+1] = ' ';
                    }
                }
            }
        }
    }
    return ret;
}
int go(int j, int blocked) {
    int &ret = dp[j][blocked];
    if (ret != -1) {
        return ret;
    }
    if (j == n) {
        ret = 0;
    } else {
        vector<string> tmp(m, string(2, ' '));
        for (int i=0; i<m; ++i) {
            if ((blocked & (1<<i)) || (j>0 && B[i][j-1]=='X')) {
                tmp[i][0] = 'X';
            }
            if (B[i][j] == 'X') {
                tmp[i][1] = 'X';
            }
        }
        ret = go(j, tmp);
    }
    return ret;
}
class TheTilesDivTwo {
public:
    int find(vector <string> board) {
        B = board;
        m = B.size();
        n = B[0].size();
        memset(dp, 0xff, sizeof dp);
        return go(0, (1<<m)-1);
    }
};
