#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int A[50][50];
class SkewSymmetric {
	public:
	int minChanges(vector <string> M) {
		int sol = 0;
		int n = M.size();
		for (int i=0; i<n; ++i) {
			istringstream is(M[i]);
			for (int j=0; j<n; ++j)
				is >> A[i][j];
		}
		for (int i=0; i<n; ++i) {
			sol += (A[i][i]!=0);
			for (int j=i+1; j<n; ++j)
				sol += (A[i][j] != -A[j][i]);
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"1 2 8", "-2 1 0", "3 99 3"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(0, Arg1, minChanges(Arg0)); }
	void test_case_1() { string Arr0[] = {"0 1 1 1 1 1", "-1 0 1 1 1 1", "-1 -1 0 1 1 1",
"-1 -1 -1 0 1 1", "-1 -1 -1 -1 0 1", "0 0 0 0 0 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(1, Arg1, minChanges(Arg0)); }
	void test_case_2() { string Arr0[] = {"0 0 0 0", "0 0 0 0", "0 0 0 0", "0 0 0 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, minChanges(Arg0)); }
	void test_case_3() { string Arr0[] = {"1 0", "0 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(3, Arg1, minChanges(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    SkewSymmetric ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
