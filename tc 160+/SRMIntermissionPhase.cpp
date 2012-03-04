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

int possible[1<<3][200002];
const int mod = 1000000007;
int ways[2][200002];
int partial[200002];
const int maxscore = 200000;
int get_mask(const string &s) {
    int ret = 0;
    for (int i=0; i<3; ++i) {
        if (s[i] == 'Y') {
            ret |= (1<<i);
        }
    }
    return ret;
}
class SRMIntermissionPhase {
public:
    int countWays(vector <int> points, vector <string> description) {
        memset(possible, 0, sizeof possible);
        possible[0][0] = 1;
        for (int mask=1; mask<(1<<3); ++mask) {
            for (int i=0; i<3; ++i) {
                if (mask & (1<<i)) {
                    partial[0] = 0;
                    for (int score=0; score<maxscore; ++score) {
                        partial[score+1] = partial[score] + possible[mask^(1<<i)][score];
                        if (partial[score+1] >= mod) {
                            partial[score+1] -= mod;
                        }
                    }
                    for (int score=0; score<=maxscore; ++score) {
                        possible[mask][score] = partial[score] - partial[score-min(points[i], score)];
                        if (possible[mask][score] < 0) {
                            possible[mask][score] += mod;
                        }
                        if (possible[mask][score] >= mod) {
                            possible[mask][score] -= mod;
                        }
                    }
                    break;
                }
            }
        }
        
        int mask = get_mask(description[0]);
        ways[0][maxscore+1] = 0;
        for (int i=maxscore; i>=0; --i) {
            ways[0][i] = ways[0][i+1] + possible[mask][i];
            if (ways[0][i] >= mod) {
                ways[0][i] -= mod;
            }
        }
        for (int i=1; i<(int)description.size(); ++i) {
            mask = get_mask(description[i]);
            ways[i&1][maxscore+1] = 0;
            for (int score=maxscore; score>=0; --score) {
                ways[i&1][score] = ways[i&1][score+1] + ((long long)possible[mask][score]*ways[(i+1)&1][score+1])%mod;
                if (ways[i&1][score] >= mod) {
                    ways[i&1][score] -= mod;
                }
            }
        }
        return ways[((int)description.size() + 1)&1][0];
    }
};
