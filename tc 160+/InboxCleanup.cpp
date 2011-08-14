#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class InboxCleanup {
	public:
	int fewestClicks(string messages, int low, int high) {
		int best = 1234567890;

		for (int sz=low; sz<=high; ++sz) {
			int cur = 0;
			for (int k=0; k<(int)messages.size()/sz; ++k) {
				int del = 0;
				for (int m=0; m<sz; ++m)
					del += (messages[k*sz + m] == 'D');
				cur += min(del, sz-del+1) + (k>0) + (del>0);
			}
			if ((int)messages.size()%sz != 0) {
				const int k = (int)messages.size()/sz;
				int del = 0;
				for (int m=0; k*sz+m < (int)messages.size(); ++m)
					del += (messages[k*sz + m] == 'D');
				cur += min(del, (int)messages.size()%sz-del+1) + (k>0) + (del>0);
			}
			best = min(best, cur);
		}
		return best;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = ".........."; int Arg1 = 5; int Arg2 = 10; int Arg3 = 0; verify_case(0, Arg3, fewestClicks(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = ".D.D.DD.D."; int Arg1 = 5; int Arg2 = 5; int Arg3 = 8; verify_case(1, Arg3, fewestClicks(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "...D..DDDDDD...D.DD.."; int Arg1 = 3; int Arg2 = 10; int Arg3 = 12; verify_case(2, Arg3, fewestClicks(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "D.D..D..DD.DDDD.D.DDD.DDDD.."; int Arg1 = 3; int Arg2 = 11; int Arg3 = 17; verify_case(3, Arg3, fewestClicks(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "DDD........................."; int Arg1 = 1; int Arg2 = 3; int Arg3 = 11; verify_case(4, Arg3, fewestClicks(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    InboxCleanup ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
