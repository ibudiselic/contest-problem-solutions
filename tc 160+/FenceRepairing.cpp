#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <numeric>
#include <cmath>
using namespace std;

double dp[2500];
class FenceRepairing {
	public:
	double calculateCost(vector <string> boards) {
		string s = accumulate(boards.begin(), boards.end(), string());
		const int n = s.size();

		dp[0] = (s[0]=='X');

		for (int i=1; i<n; ++i) {
			if (s[i] == '.') {
				dp[i] = dp[i-1];
			} else {
				dp[i] = sqrt(i+1);
				for (int j=0; j<i; ++j)
					if (s[j+1] == 'X')
						dp[i] = min(dp[i], dp[j]+sqrt(i-j));
			}
		}

		return dp[n-1];
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"X.X...X.X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 3.0; verify_case(0, Arg1, calculateCost(Arg0)); }
	void test_case_1() { string Arr0[] = {"X.X.....X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 2.732050807568877; verify_case(1, Arg1, calculateCost(Arg0)); }
	void test_case_2() { string Arr0[] = {"X.......", "......XX", ".X......", ".X...X.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 5.0; verify_case(2, Arg1, calculateCost(Arg0)); }
	void test_case_3() { string Arr0[] = {".X.......X", "..........", "...X......", "...X..X...", "..........",
 "..........", "..X....XX.", ".........X", "XXX", ".XXX.....X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 9.591663046625438; verify_case(3, Arg1, calculateCost(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    FenceRepairing ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
