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

struct state {
	int i, j, mask, cnt;
	state(int i_, int j_, int mask_, int cnt_): i(i_), j(j_), mask(mask_), cnt(cnt_) {}
};
bool done[1<<10][50][50];
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };
const int diagi[] = { -1, -1, 1, 1 };
const int diagj[] = { -1, 1, 1, -1 };

bool valid(int i, int j, int m, int n) {
	if (i<0 || j<0 || i>=m || j>=n)
		return false;

	return true;
}
void getDoorInd(vector<int> &inds, vector<int> &dirs, const vector<string> &map, int i, int j) {
	for (int d=0; d<4; ++d) {
		int r = i + di[d];
		int c = j + dj[d];

		if (valid(r, c, map.size(), map[0].size()) && map[r][c]<10) {
			inds.push_back(map[r][c]);
			dirs.push_back(d);
		}
	}
}
class RevolvingDoors {
	public:
	int turns(vector <string> map) {
		int mask = 0;
		int cntDoors = 0;
		int m = map.size();
		int n = map[0].size();
		memset(done, 0, sizeof done);

		for (int i=0; i<m; ++i)
			for (int j=0; j<n; ++j)
				if (map[i][j] == 'O') {
					if (map[i-1][j] == '|') {
						mask |= (1<<cntDoors); // vertical ~ 1
						map[i-1][j] = map[i+1][j] = ' ';
					} else {
						// horizontal ~ 0
						map[i][j-1] = map[i][j+1] = ' ';
					}
					map[i][j] = cntDoors++;
				}

		for (int i=0; i<m; ++i)
			for (int j=0; j<n; ++j)
				if (map[i][j] == 'S') {
					deque<state> Q;
					Q.push_back(state(i, j, mask, 0));

					while (!Q.empty()) {
						i = Q.front().i;
						j = Q.front().j;
						mask = Q.front().mask;
						int cnt = Q.front().cnt;

						Q.pop_front();

						done[mask][i][j] = 1;
						if (map[i][j] == 'E')
							return cnt;

						for (int d=0; d<4; ++d) {
							int r = i + di[d];
							int c = j + dj[d];

							if (!valid(r, c, m, n) || map[r][c]=='#' || map[r][c]<cntDoors)
								continue;

							if (done[mask][r][c])
								continue;

							vector<int> doors;
							vector<int> dirs;
							getDoorInd(doors, dirs, map, r, c);

							bool ok = true;
							for (int x=0; x<(int)doors.size(); ++x)
								if (dirs[x]%2==0 && (mask & (1<<doors[x])) || dirs[x]%2==1 && ((mask & (1<<doors[x]))==0)) {
									ok = false;
									break;
								}

							if (ok) {
								done[mask][r][c] = 1;
								Q.push_front(state(r, c, mask, cnt));
							}
						}

						for (int d=0; d<4; ++d) {
							int r = i + diagi[d];
							int c = j + diagj[d];

							if (!valid(r, c, m, n))
								continue;

							if (map[r][c] < cntDoors) {
								int nmask = mask ^ (1<<map[r][c]);

								if (!done[nmask][i][j])
									Q.push_back(state(i, j, nmask, cnt+1));
							}
						}
					}

					return -1;
				}
		return -1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = { "    ### ",
  "    #E# ",
  "   ## # ",
  "####  ##",
  "# S -O-#",
  "# ###  #",
  "#      #",
  "########" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, turns(Arg0)); }
	void test_case_1() { string Arr0[] = { "#### ",
  "#S|##",
  "# O #",
  "##|E#",
  " ####" }
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(1, Arg1, turns(Arg0)); }
	void test_case_2() { string Arr0[] = { " |  |  |     |  |  |  |  |  | ",
  " O  O EO -O- O  O  O  O  OS O ",
  " |  |  |     |  |  |  |  |  | " }
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(2, Arg1, turns(Arg0)); }
	void test_case_3() { string Arr0[] = { "###########",
  "#    #    #",
  "#  S | E  #",
  "#    O    #",
  "#    |    #",
  "#         #",
  "###########" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, turns(Arg0)); }
	void test_case_4() { string Arr0[] = { "        E",
  "    |    ",
  "    O    ",
  "    |    ",
  " -O-S-O- ",
  "    |    ",
  "    O    ",
  "    |    ",
  "         " }
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(4, Arg1, turns(Arg0)); }
	void test_case_5() { string Arr0[] = { "##E#   ",
  "#  ##  ",
  " -O-## ",
  " #  ## ",
  " ##  ##",
  "  -O-  ",
  "##  ## ",
  " # ### ",
  " #  S  " }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(5, Arg1, turns(Arg0)); }
	void test_case_6() { string Arr0[] = { "#############",
  "#  #|##|#   #",
  "#   O  O    #",
  "# E || || S #",
  "#    O  O   #",
  "#   #|##|#  #",
  "#############" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(6, Arg1, turns(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    RevolvingDoors ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
