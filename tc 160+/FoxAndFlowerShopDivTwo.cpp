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

using namespace std;

int F[11][11];
class FoxAndFlowerShopDivTwo {
public:
    int theMaxFlowers(vector <string> flowers, int r, int c) {
        int m = flowers.size();
        int n = flowers[0].size();
        memset(F, 0, sizeof F);
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                F[i+1][j+1] = F[i][j+1] + F[i+1][j] - F[i][j] + (flowers[i][j]=='F');
            }
        }
        int sol = 0;
        for (int r1=0; r1<m; ++r1) {
            for (int r2=r1; r2<m; ++r2) {
                for (int c1=0; c1<n; ++c1) {
                    for (int c2=c1; c2<n; ++c2) {
                        if (r1<=r && r<=r2 && c1<=c && c<=c2) {
                            continue;
                        }
                        sol = max(sol, F[r2+1][c2+1] + F[r1][c1] - F[r2+1][c1] - F[r1][c2+1]);
                    }
                }
            }
        }

        return sol;
    }
};
