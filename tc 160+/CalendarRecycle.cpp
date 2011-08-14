#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

inline bool is_leap(int year) {
	return year%4==0 && (year%100 || year%400==0);
}
class CalendarRecycle {
	public:
	int useAgain(int year) {
		int sol = year;
		int days = 0;

		do {
			days %= 7;
			++days;
			days += is_leap(sol);
			++sol;
		} while (days!=7 || is_leap(year)!=is_leap(sol));

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2002; int Arg1 = 2013; verify_case(0, Arg1, useAgain(Arg0)); }
	void test_case_1() { int Arg0 = 2013; int Arg1 = 2019; verify_case(1, Arg1, useAgain(Arg0)); }
	void test_case_2() { int Arg0 = 2008; int Arg1 = 2036; verify_case(2, Arg1, useAgain(Arg0)); }
	void test_case_3() { int Arg0 = 9999; int Arg1 = 10010; verify_case(3, Arg1, useAgain(Arg0)); }
	void test_case_4() { int Arg0 = 2525; int Arg1 = 2531; verify_case(4, Arg1, useAgain(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    CalendarRecycle ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
