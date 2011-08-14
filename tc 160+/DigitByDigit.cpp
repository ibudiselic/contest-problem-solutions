#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

double dp[51][51];
class DigitByDigit {
	public:
	double expectedScore(string digits) {
		const int cnt = count(digits.begin(), digits.end(), '_');
		for (int i=0; i<51; ++i)
			for (int j=0; j<51; ++j)
				dp[i][j] = 0;
		dp[1][0] = 4.5;
		for (int n=2; n<=cnt; ++n) {
			for (int dig=0; dig<=9; ++dig) {
				int x = n-1;
				for (int i=0; i<n-1; ++i)
					if (dig > dp[n-1][i]) {
						x = i;
						break;
					}
				dp[n][x] += 0.1 * dig;
				for (int i=0; i<x; ++i) dp[n][i] += 0.1 * dp[n-1][i];
				for (int i=x; i<n-1; ++i) dp[n][i+1] += 0.1 * dp[n-1][i];
			}
		}
		double sol = 0;
		int x = 0;
		for (int i=0; i<(int)digits.size(); ++i) {
			if (digits[i] != '_') sol = sol*10 + (digits[i]-'0');
			else sol = sol*10 + dp[cnt][x++];
		}
		return sol;
	}




// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "_0"; double Arg1 = 45.0; verify_case(0, Arg1, expectedScore(Arg0)); }
	void test_case_1() { string Arg0 = "__"; double Arg1 = 60.75; verify_case(1, Arg1, expectedScore(Arg0)); }
	void test_case_2() { string Arg0 = "_55_"; double Arg1 = 6303.25; verify_case(2, Arg1, expectedScore(Arg0)); }
	void test_case_3() { string Arg0 = "____0000000000000000"; double Arg1 = 7.482735000000001E19; verify_case(3, Arg1, expectedScore(Arg0)); }
	void test_case_4() { string Arg0 = "___6__3___"; double Arg1 = 8.604871517066002E9; verify_case(4, Arg1, expectedScore(Arg0)); }
	void test_case_5() { string Arg0 = "__________"; double Arg1 = 8.882477600592714E9; verify_case(5, Arg1, expectedScore(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    DigitByDigit ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
