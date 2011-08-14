#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class Chocolate {
	public:
	int minSplitNumber(int width, int height, int nTiles) {
		long long area = (long long)width*height;

		if (area < nTiles)
			return -1;
		else if (area == nTiles)
			return 0;
		else if (nTiles%width==0 || nTiles%height==0)
			return 1;

		for (long long a=1; a*a<=nTiles && a<min(width, height); ++a)
			if (nTiles%a==0 && nTiles/a<max(width, height))
				return 2;

		return -1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 4; int Arg2 = 12; int Arg3 = 1; verify_case(0, Arg3, minSplitNumber(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 12; int Arg1 = 10; int Arg2 = 120; int Arg3 = 0; verify_case(1, Arg3, minSplitNumber(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 1; int Arg3 = 2; verify_case(2, Arg3, minSplitNumber(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 17; int Arg1 = 19; int Arg2 = 111; int Arg3 = -1; verify_case(3, Arg3, minSplitNumber(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Chocolate ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
