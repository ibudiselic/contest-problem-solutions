#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class SlowKeyboard {
	public:
	void advance(int &m, int &s, int c) {
		if (s+c >= 60) {
			if (m == 59) {
				m = 0;
			} else {
				m = m+1;
			}
			s = (s+c)%60;
		} else {
			s += c;
		}
	}
	int type(int m, int s) {
		int ret = 1;
		if (m%10 != m/10)
			ret += 2;
		++ret;
		if (m%10 != s/10)
			ret += 2;
		++ret;
		if (s/10 != s%10)
			ret += 2;
		++ret;
		return ret;
	}
	int enterTime(string time) {
		int m, s;
		char c;
		istringstream is(time);
		is >> m >> c >> s;

		int sol = 1000;
		advance(m, s, 3);
		for (int t=4; t<=10; ++t) {
			advance(m, s, 1);
			const int v = type(m, s);
			if (v <= t)
				sol = min(sol, t);
		}
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "59:56"; int Arg1 = 4; verify_case(0, Arg1, enterTime(Arg0)); }
	void test_case_1() { string Arg0 = "59:59"; int Arg1 = 6; verify_case(1, Arg1, enterTime(Arg0)); }
	void test_case_2() { string Arg0 = "33:12"; int Arg1 = 8; verify_case(2, Arg1, enterTime(Arg0)); }
	void test_case_3() { string Arg0 = "16:35"; int Arg1 = 9; verify_case(3, Arg1, enterTime(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    SlowKeyboard ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
