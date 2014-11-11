//# probability, combinatorics, expectation, maximum minimums, inclusion-exclusion, important
//# => See comment.
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

/* RandomPaintingOnBoard Div1 hard SRM583
 *
 * There are two related probabilitic explanations that lead to the 
 * exact same result.
 *
 * We're looking for E[number of moves before done].
 * The first approach is to proceed by definition.
 *
 * E[number of moves before done] = sum i*Pr{done in move i}
 * Pr{done in move i} = Pr{not done after i-1} - Pr{not done after i}
 *
 * Putting that back into the expectation expression and changing
 * i to i-1 in the right sum we get 
 *
 * E[number of moves before done] = sum Pr{not done after i}
 *
 * Pr{not done after i} is expanded with inclusion-exclusion
 * not done == at least one row or col is not picked
 * Pr{nda i} = Pr{row1 not taken after i
 *             or row2 not taken after i
 *             ...
 *             or col1 not taken after i
 *             or col2 not taken after i
 *             ...
 *             or coln not taken after i}
 *          = (incl-excl)
 * 
 * Putting that back into E and exchanging order of summation
 * we get
 *
 * E = sum over row/col subsets s with |s| odd sum (1-P(s))^i
 *   - sum over row/col subsets s with |s| even sum (1-P(s))^i
 *
 * where P(s) is the probability any cell in row/col in s is picked.
 *
 * Then the idea is to do a dp over this P(s) counting the contribution
 * of each P(s) value...
 *
 * The other approach is to introduce variables for the move in which
 * a row/column is first picked. Then, the solution is the expectation of
 * the maximum over all those variables.
 *
 * Using the maximum minimums identity (https://en.wikipedia.org/wiki/Maximum-minimums_identity)
 * we can translate that to minima. The minimum is easy to compute for each
 * subset because it is just the first move in which any of the rows/cols 
 * in the subset are picked.
 *
 * By def, E[min s] = sum i Pr{s picked first time in move i}
 *
 * The prob is (1-P(s))^(i-1)*P(s).
 * Expanding that, we get the exact same expression for a contribution
 * of a particular P(s).
 */
vector<vector<int>> process(vector <string> &prob) {
    int m = prob.size();
    int n = prob[0].size();
    if (n > m) {
        vector<string> p(n, string(m, ' '));
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                p[i][j] = prob[j][i];
            }
        }
        prob.swap(p);
        swap(m, n);
    }

    vector<vector<int>> P(m, vector<int>(n));
    for (int i=0; i<m; ++i) {
        for (int j=0; j<n; ++j) {
            P[i][j] = prob[i][j]-'0';
        }
    }
    return P;
}

int bc[1<<12];
long long cnt[2][1500];
class RandomPaintingOnABoard {
public:
    double expectedSteps(vector <string> prob_) {
        vector<vector<int>> prob = process(prob_);
        int m = prob.size();
        int n = prob[0].size();

        int total = 0;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                total += prob[i][j];
            }
        }

        for (int mask=1; mask<(1<<n); ++mask) {
            bc[mask] = bc[mask>>1] + (mask&1);
        }

        double sol = 0.0;
        vector<int> row_contrib(m);
        for (int colmask=0; colmask<(1<<n); ++colmask) {
            int base_insum = 0;
            for (int i=0; i<m; ++i) {
                row_contrib[i] = 0;
                for (int j=0; j<n; ++j) {
                    if (colmask&(1<<j)) {
                        base_insum += prob[i][j];
                    } else {
                        row_contrib[i] += prob[i][j];
                    }
                }
            }
            
            memset(cnt, 0, sizeof cnt);
            cnt[0][base_insum] = (bc[colmask]&1)==0 ? -1 : +1;
            for (int i=0; i<m; ++i) {
                int cur = i&1;
                int next = 1-cur;
                for (int oldsum=base_insum; oldsum<=total; ++oldsum) {
                    if (cnt[cur][oldsum] == 0) continue;
                    cnt[next][oldsum] += cnt[cur][oldsum];
                    assert(oldsum+row_contrib[i] <= total);
                    cnt[next][oldsum+row_contrib[i]] -= cnt[cur][oldsum];
                    cnt[cur][oldsum] = 0;
                }
            }
            for (int insum=max(1, base_insum); insum<=total; ++insum) {
                sol += double(cnt[m&1][insum])/insum;
            }
        }
        return sol*total;
    }
};
