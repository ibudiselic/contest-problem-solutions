#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int my_round(double x) {
	return (int)(x+0.5);
}
class FastSpider {
	public:
	int findTime(double spiderSpeed, double manSpeed) {
		double x = exp(manSpeed/spiderSpeed) - 1;
		if (x < 0)
			return -1;
		else
			return my_round(x/manSpeed);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { double Arg0 = 0.25; double Arg1 = 1; int Arg2 = 54; verify_case(0, Arg2, findTime(Arg0, Arg1)); }
	void test_case_1() { double Arg0 = 0.5; double Arg1 = 1; int Arg2 = 6; verify_case(1, Arg2, findTime(Arg0, Arg1)); }
	void test_case_2() { double Arg0 = 0.5; double Arg1 = 4.8877377; int Arg2 = 3600; verify_case(2, Arg2, findTime(Arg0, Arg1)); }
	void test_case_3() { double Arg0 = 0.2; double Arg1 = 1; int Arg2 = 147; verify_case(3, Arg2, findTime(Arg0, Arg1)); }
	void test_case_4() { double Arg0 = 0.47; double Arg1 = 2.78; int Arg2 = 133; verify_case(4, Arg2, findTime(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    FastSpider ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
