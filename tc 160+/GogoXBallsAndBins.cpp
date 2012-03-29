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

int dp[2][51][10001];
const int OFFSET = 5000;
const int mod = 1000000009;
void add(int &a, int b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}
class GogoXBallsAndBins {
public:
    int solve(vector <int> T, int moves) {
        int n = T.size();
        memset(dp, 0, sizeof dp);
        
        dp[0][0][OFFSET] = 1;
        for (int i=0; i<n; ++i) {
            int cur = i&1;
            int next = 1 - cur;
            for (int prev=0; prev<=i; ++prev) {
                for (int score=-OFFSET; score<=OFFSET; ++score) {
                    if (dp[cur][prev][score+OFFSET] > 0) {
                        add(dp[next][prev][score+OFFSET], dp[cur][prev][score+OFFSET]);
                        if (prev) {
                            add(dp[next][prev][score+OFFSET], 2ll*prev*dp[cur][prev][score+OFFSET]%mod);
                            add(dp[next][prev-1][score+OFFSET+2*T[i]], (long long)prev*prev*dp[cur][prev][score+OFFSET]%mod);
                        }
                        add(dp[next][prev+1][score+OFFSET-2*T[i]], dp[cur][prev][score+OFFSET]);
                        dp[cur][prev][score+OFFSET] = 0;
                    }
                }
            }
        }
        
        return dp[n&1][0][2*moves+OFFSET];
    }
};
