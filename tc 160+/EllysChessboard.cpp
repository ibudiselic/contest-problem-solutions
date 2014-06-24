//# chess, permutation, order, manhattan distance, coordinate system
//# => Change the coordinate system to x+y, x-y where Manhattan distance becomes max(abs(u1-u2), abs(v1-v2)) i.e. the coordinates are independent. Use this to make a bounding box in which all the points are already taken and add any outer point at each step. Once this point is taken, all the remaining points in that new bounding box can as well be taken before any point outside the box is taken because they will not increase the cost of any point outside the box.
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

const int VOFFSET = 7;
const int inf = 1234567890;
vector<int> u, v;

bool inside(int i, int um, int uM, int vm, int vM) {
    return um<=u[i] && u[i]<=uM && vm<=v[i] && v[i]<=vM;
}

int cost(int i, int um, int uM, int vm, int vM) {
    int ret = abs(u[i] - um);
    ret = max(ret, abs(u[i] - uM));
    ret = max(ret, abs(v[i] - vm));
    ret = max(ret, abs(v[i] - vM));
    return ret;
}

int dp[15][15][15][15];
int go(int um, int uM, int vm, int vM) {
    assert(0<=um && um<15);
    assert(0<=uM && uM<15);
    assert(0<=vm+VOFFSET && vm+VOFFSET<15);
    assert(0<=vM+VOFFSET && vM+VOFFSET<15);
    int &ret = dp[um][uM][vm+VOFFSET][vM+VOFFSET];
    if (ret != -1) {
        return ret;
    }
    ret = inf;

    for (int i=0; i<(int)u.size(); ++i) {
        if (!inside(i, um, uM, vm, vM)) {
            int cand = cost(i, um, uM, vm, vM);
            int num = min(um, u[i]);
            int nuM = max(uM, u[i]);
            int nvm = min(vm, v[i]);
            int nvM = max(vM, v[i]);
            for (int j=0; j<(int)u.size(); ++j) {
                if (j!=i && !inside(j, um, uM, vm, vM) &&
                             inside(j, num, nuM, nvm, nvM)) {
                    cand += cost(j, num, nuM, nvm, nvM);
                }
            }
            //cerr << i << ' ' << cand << '\n';
            //cerr << um << ' ' << uM << ' ' << vm << ' ' << vM << '\n';
            //cerr << num << ' ' << nuM << ' ' << nvm << ' ' << nvM << '\n';
            ret = min(ret, cand + go(num, nuM, nvm, nvM));
        }
    }
    
    if (ret == inf) {
        ret = 0;
    }
    return ret;
}
class EllysChessboard {
public:
    int minCost(vector <string> board) {
        u.clear();
        v.clear();
        for (int i=0; i<8; ++i) {
            for (int j=0; j<8; ++j) {
                if (board[i][j] == '#') {
                    u.push_back(i+j);
                    v.push_back(i-j);
                }
            }
        }

        memset(dp, 0xff, sizeof dp);
        int sol = inf;
        for (int i=0; i<(int)u.size(); ++i) {
            sol = min(sol, go(u[i], u[i], v[i], v[i]));
        }
 
        return sol==inf ? 0 : sol;
    }
};
