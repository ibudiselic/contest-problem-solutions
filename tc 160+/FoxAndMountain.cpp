#include <algorithm>
#include <cassert>
#include <cctype>
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

const int mod = 1000000009;
void modadd(int &a, int b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}
int dp[2][51][51];
int fail[51];
class FoxAndMountain {
public:
    int count(int n, string history) {
        int K = history.size();
        vector<int> H(K);
        for (int i=0; i<K; ++i) {
            H[i] = (history[i]=='U' ? +1 : -1);
        }
        for (int i=-1, j=-2; i+1<K; fail[++i]=++j) {
            while (j>=0 && H[i]!=H[j]) {
                j = fail[j];
            }
        }

        memset(dp, 0, sizeof dp);
        dp[0][0][0] = 1;
        for (int i=0; i<n; ++i) {
            int cur = i&1;
            int next = 1-cur;
            for (int at=0; at<=i; ++at) {
                for (int h=0; h<K; ++h) {
                    if (dp[cur][at][h] > 0) {
                        int val = dp[cur][at][h];
                        dp[cur][at][h] = 0;
                        for (int d=-1; d<=1; d+=2) {
                            if (at+d < 0) continue;
                            int nh = h;
                            while (nh>=0 && H[nh]!=d) {
                                nh = fail[nh];
                            }
                            modadd(dp[next][at+d][nh+1], val);
                        }
                    }
                }
                if (dp[cur][at][K] > 0) {
                    modadd(dp[next][at+1][K], dp[cur][at][K]);
                    if (at > 0) modadd(dp[next][at-1][K], dp[cur][at][K]);
                    dp[cur][at][K] = 0;
                }
            }
        }

        return dp[n&1][0][K];
    }
};
