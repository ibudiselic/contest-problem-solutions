#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class InsideOut {
	public:
	string unscramble(string line) {
		string left = line.substr(0, line.size()/2);
		string right = line.substr(line.size()/2);

		reverse(left.begin(), left.end());
		reverse(right.begin(), right.end());

		return left + right;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "I ENIL SIHTHSIREBBIG S"; string Arg1 = "THIS LINE IS GIBBERISH"; verify_case(0, Arg1, unscramble(Arg0)); }
	void test_case_1() { string Arg0 = "LEVELKAYAK"; string Arg1 = "LEVELKAYAK"; verify_case(1, Arg1, unscramble(Arg0)); }
	void test_case_2() { string Arg0 = "H YPPAHSYADILO"; string Arg1 = "HAPPY HOLIDAYS"; verify_case(2, Arg1, unscramble(Arg0)); }
	void test_case_3() { string Arg0 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; string Arg1 = "MLKJIHGFEDCBAZYXWVUTSRQPON"; verify_case(3, Arg1, unscramble(Arg0)); }
	void test_case_4() { string Arg0 = "RUT OWT SNEH HCNERF EERHTEGDIRTRAP A DNA  SEVODELT"; string Arg1 = "THREE FRENCH HENS TWO TURTLEDOVES  AND A PARTRIDGE"; verify_case(4, Arg1, unscramble(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    InsideOut ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
