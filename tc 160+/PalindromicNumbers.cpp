#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

long long to_ll(const string &s) {
	long long ret;
	istringstream(s) >> ret;
	return ret;
}
string palin(long long x, bool odd) {
	ostringstream os;
	os << x;
	if (odd) x /= 10;
	if (x == 0) return "0";
	ostringstream os1;
	os1 << x;
	string t = os1.str();
	reverse(t.begin(), t.end());
	return os.str() + t;
}
class PalindromicNumbers {
	public:
	int countPalNums(long long lower, long long upper) {
		int sol = 0;
		for (int i=1; i<10; ++i)
			sol += (lower<=i && i<=upper);
		for (int i=1; i<100000; ++i) {
			long long p = to_ll(palin(i, 0));
			sol += (lower<=p && p<=upper);
			p = to_ll(palin(i, 1));
			sol += (lower<=p && p<=upper);
		}
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 8; int Arg1 = 25; int Arg2 = 4; verify_case(0, Arg2, countPalNums(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 111; int Arg1 = 222; int Arg2 = 12; verify_case(1, Arg2, countPalNums(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 88966989; int Arg1 = 88977987; int Arg2 = 0; verify_case(2, Arg2, countPalNums(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 999999990; int Arg1 = 1000000000; int Arg2 = 1; verify_case(3, Arg2, countPalNums(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    PalindromicNumbers ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
