#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class FryingHamburgers {
	public:
	int howLong(int panSize, int hamburgers) {
		int raw, half, fried;
		int t = 0;

		half = fried = 0;
		raw = hamburgers;

		while (fried != hamburgers) {
			int free = panSize;
			int nh, nf;
			t += 5;
			if (raw < free) {
				free -= raw;
				nh = raw;
				raw = 0;
			} else {
				raw -= free;
				nh = free;
				free = 0;
			}
			if (half < free) {
				free -= half;
				nf = half;
				half = 0;
			} else {
				half -= free;
				nf = free;
				free = 0;
			}
			half += nh;
			fried += nf;
		}
		return t;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 3; int Arg2 = 15; verify_case(0, Arg2, howLong(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 4; int Arg2 = 15; verify_case(1, Arg2, howLong(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 10; verify_case(2, Arg2, howLong(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 100; int Arg1 = 0; int Arg2 = 0; verify_case(3, Arg2, howLong(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 303; int Arg1 = 919; int Arg2 = 35; verify_case(4, Arg2, howLong(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    FryingHamburgers ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
