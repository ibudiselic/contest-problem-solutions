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
enum { UP, RIGHT, DOWN, LEFT };

vector<string> B;
int M, N;

bool valid(int i, int j) {
	if (i<0 || i>=M || j<0 || j>=N)
		return false;

	return true;
}
char newChar(char c, int d) {
	if (c == '.')
		return d==LEFT || d==RIGHT ? '-' : '|';
	else
		return '+';
}
int newDir(char c, int d) {
	if (c == '/')
		switch (d) {
			case LEFT: return DOWN;
			case RIGHT: return UP;
			case UP: return RIGHT;
			case DOWN: return LEFT;
		}
	else
		switch (d) {
			case LEFT: return UP;
			case RIGHT: return DOWN;
			case UP: return LEFT;
			case DOWN: return RIGHT;
		}
	assert(0);
	return -1;
}
void go(int i, int j, int d) {
	while (1) {
		if (B[i][j]=='.' || B[i][j]=='-' || B[i][j]=='|')
			B[i][j] = newChar(B[i][j], d);
		else if (B[i][j]=='/' || B[i][j]=='`')
			d = newDir(B[i][j], d);
		i += di[d];
		j += dj[d];

		if (!valid(i, j))
			break;
	}
}
class MirrorPath {
	public:
	vector <string> path(vector <string> map) {
		B = map;
		M = B.size();
		N = B[0].size();

		bool found = 0;
		for (int i=0; i<M; ++i)
			if (B[i][0] == '.') {
				found = 1;
				go(i, 0, RIGHT);
				break;
			} else if (B[i][N-1] == '.') {
				found = 1;
				go(i, N-1, LEFT);
				break;
			}

		if (!found)
			for (int j=0; j<N; ++j)
				if (B[0][j] == '.') {
					go(0, j, DOWN);
					break;
				} else if (B[M-1][j] == '.') {
					go(M-1, j, UP);
					break;
				}

		return B;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = { "#.#",
  "#.#",
  "#.#" }
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"#|#", "#|#", "#|#" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, path(Arg0)); }
	void test_case_1() { string Arr0[] = { "############",
  "#######/....",
  "######//####",
  "#####//#####",
  "####//######",
  "..../#######",
  "############" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"############", "#######/----", "######//####", "#####//#####", "####//######", "----/#######", "############" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, path(Arg0)); }
	void test_case_2() { string Arr0[] = { "#######",
  "##/..`#",
  "##.##.#",
  "##.##.#",
  "...../#",
  "##.####",
  "##.####" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"#######", "##/--`#", "##|##|#", "##|##|#", "--+--/#", "##|####", "##|####" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, path(Arg0)); }
	void test_case_3() { string Arr0[] = { "###########.#",
  "#/........./.",
  "#.#########.#",
  "#`........./#",
  "#############" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"###########|#", "#/---------/-", "#|#########|#", "#`---------/#", "#############" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, path(Arg0)); }
	void test_case_4() { string Arr0[] = { "########.##",
  "#./......`#",
  "#../.`....#",
  "#.`...../.#",
  "#....`.../#",
  "###.#######" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"########|##", "#./-----+`#", "#.|/-`..||#", "#.`+-+--/|#", "#..|.`---/#", "###|#######" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, path(Arg0)); }
	void test_case_5() { string Arr0[] = { "##.########",
  "#.........#",
  "..`.`.....#",
  "#..`......#",
  "#.`.`.`...#",
  "#....`....#",
  "#...`.`.`.#",
  "#.........#",
  "#.....`./.#",
  "#.........#",
  "###########" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"##|########", "#.|.......#", "--`-`.....#", "#.|`|.....#", "#.`-`-`...#", "#...|`|...#", "#...`-`-`.#", "#.....|.|.#", "#.....`-/.#", "#.........#", "###########" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, path(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    MirrorPath ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
