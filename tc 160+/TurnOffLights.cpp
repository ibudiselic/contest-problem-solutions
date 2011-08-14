#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int memo[1u<<16][32];
class TurnOffLights {
	public:
	int go(unsigned state, int start) {
		if (state == 0) return 0;
		if (start >= 32) return 1000000000;
		if (memo[state][start] != 0) return memo[state][start];

		int ret = 1000000000;
		for (int i=start; i<32; ++i) {
			const int x = i/2;
			const bool around = (i%2 == 0);
			unsigned next = state;
			next = next ^ (1<<x);
			if (around) {
				if (x%4 != 3) next = next ^ (1<<(x+1));
				if (x%4 != 0) next = next ^ (1<<(x-1));
				if (x > 3) next = next ^ (1<<(x-4));
				if (x < 12) next = next ^ (1<<(x+4));
			}
			ret = min(ret, go(next, i+1)+2-around);
		}
		return memo[state][start] = ret;
	}
	int fewestMoves(vector <string> board) {
		memset(memo, 0, sizeof memo);
		unsigned start = 0;
		for (int i=3; i>=0; --i)
			for (int j=3; j>=0; --j)
				if (board[3-i][3-j] == '1')
					start = (start | (1u<<(4*i+j)));

		return go(start, 0);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"1100",
 "1000",
 "0000",
 "0000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, fewestMoves(Arg0)); }
	void test_case_1() { string Arr0[] = {"0100",
 "1110",
 "0100",
 "0000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, fewestMoves(Arg0)); }
	void test_case_2() { string Arr0[] = {"1000",
 "0000",
 "0000",
 "0000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, fewestMoves(Arg0)); }
	void test_case_3() { string Arr0[] = {"1100",
 "1000",
 "0000",
 "0001"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, fewestMoves(Arg0)); }
	void test_case_4() { string Arr0[] = {"1011",
 "1010",
 "0000",
 "0000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(4, Arg1, fewestMoves(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    TurnOffLights ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
