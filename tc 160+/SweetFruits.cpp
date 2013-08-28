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
#include <map>

using namespace std;

const long long mod = 1000000007;
int msub(int a, int b) {
    a -= b;
    if (a < 0) {
        a += int(mod);
    }
    return a;
}
int mmul(long long a, long long b) {
    long long res = a*b;
    if (res >= mod) {
        return int(res%mod);
    } else {
        return int(res);
    }
}
int fastexp(long long n, long long k) {
    long long ret = 1;
    while (k > 0) {
        if (k & 1) ret = mmul(ret, n);
        n = mmul(n, n);
        k /= 2;
    }
    return int(ret);
}
inline int mdiv(int a, int b) {
    return mmul(a, fastexp(b, mod-2));
}

int det(vector< vector<int> > &G) {
	int ret = 1;
    int N = G.size();
	for (int r=0; r<N; ++r) {
		int nr = r;
		while (nr<N && G[nr][r]==0) {
			++nr;
		}
		if (nr == N) {
			return 0;
		}
		if (nr != r) {
			ret = msub(0, ret);
			for (int c=r; c<N; ++c) {
				swap(G[r][c], G[nr][c]);
			}
		}

		ret = mmul(ret, G[r][r]);
		for (int c=0; c<r; ++c) {
			assert(G[r][c] == 0);
		}
		int d = G[r][r];
		assert(d > 0);
		for (int r2=r+1; r2<N; ++r2) {
			int f = G[r2][r];
			for (int c=r; c<N; ++c) {
				G[r2][c] = msub(G[r2][c], mmul(mdiv(G[r][c], d), f));
			}
			assert(G[r2][r] == 0);
		}
	}

	return ret;
}

int Kirchhoff(vector< vector<int> > &G) {
    int n = G.size();
    for (int i=0; i<n; ++i) {
        int deg = 0;
        for (int j=0; j<n; ++j) {
            deg += G[i][j];
            G[i][j] *= -1;
        }
        G[i][i] += deg;
    }
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            G[i][j] = int((G[i][j]+mod)%mod);
        }
    }

    G.pop_back();
    for (int i=0; i<n-1; ++i) {
        G[i].pop_back();
    }
    return det(G);
}
int ntrees[41]; // how many labeled trees with k truly sweet nodes
int calc_trees(int nTS, int nS, int nB) {
    int n = nTS + nS + nB;
    vector< vector<int> > G(n, vector<int>(n, 0));
    for (int i=0; i<nTS; ++i) {
        for (int j=0; j<nTS+nB; ++j) {
            G[i][j] = 1;
        }
    }
    for (int i=0; i<nS; ++i) {
        for (int j=0; j<nB; ++j) {
            G[nTS+nB+i][nTS+j] = 1;
        }
    }
    for (int i=0; i<nB; ++i) {
        for (int j=0; j<n; ++j) {
            G[nTS+i][j] = 1;
        }
    }

    return Kirchhoff(G);
}

long long C[41][41];
char LG[1<<20];
char bc[1<<20];
long long sum[1<<20];
class SweetFruits {
public:
    int countTrees(vector <int> sweetness, int lim) {
        C[0][0] = 1;
        for (int n=1; n<41; ++n) {
            C[n][0] = 1;
            for (int k=1; k<=n; ++k) {
                C[n][k] = C[n-1][k-1] + C[n-1][k];
                if (C[n][k] >= mod) {
                    C[n][k] -= mod;
                }
            }
        }
        for (int i=0; i<20; ++i) {
            LG[1<<i] = char(i);
        }
        bc[0] = 0;
        for (int mask=0; mask<(1<<20); ++mask) {
            bc[mask] = char(bc[mask>>1] + (mask&1));
        }

        int N = sweetness.size();
        vector<int> S;
        int nB = 0;
        for (int i=0; i<N; ++i) {
            if (sweetness[i] == -1) {
                ++nB;
            } else {
                S.push_back(sweetness[i]);
            }
        }
        int nS = S.size();
        if (nS <= 1) {
            return fastexp(N, N-2);
        }

        ntrees[0] = calc_trees(0, nS, nB);
        for (int k=1; k<=nS; ++k) {
            ntrees[k] = calc_trees(k, nS-k, nB);
            for (int i=1; i<=k; ++i) {
                ntrees[k] = int(((ntrees[k] - C[k][i]*ntrees[k-i])%mod + mod)%mod);
                assert(ntrees[k]>=0 && ntrees[k]<mod);
            }
        }

        int n2 = nS/2;
        int n1 = nS - n2;
        vector< vector<int> > sums1(n1+1);
        sum[0] = 0;
        sums1[0].push_back(0);
        for (int mask=1; mask<(1<<n1); ++mask) {
            sum[mask] = sum[mask&(mask-1)] + S[LG[mask&-mask]];
            if (sum[mask] <= lim) {
                sums1[bc[mask]].push_back(int(sum[mask]));
            }
        }
        for (int i=0; i<=n1; ++i) {
            sort(sums1[i].begin(), sums1[i].end());
        }

        vector< vector<int> > sums2(n2+1);
        sum[0] = 0;
        sums2[0].push_back(0);
        for (int mask=1; mask<(1<<n2); ++mask) {
            sum[mask] = sum[mask&(mask-1)] + S[n1+LG[mask&-mask]];
            if (sum[mask] <= lim) {
                sums2[bc[mask]].push_back(int(sum[mask]));
            }
        }
        for (int i=0; i<=n2; ++i) {
            sort(sums2[i].begin(), sums2[i].end());
        }

        int sol = int(ntrees[0]%mod);
        for (int cnt=1; cnt<=nS; ++cnt) {
            long long ways = 0;
            for (int k1=0; k1<=min(n1, cnt); ++k1) {
                const int k2 = cnt - k1;
                if (k2 > n2) continue;

                int i = 0;
                int j = int(sums2[k2].size())-1;
                while (i<(int)sums1[k1].size() && j>=0) {
                    int val = sums1[k1][i] + sums2[k2][j];
                    if (val <= lim) {
                        ways += j+1;
                        ++i;
                    } else {
                        --j;
                    }
                }
            }
            sol = int((sol + ways%mod*ntrees[cnt])%mod);
        }

        return sol;
    }
};
