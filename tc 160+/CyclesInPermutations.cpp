#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class CyclesInPermutations {
	public:
	int maxCycle(vector <int> board) {
		int sol = 0;
		for (int i=0; i<(int)board.size(); ++i) {
			vector<bool> used(board.size(), 0);
			int cnt = 0;
			int cur = i;
			while (!used[cur]) {
				used[cur] = 1;
				cur = board[cur]-1;
				++cnt;
			}
			sol = max(sol, cnt);
		}
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3,2,4,1,6,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, maxCycle(Arg0)); }
	void test_case_1() { int Arr0[] = {1,2,3,4,5,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, maxCycle(Arg0)); }
	void test_case_2() { int Arr0[] = {5,1,2,3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(2, Arg1, maxCycle(Arg0)); }
	void test_case_3() { int Arr0[] = {5,7,14,6,16,10,8,17,11,12,18,3,4,13,2,15,9,1,20,19}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 11; verify_case(3, Arg1, maxCycle(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    CyclesInPermutations ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
