#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Snowflakes {
	public:
	vector <string> flareOut(vector <string> snowflake) {
		int n = snowflake.size();
		vector<string> sol(n, string(n, '-'));
		for (int i=0; i<n; ++i)
			for (int j=0; j<n; ++j)
				if (j<=i)
					sol[i][j] = snowflake[i][j];
				else
					sol[i][j] = snowflake[j][i];

		vector<string> t;
		for (int i=n-1; i>=0; --i)
			t.push_back(sol[i]);
		for (int i=0; i<n; ++i)
			t.push_back(sol[i]);
		sol.assign(2*n, string(2*n, '-'));
		for (int i=0; i<2*n; ++i) {
			for (int j=n-1; j>=0; --j)
				sol[i][n-1-j] = t[i][j];
			for (int j=0; j<n; ++j)
				sol[i][j+n] = t[i][j];
		}
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {".",
 "..",
 "*.*"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"*.**.*", "......", "*....*", "*....*", "......", "*.**.*" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, flareOut(Arg0)); }
	void test_case_1() { string Arr0[] = {"*",
 "..",
 ".*.",
 ".**.",
 ".*.**"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"**.*..*.**", "*.**..**.*", ".*.*..*.*.", "***....***", "....**....", "....**....", "***....***", ".*.*..*.*.", "*.**..**.*", "**.*..*.**" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, flareOut(Arg0)); }
	void test_case_2() { string Arr0[] = {".",
 "..",
 "***"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"******", "*....*", "*....*", "*....*", "*....*", "******" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, flareOut(Arg0)); }
	void test_case_3() { string Arr0[] = {"*",
 ".*",
 "***"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"******", "**..**", "*.**.*", "*.**.*", "**..**", "******" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, flareOut(Arg0)); }
	void test_case_4() { string Arr0[] = {".",
 "..",
 "***",
 "...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"........", ".******.", ".*....*.", ".*....*.", ".*....*.", ".*....*.", ".******.", "........" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, flareOut(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Snowflakes ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
