#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int dp[50][51][2];
vector<int> X;
int go(int pos, int last, bool falling) {
	if (pos == (int)X.size())
		return 0;

	int &ret = dp[pos][last][falling];
	if (ret != -1)
		return ret;

	if (last == 50) {
		ret = min(1+go(pos+1, 50, 0), min(go(pos+1, pos, 0), min(1+go(pos+1, 50, 1), go(pos+1, pos, 1))));
	} else {
		ret = go(pos+1, last, falling) + 1;
		if (!falling)
			ret = min(ret, go(pos+1, last, 1) + 1);

		if (falling && X[pos] < X[last])
			ret = min(ret, go(pos+1, pos, 1));
		if (!falling && X[pos] > X[last])
			ret = min(ret, min(go(pos+1, pos, 0), go(pos+1, pos, 1)));
	}

	return ret;
}
class IntegerSequence {
	public:
	int maxSubsequence(vector <int> numbers) {
		memset(dp, 0xff, sizeof dp);
		X = numbers;

		return go(0, 50, 0);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 4, 6, 5, 2, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(0, Arg1, maxSubsequence(Arg0)); }
	void test_case_1() { int Arr0[] = {1, 2, 1, 2, 3, 2, 1, 2, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(1, Arg1, maxSubsequence(Arg0)); }
	void test_case_2() { int Arr0[] = {2, 2, 2, 2, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(2, Arg1, maxSubsequence(Arg0)); }
	void test_case_3() { int Arr0[] = {4,5,65,34,786,45678,987,543,2,6,98,580,4326,754,54,2,1,3,5,6,8,765,43,3,54}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 14; verify_case(3, Arg1, maxSubsequence(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    IntegerSequence ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
