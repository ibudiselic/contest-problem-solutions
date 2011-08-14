#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class RugSizes {
	public:
	int rugCount(int area) {
		int sol = 0;
		for (int a=1; a<=area; ++a) {
			if (area%a != 0)
				continue;
			if (area/a < a)
				break;
			if (area/a %2==0 && a%2==0 && a*a!=area)
				continue;
			++sol;
		}
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 2; verify_case(0, Arg1, rugCount(Arg0)); }
	void test_case_1() { int Arg0 = 8; int Arg1 = 1; verify_case(1, Arg1, rugCount(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    RugSizes ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
