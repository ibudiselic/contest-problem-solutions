#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int dp[48][16];
vector<int> P;
int go(int pos, int n) {
	if (n == 0)
		return 0;
	if (pos >= (int)P.size())
		return -123456789;

	int &ret = dp[pos][n];
	if (ret != -1)
		return ret;

	return (ret = max(go(pos+1, n), P[pos] + go(pos+2, n-1)));
}

class PieSharing {
	public:
	int share(vector <int> pieces) {
		P = pieces;
		int n = P.size()/3;

		int ret = 0;
		memset(dp, 0xff, sizeof dp);
		ret = max(ret, go(1, n));
		memset(dp, 0xff, sizeof dp);
		P.pop_back();
		ret = max(ret, P[0] + go(2, n-1));

		return ret;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {33, 33, 34}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 34; verify_case(0, Arg1, share(Arg0)); }
	void test_case_1() { int Arr0[] = {5, 17, 22, 34, 18, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 51; verify_case(1, Arg1, share(Arg0)); }
	void test_case_2() { int Arr0[] = {11, 1, 1, 85, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 96; verify_case(2, Arg1, share(Arg0)); }
	void test_case_3() { int Arr0[] = {6, 13, 14, 4, 14, 10, 1, 20, 18}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 48; verify_case(3, Arg1, share(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    PieSharing ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
