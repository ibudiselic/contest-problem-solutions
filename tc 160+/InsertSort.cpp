#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <numeric>
#include <set>

using namespace std;

int dp[50];
class InsertSort {
	public:
	int calcMinimalCost(vector <int> a) {
		int n = a.size();
		int sum = accumulate(a.begin(), a.end(), 0);

		int sol = sum+1;
		for (int i=0; i<n; ++i) {
			dp[i] = a[i];
			for (int j=0; j<i; ++j)
				if (a[i] >= a[j])
					dp[i] = max(dp[i], dp[j]+a[i]);

			sol = min(sol, sum-dp[i]);
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {7, 1, 2, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(0, Arg1, calcMinimalCost(Arg0)); }
	void test_case_1() { int Arr0[] = {7, 1, 2, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(1, Arg1, calcMinimalCost(Arg0)); }
	void test_case_2() { int Arr0[] = {1, 8, 8, 12, 99}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, calcMinimalCost(Arg0)); }
	void test_case_3() { int Arr0[] = {8, 2, 6, 5, 1, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 18; verify_case(3, Arg1, calcMinimalCost(Arg0)); }
	void test_case_4() { int Arr0[] = {6, 4, 5, 3, 8, 2, 7, 2, 11, 2, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 24; verify_case(4, Arg1, calcMinimalCost(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    InsertSort ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
