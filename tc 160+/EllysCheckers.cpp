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

int dp[1<<20];
int n;
int win(int mask) {
    mask &= (1<<(n-1))-1;
    int &ret = dp[mask];
    if (ret != -1) {
        return ret;
    }
    if (mask == 0) {
        ret = 0;
    } else {
        ret = 0;
        for (int i=0; i+1<n; ++i) {
            if (mask & (1<<i)) {
                if (!(mask & (1<<(i+1))) && !win(mask^(1<<i)|(1<<(i+1)))) {
                    ret = 1;
                    break;
                }
                if (i+3<n && (mask & (1<<(i+1))) && (mask & (1<<(i+2))) && !(mask & (1<<(i+3))) && !win(mask^(1<<i)|(1<<(i+3)))) {
                    ret = 1;
                    break;
                }
            }
        }
    }
    return ret;
}
class EllysCheckers {
public:
    string getWinner(string board) {
        memset(dp, 0xff, sizeof dp);
        int mask = 0;
        n = board.size();
        for (int i=0; i+1<n; ++i) {
            if (board[i] == 'o') {
                mask |= (1<<i);
            }
        }
        return win(mask) ? "YES" : "NO";
    }
};
