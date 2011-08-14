#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

class NumberGuesser {
	public:
	bool matches(int x, int y) {
		if (x==y) return false;
		vector<int> xx(9, 0);
		vector<int> yy(9, 0);

		while (x) {
			++xx[x%10];
			x /= 10;
		}
		while (y) {
			++yy[y%10];
			y /= 10;
		}
		return xx==yy;
	}
	int guess(string leftOver) {
		for (int i=1; i<=9; ++i)
			for (int pos=0; pos<3; ++pos) {
				string s = leftOver.substr(0, pos) + char(i+'0') + leftOver.substr(pos);
				int t = atoi(s.c_str());
				for (int j=1; j<=4999; ++j)
					if (matches(j, t+j))
						return i;
			}

		return -1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "087"; int Arg1 = 3; verify_case(0, Arg1, guess(Arg0)); }
	void test_case_1() { string Arg0 = "099"; int Arg1 = 9; verify_case(1, Arg1, guess(Arg0)); }
	void test_case_2() { string Arg0 = "191"; int Arg1 = 7; verify_case(2, Arg1, guess(Arg0)); }
	void test_case_3() { string Arg0 = "689"; int Arg1 = 4; verify_case(3, Arg1, guess(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    NumberGuesser ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
