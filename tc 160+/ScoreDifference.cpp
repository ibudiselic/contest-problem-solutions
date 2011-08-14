#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <utility>
#include <map>

using namespace std;

int A[4][4];
map<int, pair<int, int> > M;
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };
bool done[1<<16];
int dp[1<<16];
bool used[16];

bool take(int mask, int x) {
	used[x] = 1;
	const pair<int, int> t = M[x];
	int i = t.first;
	int j = t.second;
	for (int d=0; d<4; ++d) {
		const int r = i + di[d];
		const int c = j + dj[d];
		if (r<0 || c<0 || r>=4 || c>=4)
			return true;
		if ((mask & (1<<A[r][c]))==0 && !used[A[r][c]] && take(mask, A[r][c]))
			return true;
	}
	return false;
}
bool cantake(int mask, int x) {
	memset(used, 0, sizeof used);
	return take(mask, x);
}
int go(int mask) {
	if (mask == 0)
		return 0;
	if (done[mask])
		return dp[mask];

	done[mask] = 1;
	int ret = -123456789;
	for (int i=0; i<16; ++i)
		if ((mask & (1<<i)) && cantake(mask, i))
			ret = max(ret, i+1-go(mask ^ (1<<i)));

	return dp[mask] = ret;
}
class ScoreDifference {
	public:
	int maximize(vector <string> board) {
		for (int i=0; i<4; ++i) {
			istringstream is(board[i]);
			for (int j=0; j<4; ++j) {
				is >> A[i][j];
				--A[i][j];
			}
		}
		M.clear();
		for (int i=0; i<4; ++i)
			for (int j=0; j<4; ++j)
				M[A[i][j]] = make_pair(i, j);
		memset(done, 0, sizeof done);

		return go((1<<16)-1);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"12 4 5 13",
 "3 14 16 9",
 "11 6 15 8",
 "2 1 7 10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, maximize(Arg0)); }
	void test_case_1() { string Arr0[] = {"15 16 11 12",
 "10 13 4 7",
 "1 2 8 6",
 "9 5 3 14"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(1, Arg1, maximize(Arg0)); }
	void test_case_2() { string Arr0[] = {"6 8 1 16",
 "10 15 9 3",
 "2 5 7 14",
 "13 12 11 4"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(2, Arg1, maximize(Arg0)); }
	void test_case_3() { string Arr0[] = {"9 8 3 1",
 "10 6 15 5",
 "12 7 4 11",
 "14 13 16 2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 16; verify_case(3, Arg1, maximize(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ScoreDifference ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
