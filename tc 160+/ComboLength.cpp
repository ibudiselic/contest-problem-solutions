#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class ComboLength {
	public:
	int howLong(string moves) {
		int a = 0;
		string s = "A";
		while (moves.find(s) != string::npos) {
			++a;
			s += 'A';
		}

		int b = a;
		s = string(b+1, 'B');
		while (moves.find(s) != string::npos) {
			++b;
			s += 'B';
		}

		return b;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "AAA"; int Arg1 = 3; verify_case(0, Arg1, howLong(Arg0)); }
	void test_case_1() { string Arg0 = "AAABBBBAA"; int Arg1 = 4; verify_case(1, Arg1, howLong(Arg0)); }
	void test_case_2() { string Arg0 = "BBAABBAABBAABBAA"; int Arg1 = 2; verify_case(2, Arg1, howLong(Arg0)); }
	void test_case_3() { string Arg0 = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"; int Arg1 = 50; verify_case(3, Arg1, howLong(Arg0)); }
	void test_case_4() { string Arg0 = "AAAAAAAAAAAAAAAAAAAAAAAAABAAAAAAAAAAAAAAAAAAAAAAAA"; int Arg1 = 25; verify_case(4, Arg1, howLong(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ComboLength ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
