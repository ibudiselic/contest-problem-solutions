#include <algorithm>
#include <cassert>
#include <cctype>
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
#include <cmath>

using namespace std;

const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };
int R[300], C[300];
vector<string> F;
int D[50][50][50][50];
void distances(int i, int j, int pi, int pj, int si, int sj, int dist) {
    D[si][sj][i][j] = dist;
    for (int d=0; d<4; ++d) {
        int r = i + di[d];
        int c = j + dj[d];
        if (r<0 || c<0 || r>=(int)F.size() || c>=(int)F[0].size() || F[r][c]=='#' || (r==pi&&c==pj)) {
            continue;
        }
        distances(r, c, i, j, si, sj, dist+1);
    }
}

class Orienteering {
public:
    double expectedLength(vector <string> field, int K) {
        ::F = field;
        int n = 0;
        for (int i=0; i<(int)F.size(); ++i) {
            for (int j=0; j<(int)F[i].size(); ++j) {
                if (F[i][j] == '*') {
                    R[n] = i;
                    C[n] = j;
                    ++n;
                }
                if (F[i][j] != '#') {
                    distances(i, j, -1, -1, i, j, 0);
                }
            }
        }

        double sol = 0.0;
        vector<double> prob(n+1);
        prob[n] = 1.0;
        for (int nn=n-1; nn>=0; --nn) {
            prob[nn] = prob[nn+1]*(nn-K+1)/(nn+1);
        }
        for (int i=0; i<(int)F.size(); ++i) {
            for (int j=0; j<(int)F[i].size(); ++j) {
                if (F[i][j] == '#') {
                    continue;
                }
                for (int d=0; d<2; d++) {
                    int r = i+di[d];
                    int c = j+dj[d];
                    if (r<0 || c<0 || r>=(int)F.size() || c>=(int)F[0].size() || F[r][c]=='#') {
                        continue;
                    }

                    int a = 0;
                    for (int k=0; k<n; ++k) {
                        if (D[R[k]][C[k]][i][j] < D[R[k]][C[k]][r][c]) {
                            ++a;
                        }
                    }
                    sol += 2*(1.0 - prob[a] - prob[n-a]);
                }
            }
        }

        prob[n] = prob[n-1] = 0.0;
        prob[n-2] = 1.0;
        for (int nn=n-3; nn>=0; --nn) {
            prob[nn] = prob[nn+1]*(nn-(K-2)+1)/(nn+1);
        }
        double sub = 0.0;
        for (int i=0; i<n; ++i) {
            for (int j=i+1; j<n; ++j) {
                const int dist = D[R[i]][C[i]][R[j]][C[j]];
                int can_pick = 0;
                for (int k=0; k<n; ++k) {
                    if (k==i || k==j || D[R[i]][C[i]][R[k]][C[k]]>dist || (D[R[i]][C[i]][R[k]][C[k]]==dist && k<j) || (D[R[j]][C[j]][R[k]][C[k]]>dist || (D[R[j]][C[j]][R[k]][C[k]]==dist && k<i))) {
                        continue;
                    }
                    ++can_pick;
                }
                sub += dist*prob[can_pick];
            }
        }
        sub = sub*K*(K-1)/n/(n-1);
        
        return sol - sub;
    }
};
