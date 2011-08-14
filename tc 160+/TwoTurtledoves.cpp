#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int val(int n) {
	return n*(n+1)/2;
}
class TwoTurtledoves {
	public:
	int presentType(int n) {
		int cnt = 0;
		int day = 1;
		int t = 0;
		while (cnt+(t=val(day)) < n) {
			cnt += t;
			++day;
		}

		n -= cnt;
		while (day--) {
			if (n <= (day+1))
				return day+1;
			n -= day+1;
		}

		return -1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arg1 = 1; verify_case(0, Arg1, presentType(Arg0)); }
	void test_case_1() { int Arg0 = 12; int Arg1 = 4; verify_case(1, Arg1, presentType(Arg0)); }
	void test_case_2() { int Arg0 = 399; int Arg1 = 11; verify_case(2, Arg1, presentType(Arg0)); }
	void test_case_3() { int Arg0 = 123456; int Arg1 = 65; verify_case(3, Arg1, presentType(Arg0)); }
	void test_case_4() { int Arg0 = 1000000000; int Arg1 = 1704; verify_case(4, Arg1, presentType(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    TwoTurtledoves ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
