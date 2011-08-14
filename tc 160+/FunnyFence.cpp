#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class FunnyFence {
	public:
	int getLength(string s) {
		int sol = 0;
		int cur = 0;
		char last = (s[0]=='-' ? '|':'-');
		for (int i=0; i<(int)s.size(); ++i) {
			if (s[i] == last) {
				sol = max(sol, cur);
				cur = 1;
			} else {
				last = s[i];
				++cur;
			}
		}
		return max(sol, cur);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "|-|-|"; int Arg1 = 5; verify_case(0, Arg1, getLength(Arg0)); }
	void test_case_1() { string Arg0 = "-|-|-|-"; int Arg1 = 7; verify_case(1, Arg1, getLength(Arg0)); }
	void test_case_2() { string Arg0 = "||||||"; int Arg1 = 1; verify_case(2, Arg1, getLength(Arg0)); }
	void test_case_3() { string Arg0 = "|-||-|-"; int Arg1 = 4; verify_case(3, Arg1, getLength(Arg0)); }
	void test_case_4() { string Arg0 = "|-|---|-|---|-|"; int Arg1 = 5; verify_case(4, Arg1, getLength(Arg0)); }
	void test_case_5() { string Arg0 = "|||-||--|--|---|-||-|-|-|--||---||-||-||-|--||"; int Arg1 = 8; verify_case(5, Arg1, getLength(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    FunnyFence ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
