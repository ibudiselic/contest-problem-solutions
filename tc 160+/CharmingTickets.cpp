#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int dp[1001][9001];
int mod = 999983;
class CharmingTickets {
	public:
	int count(int K, string good) {
		memset(dp, 0, sizeof dp);
		dp[0][0] = 1;
		for (int i=1; i<=K; ++i) {
			for (int old=0; old<=9000; ++old) {
				for (int d=0; d<(int)good.size(); ++d) {
					int next = old + good[d]-'0';
					if (next <= 9000) {
						dp[i][next] = (dp[i][next] + dp[i-1][old]) % mod;
					}
				}
			}
		}

		int sol = 0;
		for (int sum=0; sum<=9000; ++sum) {
			sol = (sol + (long long)dp[K][sum]*dp[K][sum]) % mod;
		}
		sol = 2*sol % mod;

		int sub1 = 0;
		for (int sum=0; sum<=9000; ++sum) {
			sub1 = (sub1 + (long long)dp[(K+1)/2][sum]*dp[(K+1)/2][sum]) % mod;
		}

		int sub2 = 0;
		for (int sum=0; sum<=9000; ++sum) {
			sub2 = (sub2 + (long long)dp[K/2][sum]*dp[K/2][sum]) % mod;
		}

		sol = (sol - (long long)sub1*sub2 + (long long)sub1*mod) % mod;

		return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; string Arg1 = "0123456789"; int Arg2 = 10; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; string Arg1 = "21"; int Arg2 = 8; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 2; string Arg1 = "0987654321"; int Arg2 = 1240; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 137; string Arg1 = "0123456789"; int Arg2 = 630063; verify_case(3, Arg2, count(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    CharmingTickets ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
