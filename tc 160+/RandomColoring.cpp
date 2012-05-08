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

int R, G, B;
int D1, D2;
void fix(int &r0, int &r1, int &g0, int &g1, int &b0, int &b1) {
    r0 = max(r0, 0);
    r1 = min(r1, R-1);
    g0 = max(g0, 0);
    g1 = min(g1, G-1);
    b0 = max(b0, 0);
    b1 = min(b1, B-1);
}
int volume(int r0, int r1, int g0, int g1, int b0, int b1) {
    fix(r0, r1, g0, g1, b0, b1);
    if (r0>r1 || g0>g1 || b0>b1) {
        return 0;
    } else {
        return (r1-r0+1)*(g1-g0+1)*(b1-b0+1);
    }
}

struct Cube {
    double p[50][50][50];
    Cube() {
        for (int i=0; i<R; ++i) {
            for (int j=0; j<G; ++j) {
                for (int k=0; k<B; ++k) {
                    p[i][j][k] = 0.0;
                }
            }
        }
    }
    
    void change_by(int r, int g, int b, double by) {
        if (r<0 || g<0 || b<0 || r>=R || g>=G || b>=B) {
            return;
        }
        p[r][g][b] += by;
    }
    void change_cube(int r0, int r1, int g0, int g1, int b0, int b1, double by) {
        fix(r0, r1, g0, g1, b0, b1);
        if (r0>r1 || g0>g1 || b0>b1) {
            return;
        }
        change_by(r1, g1, b1, by);

        change_by(r1, g1, b0-1, -by);
        change_by(r1, g0-1, b1, -by);
        change_by(r0-1, g1, b1, -by);
        
        change_by(r1, g0-1, b0-1, by);
        change_by(r0-1, g1, b0-1, by);
        change_by(r0-1, g0-1, b1, by);
        
        change_by(r0-1, g0-1, b0-1, -by);
    }
    void finalize() { // compute the actual probailities from block values
        for (int i=0; i<R; ++i) {
            for (int j=0; j<G; ++j) {
                for (int k=B-2; k>=0; --k) {
                    p[i][j][k] += p[i][j][k+1];
                }
            }
        }
        for (int i=0; i<R; ++i) {
            for (int j=G-2; j>=0; --j) {
                for (int k=0; k<B; ++k) {
                    p[i][j][k] += p[i][j+1][k];
                }
            }
        }
        for (int i=R-2; i>=0; --i) {
            for (int j=0; j<G; ++j) {
                for (int k=0; k<B; ++k) {
                    p[i][j][k] += p[i+1][j][k];
                }
            }
        }
    }
};
class RandomColoring {
public:
    double getProbability(int N, int maxR, int maxG, int maxB, int startR, int startG, int startB, int d1, int d2) {
        R = maxR;
        G = maxG;
        B = maxB;
        --d1;
        Cube cur;
        cur.p[startR][startG][startB] = 1.0;
        for (int iter=1; iter<N; ++iter) {
            Cube next;
            for (int i=0; i<R; ++i) {
                for (int j=0; j<G; ++j) {
                    for (int k=0; k<B; ++k) {
                        double p = cur.p[i][j][k];
                        int vol = volume(i-d2, i+d2, j-d2, j+d2, k-d2, k+d2);
                        if (d1 >= 0) {
                            vol -= volume(i-d1, i+d1, j-d1, j+d1, k-d1, k+d1);
                        }
                        if (vol > 0) {
                            p /= vol;
                            next.change_cube(i-d2, i+d2, j-d2, j+d2, k-d2, k+d2, p);
                            if (d1 >= 0) {
                                next.change_cube(i-d1, i+d1, j-d1, j+d1, k-d1, k+d1, -p);
                            }
                        }
                    }
                }
            }
            next.finalize();
            cur = next;
        }
        
        double sol = 0.0;
        for (int i=max(0, startR-d2); i<=min(R-1, startR+d2); ++i) {
            for (int j=max(0, startG-d2); j<=min(G-1, startG+d2); ++j) {
                for (int k=max(0, startB-d2); k<=min(B-1, startB+d2); ++k) {
                    if (abs(i-startR)>d1 || abs(j-startG)>d1 || abs(k-startB)>d1) {
                        sol += cur.p[i][j][k];
                    }
                }
            }
        }
        return 1.0 - sol;
    }
};
