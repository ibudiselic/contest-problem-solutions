#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

enum {
    ODD=1, EVEN=2
};

const int mod = 1000000007;
int dp[2][1024];
int bc[1024];
int add_mod(int a, int b) {
    if ((a+=b) >= mod) {
        a -= mod;
    }
    return a;
}
long long mul_mod(long long a, long long b) {
    return int(a*b%mod);
}
int pow_mod(long long n, long long k) {
    long long ret = 1;
    while (k > 0) {
        if (k&1) {
            ret = mul_mod(ret, n);
        }
        n = mul_mod(n, n);
        k >>= 1;
    }
    return int(ret);
}
class MagicalGirlLevelTwoDivOne {
	public:
	int theCount(vector <string> palette, int m, int n) {
		int R = palette.size();
        int C = palette[0].size();
        
        int can[10][10];
        int times[10][10];
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                can[i][j] = ODD | EVEN;
                times[i][j] = 0;
                for (int a=i; a<R; a+=m) {
                    for (int b=j; b<C; b+=n) {
                        char c = palette[a][b];
                        if (c == '.') {
                            ++times[i][j];
                        } else {
                            can[i][j] &= ((c-'0')&1) ? ODD : EVEN;
                            if (can[i][j] == 0) {
                                return 0;
                            }
                        }
                    }
                }
            }
        }
        
        for (int i=1; i<1024; ++i) {
            bc[i] = bc[i>>1] + (i&1);
        }
        
        int cur=0, prev=1;
        memset(dp[prev], 0, sizeof dp[prev]);
        dp[prev][0] = 1;
        for (int i=0; i<m; ++i, swap(cur, prev)) {
            memset(dp[cur], 0, sizeof dp[cur]);
            for (int rowmask=0; rowmask<(1<<n); ++rowmask) {
                if (bc[rowmask] & 1) { // must have an odd number of odd numbers
                    int ways = 1;
                    for (int j=0; j<n; ++j) {
                        if (rowmask & (1<<j)) { // odd number
                            if (!(can[i][j] & ODD)) {
                                ways = 0;
                                break;
                            }
                            ways = mul_mod(ways, pow_mod(5, times[i][j]));
                        } else { // even number
                            if (!(can[i][j] & EVEN)) {
                                ways = 0;
                                break;
                            }
                            ways = mul_mod(ways, pow_mod(4, times[i][j]));
                        }
                    }
                    
                    if (ways > 0) {
                        for (int prevmask=0; prevmask<(1<<n); ++prevmask) {
                            if (dp[prev][prevmask] > 0) {
                                dp[cur][prevmask^rowmask] = add_mod(dp[cur][prevmask ^ rowmask], mul_mod(ways, dp[prev][prevmask]));
                            }
                        }
                    }
                }
            }
        }
        
        return dp[prev][(1<<n)-1];
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"12",
 "2."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 2; int Arg3 = 5; verify_case(0, Arg3, theCount(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"21",
 "1."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 2; int Arg3 = 4; verify_case(1, Arg3, theCount(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"...",
 "...",
 "..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 1; int Arg3 = 1953125; verify_case(2, Arg3, theCount(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"..58..",
 "..47.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 3; int Arg3 = 0; verify_case(3, Arg3, theCount(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"...1.2.3",
 "4.5.6...",
 "...7.8.9",
 "1.2.3..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 4; int Arg3 = 886073030; verify_case(4, Arg3, theCount(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arr0[] = {"....................",
 "....................",
 "....................",
 "....................",
 "....................",
 "....................",
 "....................",
 "....................",
 "....................",
 "....................",
 "....................",
 "....................",
 "....................",
 "....................",
 "....................",
 "....................",
 "....................",
 "....................",
 "....................",
 "...................."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 10; int Arg3 = 240076532; verify_case(5, Arg3, theCount(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    MagicalGirlLevelTwoDivOne ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
