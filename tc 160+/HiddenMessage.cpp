#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class HiddenMessage {
	public:
	string getMessage(string text) {
		string sol, w;
		istringstream is(text);
		while (is >> w)
			sol += w[0];

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "compete online design event rating"; string Arg1 = "coder"; verify_case(0, Arg1, getMessage(Arg0)); }
	void test_case_1() { string Arg0 = "  c    o d     e      r    "; string Arg1 = "coder"; verify_case(1, Arg1, getMessage(Arg0)); }
	void test_case_2() { string Arg0 = "round  elimination during  onsite  contest"; string Arg1 = "redoc"; verify_case(2, Arg1, getMessage(Arg0)); }
	void test_case_3() { string Arg0 = " "; string Arg1 = ""; verify_case(3, Arg1, getMessage(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    HiddenMessage ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
