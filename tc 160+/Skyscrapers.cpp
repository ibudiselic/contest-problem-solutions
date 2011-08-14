#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int mod = 1000000007;
long long C[101][101];
long long F[101];
long long dp[101][101];
long long go(int n, int x) {
    if (n == 0) {
        return (x == 0);
    }
    if (n == 1) {
        return (x == 1);
    }
    if (x == 0) {
        return 0;
    }

    long long &ret = dp[n][x];
    if (ret != -1) {
        return ret;
    }

    ret = 0;
    for (int i=0; i<n; ++i) {
        long long add = C[n-1][i]*go(i, x-1) % mod;
        add = add*F[n-1-i] % mod;
        ret = (ret + add) % mod;
    }

    return ret;
}
class Skyscrapers {
	public:
	int buildingCount(int N, int leftSide, int rightSide) {
        if (N == 1) {
            return leftSide==1 && rightSide==1;
        }

		F[0] = 1;
        for (long long x=1; x<=100; ++x) {
            F[x] = F[x-1]*x % mod;
        }

        C[0][0] = 1;
        for (int n=1; n<=100; ++n) {
            C[n][0] = 1;
            C[n][n] = 1;
            for (int k=1; k<n; ++k) {
                C[n][k] = (C[n-1][k] + C[n-1][k-1]) % mod;
            }
        }

        memset(dp, 0xff, sizeof dp);
        long long sol = 0;
        for (int i=0; i<N; ++i) {
            long long cur = C[N-1][i]*go(i, leftSide-1) % mod;
            cur = cur*go(N-1-i, rightSide-1) % mod;

            sol = (sol + cur) % mod;
        }

        return int(sol);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 2; int Arg3 = 2; verify_case(0, Arg3, buildingCount(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 1; int Arg3 = 1; verify_case(1, Arg3, buildingCount(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 3; int Arg2 = 2; int Arg3 = 18; verify_case(2, Arg3, buildingCount(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 12; int Arg1 = 1; int Arg2 = 1; int Arg3 = 0; verify_case(3, Arg3, buildingCount(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 8; int Arg1 = 3; int Arg2 = 2; int Arg3 = 4872; verify_case(4, Arg3, buildingCount(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    Skyscrapers ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
