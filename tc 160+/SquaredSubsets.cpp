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

using namespace std;

int my_abs(int x) { return x<0 ? -x : x; }
class SquaredSubsets {
public:
    long long countSubsets(int n, vector <int> x, vector <int> y) {
        n *= 2;
        for (int i=0; i<(int)x.size(); ++i) {
            x[i] *= 2;
            y[i] *= 2;
        }
        
        set<long long> sol;
        for (int i=0; i<(int)x.size(); ++i) {
            for (int j=0; j<(int)y.size(); ++j) {
                for (int dx=-1; dx<2; ++dx) {
                    for (int dy=-1; dy<2; ++dy) {
                        int X = x[i] + dx;
                        int Y = y[j] + dy;
                        long long mask[2][2] = {{0}};
                        for (int k=0; k<(int)x.size(); ++k) {
                            if (max(my_abs(x[k]-X), my_abs(y[k]-Y)) > n) {
                                continue;
                            }
                            if (x[k]<=X && y[k]<=Y) mask[0][0] |= (1ll<<k);
                            if (x[k]<=X && y[k]>=Y) mask[0][1] |= (1ll<<k);
                            if (x[k]>=X && y[k]<=Y) mask[1][0] |= (1ll<<k);
                            if (x[k]>=X && y[k]>=Y) mask[1][1] |= (1ll<<k);
                        }
                        for (int a=0; a<2; ++a) {
                            for (int b=0; b<2; ++b) {
                                if (mask[a][b]) {
                                    sol.insert(mask[a][b]);
                                }
                            }
                        }
                    }
                }
            }
        }
        
        return sol.size();
    }
};
