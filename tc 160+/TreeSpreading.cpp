#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

long long dp[11][11][11][11][5];
bool endCond(const vector<int> &v) {
	for (int i=0; i<4; ++i)
		if (v[i] != 0)
			return false;
	return true;
}
long long& getVal(const vector<int> &v, int last) {
	return dp[v[0]][v[1]][v[2]][v[3]][last];
}
long long go(vector<int> &v, int last) {
	if (endCond(v))
		return 1;

	long long &ret = getVal(v, last);
	if (ret != -1)
		return ret;

	ret = 0;
	for (int i=0; i<4; ++i)
		if (i!=last && v[i]>0) {
			--v[i];
			ret += go(v, i);
			++v[i];
		}

	return ret;
}

class TreeSpreading {
	public:
	long long countArrangements(int a, int b, int c, int d) {
		memset(dp, 0xff, sizeof dp);
		vector<int> v;
		v.push_back(a); v.push_back(b); v.push_back(c); v.push_back(d);
		return go(v, 4);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 0; int Arg3 = 0; long long Arg4 = 2LL; verify_case(0, Arg4, countArrangements(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 0; int Arg3 = 0; long long Arg4 = 2LL; verify_case(1, Arg4, countArrangements(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1; int Arg3 = 1; long long Arg4 = 24LL; verify_case(2, Arg4, countArrangements(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 1; int Arg3 = 1; long long Arg4 = 96LL; verify_case(3, Arg4, countArrangements(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    TreeSpreading ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
