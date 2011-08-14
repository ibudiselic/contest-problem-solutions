#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };
vector<string> L;
int m, n;
bool used[50][50];
bool region_ok;
bool valid(int i, int j) {
	return i>=0 && i<m && j>=0 && j<n;
}
void test(int i, int j, char lev) {
	used[i][j] = 1;
	for (int d=0; d<4; ++d) {
		const int r = i+di[d];
		const int c = j+dj[d];
		if (!valid(r, c) || L[r][c]<lev)
			region_ok = false;
		if (valid(r, c) && L[r][c]==lev && !used[r][c])
			test(r, c, lev);
	}
}
int add(int i, int j, char lev) {
	++L[i][j];
	int ret = 1;
	for (int d=0; d<4; ++d) {
		const int r = i+di[d];
		const int c = j+dj[d];
		if (L[r][c] == lev)
			ret += add(r, c, lev);
	}
	return ret;
}
class PoolFiller {
	public:
	int getCapacity(vector <string> layout) {
		m = layout.size();
		n = layout[0].size();
		L = layout;

		int sol = 0;
		for (char lev='1'; lev<='8'; ++lev) {
			memset(used, 0, sizeof used);
			for (int i=0; i<m; ++i)
				for (int j=0; j<n; ++j)
					if (L[i][j]==lev && !used[i][j]) {
						region_ok = true;
						test(i, j, lev);
						if (region_ok) {
							sol += add(i, j, lev);
						}
					}
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {
"16661",
"61116",
"16661"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 15; verify_case(0, Arg1, getCapacity(Arg0)); }
	void test_case_1() { string Arr0[] = {
"999999",
"955119",
"955119",
"999999"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 48; verify_case(1, Arg1, getCapacity(Arg0)); }
	void test_case_2() { string Arr0[] = {
"111111111",
"115111611",
"131516161",
"115111611",
"111111111"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(2, Arg1, getCapacity(Arg0)); }
	void test_case_3() { string Arr0[] = {
"1111111111111",
"1555555555551",
"1511111111151",
"1511199911151",
"1511192911151",
"1511199911151",
"1511111111151",
"1555555555551",
"1111111111111"
}

; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 151; verify_case(3, Arg1, getCapacity(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    PoolFiller ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
