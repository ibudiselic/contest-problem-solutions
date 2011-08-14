#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class BettingStrategy {
	public:
	int finalSum(int cur, string outcome) {
		int bet = 1;
		for (int i=0; i<(int)outcome.size(); ++i) {
			if (bet > cur)
				break;
			if (outcome[i] == 'W') {
				cur += bet;
				bet = 1;
			} else {
				cur -= bet;
				bet *= 2;
			}
		}

		return cur;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 12; string Arg1 = "WWWWWWWW"; int Arg2 = 20; verify_case(0, Arg2, finalSum(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 15; string Arg1 = "LLLWLLLL"; int Arg2 = 1; verify_case(1, Arg2, finalSum(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 20; string Arg1 = "WLWLWLWL"; int Arg2 = 23; verify_case(2, Arg2, finalSum(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 925; string Arg1 = "WLLLLLWLLLLLLWWWWWLWLLWLLLLLLWL"; int Arg2 = 934; verify_case(3, Arg2, finalSum(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    BettingStrategy ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
