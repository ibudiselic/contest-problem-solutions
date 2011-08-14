#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

long long dp[13][1<<12];
long long F[1001];
int bc[1<<12];
int K;
long long dp2[1001][13];
long long dp3[1001][1001];
const long long mod = 1000000007;
/*memo sol
    long long go(int k, int mask, int total) {
    long long &ret = dp[k][mask];
    if (ret != -1) {
        return ret;
    }
    if (k == K) {
        return ret = F[total];
    }
    ret = 0;
    for (int i=0; i<K; ++i) {
        if (i!=k && (mask & (1<<i))) {
            ret += go(k+1, mask ^ (1<<i), total-1);
        }
    }
    if (total > bc[mask]) {
        ret += (total-bc[mask])*go(k+1, mask, total-1);
    }
    ret %= mod;
    return ret;
}*/
long long fastexp(long long a, long long n) {
    long long ret = 1;
    while (n > 0) {
        if (n & 1LL) {
            ret = ret*a%mod;
        }
        a = a*a%mod;
        n >>= 1;
    }
    return ret;
}
long long inv_mod(int a) {
    return fastexp(a, mod-2);
}
class CarelessSecretary {
	public:
	int howMany(int N, int K) {
        ::K = K;
        bc[0] = 0;
        for (int i=1; i<(1<<K); ++i) {
            bc[i] = bc[i>>1] + (i&1);
        }
        F[0] = 1;
        for (int i=1; i<=N; ++i) {
            F[i] = F[i-1] * i % mod;
        }
        /* memo
		memset(dp, 0xff, sizeof dp);
        return go(0, (1<<K)-1, N);
        */
        
        /*
        forward-out dp (computing forward, data goes out from a computed value to the next row)
        dp[i][j] = ways for the ith guy to have a choice between hats with unused mask j
        
        memset(dp, 0, sizeof dp);
        dp[0][(1<<K)-1] = 1;
        for (int i=0; i<K; ++i) {
            memset(dp[(i+1)&1], 0, sizeof dp[(i+1)&1]);
            for (int mask=0; mask<(1<<K); ++mask) {
                if (dp[i&1][mask] > 0) {
                    int others = N - i - bc[mask];
                    if (others > 0) {
                        dp[(i+1)&1][mask] = (dp[(i+1)&1][mask] + others*dp[i&1][mask])%mod;
                    }
                    for (int k=0; k<K; ++k) {
                        if (k!=i && (mask & (1<<k))) {
                            dp[(i+1)&1][mask^(1<<k)] = (dp[(i+1)&1][mask^(1<<k)]
                                + dp[i&1][mask])%mod;
                        }
                    }
                }
            }
        }
        long long sol = 0;
        for (int mask=0; mask<(1<<K); ++mask) {
            sol += F[N-K]*dp[K&1][mask]%mod;
        }
        return sol % mod;
        */
        
        /* forward-in dp (computing forward, data comes in from precomputed locations) 
           dp[i][j] = ways for the ith guy to have a choice between hats with unused mask j
           identical numbers as forward-out, just calculated in a slighly different way
        memset(dp, 0, sizeof dp);
        dp[0][(1<<K)-1] = 1;
        for (int i=1; i<=K; ++i) {
            for (int mask=0; mask<(1<<K); ++mask) {
                dp[i&1][mask] = 0;
                int others = N - (i-1) - bc[mask]; // last guy had this many other options
                if (others > 0) {
                    dp[i&1][mask] += others*dp[(i+1)&1][mask];
                }
                for (int k=0; k<K; ++k) {
                    if (k!=i-1 && !(mask & (1<<k))) {
                        dp[i&1][mask] += dp[(i+1)&1][mask | (1<<k)];
                    }
                }
                dp[i&1][mask] %= mod;
            }
        }
        long long sol = 0;
        for (int mask=0; mask<(1<<K); ++mask) {
            sol = (sol + dp[K&1][mask]*F[N-K]) % mod;
        }
        return sol;*/
        
        /* backward-in (same order as memo)
            dp[i][j] = ways that guy i will see the unused mask j before making his choice
        memset(dp, 0, sizeof dp);
        for (int mask=0; mask<(1<<K); ++mask) {
            dp[K&1][mask] = F[N-K];
        }
        for (int i=K-1; i>=0; --i) {
            for (int mask=0; mask<(1<<K); ++mask) {
                dp[i&1][mask] = 0;
                
                int others = N - i - bc[mask];
                if (others > 0) {
                    dp[i&1][mask] += others*dp[(i+1)&1][mask];
                }
                for (int k=0; k<K; ++k) {
                    if (k!=i && (mask & (1<<k))) {
                        dp[i&1][mask] += dp[(i+1)&1][mask ^ (1<<k)];
                    }
                }
                
                dp[i&1][mask] %= mod;
            }
        }
        return dp[0][(1<<K)-1]; // we know this is the only mask guy 0 can se before his choice
        */
        
        /* backward-out dp
           dp[i][j] = ways that guy i will see unused mask j before his pick
           (same values as backward-in but different way of calculating it)
        memset(dp, 0, sizeof dp);
        for (int mask=0; mask<(1<<K); ++mask) {
            dp[K&1][mask] = F[N-K];
        }
        for (int i=K; i>0; --i) {
            memset(dp[(i+1)&1], 0, sizeof dp[(i+1)&1]);
            for (int mask=0; mask<(1<<K); ++mask) {
                if (dp[i&1][mask] > 0) {
                    int others = N - (i-1) - bc[mask];
                    if (others > 0) {
                        dp[(i+1)&1][mask] = (dp[(i+1)&1][mask]
                            + others*dp[i&1][mask]) % mod;
                    }
                    for (int k=0; k<K; ++k) {
                        if (k!=i-1 && !(mask & (1<<k))) {
                            dp[(i+1)&1][mask | (1<<k)] = (dp[(i+1)&1][mask | (1<<k)]
                                + dp[i&1][mask]) % mod;
                        }
                    }
                }
            }
        }
        return dp[0][(1<<K)-1]; // this is the only mask the 0th guy can see
        */
        
        /* different statespace (faster) */
        /**/
        
        /* count the number of dearangements for K<=i<=N
           -every permutation that satisfies the problem condition has
           exactly K, K+1, K+2, ..., N-1 or N elements in dearangement
           - for every element count, the first K elements are chosen in
           a fixed way, but the remaining i-K elements that are in 
           dearangement can be chosen in choose(N-K, i-K) ways
           - also, all the other elements (those that are not 
           in dearangement) have fixed values (i.e. P(i) = i)
           - therefore the solution is
                sum(K<=i<=N) (choose(N-K, i-K)*!i)
             where !i is the number of dearangements with i elements
           - the number of dearangements can be calculated by dp */
        /*long long num_dearangements[1001];
        num_dearangements[0] = 1;
        num_dearangements[1] = 0;
        for (int i=2; i<=N; ++i) {
            num_dearangements[i] = (i-1)
                * (num_dearangements[i-2] + num_dearangements[i-1]) % mod;
        }
        long long sol = num_dearangements[K];
        long long choose = 1;
        for (int i=K+1; i<=N; ++i) {
            choose = choose * (N-i+1) % mod * inv_mod(i-K) % mod;
            sol = (sol + choose * num_dearangements[i]) % mod;
        }
        
        return sol;*/
        
        /* dp[i][j] = number of permutations of i elements with j special elements
            that are NOT mapped to themselves 
           - the method for calculating this is derived using a method similar to
             how the number of dearangements is derived (only with two more cases) */
        memset(dp3, 0, sizeof dp3);
        dp3[0][0] = 1;
        for (int i=1; i<=N; ++i) {
            dp3[i][0] = dp3[i-1][0] * i % mod; // i factorial
            const int lim = min(K, i);
            for (int j=1; j<=lim; ++j) {
                if (i > 1) {
                    dp3[i][j] += (i-j) * dp3[i-2][j-1];
                }
                dp3[i][j] += (i-j) * dp3[i-1][j];
            
                if (i > 1) {
                    dp3[i][j] += (j-1) * dp3[i-2][j-2];
                }
                dp3[i][j] += (j-1) * dp3[i-1][j-1];
                
                dp3[i][j] %= mod;
            }
        }
        
        return dp3[N][K];
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 1; int Arg2 = 1; verify_case(0, Arg2, howMany(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 4; verify_case(1, Arg2, howMany(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 2; verify_case(2, Arg2, howMany(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 7; int Arg1 = 4; int Arg2 = 2790; verify_case(3, Arg2, howMany(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 9; int Arg1 = 1; int Arg2 = 322560; verify_case(4, Arg2, howMany(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 714; int Arg1 = 9; int Arg2 = 466134693; verify_case(5, Arg2, howMany(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    CarelessSecretary ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
