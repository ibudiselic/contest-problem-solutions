#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool win(const string &s, int x) {
	int r = 0, b = 0;
	for (int i=x; i<(int)s.size(); ++i) {
		if (s[i] == 'R')
			++r;
		else
			++b;

		if (r > b)
			return false;
	}
	for (int i=0; i<x; ++i) {
		if (s[i] == 'R')
			++r;
		else
			++b;

		if (r > b)
			return false;
	}

	return true;
}
class BlackAndRed {
	public:
	int cut(string deck) {
		for (int sol=0; sol<(int)deck.size(); ++sol)
			if (win(deck, sol))
				return sol;

		return -1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "BRBRBR"; int Arg1 = 0; verify_case(0, Arg1, cut(Arg0)); }
	void test_case_1() { string Arg0 = "RBRBRB"; int Arg1 = 1; verify_case(1, Arg1, cut(Arg0)); }
	void test_case_2() { string Arg0 = "BBBRRRRB"; int Arg1 = 7; verify_case(2, Arg1, cut(Arg0)); }
	void test_case_3() { string Arg0 = "BR"; int Arg1 = 0; verify_case(3, Arg1, cut(Arg0)); }
	void test_case_4() { string Arg0 = "RBRBBRRRRBBBRBBRRBRBBRRRBRBBBRBRBRBRBRRB"; int Arg1 = 9; verify_case(4, Arg1, cut(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    BlackAndRed ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
