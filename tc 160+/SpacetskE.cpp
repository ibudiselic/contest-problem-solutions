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

int gcd(int m, int n) {
    return m==0 ? n : gcd(n%m, m);
}
const int mod = 1000000007;
void add(int &a, int b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}
int C[2002][2002];
class SpacetskE {
public:
    int countsets(int L, int H, int K) {
        if (K == 1) {
            return (L+1)*(H+1);
        }
        C[0][0] = 1;
        for (int i=1; i<=2001; ++i) {
            C[i][0] = 1;
            for (int j=1; j<=i; ++j) {
                C[i][j] = C[i-1][j-1];
                add(C[i][j], C[i-1][j]);
            }
        }

        int vert = int((long long)C[H+1][K]*(L+1)%mod);
        int sloped = 0;
        for (int dx=1; dx<=L; ++dx) {
            for (int dy=1; dy<=H; ++dy) {
                if (gcd(dx, dy) != 1) {
                    continue;
                }
                int points = min(L/dx, H/dy) + 1;
                int start = 0;
                while (points >= K) {
                    int endpoint = start + (points-1)*dx;
                    assert(endpoint <= L);
                    add(sloped, int((long long)(L-endpoint+1)*C[points][K]%mod));
                    start += L-endpoint+1;
                    --points;
                }
            }
        }

        return (2*sloped%mod + vert)%mod;
    }
};
