#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int dp[10][11];

long long calc(int num) {
	string s;
	ostringstream os;
	os << num;
	s = os.str();
	long long ret = 1 + (num!=0); /* because of zero and the limit which are never considered */
	for (int i=1; i<(int)s.size(); ++i)
		for (int d=1; d<10; ++d)
			ret += dp[d][s.size()-i];

	for (int d=1; d<s[0]-'0'; ++d)
		ret += dp[d][s.size()];

	for (int i=1; i<(int)s.size(); ++i) {
		for (int d=0; d<s[i]-'0'; ++d)
			if (abs(s[i-1]-'0'-d) >= 2)
				ret += dp[d][s.size()-i];
		if (abs(s[i] - s[i-1]) < 2) {
			--ret;
			break;
		}
	}
	return ret;
}
class JumpyNum {
	public:
	int howMany(int low, int high) {
		memset(dp, 0, sizeof dp);
		for (int i=0; i<10; ++i)
			dp[i][1] = 1;
		for (int i=2; i<11; ++i)
			for (int d=0; d<10; ++d)
				for (int j=0; j<10; ++j)
					if (abs(d-j) >= 2)
						dp[d][i] += dp[j][i-1];

		return calc(high) - calc(low-1);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 10; int Arg2 = 9; verify_case(0, Arg2, howMany(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 9; int Arg1 = 23; int Arg2 = 9; verify_case(1, Arg2, howMany(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 2000000000; int Arg1 = 2000000000; int Arg2 = 0; verify_case(2, Arg2, howMany(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 8000; int Arg1 = 20934; int Arg2 = 3766; verify_case(3, Arg2, howMany(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    JumpyNum ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
