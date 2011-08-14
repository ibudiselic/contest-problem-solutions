#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class DivisibilityRules {
	public:
	int similar(int B, int div) {
		int sol = 0;
		vector<int> f;
		int d = 1;
		for (int i=0; i<B; ++i) {
			d = (d*B) % div;
			f.push_back(d);
		}

		for (int t=2; t<B; ++t) {
			vector<int> v;
			d = 1;
			for (int i=0; i<B; ++i) {
				d = (d*B) % t;
				v.push_back(d);
			}
			sol += (v == f);
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arg1 = 3; int Arg2 = 2; verify_case(0, Arg2, similar(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 5; int Arg2 = 2; verify_case(1, Arg2, similar(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 511; int Arg1 = 32; int Arg2 = 10; verify_case(2, Arg2, similar(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 1; verify_case(3, Arg2, similar(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 1000; int Arg1 = 999; int Arg2 = 7; verify_case(4, Arg2, similar(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 655; int Arg1 = 532; int Arg2 = 1; verify_case(5, Arg2, similar(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    DivisibilityRules ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
