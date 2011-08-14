#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class Snaky {
	public:
	int longest(vector <string> snake) {
		int sol = 0;

		int m = snake.size();
		int n = snake[0].size();
		const int di[] = { -1, 0, 1, 0 };
		const int dj[] = { 0, 1, 0, -1 };
		for (int i=0; i<m; ++i)
			for (int j=0; j<n; ++j)
				if (snake[i][j] == 'x')
					for (int d=0; d<4; ++d) {
						int r = i + di[d];
						int c = j + dj[d];
						int cnt = 1;

						while (r>=0 && r<m && c>=0 && c<n && snake[r][c]=='x') {
							++cnt;
							r += di[d];
							c += dj[d];
						}

						sol = max(sol, cnt);
					}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"x.xxx.xxx",
 "x.x.x.x.x",
 "xxx.xxx.x"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, longest(Arg0)); }
	void test_case_1() { string Arr0[] = {"xxxx..",
 "...x..",
 "...x..",
 "......"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(1, Arg1, longest(Arg0)); }
	void test_case_2() { string Arr0[] = {"...x................",
 "...x................",
 "....................",
 "...................."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, longest(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Snaky ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
