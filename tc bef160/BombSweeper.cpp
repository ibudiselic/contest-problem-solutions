#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int n, m;
class BombSweeper {
	public:
	bool test(int i, int j) {
		return (i>=0 && i<n && j>=0 && j<m);
	}
	double winPercentage(vector <string> board) {
		int win=0, lose=0;
		n = board.size();
		m = board[0].size();

		for (int i=0; i<n; ++i)
			for (int j=0; j<m; ++j)
				if (board[i][j]=='B')
					++lose;
				else {
					bool ok = true;
					for (int di = -1; di <= 1; ++di)
						for (int dj = -1; dj<=1; ++dj) {
							if (di==0 && dj==0) continue;
							if (test(i+di, j+dj) && board[i+di][j+dj]=='B') {
								ok = false;
								break;
							}
						}
					win += ok;
				}
		return (double)win/(win+lose)*100;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".....",
 ".....",
 "..B..",
 ".....",
 "....."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 94.11764705882354; verify_case(0, Arg1, winPercentage(Arg0)); }
	void test_case_1() { string Arr0[] = {"BBBBB",
 "B...B",
 "B...B",
 "B...B",
 "BBBBB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 5.882352941176471; verify_case(1, Arg1, winPercentage(Arg0)); }
	void test_case_2() { string Arr0[] = {".........",
 ".B..B..B.",
 ".........",
 ".........",
 ".B..B..B.",
 ".........",
 ".........",
 ".B..B..B.",
 "........."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.0; verify_case(2, Arg1, winPercentage(Arg0)); }
	void test_case_3() { string Arr0[] = {".........................",
 ".........................",
 ".........................",
 "........................."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 100.0; verify_case(3, Arg1, winPercentage(Arg0)); }
	void test_case_4() { string Arr0[] = {"......B.......B..B...........................B....",
 "..............B..................BB..B............",
 "B.B.B.............B.....B..............B..........",
 "...................B...B....................BB....",
 "...B.....B.........................B.......B.....B",
 "B.B.........B.....B.......B..B......B.B...B.BB....",
 "..B...................BB...............B..........",
 ".........B...B................B..B................",
 ".......BB.......B....B................B.....BBB...",
 ".......BB..........B..............B......BB.......",
 "...................BB.....................B.......",
 "...B.B.B......B..............B...B......B.........",
 "B................B................................",
 "....B..........B.....B..BB....B...............BB..",
 "..B....B.....B.............B.....B............B...",
 "...................B.B........B..B.........B.B....",
 ".....B.....B......................................",
 "...........BB......BB...B.B........B...B..........",
 ".....BBB..........................................",
 ".B...........B....B...BB......B......B...B.B......",
 "..................B........BB................B....",
 "...............................B..B....BBB.B....B.",
 "..........B.......................................",
 ".....B..........B....BB......B.B......B......B....",
 ".....B..................B........B................",
 "............B.....B..B....BB...B....BB........B...",
 "..B.................B.........B...................",
 ".BB..............B................................",
 "...B....B..................B.................B....",
 "......B...B......B......................B.B.......",
 "..............B..................B.......B........",
 ".....B........BB...B.....B........................",
 ".......B......B.B..B..........B...........B....B..",
 "B...B...........B...B...B......B.B...B..B......B..",
 "....B..B.....B.B.......BB..B............B.B....B..",
 "B.......B..........B.........B...B.BB......B......",
 "....B...............................B.............",
 ".....B.B..........................................",
 "..........B............B......B.B..B....B.........",
 "....B...B.......................B.................",
 "B.................B...........B..B....B...........",
 "...B.....B........................................",
 "...B..B......................................BBB..",
 ".B...B....................................B....B..",
 "...B...B..........B...B.B.........................",
 ".....B.............B...BB..........B..BBB.BB......",
 "....................B.....B.......................",
 "........B..BB..........B.B....B...........B......B",
 ".........B.....BB..B.............B....BB..........",
 "....B..B..............B...B..B..........B........."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 77.67558528428094; verify_case(4, Arg1, winPercentage(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    BombSweeper ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
