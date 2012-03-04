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

const int mod = 1000000009;
int C, L;
vector<string> W;
int len[6][51][6];
int next[6][51][6][26];
int dp[50][1<<6][6][50];
int bc[1<<6];
int go(int at, int mask, int w, int l) {
    if (bc[mask] > C) {
        return 0;
    }
    if (at == L) {
        return (bc[mask] == C);
    }
    int &ret = dp[at][mask][w][l];
    if (ret != -1) {
        return ret;
    }
    
    ret = 0;
    for (int c='a'; c<='z'; ++c) {
        int foundmask = 0;
        int okmask = 0;
        for (int i=0; i<(int)W.size(); ++i) {
            if (len[w][l][i]<(int)W[i].size() && W[i][len[w][l][i]]==c) {
                if (len[w][l][i]+1 == (int)W[i].size()) {
                    foundmask |= (1<<i);
                } else {
                    okmask |= (1<<i);
                }
            }
        }
        int bestlen = -1;
        int nw = 0;
        for (int i=0; i<(int)W.size(); ++i) {
            if (okmask & (1<<i)) {
                if (len[w][l][i] > bestlen) {
                    bestlen = len[w][l][i];
                    nw = i;
                }
            } else if (!(foundmask&(1<<i)) && next[w][l][i][c-'a']>bestlen) {
                bestlen = next[w][l][i][c-'a'];
                nw = i;
            }
        }
        ret += go(at+1, mask|foundmask, nw, bestlen+1);
        if (ret >= mod) {
            ret -= mod;
        }
    }
    return ret;
}
class RequiredSubstrings {
public:
    int solve(vector <string> words, int C, int L) {
        ::C = C;
        ::L = L;
        W = words;
        memset(len, 0, sizeof len);
        memset(next, 0xff, sizeof next);
        for (int i=0; i<(int)W.size(); ++i) {
            for (int j=0; j<(int)W.size(); ++j) {
                for (int l=1; l<=(int)W[i].size(); ++l) {
                    next[i][l][j][W[j][0]-'a'] = 0;
                    for (int k=min(l, (int)W[j].size()); k>0; --k) {
                        if (W[i].substr(l-k, k) == W[j].substr(0, k)) {
                            if (len[i][l][j] == 0) {
                                len[i][l][j] = k;
                            }
                            if (k < (int)W[j].size()) {
                                int nextc = W[j][k];
                                next[i][l][j][nextc-'a'] = max(next[i][l][j][nextc-'a'], k);
                            }
                        }
                    }
                }
            }
        }
        for (int i=1; i<(1<<W.size()); ++i) {
            bc[i] = bc[i>>1] + (i&1);
        }
        
        memset(dp, 0xff, sizeof dp);
        return go(0, 0, 0, 0);
    }
};
