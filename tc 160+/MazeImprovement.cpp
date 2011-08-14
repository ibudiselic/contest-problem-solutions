#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

const int di[] = { -1,  0, 0, 1 };
const int dj[] = {  0, -1, 1, 0 };

template<class T> int bitcount(T x) {
	int ret = 0;
	for (typeof(x) i=0; (1ull<<i)<=x; ++i)
		if (((1<<i) & x) != 0)
			++ret;
	return ret;
}
int m, n;
bool valid(int i, int j) {
	return i>=1 && i<=m && j>=1 && j<=n;
}
enum dir {
	NORTH = 1, WEST = 2, EAST = 4, SOUTH = 8
};
vector<vector<unsigned> > cnt;
unsigned deadend(int i, int j) {
	if (bitcount(cnt[i][j]) == 1)
		return cnt[i][j];
	else return 0;
}
bool short_deadend(int i, int j) {
	return deadend(i, j) &&
								(cnt[i][j]&NORTH && bitcount(cnt[i-1][j])>=3
							  ||
							  cnt[i][j]&WEST && bitcount(cnt[i][j-1])>=3
							  ||
							  cnt[i][j]&EAST && bitcount(cnt[i][j+1])>=3
							  ||
							  cnt[i][j]&SOUTH && bitcount(cnt[i+1][j])>=3);
}

