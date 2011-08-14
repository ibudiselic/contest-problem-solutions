#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int dp[151][151][151];

class FixedSizeSums {
	public:
	string kthElement(int sum, int count, int index) {
		memset(dp, 0, sizeof dp);
		for (int i=1; i<=sum; ++i) dp[0][i][i] = 1;

		for (int x=1; x<count; ++x)
			for (int m=1; m<=sum; ++m)
				for (int rem=m; rem<=sum; ++rem)
					for (int i=1; i<=m; ++i)
						dp[x][m][rem] += dp[x-1][i][rem-m];
		/* dp[x][m][rem] - broj konfiguracija duljine x+1 koje na mjestu x imaju m, uz zbroj rem */

		int cur = 0;
		for (int i=1; i<=sum; ++i)
			cur += dp[count-1][i][sum];
		if (cur <= index) return "";

		ostringstream sol;
		sol << sum << "=";
		int last = sum;
		for (int i=count-1; i>=0; --i) {
		  cur = 0;
			int k = last;
			while (cur <= index) {
				cur += dp[i][k][sum];
				--k;
			}
			++k;
			sol << k << '+';
			index -= cur - dp[i][k][sum];
			sum -= k;
			last = k;
		}
		return sol.str().substr(0, sol.str().size()-1);;
	}





// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 8; int Arg1 = 3; int Arg2 = 2; string Arg3 = "8=4+3+1"; verify_case(0, Arg3, kthElement(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 13; int Arg1 = 1; int Arg2 = 0; string Arg3 = "13=13"; verify_case(1, Arg3, kthElement(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 13; int Arg1 = 13; int Arg2 = 0; string Arg3 = "13=1+1+1+1+1+1+1+1+1+1+1+1+1"; verify_case(2, Arg3, kthElement(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 7; int Arg1 = 10; int Arg2 = 3; string Arg3 = ""; verify_case(3, Arg3, kthElement(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 17; int Arg1 = 2; int Arg2 = 4; string Arg3 = "17=12+5"; verify_case(4, Arg3, kthElement(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 140; int Arg1 = 17; int Arg2 = 87654321; string Arg3 = "140=40+31+15+15+9+7+4+4+2+2+2+2+2+2+1+1+1"; verify_case(5, Arg3, kthElement(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    FixedSizeSums ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
