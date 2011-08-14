#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

vector<string> M;
int m, n;
bool dp[4][50][50][2];
const int di[] = { -1, 1, 0, 0 };
const int dj[] = { 0, 0, -1, 1 };

bool valid(int i, int j) {
	return i>=0 && i<m && j>=0 && j<n;
}
class LumberjackHack {
	public:
	int timeToShore(vector <string> riverMap) {
		M = riverMap;
		m = M.size();
		n = M[0].size();

		int i=0, j=0;
		for (i=0; i<m; ++i)
			for (j=0; j<n; ++j)
				if (M[i][j] == '+') {
					M[i][j] = '|';
					goto go;
				}
		go: ;
		if (j==0 || j==n-1)
			return 0;

		memset(dp, 0, sizeof dp);
		dp[1][i][j][0] = 1;

		for (int t=1; t<=2500; ++t) {
			for (int r=0; r<m; ++r)
				for (int c=0; c<n; ++c) {
					for (int water=0; water<2; ++water) {
						if (M[r][c] == '|') {
							for (int d=0; d<4; ++d) {
								i = r + di[d];
								j = c + dj[d];
								int cost = 1+(d>=2);
								if (valid(i, j) && dp[cost][i][j][water]) {
									dp[0][r][c][water] = 1;
									break;
								}
							}
						} else if (water) {
							for (int d=0; d<4; ++d) {
								i = r + di[d];
								j = c + dj[d];
								if (valid(i, j) && dp[3][i][j][0]) {
									dp[0][r][c][1] = 1;
									break;
								}
							}
						}
					}
					if ((c==0 || c==n-1) && (dp[0][r][c][0] || dp[0][r][c][1]))
						return t;
				}
			for (int v=2; v>=0; --v)
				memmove(dp[v+1], dp[v], sizeof dp[v+1]);
			memset(dp[0], 0, sizeof dp[0]);
		}

		return -1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".+.",
 "||."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, timeToShore(Arg0)); }
	void test_case_1() { string Arr0[] = {"..+",
 "||."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, timeToShore(Arg0)); }
	void test_case_2() { string Arr0[] = {"....|||",
 "....|..",
 "...||..",
 "||.+...",
 "...|...",
 "...||||"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(2, Arg1, timeToShore(Arg0)); }
	void test_case_3() { string Arr0[] = {"||.|....",
 "........",
 ".|.+|..|",
 "...|....",
 "|..|.|.|"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(3, Arg1, timeToShore(Arg0)); }
	void test_case_4() { string Arr0[] = {".........|.|.|.|.|..||...||.|..|.||...|.|.|||...||",
 ".||.||...||..|||.....|.||||...|.|.|.|.|..|...|.|||",
 "||.|.|..||.||....|.....|.||.|||||.|.|.||.|||||.|..",
 "|.....|.|.||||.||..|.|..|..|.|||||.....||.|.||....",
 "..|..||...||.|.......|||+||.||||....||||.....|..||",
 "...||..||||.|......||..|.|||||.|.|||||.||..|||...|",
 "|||...|..|..|.|||.||.|..|...||.|||..|..||.|.||....",
 "|..|||||||||.||.....|..|.|.|||||...||...|.|.|||||.",
 ".|..||...|||............|.|..|||.||.|||.||..||.|||",
 ".|.|||...||..|..|...||.||..|..|||||.|.|...||..||.|",
 "||||.|||.|..||||..|..||...|..||.|.||||...|...|.|..",
 ".||..||...|.....|||.|||||..||......|.||.||.|..||..",
 "|.|||....|||||.|..|..|.|||..|.||.||.|.|.|.|..||...",
 ".||.||||||...||||||..||....|..||.|||..||...|.|||||",
 ".||||.|....|...|.||..||..|||.|||||....|...||.|.||.",
 ".|...|..||....||...|.||||.....||||.||.|||||||..|||",
 ".||||...|...|..||...|...|...|.|..|.|.|..|..|||.||.",
 ".|.|||..||||||||........|||||||||.|.|........|||||",
 ".....|...||.||...|||...||||..|||...||....||..||.||",
 "||...||..||.||...||...||||..|.|..|...|||..||..|||.",
 "|..||||.||..|...|....||||||...|||.|.|||||..|||...|",
 ".....|||..||.|||.....||..||||...|||||.||.|.||..|||",
 "|..|.||..|..||..||..|...|..|.||..||||..|...||..|..",
 "||.|..|.|||||...|...|.|..|||||...|.......|.||.||||",
 ".|.....|.|||||.....|||...|..|||||...|.||..||.|||.|",
 ".|...||....|||...|||.||.|.|......|........|.||||||",
 "..|.|.|.|||||..|||..|.........|...|.|.|...||.....|",
 ".|.|.|.|..|.|||||||||||.|.|||....|||||...|.||||.|.",
 "|.|||....|.||||..||......|..|||||.....||.|..||..|.",
 "||.||.|||.|......|..|.|...|..||.|||..||.....|.|..|",
 ".||||..|.|.||||.|||.||.||.....|....|....||...|..||",
 ".....|||...||.||.||....|.||..||....|....|||||.|..|",
 "|.|.|||||...|.||..|..|..|.|..|.|........||..|.|.||",
 "....|..|.|..|.||||||....||||.|.||||||.|.|.|.......",
 "||||....|..|...||..||||||||...|.|||||.|.|||.|...||",
 "|...|.|..|..|..|....|..||..|||....||..||..|..|..|.",
 "|||||....|.||.|..|.||..|||..|.|.|..||.|...|.|..||.",
 "..|.|||.|.||..|...|||.|..|||..||...||...||||.....|",
 "..||||.|.|.....|||..||||..|.||||..|..|||.....||.||",
 "|..|||||....|........|.||||.||..||||.|....|||||||.",
 ".|...||.|.||..|.|....|.||..|.|....|.|.||.||.||.|..",
 ".|..|..|.||||.||||....|||.....|.|...|.|...|...||..",
 "|..|||..|.||.|||..||.....|.|..|.|.|...|.....|.....",
 "||..||.|...|.||...|..|..||.|||.||.|.||...|....|||.",
 ".|....|.|||.|..|||..|.....|.||.||...|...||.......|",
 ".||..|||.|.|....|||...|..|.||.||.|.|...|||||.|.|.|",
 "|.|.||.||.|.|.||.|||.||....||.|||||.||.|.|||......",
 "|...|||...|.||||....|.||.||.|.........|..||.|..||.",
 ".|.....|.|.|....||.||...|||.|..||...||.|||.||.|.|.",
 "||.||.|||.|||..||......|......||..||||.|..||.||||."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 63; verify_case(4, Arg1, timeToShore(Arg0)); }
	void test_case_5() { string Arr0[] = {".+."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(5, Arg1, timeToShore(Arg0)); }
	void test_case_6() { string Arr0[] = {"..+.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(6, Arg1, timeToShore(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    LumberjackHack ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
