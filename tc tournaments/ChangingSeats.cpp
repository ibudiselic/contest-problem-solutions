#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class ChangingSeats {
	public:
	int getDistance(string ss) {
		int sol = 1234567890;

		int cnt = count(ss.begin(), ss.end(), 'X');

		for (int start=0; start+cnt<=(int)ss.size(); ++start) {
			int cur = 0;
			string s = ss;
			for (int i=0; i<cnt; ++i) {
				int j = 0;
				for (; s[j]=='.'; ++j)
					;
				cur += abs(j-(start+i));
				s[j] = '.';
			}
			sol = min(sol, cur);
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "X.X"; int Arg1 = 1; verify_case(0, Arg1, getDistance(Arg0)); }
	void test_case_1() { string Arg0 = "X.X.XXX"; int Arg1 = 3; verify_case(1, Arg1, getDistance(Arg0)); }
	void test_case_2() { string Arg0 = "....X.X.X.X.XXXXX"; int Arg1 = 10; verify_case(2, Arg1, getDistance(Arg0)); }
	void test_case_3() { string Arg0 = ".XXXXX..........X.X.XX......X.XX...."; int Arg1 = 81; verify_case(3, Arg1, getDistance(Arg0)); }
	void test_case_4() { string Arg0 = "...................."; int Arg1 = 0; verify_case(4, Arg1, getDistance(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ChangingSeats ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
