#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

class TileCutting {
	public:
	int calc(int l, int h, int q) {
		int ret = 2*l;
		q -= l;
		ret += 2*(h/2) + 2*(h%2);
		if (q>0 && h%2) {
				++ret;
				q -= 2;
		}
		if (q > 0)
			ret += 4*(q/4);

		q %= 4;
		switch (q) {
			case 1: ret += 2; break;
			case 2: ret += 3; break;
			case 3: ret += 4; break;
		}

		return ret;
	}
	int go(int l, int h, int q) {
		int ret = INT_MAX;
		for (int i=0; i<=l; ++i)
			for (int j=0; j<=h+(l-i); ++j)
				ret = min(ret, calc(i, j, q+(l-i)+2*(h+(l-i)-j)));

		return ret;
	}
	int cuts(vector <string> a) {
		int h, q, l;
		int	m = a.size();
		int n = a[0].size();

		h = q = l = 0;

		for (int i=0; i<m; i+=2)
			for (int j=0; j<n; j+=2) {
				int empty = 0;
				for (int di=0; di<=1; ++di)
					for (int dj=0; dj<=1; ++dj)
						empty += a[i+di][j+dj]=='.';

				switch (empty) {
					case 1: ++q; break;
					case 3: ++l; break;
					case 2:
						if (a[i][j]==a[i+1][j+1]) q+=2; else ++h;
						break;
				}

			}

		return go(l, h, q);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = { "..",
  ".." }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(0, Arg1, cuts(Arg0)); }
	void test_case_1() { string Arr0[] = { "x.",
  ".." }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, cuts(Arg0)); }
	void test_case_2() { string Arr0[] = { ".x",
  "xx" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, cuts(Arg0)); }
	void test_case_3() { string Arr0[] = { "xxxx..xxxx",
  "x..x..xx..",
  "x..xxxxx..",
  "xxxxxxxxxx" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(3, Arg1, cuts(Arg0)); }
	void test_case_4() { string Arr0[] = { "xxxxxx",
  "x....x" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(4, Arg1, cuts(Arg0)); }
	void test_case_5() { string Arr0[] = { "x..x....",
  "x..xx...",
  "..xx....",
  "...x....",
  "......xx",
  "......xx" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(5, Arg1, cuts(Arg0)); }
	void test_case_6() { string Arr0[] = { "x..xx.x..x.xx..x.xx.",
  "..x..x..x.x..xx...x.",
  ".xx...x...x...x..x..",
  ".xx...x.x.x...x..xx.",
  ".x..x...x.....x...x.",
  ".x.x.x..x..x..x..x.x",
  "...x.x.x.x.x.x.x...x",
  ".x..x..x...x..x...x.",
  "...x.x.x..x.x.x.....",
  "...x.x.x..x.x.xxx.x.",
  "xx.xx.xx.x.x.x.x..x.",
  ".x..xxx...x.xx...x.x",
  "xx..x.x...x.x.x.x..x",
  ".xx..x.xx.xxxxx...xx",
  "x....x.x...x...x.x..",
  ".x.xx.x..x.x.xxx.x..",
  "...xx.xxx.....xx.xxx",
  ".xx..x..xx.x...x.xx.",
  "x.x...x.x.xx.x..x.xx",
  ".....xx.x.......xx.x",
  "x...x.xx.x..x....x..",
  ".x..xxx.....x.x.x.xx" }
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 121; verify_case(6, Arg1, cuts(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    TileCutting ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
