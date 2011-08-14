#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <utility>

using namespace std;

int K[128];
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };
int m, n;
int dp[50][50][2500];
vector<short> M;
vector<string> B;
pair<int, int> me, him, finish;
bool valid(int i, int j) {
	return i>=0 && i<m && j>=0 && j<n;
}
int go(int r, int c, int t) {
	if (make_pair(r, c) == finish)
		return 0;
	if (t == (int)M.size())
		return 1234567890;
	if (dp[r][c][t] != -1)
		return dp[r][c][t];

	int ret = 1234567890;
	for (int k=0; k<=1; ++k) {
		const int i = r + k*di[M[t]];
		const int j = c + k*dj[M[t]];
		if (valid(i, j) && B[i][j]!='#')
			ret = min(ret, 1+go(i, j, t+1));
	}
	return dp[r][c][t] = ret;
}

class RoboRace {
	public:
	int startTime(vector <string> board, vector <string> commands) {
		K['N'] = 0; K['E'] = 1; K['S'] = 2; K['W'] = 3;
		M.clear();
		B = board;
		m = B.size();
		n = B[0].size();
		for (int i=0; i<(int)commands.size(); ++i)
			for (int j=0; j<(int)commands[i].size(); ++j)
				M.push_back(K[commands[i][j]]);

		for (int i=0; i<m; ++i)
			for (int j=0; j<n; ++j)
				if (B[i][j] == 'X') finish = make_pair(i, j);
				else if (B[i][j] == 'Y') me = make_pair(i, j);
				else if (B[i][j] == 'F') him = make_pair(i, j);

		memset(dp, 0xff, sizeof dp);
		for (int t=0; t<(int)M.size(); ++t)
			if (go(me.first, me.second, t) < go(him.first, him.second, t))
				return t;

		return -1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"#F",
 "YX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NES"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(0, Arg2, startTime(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"########",
 "#......#",
 "#.Y....#",
 "#.F.#..#",
 "#...X..#",
 "#...#..#",
 "#......#",
 "########"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"SSEEESSW"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(1, Arg2, startTime(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"########",
 "#......#",
 "#.Y....#",
 "#.F.#..#",
 "#...X..#",
 "#...#..#",
 "#......#",
 "########"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"ESSEESSW"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(2, Arg2, startTime(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"##.#.#.",
 "..##...",
 "..#...X",
 "Y...##.",
 "#...#.#",
 "..#..F."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"SSSNWSSSEWNSENENENNNNENWNEWESE"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(3, Arg2, startTime(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"#..#.........#...X##....",
 "#........#..........##.#",
 ".#.#........#.....#.#...",
 "..###...#..##.##...#....",
 "..#.#.....#....#.#.####.",
 "#...##.##.##..#.....##..",
 ".##...#.#....#.......#.#",
 "....##.#..#....#....#...",
 "....###.##.....###...#..",
 "#.#.......#.#......#..#.",
 ".##....##.#.##.......#.#",
 "......###...####......#.",
 "..#.##.#..#.#...#...#...",
 ".....#.#..........#...#.",
 "##.#....##F#.....#.##.#.",
 ".##....#.......##.##.##.",
 "..#...#..##....#..#...Y.",
 "#...........#...###..###",
 ".....#...#..#.........#.",
 ".#...##..#.#...#..#.##..",
 "#..#...######....###.#..",
 "#.#.....#.......#.##....",
 "#..#....###....#.#..#...",
 "..#...#.##.##.#.##.##..#",
 "#....##.##..........#..#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NWWSEWSSNWESSWES",
 "ESEEENSNWNNWSNSNWWNWWNNNWE",
 "NSNENENNSEENWWNSNNNNWWSSN",
 "EENEWNWESESEEESNNNSEENNEWNNESNEESSEESEEENENNNWSSW",
 "NWNNWSNWSWSSSSEEWSSWSESWWNNWWENSNNWWSSWWNNE",
 "NWEWNEWSNEN",
 "NNNEWNSWSNWESWNNNSWWNNNWWWNNEWNEEWSSWNSSWWNNWESEWS",
 "WSSSEESSEEEEENNSWEWWWENSENWNSEENES",
 "NNSNESESWNESNENSEESESWSENNESESNESNESEEW",
 "ESNENEENWSNS"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 18; verify_case(4, Arg2, startTime(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    RoboRace ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
