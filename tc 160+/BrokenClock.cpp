#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class BrokenClock {
	public:
	int fewestClicks(string clockTime, string currentTime) {
		int h = (currentTime[0]-'0')*10 + (currentTime[1]-'0');
		int m = (currentTime[3]-'0')*10 + (currentTime[4]-'0');

		int H = (clockTime[0]-'0')*10 + (clockTime[1]-'0');
		int M = (clockTime[3]-'0')*10 + (clockTime[4]-'0');

		int sol = 0;
		while (H != h) {
			H = (H+1)%24;
			M = (M+1)%60;
			++sol;
		}
		while (M != m) {
			M = (M+1)%60;
			++sol;
		}
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "03:12"; string Arg1 = "04:15"; int Arg2 = 3; verify_case(0, Arg2, fewestClicks(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "07:07"; string Arg1 = "13:21"; int Arg2 = 14; verify_case(1, Arg2, fewestClicks(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "14:55"; string Arg1 = "14:05"; int Arg2 = 10; verify_case(2, Arg2, fewestClicks(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "23:14"; string Arg1 = "00:20"; int Arg2 = 6; verify_case(3, Arg2, fewestClicks(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "18:43"; string Arg1 = "18:43"; int Arg2 = 0; verify_case(4, Arg2, fewestClicks(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    BrokenClock ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
