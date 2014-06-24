//# chess, dp, greedy, permutation, order, manhattan distance
//# => f
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
#include <unordered_map>

using namespace std;

vector<int> R, C;
typedef unsigned long long ull;
int bc(ull x) {
    int ret = 0;
    while (x > 0) {
        ++ret;
        x &= x-1;
    }
    return ret;
}
int dist(int i, int j) {
    return abs(R[i]-R[j]) + abs(C[i]-C[j]);
}
unordered_map<ull, int> dp;
int go(ull used) {
    auto p = dp.find(used);
    if (p != dp.end()) {
        return p->second;
    }
    int &ret = dp[used];
    if (bc(used) + 1 >= (int)R.size()) {
        ret = 0;
    } else {
        int maxdist = -1;
        int mi=-1, mj=-1;
        for (int i=0; i<(int)R.size(); ++i) {
            if (used & (1ull<<i)) continue;
            for (int j=i+1; j<(int)R.size(); ++j) {
                if (used & (1ull<<j)) continue;
                int cand = dist(i, j);
                if (cand > maxdist) {
                    maxdist = cand;
                    mi = i;
                    mj = j;
                }
            }
        }
        ret = min(go(used|(1ull<<mi)), go(used|(1ull<<mj))) + maxdist;
    }
    return ret;
}
class EllysChessboard {
public:
    int minCost(vector <string> board) {
        R.clear();
        C.clear();
        for (int i=0; i<8; ++i) {
            for (int j=0; j<8; ++j) {
                if (board[i][j] == '#') {
                    R.push_back(i);
                    C.push_back(j);
                }
            }
        }

        dp.clear();
        return go(0);
    }
};
