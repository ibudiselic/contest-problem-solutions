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

vector<int> A, B, X, Y;
int dp[51][51][51];
const int mod = 1000000007;
void modadd(int &a, int b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}
class AliceBobShuffle {
public:
    int countWays(vector <int> AliceStart, vector <int> BobStart, vector <int> AliceEnd, vector <int> BobEnd) {
        A = AliceStart;
        B = BobStart;
        X = AliceEnd;
        Y = BobEnd;
        if (A.size()+B.size() != X.size()+Y.size()) {
            return 0;
        }

        memset(dp, 0, sizeof dp);
        dp[A.size()][B.size()][X.size()] = 1;
        for (int a=(int)A.size(); a>=0; --a) {
            for (int b=(int)B.size(); b>=0; --b) {
                if (a==int(A.size()) && b==int(B.size())) {
                    continue;
                }
                int lim = min((int)X.size(), int(A.size())-a + int(B.size())-b);
                for (int x=int(X.size()); x>=(int)X.size()-lim; --x) {
                    int y = int(Y.size()) - (int(A.size())-a + int(B.size())-b - (int(X.size())-x));
                    if (y < 0) {
                        continue;
                    }
                    dp[a][b][x] = 0;
                    if (a < (int)A.size()) {
                        if (x<(int)X.size() && A[a]==X[x]) {
                            modadd(dp[a][b][x], dp[a+1][b][x+1]);
                        }
                        if (y<(int)Y.size() && A[a]==Y[y]) {
                            modadd(dp[a][b][x], dp[a+1][b][x]);
                        }
                    }
                    if (b < (int)B.size()) {
                        if (x<(int)X.size() && B[b]==X[x]) {
                            modadd(dp[a][b][x], dp[a][b+1][x+1]);
                        }
                        if (y<(int)Y.size() && B[b]==Y[y]) {
                            modadd(dp[a][b][x], dp[a][b+1][x]);
                        }
                    }
                }
            }
        }

        return dp[0][0][0];
    }
};
