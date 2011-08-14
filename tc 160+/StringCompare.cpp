#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class StringCompare {
	public:
	int simpleDifference(string a, string b) {
		int sol = 0;
		for (int i=0; i<(int)min(a.size(), b.size()); ++i)
			sol += (a[i] == b[i]);

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "TICK"; string Arg1 = "TOCK"; int Arg2 = 3; verify_case(0, Arg2, simpleDifference(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "CAT"; string Arg1 = "DOG"; int Arg2 = 0; verify_case(1, Arg2, simpleDifference(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "APPLE"; string Arg1 = "APPLES"; int Arg2 = 5; verify_case(2, Arg2, simpleDifference(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "FANTASTIC"; string Arg1 = "ANTASTIC"; int Arg2 = 0; verify_case(3, Arg2, simpleDifference(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "ANTIDISESTABLISHMENTARIANISM"; string Arg1 = "FLOCCIPAUCINIHILIPIFICATION"; int Arg2 = 1; verify_case(4, Arg2, simpleDifference(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    StringCompare ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
