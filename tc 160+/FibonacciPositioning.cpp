#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class FibonacciPositioning {
	public:
	double getFPosition(int n) {
		int x=0;
		int y=1;
		int cnt=0;

		while (1) {
			y += x;
			x = y-x;
			++cnt;
			if (x == n)
				return cnt==1 ? 2:cnt;
			else if (x<n && n<y)
				return cnt+double(n-x)/(y-x);
		}
		return -1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; double Arg1 = 2.0; verify_case(0, Arg1, getFPosition(Arg0)); }
	void test_case_1() { int Arg0 = 5; double Arg1 = 5.0; verify_case(1, Arg1, getFPosition(Arg0)); }
	void test_case_2() { int Arg0 = 4; double Arg1 = 4.5; verify_case(2, Arg1, getFPosition(Arg0)); }
	void test_case_3() { int Arg0 = 100; double Arg1 = 11.2; verify_case(3, Arg1, getFPosition(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    FibonacciPositioning ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
