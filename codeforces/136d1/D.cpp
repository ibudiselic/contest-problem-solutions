#include <cassert>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;

const long long mod = 1000000007ll;
long long parity_ways[2][2];
int gcd[4001][4001];
void modadd(long long &a, long long b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}
int main() {
    int w, h;
    scanf("%d %d", &w, &h);
    ++w; ++h;
    
    for (int a=0; a<2; ++a) {
        for (int b=0; b<2; ++b) {
            parity_ways[a][b] = (long long)(w/2 + (!a&&(w&1))) * (h/2 + (!b&&(h&1)));
        }
    }
    long long sol = 0;
    for (int a=0; a<2; ++a) {
        for (int b=0; b<2; ++b) {
            for (int c=0; c<2; ++c) {
                for (int d=0; d<2; ++d) {
                    for (int e=0; e<2; ++e) {
                        for (int f=0; f<2; ++f) {
                            int x1=c-a, y1=d-b, x2=e-a, y2=f-b;
                            int area = x1*y2 - y1*x2;
                            if (area < 0) {
                                area = -area;
                            }
                            if (area%2 == 0) {
                                modadd(sol, parity_ways[a][b]*parity_ways[c][d]%mod*parity_ways[e][f]%mod);
                            }
                        }
                    }
                }
            }
        }
    }

    long long all_points = (long long)w*h%mod;
    long long zeros = all_points; // 3 equal
    modadd(zeros, all_points*(all_points-1)%mod*3%mod); // 2 equal + any
    modadd(zeros, all_points*(w-1)%mod*(w-2)%mod); // vert 3-line
    modadd(zeros, all_points*(h-1)%mod*(h-2)%mod); // horiz 3-line
    
    for (int i=0; i<w; ++i) {
        for (int j=0; j<h; ++j) {
            if (i == 0) gcd[i][j] = j;
            else if (j == 0) gcd[i][j] = i;
            else if (i < j) gcd[i][j] = gcd[j%i][i];
            else gcd[i][j] = gcd[i%j][j];
        }
    }
    for (int x=1; x<w; ++x) {
        for (int y=1; y<h; ++y) {
            if (gcd[x][y] >= 2) {
                // 3 on a sloped line segment
                // endpoinds fixed
                // 1 + gcd(x, y) total points -> gcd(x, y) - 1 points remain
                // (w-x)*(h-y) ways to position the segment
                // 3! = 6 ways to order the points
                // *2 because there is an equivalent line with negative slope
                modadd(zeros, (gcd[x][y]-1)*(w-x)%mod*(h-y)%mod*12%mod);
            }
        }
    }
    sol = (sol - zeros + mod) % mod;

    printf("%d\n", int(sol));
    return 0;
}
