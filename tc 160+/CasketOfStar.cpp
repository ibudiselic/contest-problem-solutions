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

int dp[50][50];
vector<int> W;
int go(int l, int r) {
    int &ret = dp[l][r];
    if (ret != -1) {
        return ret;
    }
    if (l+1 == r) {
        ret = 0;
    } else {
        ret = W[l] * W[r];
        int add = 0;
        for (int i=l+1; i<r; ++i) {
            add = max(add, go(l, i) + go(i, r));
        }
        ret += add;
    }
    return ret;
}
class CasketOfStar {
public:
    int maxEnergy(vector <int> weight) {
        W = weight;
        memset(dp, 0xff, sizeof dp);
        return go(0, W.size()-1);
    }
};
