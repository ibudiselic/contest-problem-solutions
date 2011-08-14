#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<string> M;
int n;
int dp[1<<18];
int go(unsigned state, int start) {
	if (dp[state] != -1)
		return dp[state];

	int ret = 0;
	for (int i=start; i<n-1; ++i)
		if ((state & (1u<<i)) == 0)
			for (int j=i+1; j<n; ++j)
				if ((state & (1u<<j))==0 && M[i][j]=='Y')
					ret = max(ret, 1+go(state | (1u<<i) | (1u<<j), i+1));
	return dp[state] = ret;
}
class SeparateConnections {
	public:
	int howMany(vector <string> mat) {
		M = mat;
		n = M.size();

		memset(dp, 0xff, sizeof dp);
		return go(0, 0) * 2;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {
"NYYYY",
"YNNNN",
"YNNNN",
"YNNNN",
"YNNNN"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, howMany(Arg0)); }
	void test_case_1() { string Arr0[] = {
"NYYYY",
"YNNNN",
"YNNNY",
"YNNNY",
"YNYYN"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(1, Arg1, howMany(Arg0)); }
	void test_case_2() { string Arr0[] = {
"NNYYYYYYYYYYYYYYYY",
"NNYYYYYYYYYYYYYYYY",
"YYNNNNNNNNNNNNNNNN",
"YYNNNNNNNNNNNNNNNN",
"YYNNNNNNNNNNNNNNNN",
"YYNNNNNNNNNNNNNNNN",
"YYNNNNNNNNNNNNNNNN",
"YYNNNNNNNNNNNNNNNN",
"YYNNNNNNNNNNNNNNNN",
"YYNNNNNNNNNNNNNNNN",
"YYNNNNNNNNNNNNNNNN",
"YYNNNNNNNNNNNNNNNN",
"YYNNNNNNNNNNNNNNNN",
"YYNNNNNNNNNNNNNNNN",
"YYNNNNNNNNNNNNNNNN",
"YYNNNNNNNNNNNNNNNN",
"YYNNNNNNNNNNNNNNNN",
"YYNNNNNNNNNNNNNNNN"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(2, Arg1, howMany(Arg0)); }
	void test_case_3() { string Arr0[] = {
"NNNNNNNNNYNNNNNYN",
"NNNNNNNNNNNNNNNNN",
"NNNNNNNYNNNNNNNNN",
"NNNNNYNNNNNYNNYYY",
"NNNNNNNNNNNNNNNYN",
"NNNYNNNNNNNNNNYNN",
"NNNNNNNNNYNNNNNNN",
"NNYNNNNNNNNNNNNNN",
"NNNNNNNNNYNNNNNNN",
"YNNNNNYNYNNNNNNNY",
"NNNNNNNNNNNNNNNNN",
"NNNYNNNNNNNNNNNNN",
"NNNNNNNNNNNNNNNNN",
"NNNNNNNNNNNNNNNNN",
"NNNYNYNNNNNNNNNNN",
"YNNYYNNNNNNNNNNNN",
"NNNYNNNNNYNNNNNNN"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(3, Arg1, howMany(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    SeparateConnections ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
