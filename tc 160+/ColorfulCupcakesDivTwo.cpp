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

const int mod = 1000000007;
void modadd(int &a, int b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}
int dp[2][51][51][3];
class ColorfulCupcakesDivTwo {
public:
    int countArrangements(string cupcakes) {
        int cnt[3] = {0};
        int n = cupcakes.size();
        for (int i=0; i<n; ++i) {
            ++cnt[cupcakes[i]-'A'];
        }

        int sol = 0;
        for (int first=0; first<3; ++first) {
            if (cnt[first] > 0) {
                memset(dp, 0, sizeof dp);
                dp[0][cnt[0]-(first==0)][cnt[1]-(first==1)][first] = 1;
                for (int i=0; i+1<n; ++i) {
                    int cur = i&1;
                    int next = 1-cur;
                    for (int a=0; a<=cnt[0]; ++a) {
                        for (int b=0; b<=cnt[1]; ++b) {
                            int c = n-i-1-a-b;
                            if (c<0 || c>cnt[2]) continue;
                            int cc[] = {a, b, c};
                            for (int last=0; last<3; ++last) {
                                if (dp[cur][a][b][last] == 0) continue;
                                for (int here=0; here<3; ++here) {
                                    if (last==here || cc[here]==0) continue;
                                    if (i+2==n && here==first) continue;
                                    modadd(dp[next][cc[0]-(here==0)][cc[1]-(here==1)][here], dp[cur][a][b][last]);
                                }
                                dp[cur][a][b][last] = 0;
                            }
                        }
                    }
                }
                for (int i=0; i<3; ++i) {
                    modadd(sol, dp[(n+1)&1][0][0][i]);
                }
            }
        }

        return sol;
    }
};
