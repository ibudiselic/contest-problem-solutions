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

const long long mod = 1000000007;
void modadd(long long &a, long long b) {
    assert(a >= 0);
    assert(b >= 0);
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}
void modsub(long long &a, long long b) {
    assert(a >= 0);
    assert(b >= 0);
    a -= b;
    if (a < 0) {
        a += mod;
    }
}
long long C_[1226][51];
long long choose(int n, int k) {
    if (n<0 || k<0 || k>n) {
        return 0;
    }
    assert(n<1226);
    assert(k<51);
    return C_[n][k];
}
long long W_[51][51];
int N, K;
long long ways(int n, int k) {
    if (n<0 || n>N || k<0 || k>K) {
        return 0;
    }
    assert(n<51);
    assert(k<51);
    return W_[n][k];
}
class KingdomAndCities {
public:
    int howMany(int N, int M, int K) {
        ::N = N;
        ::K = K;
        C_[0][0] = 1;
        for (int i=1; i<=N*(N-1)/2; ++i) {
            C_[i][0] = 1;
            const int lim = min(50, i);
            for (int j=1; j<=lim; ++j) {
                C_[i][j] = C_[i-1][j];
                modadd(C_[i][j], C_[i-1][j-1]);
            }
        }
        W_[0][0] = W_[1][0] = 1;
        for (int n=2; n<=N; ++n) {
            for (int k=n-1; k<=K; ++k) {
                W_[n][k] = choose(n*(n-1)/2, k);
                for (int n1=1; n1<=n-1; ++n1) {
                    int lim = min(n1*(n1-1)/2, k);
                    for (int k1=n1-1; k1<=lim; ++k1) {
                        modsub(W_[n][k], choose(n-1, n1-1)*W_[n1][k1]%mod*choose((n-n1)*(n-n1-1)/2, k-k1)%mod);
                    }
                }
            }
        }

        long long sol = -1;
        if (M == 0) {
            sol = ways(N, K);
        } else if (M == 1) {
            sol = ways(N-1, K-2)*choose(N-1, 2)%mod;
            for (int n1=1; n1<=N-2; ++n1) {
                for (int k1=n1-1; k1<=n1*(n1-1)/2; ++k1) {
                    const int n2 = N-1-n1;
                    const int k2 = K-2-k1;
                    modadd(sol, ways(n1, k1)*choose(N-2, n1-1)%mod*ways(n2, k2)%mod*n1*n2%mod);
                }
            }
        } else {
            sol = ways(N-2, K-4)*choose(N-2, 2)%mod*choose(N-2, 2)%mod;
            modadd(sol, ways(N-2, K-3)*(N-2)*(N-2)%mod);
            for (int n1=1; n1<=N-3; ++n1) {
                for (int k1=n1-1; k1<=n1*(n1-1)/2; ++k1) {
                    int n2 = N-2-n1;
                    int k2 = K-4-k1;
                    modadd(sol, ways(n1, k1)*ways(n2, k2)%mod*choose(N-3, n1-1)%mod*(2*n1*n2*(choose(n1, 2)+choose(n2, 2))%mod+n1*n1*n2*n2%mod)%mod);
                    ++k2;
                    modadd(sol, ways(n1, k1)*ways(n2, k2)%mod*choose(N-3, n1-1)%mod*2*n1*n2%mod);
                }
            }
            for (int n1=1; n1<=N-4; ++n1) {
                for (int k1=n1-1; k1<=n1*(n1-1)/2; ++k1) {
                    for (int n2=1; n2<=N-3-n1; ++n2) {
                        int n3 = N-2-n1-n2;
                        if (n3 <= 0) {
                            break;
                        }
                        for (int k2=n2-1; k2<=n2*(n2-1)/2; ++k2) {
                            int k3 = K-4-k1-k2;
                            if (k3 > n3*(n3-1)/2) {
                                continue;
                            }
                            if (k3 < n3-1) {
                                break;
                            }
                            modadd(sol, ways(n1, k1)*ways(n2, k2)%mod*ways(n3, k3)%mod*choose(N-3, n1-1)%mod*choose(N-3-n1, n2-1)%mod*2*(n1+n2+n3)%mod*n1*n2*n3%mod);
                        }
                    }
                }
            }
        }

        return int(sol);
    }
};
