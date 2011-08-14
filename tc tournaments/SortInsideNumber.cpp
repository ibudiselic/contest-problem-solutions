#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <functional>

using namespace std;

class SortInsideNumber {
	public:
	int sort(int x) {
		ostringstream os;
		os << x;
		string s = os.str();
		::sort(s.begin(), s.end(), greater<char>());
		istringstream is(s);
		is >> x;

		return x;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2143; int Arg1 = 4321; verify_case(0, Arg1, sort(Arg0)); }
	void test_case_1() { int Arg0 = 999998999; int Arg1 = 999999998; verify_case(1, Arg1, sort(Arg0)); }
	void test_case_2() { int Arg0 = 61423; int Arg1 = 64321; verify_case(2, Arg1, sort(Arg0)); }
	void test_case_3() { int Arg0 = 500613009; int Arg1 = 965310000; verify_case(3, Arg1, sort(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    SortInsideNumber ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
