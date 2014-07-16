//# probability, rock, paper, scissors, expected value, dp
//# => Compute probability that ith die is not taken given a certain number of rocks, papers and scisorss via DP. Use that to compute EV for each round of the game.
#include <algorithm>
#include <cassert>
#include <cctype>
#include <cmath>
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

const int MAXN = 50+2;
double P[MAXN][MAXN][MAXN][MAXN]; // [i][r][p][s] prob r, p and s rocks/papers/scissors were picked and i was not picked
class RockPaperScissors {
public:
    double bestScore(vector <int> rockProb, vector <int> paperProb, vector <int> scissorsProb) {
        memset(P, 0, sizeof P);
        int n = rockProb.size();
        for (int i=0; i<n; ++i) {
            P[i][0][0][0] = 1.0;
            for (int cand=0; cand<n; ++cand) { // pick between the first cand+1 dice
                double probRock = rockProb[cand]/300.0;
                double probPaper = paperProb[cand]/300.0;
                double probScissors = scissorsProb[cand]/300.0;
                for (int sum=cand+1; sum>=0; --sum) { // start at largest possible sum (all dice picked) so we can reuse results for the previous cand value
                    double prob_picked = sum/(cand+1.0);
                    for (int r=0; r<=sum; ++r) {
                        for (int p=0; r+p<=sum; ++p) {
                            int s = sum-r-p;
                            double total = 0.0;
                            if (r > 0) total += probRock*P[i][r-1][p][s];
                            if (p > 0) total += probPaper*P[i][r][p-1][s];
                            if (s > 0) total += probScissors*P[i][r][p][s-1];
                            P[i][r][p][s] *= 1 - prob_picked; // cand was not picked
                            if (cand != i) P[i][r][p][s] += prob_picked*total; // cand was picked
                        }
                    }
                }
            }
        }

        double sol = 0.0;
        for (int move=0; move<n; ++move) {
            for (int r=0; r<=move; ++r) {
                for (int p=0; r+p<=move; ++p) {
                    int s = move-r-p;
                    double probRock = 0.0;
                    double probPaper = 0.0;
                    double probScissors = 0.0;
                    for (int i=0; i<n; ++i) {
                        probRock += P[i][r][p][s]*rockProb[i];
                        probPaper += P[i][r][p][s]*paperProb[i];
                        probScissors += P[i][r][p][s]*scissorsProb[i];
                    }
                    probRock /= 300*(n-move);
                    probPaper /= 300*(n-move);
                    probScissors /= 300*(n-move);

                    double best = 3*probRock + probPaper;
                    best = max(best, 3*probPaper + probScissors);
                    best = max(best, 3*probScissors + probRock);
                    sol += best;
                }
            }
        }
        return sol;
    }
};
