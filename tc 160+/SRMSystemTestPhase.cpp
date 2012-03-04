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

const int mod = 1000000007;
int ways[51][4][4];
class SRMSystemTestPhase {
public:
    int countWays(vector <string> description) {
        description.insert(description.begin(), string());
        memset(ways, 0, sizeof ways);
        ways[0][3][0] = 1;
        for (int i=1; i<(int)description.size(); ++i) {
            for (int state=0; state<64; ++state) {
                int nc = 0;
                int np = 0;
                bool ok = true;
                int s = state;
                for (int j=0; j<3; ++j) {
                    int t = s%4;
                    s /= 4;
                    if (t&&description[i][j]=='N' || !t&&description[i][j]=='Y') {
                        ok = false;
                        break;
                    }
                    nc += (t==1);
                    np += (t==2);
                }
                if (!ok) {
                    continue;
                }
                for (int oldp=np+1; oldp<=3; ++oldp) {
                    for (int oldc=0; oldc<=3; ++oldc) {
                        ways[i][np][nc] += ways[i-1][oldp][oldc];
                        if (ways[i][np][nc] >= mod) {
                            ways[i][np][nc] -= mod;
                        }
                    }
                }
                for (int oldc=0; oldc<=nc; ++oldc) {
                    ways[i][np][nc] += ways[i-1][np][oldc];
                    if (ways[i][np][nc] >= mod) {
                        ways[i][np][nc] -= mod;
                    }
                }
            }
        }
        
        int sol = 0;
        for (int i=0; i<=3; ++i) {
            for (int j=0; j<=3; ++j) {
                sol += ways[(int)description.size()-1][i][j];
                if (sol >= mod) {
                    sol -= mod;
                }
            }
        }
        return sol;
    }
};
