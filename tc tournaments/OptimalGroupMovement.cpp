#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int sqr(int x) { return x*x; }

int calc(const string &B, int x) {
	int ret = 0;
	for (int i=0; i<(int)B.size(); ++i)
		if (B[i] == 'X') {
			int j = i;
			while (j<(int)B.size() && B[j]=='X')
				++j;
			int sz = j-i;

			ret += abs(i-x)*sqr(sz);
			x += sz;
			i = j-1;
		}

	return ret;
}

class OptimalGroupMovement {
	public:
	int minimumCost(string board) {
		int sol = 1234567890;
		int cnt = 0;
		for (int i=0; i<(int)board.size(); ++i)
			cnt += (board[i]=='X');
		for (int i=0; i+cnt<=(int)board.size(); ++i)
			sol = min(sol, calc(board, i));

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = ".XXX.XXXX."; int Arg1 = 9; verify_case(0, Arg1, minimumCost(Arg0)); }
	void test_case_1() { string Arg0 = "X"; int Arg1 = 0; verify_case(1, Arg1, minimumCost(Arg0)); }
	void test_case_2() { string Arg0 = "XXXXX...X..X.X"; int Arg1 = 14; verify_case(2, Arg1, minimumCost(Arg0)); }
	void test_case_3() { string Arg0 = ".X.X.X..X.X.X.......XX..X.X..X"; int Arg1 = 70; verify_case(3, Arg1, minimumCost(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    OptimalGroupMovement ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