class MazeImprovement {
	public:
	vector <string> improve(vector <string> maze) {
		m = maze.size();
		n = maze[0].size();
		cnt.clear();
		for (int i=0; i<m+2; ++i)
			cnt.push_back(vector<unsigned>(n+2, 0));
		vector<string> grid;
		grid.push_back(string(n+2, '+'));
		for (int i=0; i<m; ++i)
			grid.push_back('+' + maze[i] + '+');
		grid.push_back(string(n+2, '+'));

		for (int i=1; i<=m; ++i)
			for (int j=1; j<=n; ++j)
				switch (grid[i][j]) {
					case '|':
						cnt[i][j] |= NORTH;
						cnt[i-1][j] |= SOUTH;
						break;
					case '-':
						cnt[i][j] |= EAST;
						cnt[i][j+1] |= WEST;
						break;
					case 'L':
						cnt[i][j] |= NORTH | EAST;
						cnt[i-1][j] |= SOUTH;
						cnt[i][j+1] |= WEST;
						break;
					case '.':
						assert((cnt[i][j]&NORTH)==0 && (cnt[i][j]&EAST)==0);
						break;
				}

		bool done = false;
		while (!done) {
			done = true;

			for (int i=1; i<=m; ++i)
				for (int j=1; j<=n; ++j)
					if (short_deadend(i, j)) {
						unsigned cur = 16;
						for (int d=0; d<4; ++d) {
							const int ii = i+di[d];
							const int jj = j+dj[d];

							if (valid(ii, jj) && short_deadend(ii, jj)) {
								switch (d) {
									case 0: cur = NORTH; break;
									case 1: cur = WEST; break;
									case 2: cur = EAST; break;
									case 3: cur = SOUTH; break;
								}
								break;
							}
						}
						if (16 == cur)
							for (int d=0; d<4; ++d) {
								const int ii = i+di[d];
								const int jj = j+dj[d];

								if (valid(ii, jj) && deadend(ii, jj)) {
									switch (d) {
										case 0: cur = NORTH; break;
										case 1: cur = WEST; break;
										case 2: cur = EAST; break;
										case 3: cur = SOUTH; break;
									}
									break;
								}
							}
						if (16 != cur) {
							done = false;
							unsigned disc = deadend(i, j);
							switch (disc) {
								case NORTH:
									cnt[i][j] ^= NORTH;
									cnt[i-1][j] ^= SOUTH;
									break;
								case WEST:
									cnt[i][j] ^= WEST;
									cnt[i][j-1] ^= EAST;
									break;
								case EAST:
									cnt[i][j] ^= EAST;
									cnt[i][j+1] ^= WEST;
									break;
								case SOUTH:
									cnt[i][j] ^= SOUTH;
									cnt[i+1][j] ^= NORTH;
									break;
								default: assert(0); break;
							}
							switch (cur) {
								case NORTH:
									cnt[i][j] |= NORTH;
									cnt[i-1][j] |= SOUTH;
									break;
								case WEST:
									cnt[i][j] |= WEST;
									cnt[i][j-1] |= EAST;
									break;
								case EAST:
									cnt[i][j] |= EAST;
									cnt[i][j+1] |= WEST;
									break;
								case SOUTH:
									cnt[i][j] |= SOUTH;
									cnt[i+1][j] |= NORTH;
									break;
								default: assert(0); break;
							}
							goto kraj;
						}
					}
			kraj: ;
		}
		for (int i=1; i<=m; ++i)
			for (int j=1; j<=n; ++j)
				if ((cnt[i][j]&NORTH)!=0 && (cnt[i][j]&EAST)!=0)
					grid[i][j] = 'L';
				else if ((cnt[i][j]&NORTH) != 0)
					grid[i][j] = '|';
				else if ((cnt[i][j]&EAST) != 0)
					grid[i][j] = '-';
				else
					grid[i][j] = '.';

		for (int i=1; i<=m; ++i)
			maze[i-1] = grid[i].substr(1, n);

		return maze;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = { ".---.",
  "L-|-|",
  "----|" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "-.--.",  "L-|-|",  "----|" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, improve(Arg0)); }
	void test_case_1() { string Arr0[] = {
  "........",
  "LLLLLLL|",
  "||||||||"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "-.-.-.-.",  "-L-L-L-|",  "|-|-|-||" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, improve(Arg0)); }
	void test_case_2() { string Arr0[] = { "--.--.",
  "|.-L.|",
  "|L-|-.",
  "L--L-|" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "--.--.",  "|.||-|",  "|L-|-.",  "L--L-|" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, improve(Arg0)); }
	void test_case_3() { string Arr0[] = { "....-.--....-..",
  "|LLL.L||-|L|L-|",
  "L-L-.-|L-|.LL..",
  "-|-||---.|L||.|",
  "-.-.LL-.LL|.LL|",
  "-L|L||-|||L|L.|" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "..-.-.-.-.-.-..",  "|L-||L||||L.L-|",  "L-L-.-|L-|.L|..",  "-|-||---.|L||||",  "-.-.LL-.LL|.LL|",  "|L|L|--|-|L|L-." }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, improve(Arg0)); }
	void test_case_4() { string Arr0[] = { "--.-..--.----.--.--.-..-...-..",
  "-.LL-L-L.L---.L-.--LL-|-|LL-||",
  "-|-L-.L---||L--||--L--.||---L|",
  "L.-.--||-||L.|-|--L.L-.|-L.|||",
  "-|.L|-L.-L--..L.|L.||L-L.-.|L.",
  ".LL-||L--.|-.L|LL-.||-|-|L.|-.",
  "L.|-|-||L.-|-|...||--L.|-L-|-|",
  "|L.||-|..-L.|-LL|.---.||L-.-||",
  "L---..L|L-.L--.L.|L---L--|.L-.",
  "--|-LL||||L.|-.L-L|.L---.|LL.|",
  "|--|.|.-|||-L|L-|L.||L.---||L.",
  "||-LL-L||||--L-.|L.L-L--||||-|" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "--.-.--..----.--.--.-..-.-.-..",  "-.LL---L|L--.|L-.--LL-|-|L--||",  "-|.L-.L---||L--|||-L--.|.---L|",  "L.L.--|--||L..-|--L.L.||L|.||.",  ".|.L|-|--L--.|L.|L.||L-L.-||L|",  "|LL-||L-.-|-.L|LL-.||-|-|L.|-.",  "L..-|.|.L.-|-|-.-.|--L.|-L-|-|",  "|L|L.L||--L.|--L|.---.||L..-||",  "L---..L|--.L--.L.|L---L--||L-.",  "--|-LL|||||.|-.L-L|.L----.LL.|",  "|--|-|.-|||LL|L-||.|||----||L.",  "|L.L--L|-||--L--.L|L-L--|-||-|" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, improve(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    MazeImprovement ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
