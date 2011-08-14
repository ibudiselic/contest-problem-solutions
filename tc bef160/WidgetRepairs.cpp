#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class WidgetRepairs {
	public:
	int days(vector <int> arrivals, int numPerDay) {
		int sol, cur;
		sol = cur = 0;
		for (int i=0; i<(int)arrivals.size(); ++i) {
			cur += arrivals[i];
			if (cur > 0) {
				cur = ::max(0, cur-numPerDay);
				++sol;
			}
		}
		return sol + cur/numPerDay + ((cur%numPerDay == 0) ? (0):(1));
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 10, 0, 0, 4, 20 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; int Arg2 = 6; verify_case(0, Arg2, days(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = { 0, 0, 0 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 0; verify_case(1, Arg2, days(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = { 100, 100 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 20; verify_case(2, Arg2, days(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = { 27, 0, 0, 0, 0, 9 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; int Arg2 = 4; verify_case(3, Arg2, days(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = { 6, 5, 4, 3, 2, 1, 0, 0, 1, 2, 3, 4, 5, 6 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 15; verify_case(4, Arg2, days(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    WidgetRepairs ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
