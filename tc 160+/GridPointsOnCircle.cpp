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

long long R;
int calc(long long x) {
	if (x*x > R)
		return -1;

	const long long x2 = x*x;
	long long y = (long long)sqrt(R-x2) - 10;

	for (int i=0; i<20; ++i, ++y) {
		if (y < 0)
			continue;
		if (x2 + y*y > R)
			break;
		if (x2 + y*y == R)
			return 1;
	}

	return 0;
}
class GridPointsOnCircle {
	public:
	int countPoints(int rSquare) {
		R = rSquare;
		int ret = 0;
		for (long long x=1; ; ++x) {
			int t = calc(x);
			if (t == -1)
				break;
			ret += t;
		}

		return 4*ret;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 4; verify_case(0, Arg1, countPoints(Arg0)); }
	void test_case_1() { int Arg0 = 25; int Arg1 = 12; verify_case(1, Arg1, countPoints(Arg0)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 0; verify_case(2, Arg1, countPoints(Arg0)); }
	void test_case_3() { int Arg0 = 44; int Arg1 = 0; verify_case(3, Arg1, countPoints(Arg0)); }
	void test_case_4() { int Arg0 = 50; int Arg1 = 12; verify_case(4, Arg1, countPoints(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    GridPointsOnCircle ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
