#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;
typedef pair<int, int> PII;


const int dy[] = { -1,  0,  1,  0 };
const int dx[] = {  0,  1,  0, -1 };

int m, n;
inline bool valid(int i, int j) {
	return i>=0 && i<m && j>=0 && j<n;
}

vector<string> mapa;
vector<int> d;
vector<int> cnt;

class TreasureHunt {
	public:
	inline int sqr(int x) {
		return x*x;
	}
	inline double dist(int y1, int x1, int y2, int x2) {
		return sqrt(sqr(x1-x2)+sqr(y1-y2));
	}
	bool is_beach(int y, int x) {
		for (int dir=0; dir<4; ++dir) {
			const int i = y+dy[dir];
			const int j = x+dx[dir];
			if (!valid(i, j) || mapa[i][j]=='.')
				return true;
		}
		return false;
	}
	PII do_walk(int y, int x) {
		for (int t=0; t<(int)d.size(); ++t)
			for (int c=0; c<cnt[t]; ++c) {
				y += dy[d[t]];
				x += dx[d[t]];
				if (!valid(y, x) || mapa[y][x]=='.')
					return make_pair(-1, -1);
			}
		return make_pair(y, x);
	}
	vector <int> findTreasure(vector <string> island, vector <string> instructions) {
		d.clear();
		cnt.clear();
		mapa = island;

		for (int i=0; i<(int)instructions.size(); ++i) {
			switch (instructions[i][0]) {
				case 'N': d.push_back(0); break;
				case 'E': d.push_back(1); break;
				case 'S': d.push_back(2); break;
				case 'W': d.push_back(3); break;
			}
			cnt.push_back(0);
			sscanf(instructions[i].substr(2).c_str(), "%d", &cnt[cnt.size()-1]);
		}

		int best[50][50] = {0};

		m = island.size();
		n = island[0].size();

		int tx=0, ty=0;
		for (int y=0; y<m; ++y)
			for (int x=0; x<n; ++x) {
				if ((mapa[y][x]=='O' || mapa[y][x]=='X') && is_beach(y, x)) {
					PII dest = do_walk(y, x);
					if (valid(dest.first, dest.second))
						++best[dest.first][dest.second];
				}
				if (mapa[y][x] == 'X') {
					ty = y;
					tx = x;
				}
			}

		int y=0;
		int x=0;
		for (int i=0; i<m; ++i)
			for (int j=0; j<n; ++j)
				if (best[i][j]>best[y][x] || (best[i][j]==best[y][x] && dist(i, j, ty, tx)<dist(y, x, ty, tx))) {
					y = i;
					x = j;
				}
		vector<int> sol;
		if (best[y][x] > 0) {
			sol.push_back(x);
			sol.push_back(y);
		}
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"..OOOO..",
 ".OOOO...",
 "OOXOOOOO",
 "OOOOOOO.",
 ".OOOO...",
 "..OOO..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"W 3","S 1","E 2"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 3,  2 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, findTreasure(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {".......",
 ".OOOOO.",
 ".OOOOO.",
 ".OOXOO.",
 ".OOOOO.",
 ".OOOOO.",
 "......."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"N 1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 3,  4 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, findTreasure(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"OOOOOOOOOOO.",
 "OX..........",
 "OOOOOOOOOOO."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"W 2"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 1,  0 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, findTreasure(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"....OO.",
 "..OOXOO",
 "OOOO...",
 ".OOOOOO",
 "...OOOO",
 ".OOOOO.",
 "..OOO.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"N 1","E 1","N 4"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 3,  1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, findTreasure(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"N 1","E 1","S 1","W 1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, findTreasure(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {".................O..",
 "..OO.......OOOOO.O..",
 "..OOO..OOO.OOOOOOOO.",
 "..OOOOOOOOOOOOOOOOO.",
 "..OOOOOOOOOOOOOOOOO.",
 "...OOOOOOOOOOOOOOOO.",
 "OO.OOOOOOOXOOOOOO...",
 ".OOOOOOO..OOOOOOOO..",
 "OOOOOOOOO..OOOOOOOO.",
 "OOOOOOOOO..OOOOOOO..",
 ".OOOOOOOOO..........",
 "OOOOOOOOOOOOOOOOOO..",
 "..OOOOOOOOOOOOOOO...",
 "OOOOOOOOOOOOOOOOO...",
 ".OOOOOOOOOOOOOOOOOOO",
 "OOOOOOOOOOOOOOOOOO..",
 "..OOOOOOOOOOOOOOOOO.",
 "OOOOO.OOOOOO..OOO...",
 "O..OO.OOOO.....OOO..",
 "O......O.OO......OO."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"N 2","E 3","N 4","E 2","S 1","W 2","E 9","E 2",
 "N 3","W 5","N 1","W 6","N 6","S 1","S 1","E 7"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 10,  6 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(5, Arg2, findTreasure(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    TreasureHunt ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
