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

int L[31][31], P[31][31];
int LmP[30][30][901], PmL[30][30][901];


class TournamentTree {
public:
    TournamentTree(int N) {
        for (n=1; n<N; n<<=1) ;
        T.assign(2*n, -1);
    }
    void set(int pos, int x) {
        pos += n;
        T[pos] = x;
        for (pos/=2; pos>0; pos/=2) {
            T[pos] = max(T[2*pos], T[2*pos+1]);
        }
    }
    int getmax(int a, int b) const { // [a, b]
        l = a;
        r = b+1;
        return getmax(1, 0, n);
    }
private:
    int getmax(int node, int a, int b) const { // [a, b>
        if (b<=l || a>=r) return -1;
        if (l<=a && b<=r) return T[node];
        int mid = a + (b-a)/2;
        return max(getmax(2*node, a, mid), getmax(2*node+1, mid, b));
    }
    int n;
    mutable int l, r;
    vector<int> T;
};
class FoxAndFlowerShopDivOne {
public:
    int theMaxFlowers(vector <string> F, int maxDiff) {
        int m = F.size();
        int n = F[0].size();
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                L[i+1][j+1] = L[i][j+1] + L[i+1][j] - L[i][j] + (F[i][j]=='L');
                P[i+1][j+1] = P[i][j+1] + P[i+1][j] - P[i][j] + (F[i][j]=='P');
            }
        }

        vector<vector<TournamentTree> > A(m, vector<TournamentTree>(n, TournamentTree(901)));
        vector<vector<TournamentTree> > B(m, vector<TournamentTree>(n, TournamentTree(901)));
        memset(LmP, 0xff, sizeof LmP);
        memset(PmL, 0xff, sizeof PmL);
        for (int r2=0; r2<m; ++r2) {
            for (int c2=0; c2<n; ++c2) {
                for (int r1=0; r1<=r2; ++r1) {
                    for (int c1=0; c1<=c2; ++c1) {
                        int l = L[r2+1][c2+1] - L[r1][c2+1] - L[r2+1][c1] + L[r1][c1];
                        int p = P[r2+1][c2+1] - P[r1][c2+1] - P[r2+1][c1] + P[r1][c1];

                        if (l >= p) {
                            LmP[r2][c2][l-p] = max(LmP[r2][c2][l-p], l+p);
                        }
                        if (p >= l) {
                            PmL[r2][c2][p-l] = max(PmL[r2][c2][p-l], l+p);
                        }
                    }
                }
                for (int diff=0; diff<=900; ++diff) {
                    if (r2 > 0) {
                        LmP[r2][c2][diff] = max(LmP[r2][c2][diff], LmP[r2-1][c2][diff]);
                        PmL[r2][c2][diff] = max(PmL[r2][c2][diff], PmL[r2-1][c2][diff]);
                    }
                    if (c2 > 0) {
                        LmP[r2][c2][diff] = max(LmP[r2][c2][diff], LmP[r2][c2-1][diff]);
                        PmL[r2][c2][diff] = max(PmL[r2][c2][diff], PmL[r2][c2-1][diff]);
                    }

                    A[r2][c2].set(diff, LmP[r2][c2][diff]);
                    B[r2][c2].set(diff, PmL[r2][c2][diff]);
                }
            }
        }

        int sol = -1;
        for (int r2=0; r2<m; ++r2) {
            for (int c2=0; c2<n; ++c2) {
                for (int r1=0; r1<=r2; ++r1) {
                    for (int c1=0; c1<=c2; ++c1) {
                        int l = L[r2+1][c2+1] - L[r1][c2+1] - L[r2+1][c1] + L[r1][c1];
                        int p = P[r2+1][c2+1] - P[r1][c2+1] - P[r2+1][c1] + P[r1][c1];

                        int best = -1;
                        if (l >= p) {
                            int maxl = maxDiff - (l-p);
                            if (maxl >= 0) {
                                if (r1 > 0) best = max(best, A[r1-1][n-1].getmax(0, maxl));
                                if (c1 > 0) best = max(best, A[m-1][c1-1].getmax(0, maxl));
                            }

                            int maxp = min(900, maxDiff + (l-p));
                            int minp = max(0, (l-p) - maxDiff);
                            if (minp <= maxp) {
                                if (r1 > 0) best = max(best, B[r1-1][n-1].getmax(minp, maxp));
                                if (c1 > 0) best = max(best, B[m-1][c1-1].getmax(minp, maxp));
                            }
                        }
                        if (p >= l) {
                            int maxl = min(900, maxDiff + (p-l));
                            int minl = max(0, (p-l) - maxDiff);
                            if (minl <= maxl) {
                                if (r1 > 0) best = max(best, A[r1-1][n-1].getmax(minl, maxl));
                                if (c1 > 0) best = max(best, A[m-1][c1-1].getmax(minl, maxl));
                            }

                            int maxp = maxDiff - (p-l);
                            if (maxp >= 0) {
                                if (r1 > 0) best = max(best, B[r1-1][n-1].getmax(0, maxp));
                                if (c1 > 0) best = max(best, B[m-1][c1-1].getmax(0, maxp));
                            }
                        }

                        if (best > -1) {
                            sol = max(sol, best + p + l);
                        }
                    }
                }
            }
        }

        return sol;
    }
};
