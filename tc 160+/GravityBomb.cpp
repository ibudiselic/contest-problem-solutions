#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class GravityBomb {
	public:
	vector <string> aftermath(vector <string> board) {
		int m = board.size();
		int n = board[0].size();
		bool change = 1;
		while (change) {
			change = 0;
		for (int i=m-1; i>0; --i)
			for (int j=0; j<n; ++j)
				if (board[i][j]=='.' && board[i-1][j]=='X') {
					change = 1;
					swap(board[i][j], board[i-1][j]);
				}
		}


		for (int i=m-1; i>=0; --i)
			if (board[i] == string(n, 'X')) {
				board.erase(board.begin() + i);
				board.insert(board.begin(), string(n, '.'));
				++i;
			}

		return board;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"..X",
 "X.X",
 ".X."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "...",  "...",  "..X" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, aftermath(Arg0)); }
	void test_case_1() { string Arr0[] = {"...",
 "X..",
 ".X."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "...",  "...",  "XX." }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, aftermath(Arg0)); }
	void test_case_2() { string Arr0[] = {"XXXXXX",
 "......",
 "......"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "......",  "......",  "......" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, aftermath(Arg0)); }
	void test_case_3() { string Arr0[] = {"XX.XX....XX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "XX.XX....XX" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, aftermath(Arg0)); }
	void test_case_4() { string Arr0[] = {"X",".",".",".",".",".",".",".",".",".",".",".",".",
 ".",".",".",".",".",".",".",".",".",".",".",".",".",
 ".",".",".",".",".",".",".",".",".",".",".",".",".",
 ".",".",".",".",".",".",".",".",".",".","."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  ".",  "." }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, aftermath(Arg0)); }
	void test_case_5() { string Arr0[] = {"XXX", "XXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "...",  "..." }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, aftermath(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    GravityBomb ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
