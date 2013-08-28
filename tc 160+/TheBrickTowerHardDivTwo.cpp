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

const int mod = 1234567891;
inline void modadd(int &a, int b) {
    long long tmp = (long long)a + b;
    if (tmp >= mod) {
        tmp -= mod;
    }
    a = int(tmp);
}
inline int modmul(long long a, long long b) {
    a *= b;
    if (a >= mod) {
        a %= mod;
    }
    return int(a);
}
int ways[2][5][5][5][5][8];
class TheBrickTowerHardDivTwo {
public:
    int find(int C, int K, int H) {
        memset(ways, 0, sizeof ways);
        ways[0][C][C][C][C][0] = 1;
        int sol = 0;
        for (int h=0; h<H; ++h) {
            int cur = h&1;
            int next = 1 - cur;
            for (int c0=0; c0<=C; ++c0) {
                for (int c1=0; c1<=C; ++c1) {
                    for (int c2=0; c2<=C; ++c2) {
                        for (int c3=0; c3<=C; ++c3) {
                            for (int k=0; k<=K; ++k) {
                                if (ways[cur][c0][c1][c2][c3][k] > 0) {
                                    int val = ways[cur][c0][c1][c2][c3][k];
                                    ways[cur][c0][c1][c2][c3][k] = 0;
                                    int bot[] = {c0, c1, c2, c3};
                                    for (int c0=0; c0<C; ++c0) {
                                        for (int c1=0; c1<C; ++c1) {
                                            for (int c2=0; c2<C; ++c2) {
                                                for (int c3=0; c3<C; ++c3) {
                                                    int top[] = {c0, c1, c2, c3};
                                                    int nk = k;
                                                    for (int i=0; i<4; ++i) {
                                                        if (bot[i] == top[i]) {
                                                            ++nk;
                                                        }
                                                    }
                                                    if (c0 == c1) ++nk;
                                                    if (c0 == c2) ++nk;
                                                    if (c1 == c3) ++nk;
                                                    if (c2 == c3) ++nk;
                                                    if (nk > K) continue;
                                                    modadd(ways[next][c0][c1][c2][c3][nk], val);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }

            for (int c0=0; c0<=C; ++c0) {
                for (int c1=0; c1<=C; ++c1) {
                    for (int c2=0; c2<=C; ++c2) {
                        for (int c3=0; c3<=C; ++c3) {
                            for (int k=0; k<=K; ++k) {
                                modadd(sol, ways[next][c0][c1][c2][c3][k]);
                            }
                        }
                    }
                }
            }
        }
        return sol;
    }
};
