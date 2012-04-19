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

using namespace std;

vector<int> A, B;
int bit;
bool done[51][50][2];
double dp[51][50][2];
double go(int remsteps, int at, int val) {
    if (done[remsteps][at][val]) {
        return dp[remsteps][at][val];
    }
    done[remsteps][at][val] = 1;
    double &ret = dp[remsteps][at][val];
    if (remsteps == 0) {
        ret = (at==0 && val==1);
    } else {
        ret = go(remsteps-1, B[at], val) + go(remsteps-1, at, val ^ ((A[at]>>bit) & 1));
        ret /= 2;
    }
    return ret;
}
class KingXMagicSpells {
public:
    double expectedNumber(vector <int> ducks, vector <int> spellOne, vector <int> spellTwo, int K) {
        A = spellOne;
        B = spellTwo;
        double sol = 0.0;
        for (int bit=0; bit<31; ++bit) {
            ::bit = bit;
            memset(done, 0, sizeof done);
            for (int i=0; i<(int)ducks.size(); ++i) {
                sol += go(K, i, (ducks[i]>>bit)&1) * (1<<bit);
            }
        }
        
        return sol;
    }
};
