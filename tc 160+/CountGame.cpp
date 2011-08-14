#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;
int dp[1001];
int win(int next, int add, int goal) {
	if (next > goal)
		return 1234567890;
	if (next + add-1 >= goal)
		return goal - next + 1;
	if (dp[next] != -1)
		return dp[next];

	for (int i=0; i<add; ++i) {
		const int start = next+1 + i;
		bool good = true;
		for (int j=0; j<add; ++j)
			good &= (win(start+1 + j, add, goal)!=1234567890);
		if (good)
			return dp[next] = i+1;
	}
	return dp[next] = 1234567890;
}
class CountGame {
	public:
	int howMany(int maxAdd, int goal, int next) {
		memset(dp, 0xff, sizeof dp);

		const int sol = win(next, maxAdd, goal);

		return sol==1234567890 ? -1 : sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 20; int Arg2 = 10; int Arg3 = 3; verify_case(0, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 20; int Arg2 = 10; int Arg3 = 5; verify_case(1, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 20; int Arg2 = 9; int Arg3 = -1; verify_case(2, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 50; int Arg2 = 50; int Arg3 = 1; verify_case(3, Arg3, howMany(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    CountGame ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
