#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

long long dp[1001][1001];
// [i][j] broj nacina za napraviti cikluse ukupne duljine <= i
// koristeci potencije samo do j-tog prim broja
class NumPermutationOrders {
	public:
	long long howMany(int n) {
		vector<int> primes;
		for (int pc=2; pc<=n; ++pc) {
			bool is_prime = true;
			for (int dc=2; dc*dc<=pc; ++dc)
				if (pc%dc == 0) {
					is_prime = false;
					break;
				}
			if (is_prime)
				primes.push_back(pc);
		}
		int np = primes.size();

		memset(dp, 0, sizeof dp);
		for (int i=0; i<=np; ++i)
			dp[0][i] = 1;
		for (int len=1; len<=n; ++len) {
			dp[len][0] = 1;
			for (int pc=0; pc<np; ++pc) {
				dp[len][pc+1] += dp[len][pc];
				for (int x=primes[pc]; x<=len; x*=primes[pc])
					dp[len][pc+1] += dp[len-x][pc];
			}
		}
		return dp[n][np];
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; long long Arg1 = 1LL; verify_case(0, Arg1, howMany(Arg0)); }
	void test_case_1() { int Arg0 = 2; long long Arg1 = 2LL; verify_case(1, Arg1, howMany(Arg0)); }
	void test_case_2() { int Arg0 = 3; long long Arg1 = 3LL; verify_case(2, Arg1, howMany(Arg0)); }
	void test_case_3() { int Arg0 = 4; long long Arg1 = 4LL; verify_case(3, Arg1, howMany(Arg0)); }
	void test_case_4() { int Arg0 = 10; long long Arg1 = 16LL; verify_case(4, Arg1, howMany(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    NumPermutationOrders ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
