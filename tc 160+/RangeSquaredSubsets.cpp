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
#include <set>
#include <utility>

using namespace std;

vector<int> X, Y;
int L, H;
set<long long> sol;

int my_abs(int x) {
    return x < 0 ? -x : x;
}
void go(int x, long y) {
    vector< pair<int, int> > A[2][2];
    for (int i=0; i<(int)X.size(); ++i) {
        pair<int, int> t(max(L, max(my_abs(x-X[i]), my_abs(y-Y[i]))), i);
        if (X[i]<=x && Y[i]<=y) A[0][0].push_back(t);
        if (X[i]<=x && Y[i]>=y) A[0][1].push_back(t);
        if (X[i]>=x && Y[i]<=y) A[1][0].push_back(t);
        if (X[i]>=x && Y[i]>=y) A[1][1].push_back(t);
    }
    for (int i=0; i<2; ++i) {
        for (int j=0; j<2; ++j) {
            sort(A[i][j].begin(), A[i][j].end());
            long long mask = 0;
            for (int k=0; k<(int)A[i][j].size(); ++k) {
                if (A[i][j][k].first > H) {
                    break;
                }
                mask |= (1ll<<A[i][j][k].second);
                if (k+1==(int)A[i][j].size() || A[i][j][k+1].first!=A[i][j][k].first) {
                    sol.insert(mask);
                }
            }
        }
    }
}
class RangeSquaredSubsets {
public:
    long long countSubsets(int nlow, int nhigh, vector <int> x, vector <int> y) {
        nlow *= 2;
        nhigh *= 2;
        for (int i=0; i<(int)x.size(); ++i) {
            x[i] *= 2;
            y[i] *= 2;
        }
        X = x;
        Y = y;
        L = nlow;
        H = nhigh;
        sol.clear();
        for (int i=0; i<(int)X.size(); ++i) {
            for (int j=0; j<(int)Y.size(); ++j) {
                for (int dx=-1; dx<2; ++dx) {
                    for (int dy=-1; dy<2; ++dy) {
                        go(X[i]+dx, Y[j]+dy);
                    }
                }
            }
        }
        return sol.size();
    }
};
