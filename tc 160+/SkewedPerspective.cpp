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
#include <numeric>

using namespace std;

const int mod = 1000000007;
int cube_ways[51][51]; // [i][j] ways to make a tower with j cubes using the cube colors 0 through i-1 (modulo mod)
inline void add(int &a, int b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}
int C[51][51];
int B, W, total;
int ways[51][9][11][9][40][2];
int go(int cubes_in_view, int b1, int b2, int need1, int need2, bool can_1b) {
    assert(need1 <= b1);
    if (cubes_in_view+need1>total || b1+b2>B || b1==W || need2*2>(total-cubes_in_view-need1)+2*(B-b1-b2)) {
        return 0;
    }
    
    int &ret = ways[cubes_in_view][b1][b2][need1][need2][can_1b];
    if (ret != -1) {
        return ret;
    }
    int h = cubes_in_view + b1 + 2*b2;
    ret = 0;
    if (h > 0) {
        add(ret, cube_ways[0][cubes_in_view]);
    }
    add(ret, go(cubes_in_view+1, b1, b2, need1, need2, true)); // add color cube
    add(ret, go(cubes_in_view, b1, b2+1, need1, need2, false)); // add black 2-brick with both parts visible
    if (h>=1 && ((h==2&&b2==1) || can_1b)) {
        add(ret, go(cubes_in_view, b1+1, b2, need1+(h-1)%2, need2+(h-1)/2, false)); // add black 2-brick such that only the top part is visible (add a column)
    }
    return ret;
}
class SkewedPerspective {
public:
    int countThem(vector <int> cubes, int B, int w) {
        ::B = B;
        ::W = w;
        C[0][0] = 1;
        for (int i=1; i<51; ++i) {
            C[i][0] = 1;
            for (int j=1; j<=i; ++j) {
                C[i][j] = C[i-1][j-1];
                add(C[i][j], C[i-1][j]);
            }
        }
        memset(cube_ways, 0, sizeof cube_ways);
        cube_ways[0][0] = 1;
        total = accumulate(cubes.begin(), cubes.end(), 0);
        for (int i=0; i<(int)cubes.size(); ++i) {
            for (int x=0; x<=total; ++x) {
                for (int take=0; take<=cubes[i] && take<=x; ++take) {
                    add(cube_ways[i+1][x], int((long long)C[x][take]*cube_ways[i][x-take]%mod));
                }
            }
        }
        for (int x=0; x<=total; ++x) { // reorganize so that [0][i] is the number of ways to make the tower using any color cubes
            cube_ways[0][x] = cube_ways[cubes.size()][x];
        }
        
        memset(ways, 0xff, sizeof ways);
        return go(0, 0, 0, 0, 0, 0);
    }
};
