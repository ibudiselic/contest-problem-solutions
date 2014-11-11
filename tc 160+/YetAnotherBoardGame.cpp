//# board game, xor, bitmasks, board, backtracking
//# => The key insight is that once the actions in the first row are selected, the remaining actions are uniquely determined except for the type of action. However, most choices of types lead to invalid constructions because of the column type restriction. In fact, there are at most 3^n valid constructions because once colum types and the first-row actions are fixed, all other moves are fixed (see the editorial for details) - this is also the explanation of why the backtracking approach works in time (it takes at most 11ms on systests).
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

int m, n;
vector<int> orig;

int bc[1<<13];
int mask1[1<<13][2]; // [x][t] -> xor mask for the first row if moves of type t are applied according to mask x (applied in cols where x has a 1 bit)
// the second row simply gets xord by x regardless of move type

const int INF = 1234567890;
int sol;
void rec(int i, int r1, int r2, int cType1, int cType2, int nmoves) {
    if (nmoves >= sol) return;
    if (cType1 & cType2) return;
    if (i == m) {
        if (r1 == 0) {
            sol = nmoves;
        }
        return;
    }

    for (int type=0; type<2; ++type) {
        int nr1 = r2;
        int nr2 = (i+1==m ? 0 : orig[i+1]);

        nr1 ^= mask1[r1][type];
        nr2 ^= r1;
        int ncType1 = cType1;
        int ncType2 = cType2;
        if (type) ncType1 |= r1;
        else ncType2 |= r1;
        rec(i+1, nr1, nr2, ncType1, ncType2, nmoves+bc[r1]);
    }
}

class YetAnotherBoardGame {
public:
    int minimumMoves(vector <string> B) {
        m = B.size();
        n = B[0].size();
        orig.assign(m, 0);
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (B[i][j] == 'W') {
                    orig[i] |= 1<<j;
                }
            }
        }

        for (int mask=0; mask<(1<<n); ++mask) {
            for (int type=0; type<2; ++type) {
                mask1[mask][type] = 0;
                for (int j=0; j<n; ++j) {
                    if (mask & (1<<j)) { // apply move
                        for (int jj=j-1; jj<=j+1; jj+=type+1) {
                            if (jj>=0 && jj<n) {
                                mask1[mask][type] ^= 1<<jj;
                            }
                        }
                    }
                }
            }
        }

        for (int mask=1; mask<(1<<n); ++mask) {
            bc[mask] = bc[mask>>1] + (mask&1);
        }

        sol = INF;
        for (int r1=0; r1<(1<<n); ++r1) {
            rec(0, r1, orig[0], 0, 0, 0);
        }
        return sol==INF ? -1 : sol;
    }
};
