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
const int dj[] = { 0, -1, 0, 1 };
const int INF = 1000;
int dist[7*50][7*50];
int m, n, sz;
inline int calc(int i, int j) {
	return i*n + j;
}
bool valid(int i, int j) {
	return i>=0 && i<m && j>=0 && j<n;
}
class FourBears {
	public:
	int clearPassages(vector <string> field) {
		m = field.size();
		n = field[0].size();
		sz = m*n;
		for (int i=0; i<m; ++i)
			for (int j=0; j<n; ++j)
				for (int r=0; r<m; ++r)
					for (int c=0; c<n; ++c)
						dist[calc(i, j)][calc(r, c)] = (calc(i, j)==calc(r, c) ? 0 : INF);

		for (int i=0; i<m; ++i)
			for (int j=0; j<n; ++j)
				for (int d=0; d<4; ++d) {
					const int ii = i + di[d];
					const int jj = j + dj[d];
					if (valid(ii, jj))
						if (jj!=0&&jj!=n-1 || field[ii][jj]=='B')
							dist[calc(i, j)][calc(ii, jj)] = (field[ii][jj]=='.' ? 1:0);
				}
		for (int k=0; k<sz; ++k)
			for (int i=0; i<sz; ++i)
				for (int j=0; j<sz; ++j)
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

		int b11 = -1, b12 = -1;
		int b21 = -1, b22 = -1;
		for (int i=0; i<m; ++i) {
			if (field[i][0] == 'B') {
				if (b11 == -1)
					b11 = calc(i, 0);
				else
					b12 = calc(i, 0);
			}
			if (field[i][n-1] == 'B') {
				if (b21 == -1)
					b21 = calc(i, n-1);
				else
					b22 = calc(i, n-1);
			}
		}

		int sol = INF;
		for (int x=0; x<sz; ++x)
			for (int y=0; y<sz; ++y) {
				int best = INF;
				best = min(best, dist[b11][x]+dist[b12][x] + dist[b21][y]+dist[b22][y] + dist[x][y]);
				best = min(best, dist[b11][x]+dist[b21][x] + dist[b12][y]+dist[b22][y] + dist[x][y]);
				best = min(best, dist[b11][x]+dist[b22][x] + dist[b12][y]+dist[b21][y] + dist[x][y]);
				if (x == y)
					best -= 3*(field[x/n][x%n]=='.');
				else {
					best -= (field[x/n][x%n] == '.');
					best -= (field[y/n][y%n] == '.');
					best -= (field[x/n][x%n]=='.' && field[y/n][y%n]=='.');
				}

				sol = min(sol, best);
			}
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {
 "B.X...............",
 "..X..XXXXXXXXXX..B",
 "B.X..X........X...",
 ".....X........X...",
 "..XXXX........X..B"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(0, Arg1, clearPassages(Arg0)); }
	void test_case_1() { string Arr0[] = {
 "..................",
 "B..........XXXX..B",
 "..........X.......",
 "....XXXXXX........",
 "..........XX......",
 "B............XX..B",
 ".................."
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 15; verify_case(1, Arg1, clearPassages(Arg0)); }
	void test_case_2() { string Arr0[] = {
 "B.B",
 "...",
 "B.B"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(2, Arg1, clearPassages(Arg0)); }
	void test_case_3() { string Arr0[] = {
 "..B",
 "B.B",
 "B.."
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(3, Arg1, clearPassages(Arg0)); }
	void test_case_4() { string Arr0[] = {
 "B..................XX.................XX.XXX.....B",
 "...XXXXX.....XXXX......XXXXX.....XXXX..XXX.XXXX...",
 "............XX..................XX................",
 ".......XXX........XX..X....XXX...........XXX......",
 "............XXX......X.XXX......XXX.XXX..X.XXX....",
 "....XXXX......XXX...X...XXXX......XXX.XXXX........",
 "B..XX..............XX............................B"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 28; verify_case(4, Arg1, clearPassages(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    FourBears ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
