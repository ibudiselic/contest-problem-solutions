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
#include <cmath>

using namespace std;

// this is basically AI.Cash's solution

long long mod;
long long catalan[500];
long long dp[500];
double alpha[500];
double area[500][500];
const double PI = acos(-1.0);
const double EPS = 1e-9;
void modadd(long long &a, long long b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}
class MaximalTriangle {
public:
    int howMany(int n, int z) {
        mod = z;
        catalan[0] = 1%mod;
        for (int i=1; i<=n; ++i) {
            catalan[i] = 0;
            for (int j=0; j<i; ++j) {
                catalan[i] = (catalan[i] + catalan[j]*catalan[i-j-1])%mod;
            }
        }

        for (int i=0; i<n; ++i) {
            alpha[i] = 2*PI*i/n;
        }
        for (int i=1; i<n; ++i) {
            for (int j=1; i+j<n; ++j) {
                // if you take the radius of the escribed circle of
                // the regular n-gon to be sqrt(2), the area of the
                // triangle covering k "sections" equals the sine
                // of the inner angle
                // we only care about relative areas here, so we can
                // "set" the radius to anything
                area[i][j] = fabs(sin(alpha[i]) + sin(alpha[j]) - sin(alpha[i+j]));
            }
        }

        long long sol = 0;
        for (int a=1; 3*a<=n; ++a) {
            for (int b=a; a+2*b<=n; ++b) {
                int c = n - a - b;
                long long ways = n;
                if (a==b && b==c) {
                    assert(ways%3 == 0);
                    ways /= 3;
                }
                if (a!=b && b!=c) {
                    ways *= 2; // permutations modulo rotations
                }

                dp[0] = 0;
                dp[1] = 1%mod;
                for (int i=2; i<=c; ++i) {
                    int mid = i/2;
                    if (area[mid][i-mid] + EPS < area[a][b]) {
                        // any triangulation works because the mid triangle is the largest possible
                        dp[i] = catalan[i-1];
                        continue;
                    }
                    dp[i] = 0;
                    for (int j=1; area[j][i-j]+EPS<area[a][b]; ++j) {
                        dp[i] = (dp[i] + dp[j]*dp[i-j])%mod;
                    }
                    modadd(dp[i], dp[i]);
                }

                sol = (sol + ways*dp[a]%mod*(dp[b]*dp[c]%mod))%mod;
            }
        }

        return int(sol);
    }
};
