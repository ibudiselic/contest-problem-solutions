#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class ZCurve {
	public:
	int zValue(int N, int r, int c) {
		if (N == 1)
			return r*2 + c;

		int cnt = 1<<(N-1);
		if (r < cnt) {
			if (c < cnt)
				return zValue(N-1, r, c);
			else
				return cnt*cnt + zValue(N-1, r, c-cnt);
		} else {
			if (c < cnt)
				return 2*cnt*cnt + zValue(N-1, r-cnt, c);
			else
				return 3*cnt*cnt + zValue(N-1, r-cnt, c-cnt);
		}
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 3; int Arg2 = 1; int Arg3 = 11; verify_case(0, Arg3, zValue(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 0; int Arg2 = 0; int Arg3 = 0; verify_case(1, Arg3, zValue(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 7; int Arg2 = 7; int Arg3 = 63; verify_case(2, Arg3, zValue(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 7; int Arg2 = 7; int Arg3 = 63; verify_case(3, Arg3, zValue(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 10; int Arg1 = 511; int Arg2 = 511; int Arg3 = 262143; verify_case(4, Arg3, zValue(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 10; int Arg1 = 512; int Arg2 = 512; int Arg3 = 786432; verify_case(5, Arg3, zValue(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ZCurve ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
