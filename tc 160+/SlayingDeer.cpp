#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class SlayingDeer {
	public:
	int getTime(int A, int B, int C) {
		if (30*B - 45*A >= 0)
			return -1;

		int t = 0;
		int a = 0;
		int b = C;
		while (a < b) {
			if (a + 30*A >= b + 30*B)
				return t + (b-a + A-B-1)/(A-B);
			t += 30;
			a += 30*A;
			b += 30*B;
			if (a + 15*A >= b)
				return t + (b-a + A-1)/A;
			t += 15;
			a += 15*A;
			b = b-a;
			a = 0;
		}
		return t;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 4; int Arg2 = 20; int Arg3 = 20; verify_case(0, Arg3, getTime(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 4; int Arg2 = 47; int Arg3 = 34; verify_case(1, Arg3, getTime(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 17; int Arg2 = 1; int Arg3 = -1; verify_case(2, Arg3, getTime(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 133; int Arg1 = 198; int Arg2 = 7515; int Arg3 = 7515; verify_case(3, Arg3, getTime(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 1; int Arg1 = 1000; int Arg2 = 15819; int Arg3 = -1; verify_case(4, Arg3, getTime(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    SlayingDeer ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
