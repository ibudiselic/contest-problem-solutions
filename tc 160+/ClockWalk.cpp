#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class ClockWalk {
	public:
	int finalPosition(string flips) {
		int cur = 0;
		for (int i=0; i<(int)flips.size(); ++i)
			if (flips[i]=='h')
				cur = (cur+i+1)%12;
			else {
				cur -= i+1;
				if (cur < 0) {
					int t = -cur;
					t %= 12;
					cur = 12 - t;
				}
			}
		return cur==0 ? 12:cur;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "hhthh"; int Arg1 = 9; verify_case(0, Arg1, finalPosition(Arg0)); }
	void test_case_1() { string Arg0 = "hhtht"; int Arg1 = 11; verify_case(1, Arg1, finalPosition(Arg0)); }
	void test_case_2() { string Arg0 = "hthth"; int Arg1 = 3; verify_case(2, Arg1, finalPosition(Arg0)); }
	void test_case_3() { string Arg0 = "hthhhhh"; int Arg1 = 12; verify_case(3, Arg1, finalPosition(Arg0)); }
	void test_case_4() { string Arg0 = "hthhthtththhtttthttthhhthtttthh"; int Arg1 = 6; verify_case(4, Arg1, finalPosition(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ClockWalk ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
