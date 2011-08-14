#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

void flip(int m, int n, vector<string> &B) {
	for (int i=0; i<=m; ++i) {
		for (int j=0; j<=n; ++j) {
			B[i][j] = (B[i][j]=='0' ? '1' : '0');
		}
	}
}

bool valid(int i, int j, int m, int n) {
	if (i<0 || j<0 || i>=m || j>=n) {
		return false;
	}
	return true;
}
class TurningLightOn {
	public:
	int minFlips(vector <string> board) {
		int sol = 0;
		int m = board.size();
		int n = board[0].size();
		int k = max(m, n)-1;

		while (k >= 0) {
			for (int i=k; i>=0; --i) {
				if (valid(k, i, m, n) && board[k][i]=='0') {
					++sol;
					flip(k, i, board);
				}
				if (valid(i, k, m, n) && board[i][k]=='0') {
					++sol;
					flip(i, k, board);
				}
			}
			--k;
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"0001111",
 "0001111",
 "1111111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, minFlips(Arg0)); }
	void test_case_1() { string Arr0[] = {"1111111",
 "1111111",
 "1111111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, minFlips(Arg0)); }
	void test_case_2() { string Arr0[] = {"01001"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(2, Arg1, minFlips(Arg0)); }
	void test_case_3() { string Arr0[] = {"0101",
 "1010",
 "0101",
 "1010"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(3, Arg1, minFlips(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    TurningLightOn ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
