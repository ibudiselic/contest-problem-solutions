#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class CultureShock {
	public:
	string translate(string text) {
		istringstream is(text);
		string sol;
		string w;
		while (is >> w) {
			if (w == "ZEE")
				sol += "ZED ";
			else
				sol += w + ' ';
		}

		return sol.substr(0, sol.size()-1);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "THE TWENTY SIXTH LETTER OF THE ALPHABET IS ZEE"; string Arg1 = "THE TWENTY SIXTH LETTER OF THE ALPHABET IS ZED"; verify_case(0, Arg1, translate(Arg0)); }
	void test_case_1() { string Arg0 = "ZEE"; string Arg1 = "ZED"; verify_case(1, Arg1, translate(Arg0)); }
	void test_case_2() { string Arg0 = "SPELLING IN ENGLISH IS EZEE"; string Arg1 = "SPELLING IN ENGLISH IS EZEE"; verify_case(2, Arg1, translate(Arg0)); }
	void test_case_3() { string Arg0 = "ZEE ZEE ZED ZEDS ZEE ZEES"; string Arg1 = "ZED ZED ZED ZEDS ZED ZEES"; verify_case(3, Arg1, translate(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    CultureShock ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
