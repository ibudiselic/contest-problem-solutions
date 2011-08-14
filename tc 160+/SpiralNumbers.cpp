#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class SpiralNumbers {
	public:
	string getPosition(int N) {
		if (N == 1)
			return "(0,0)";
		int i = 0;
		for (i=1; ; ++i)
			if ((long long)(2*i+1)*(2*i+1) >= N)
				break;

		N -= (2*(i-1)+1)*(2*(i-1)+1);
		const int d = 2*i;
		int side = N/d;
		N -= side*d;

		int r = 0;
		int c = 0;
		if (side == 0) {
			c = i;
			r = N-i;
		} else if (side == 1) {
			r = i;
			c = i-N;
		} else if (side == 2) {
			c = -i;
			r = i-N;
		} else if (side == 3) {
			r = -i;
			c = N-i;
		} else {
			r = -i;
			c = i;
		}

		ostringstream os;
		os << '(' << r << ',' << c << ')';
		return os.str();
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; string Arg1 = "(0,1)"; verify_case(0, Arg1, getPosition(Arg0)); }
	void test_case_1() { int Arg0 = 3; string Arg1 = "(1,1)"; verify_case(1, Arg1, getPosition(Arg0)); }
	void test_case_2() { int Arg0 = 7; string Arg1 = "(-1,-1)"; verify_case(2, Arg1, getPosition(Arg0)); }
	void test_case_3() { int Arg0 = 17; string Arg1 = "(2,-2)"; verify_case(3, Arg1, getPosition(Arg0)); }
	void test_case_4() { int Arg0 = 24; string Arg1 = "(-2,1)"; verify_case(4, Arg1, getPosition(Arg0)); }
	void test_case_5() { int Arg0 = 830; string Arg1 = "(-14,3)"; verify_case(5, Arg1, getPosition(Arg0)); }
	void test_case_6() { int Arg0 = 765409; string Arg1 = "(-437,221)"; verify_case(6, Arg1, getPosition(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    SpiralNumbers ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
