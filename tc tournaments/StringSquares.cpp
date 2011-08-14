#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <set>
using namespace std;

bool is_square(const string &s) {
	return s.substr(0, s.size()/2) == s.substr(s.size()/2);
}
class StringSquares {
	public:
	int count(string s) {
		set<string> sol;

		for (int i=0; i<(int)s.size(); ++i)
			for (int j=2; i+j<=(int)s.size(); j+=2)
				if (is_square(s.substr(i, j)))
					sol.insert(s.substr(i, j));

		return sol.size();
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "aaabccabccCC"; int Arg1 = 4; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { string Arg0 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"; int Arg1 = 21; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { string Arg0 = "cc"; int Arg1 = 1; verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { string Arg0 = "B"; int Arg1 = 0; verify_case(3, Arg1, count(Arg0)); }
	void test_case_4() { string Arg0 = "ABCDABCDabcdabcdABCDABCDabcdabcd"; int Arg1 = 3; verify_case(4, Arg1, count(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    StringSquares ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
