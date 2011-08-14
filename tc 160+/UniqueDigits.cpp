#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int f(int x) {
	ostringstream os;
	os << x;
	string s = os.str();
	vector<char> t(s.begin(), s.end());
	sort(t.begin(), t.end());

	return (unique(t.begin(), t.end()) == t.end());
}
class UniqueDigits {
	public:
	int count(int n) {
		int sol = 0;
		for (int x=1; x<n; ++x)
			sol += f(x);

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 21; int Arg1 = 19; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { int Arg0 = 101; int Arg1 = 90; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { int Arg0 = 1001; int Arg1 = 738; verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { int Arg0 = 1; int Arg1 = 0; verify_case(3, Arg1, count(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    UniqueDigits ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
