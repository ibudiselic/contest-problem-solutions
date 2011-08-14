#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class CreatePairs {
	public:
	int maximalSum(vector <int> data) {
		sort(data.begin(), data.end());
		data.insert(data.begin(), 1);

		int dp[51] = {0};
		for (int i=1; i<(int)data.size(); ++i)
			dp[i] = max(dp[i-1] + data[i], (i>1 ? dp[i-2] : 0) + data[i-1]*data[i]);

		return dp[data.size()-1];
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0, 1, 2, 4, 3, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 27; verify_case(0, Arg1, maximalSum(Arg0)); }
	void test_case_1() { int Arr0[] = {-1, 1, 2, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(1, Arg1, maximalSum(Arg0)); }
	void test_case_2() { int Arr0[] = {-1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(2, Arg1, maximalSum(Arg0)); }
	void test_case_3() { int Arr0[] = {-1, 0, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(3, Arg1, maximalSum(Arg0)); }
	void test_case_4() { int Arr0[] = {1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(4, Arg1, maximalSum(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    CreatePairs ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
