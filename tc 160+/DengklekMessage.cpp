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
#include <numeric>
#include <cmath>

using namespace std;

int add[500][50];
int next_prefix[500][50];
int T[500];
string G;
int L;
vector<string> P;
void KMP(int sz, int part) {
    string S = G.substr(0, sz) + P[part];
    add[sz][part] = 0;
    int i = 0;
    int m = 0;
    while (i+m < (int)S.size()) {
        if (S[i+m] == G[m]) {
            if (++m == (int)G.size()) {
                ++add[sz][part];
                i += m-1 - T[m-1];
                m = max(0, T[m-1]);
            }
        } else {
            i += m - T[m];
            m = max(0, T[m]);
        }
    }
    next_prefix[sz][part] = m;
}

double dp[502][500]; // [# parts to add][prefix len]
class DengklekMessage {
public:
    double theExpected(vector <string> pieces, vector <string> goodSubstring, long long K) {
        G = accumulate(goodSubstring.begin(), goodSubstring.end(), string());
        L = G.size();

        for (int i=-1, j=-2; i<L; T[++i] = ++j) {
            while (j>=0 && G[i]!=G[j]) {
                j = T[j];
            }
        }

        P = pieces;
        for (int len=0; len<L; ++len) {
            for (int p=0; p<(int)pieces.size(); ++p) {
                KMP(len, p);
            }
        }
        
        for (int len=0; len<L; ++len) {
            dp[0][len] = 0.0;
        }
        for (int nparts=1; nparts<=L+1; ++nparts) {
            for (int len=0; len<L; ++len) {
                dp[nparts][len] = 0.0;
                for (int p=0; p<(int)P.size(); ++p) {
                    dp[nparts][len] += add[len][p] + dp[nparts-1][next_prefix[len][p]];
                }
                dp[nparts][len] /= P.size();
            }
        }
        
        if (K <= L+1) {
            return dp[K][0];
        } else {
            return dp[L][0] + (dp[L+1][0]-dp[L][0])*(K-L);
        }
    }
};
