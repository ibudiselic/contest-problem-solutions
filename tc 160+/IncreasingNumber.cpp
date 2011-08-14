#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int pos[500];
long long cnt[500];
long long dp[2][9][500];
long long mod = 1000000007;
long long inv[10];
long long get_cnt(long long n, int k) {
    // ways to choose k items from n infinite buckets
    // for example, number of solutions to x1+x2+x3+...+xn = k with integer xi>=0
    // equals (n+k-1 choose k)
    long long ret = 1;
    
    n += k-1;
    for (int i=0; i<k; ++i) {
        ret = ret * ((n-i)%mod) % mod;
        ret = ret * inv[i+1] % mod;
    }
    
    return ret;
}

// inv(x) = egcd(x, m).s if x coprime to m (specifically, if m is prime and x < m)
struct egcds {
	long long s, t, d;
};
egcds egcd(int m, int n) {
	if (m == 0) {
		return (egcds){0, 1, n};
	}
	egcds next = egcd(n%m, m);
	long long temp = next.s;
	next.s = next.t - temp*(n/m);
	next.t = temp;

	assert(next.s*m + next.t*n == next.d);
	return next;
}

// returns multiplicative inverse of a in Z_mod
// mod can be composite! but make sure there is a mulinv
long long mul_inv(long long a, long long mod) {
    egcds temp = egcd(a, mod);
    if (temp.d != 1) {
        assert(!"No multiplicative inverse");
    }
    if (temp.s < 0) {
        temp.s += (-temp.s+mod-1)/mod * mod;
    }
    assert(temp.s*a%mod == 1);
    return temp.s;
}

long long ways[10];
class IncreasingNumber {
	public:
	int countNumbers(long long digits, int divisor) {
		/* Any increasing number can be written as
             1*a + 11*b + 111*c + ...
           where
             a + b + c + ... <= 9.
           A 'digits' digit increasing number can be written as
             1*a + 11*b + 111*c + ... + 111...('digits' 1 digits)...111
           where
             a + b + c + ... <= 8.
           
           Let's set
             r = -111...('digits' 1 digits)...111.
           Then a 'digits' digit increasing number divisible by 'divisor'
           has to satisfy these properties:
             (1%divisor)*a + (11%divisor)*b + (111%divisor)*c + ... = r%divisor (mod divisor)
             a + b + c + ... <= 8.
           When we extract the common factors from the (111...111%divisor) terms we get 
             (x_0_0+x_0_1+...+x_0_cnt[0]-1)*0 + (x_1_0+x_1_1+...x_1_cnt[1]-1)*1 + ... = r%divisor (mod divisor)
             x_0_0+x_0_1+...+x_0_cnt[0]-1 + x_1_0+x_1_1+...+x_1_cnt[1]-1 + ... <= 8.
        
           Now we use DP to determine the number of ways of choosing xs such that both of these
           relations hold. */
        memset(pos, 0xff, sizeof pos);
        int x = 1%divisor;
        vector<int> mods;
        while (pos[x] == -1) {
            pos[x] = mods.size();
            mods.push_back(x);
            x = (x*10+1) % divisor;
        }
        int precycle = pos[x];
        int cycle = (int)mods.size() - pos[x];
        assert(cycle >= 1);
            
        memset(cnt, 0, sizeof cnt);
        for (int i=0; i<divisor; ++i) {
            if (pos[i] == -1) {
                continue;
            }
            if (pos[i] < precycle) {
                if (pos[i] < digits) {
                    cnt[i] = 1;
                }
            } else if (digits > precycle) {
                cnt[i] = (digits-1-precycle)/cycle + (pos[i]-precycle <= (digits-1-precycle)%cycle);
            }
        }
        /*long long real_cnt[501] = {0};
        x = 1%divisor;
        for (long long i=0; i<digits; ++i) {
            ++real_cnt[x];
            x = (x*10 + 1)%divisor;
        }
        
        for (int i=0; i<=divisor; ++i) {
            cerr << i << ' ' << cnt[i] << ' ' << real_cnt[i] << ' ' << (cnt[i]==real_cnt[i] ? "OK" : "FAIL") << '\n';
        }*/
        
        int r = -1;
        if (digits <= precycle) {
            r = mods[digits-1];
        } else {
            r = mods[precycle + (digits-1-precycle)%cycle];
        }
        /*int real_r = 0;
        for (int i=0; i<digits; ++i) {
            real_r = (real_r*10 + 1)%divisor;
        }
        cerr << r << ' ' << real_r << ' ' << (r==real_r ? "OK" : "FAIL") << '\n';*/
        if (r > 0) {
            r = divisor-r;
        }
        
        memset(inv, 0, sizeof inv);
        for (int i=1; i<9; ++i) {
            inv[i] = mul_inv(i, mod);
        }

        memset(dp, 0, sizeof dp);
        dp[0][0][0] = 1;
        int t = 0;
        for (int i=0; i<divisor; ++i) {
            if (cnt[i] == 0) {
                continue;
            }
            ways[0] = 1;
            for (int j=1; j<9; ++j) {
                ways[j] = get_cnt(cnt[i], j);
            }
            for (int j=0; j<9; ++j) {
                for (int k=0; k<divisor && (j>0 || k==0); ++k) {
                    if (dp[t][j][k] > 0) {
                        for (int add=0; add<=8-j; ++add) {
                            long long &temp = dp[!t][j+add][(k+add*i)%divisor];
                            temp = (temp + (dp[t][j][k] * ways[add])%mod) % mod;
                        }
                    }
                }
            }
            memset(dp[t], 0, sizeof dp[t]);
            t = !t;
        }
        
        long long sol = 0;
        for (int i=0; i<9; ++i) {
            sol += dp[t][i][r];
        }
        return sol%mod;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 2LL; int Arg1 = 12; int Arg2 = 4; verify_case(0, Arg2, countNumbers(Arg0, Arg1)); }
	void test_case_1() { long long Arg0 = 3LL; int Arg1 = 111; int Arg2 = 9; verify_case(1, Arg2, countNumbers(Arg0, Arg1)); }
	void test_case_2() { long long Arg0 = 452LL; int Arg1 = 10; int Arg2 = 0; verify_case(2, Arg2, countNumbers(Arg0, Arg1)); }
	void test_case_3() { long long Arg0 = 6LL; int Arg1 = 58; int Arg2 = 38; verify_case(3, Arg2, countNumbers(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    IncreasingNumber ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
