#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <utility>

using namespace std;


bool canReach[50][50][26][2];
bool done[50][50][26][2];

int C[50][50];

vector<string> T;
string W;
int M, N;
bool valid(int i, int j) {
	return i>=0 && i<M && j>=0 && j<N;
}

const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };

bool go(int i, int j, int pos, int direction) {
	if (pos<0 || pos==(int)W.size())
		return false;
	if (done[i][j][pos][direction])
		return canReach[i][j][pos][direction];

	done[i][j][pos][direction] = 1;

	if (T[i][j] != W[pos])
		return canReach[i][j][pos][direction] = 0;
	if (direction==0 && pos==0 || direction==1 && pos==(int)W.size()-1)
		return canReach[i][j][pos][direction] = 1;

	for (int d=0; d<4; ++d) {
		const int r = i + di[d];
		const int c = j + dj[d];
		if (valid(r, c) && go(r, c, pos + (direction ? 1 : -1), direction))
			return canReach[i][j][pos][direction] = 1;
	}

	return canReach[i][j][pos][direction] = 0;
}
void dfs(int i, int j, int comp) {
	C[i][j] = comp;

	for (int pos=0; pos<(int)W.size(); ++pos)
		for (int d=0; d<4; ++d) {
			const int r = i + di[d];
			const int c = j + dj[d];

			if (pos < (int)W.size()-1)
				if (valid(r, c) && C[r][c]==-1 && go(i, j, pos, 0) && go(r, c, pos+1, 1))
					dfs(r, c, comp);
			if (pos > 0)
				if (valid(r, c) && C[r][c]==-1 && go(i, j, pos, 1) && go(r, c, pos-1, 0))
					dfs(r, c, comp);
		}
}
class WordConnect {
	public:
	int numComponents(string word, vector <string> table) {
		M = table.size();
		N = table[0].size();
		T = table;
		W = word;

		memset(done, 0, sizeof done);
		memset(C, 0xff, sizeof C);

		int sol = 0;
		for (int i=0; i<M; ++i)
			for (int j=0; j<N; ++j)
				if (C[i][j] == -1)
					dfs(i, j, sol++);

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "top"; string Arr1[] = {
"toptoptop",
"toptoptop"
}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(0, Arg2, numComponents(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "top"; string Arr1[] = {
"aaaaaaaaaaa",
"aaaopopoaaa",
"aaatototaaa",
"aaaopopoaaa",
"aaaaaaaaaaa"
}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 41; verify_case(1, Arg2, numComponents(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "topcader"; string Arr1[] = {
"topcader",
"oaaaaaae",
"paaaaaad",
"caaaaaaa",
"aaaaaaac",
"daaaaaap",
"eaaaaaao",
"redacpot"
}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 37; verify_case(2, Arg2, numComponents(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "topcader"; string Arr1[] = {
"topcoder",
"oaaaaaae",
"paaaaaad",
"caaaaaaa",
"aaaaaaac",
"daaaaaap",
"eaaaaaao",
"redocpot"
}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 50; verify_case(3, Arg2, numComponents(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "a"; string Arr1[] = {
"aaaaaaaaaaaaaaaaaaaaaa",
"aaaaaaaaaaaaaaaaaaaaaa",
"aaaaaaaaaaaaaaaaaaaaaa",
"aaaaaaaaaaaaaaaaaaaaaa",
"aaaaaaaaaaaaaaaaaaaaaa",
"aaaaaaaaaaaaaaaaaaaaaa",
"aaaaaaaaaaaaaaaaaaaaaa",
"aaaaaaaaaaaaaaaaaaaaaa",
"aaaaaaaaaaaaaaaaaaaaaa",
"aaaaaaaaaaaaaaaaaaaaaa"
}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 220; verify_case(4, Arg2, numComponents(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    WordConnect ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
