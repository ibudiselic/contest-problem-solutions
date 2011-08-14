#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class WarCry {
	public:
	int alertTime(string cur) {
		int sol = 0;
		string next = cur;
		while (cur != string(cur.size(), 'x')) {
			++sol;
			for (int i=0; i<(int)cur.size(); ++i)
				if (cur[i] == 'x') {
					if (i > 0)
						next[i-1] = 'x';
					if (i+1 < (int)cur.size())
						next[i+1] = 'x';
				}
			cur.swap(next);
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "-x---x-"; int Arg1 = 2; verify_case(0, Arg1, alertTime(Arg0)); }
	void test_case_1() { string Arg0 = "xx--xx"; int Arg1 = 1; verify_case(1, Arg1, alertTime(Arg0)); }
	void test_case_2() { string Arg0 = "xx----xx"; int Arg1 = 2; verify_case(2, Arg1, alertTime(Arg0)); }
	void test_case_3() { string Arg0 = "xx-------xx"; int Arg1 = 4; verify_case(3, Arg1, alertTime(Arg0)); }
	void test_case_4() { string Arg0 = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"; int Arg1 = 0; verify_case(4, Arg1, alertTime(Arg0)); }
	void test_case_5() { string Arg0 = "x------------------------------------------------x"; int Arg1 = 24; verify_case(5, Arg1, alertTime(Arg0)); }
	void test_case_6() { string Arg0 = "--x----x----x--"; int Arg1 = 2; verify_case(6, Arg1, alertTime(Arg0)); }
	void test_case_7() { string Arg0 = "x"; int Arg1 = 0; verify_case(7, Arg1, alertTime(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    WarCry ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
