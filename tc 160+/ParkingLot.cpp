#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

const int di[] = { -1,  0,  1,  0 };
const int dj[] = {  0,  1,  0, -1 };

vector<string> grid;
const int INF = 1000000;
int m, n;
bool inbounds(int i, int j) {
	return i>=0 && i<m && j>=0 && j<n;
}

inline int car_code(int i, int j) {
	return i*100+j;
}
struct Match {
	int dist;
	int car, spot;
	Match(int d, int c, int s): dist(d), car(c), spot(s) {}
};
bool operator<(const Match &a, const Match &b) {
	if (a.dist!=b.dist)
		return a.dist < b.dist;
	else if (a.car!=b.car)
		return a.car < b.car;
	else return a.spot < b.spot;
}
vector<Match> a;
int curcarcode;
vector<vector<bool> > used;
void car_bfs_(int x, int y) {
	queue<int> qi, qj, len;
	qi.push(x); qj.push(y);
	len.push(0);
	used[x][y] = true;
	while (!qi.empty()) {
		const int i = qi.front(); qi.pop();
		const int j = qj.front(); qj.pop();
		const int dist = len.front(); len.pop();

		for (int dir=0; dir<4; ++dir) {
			const int ii = i+di[dir];
			const int jj = j+dj[dir];
			if (inbounds(ii, jj) && !used[ii][jj] && grid[ii][jj]!='X' && grid[ii][jj]!='E' && grid[ii][jj]!='U') {
				if (grid[ii][jj] == 'A')
					a.push_back(Match(dist+1, curcarcode, ii*100+jj));
				else {
					qi.push(ii);
					qj.push(jj);
					len.push(dist+1);
					used[ii][jj] = true;
				}
			}
		}
	}
}
void car_bfs(int i, int j) {
	for (int x=0; x<m; ++x)
		for (int y=0; y<n; ++y)
			used[x][y] = false;
	car_bfs_(i, j);
}
int bfs_(int x, int y) {
	queue<int> qi, qj, len;
	qi.push(x); qj.push(y);
	len.push(0);
	used[x][y] = true;
	while (!qi.empty()) {
		const int i = qi.front(); qi.pop();
		const int j = qj.front(); qj.pop();
		const int dist = len.front(); len.pop();

		for (int dir=0; dir<4; ++dir) {
			const int ii = i+di[dir];
			const int jj = j+dj[dir];
			if (inbounds(ii, jj) && !used[ii][jj] && grid[ii][jj]!='X') {
				if (grid[ii][jj]=='E')
					return dist+1;
				else {
					qi.push(ii);
					qj.push(jj);
					len.push(dist+1);
					used[ii][jj] = true;
				}
			}
		}
	}
	return INF;
}
int bfs(int x, int y) {
	for (int i=0; i<m; ++i)
		for (int j=0; j<n; ++j)
			used[i][j] = false;
	return bfs_(x, y);
}
class ParkingLot {
	public:
	int fastest(vector <string> lot) {
		grid = lot;
		a.clear();
		m = grid.size();
		n = grid[0].size();
		used.resize(m);
		for (int i=0; i<m; ++i)
			used[i].resize(n);
		int mycar = -1;
		vector<vector<int> > walk(m, vector<int>(n, INF));

		for (int i=0; i<m; ++i)
			for (int j=0; j<n; ++j)
				if (grid[i][j]=='Y') {
					curcarcode = mycar = car_code(i, j);
					car_bfs(i, j);
				} else if (grid[i][j]=='C') {
					curcarcode = car_code(i, j);
					car_bfs(i, j);
				}	else if (grid[i][j]=='A') {
					walk[i][j] = 2*bfs(i, j);
				}

		assert(mycar != -1);
		sort(a.begin(), a.end());
		vector<int> usedc(50*100+50, false);
		vector<int> useds(50*100+50, false);

		int sol = INF;
		const int sz = a.size();
		for (int i=0; i<sz; ++i)
			if (!usedc[a[i].car] && !useds[a[i].spot]) {
				if (a[i].car==mycar)
					sol <?= a[i].dist + walk[a[i].spot/100][a[i].spot%100];
				else {
					usedc[a[i].car] = true;
					useds[a[i].spot] = true;
				}
			}
		return (sol==INF ? -1:sol);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".Y...........C",
 ".XUUUUUUUAUUX.",
 ".XUUUAUUAUUUX.",
 "..C...........",
 ".XUUUUUUAUUUX.",
 ".XUUUUUUUUUAX.",
 "......C.......",
 ".............E"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 29; verify_case(0, Arg1, fastest(Arg0)); }
	void test_case_1() { string Arr0[] = {"C..A..Y.E"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(1, Arg1, fastest(Arg0)); }
	void test_case_2() { string Arr0[] = {"C..A.Y..E"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(2, Arg1, fastest(Arg0)); }
	void test_case_3() { string Arr0[] = {"Y...C",
 ".XXX.",
 ".....",
 "UUAUU",
 "EA..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 11; verify_case(3, Arg1, fastest(Arg0)); }
	void test_case_4() { string Arr0[] = {".X.U..X....UU.U.XA...UC..U.UA.A.E.A",
 "..U..A.X...XX...U...U...X..U.XUX.X.",
 "U...U.X...U..........A...AXU.U..UUC",
 "UX..XX.AU..XAA.X.U.XCX..UX.......U.",
 "UAUX..UX...X....X.X..C.X..U...AXU..",
 "AA..AA..XUAX..A..XXX..AUUXUAXU.XUAU",
 "..A....A...XUU..A..A.XU..U..A.XX.X.",
 "XX.XU...AX.A.A.....UAA.UX.XA.C....X",
 ".UA.X.A.C...A..UXA.UAX.U.CU.XU....X",
 "..XX....UUU...XX..U..A.......U..A..",
 ".ACCUU.A.A.A.XX.....X..UX..A..U..X.",
 "XCX..UX...X.A.XAUA.UX.X.UA..U..A.A.",
 "UA..X.UC...U..X.AUUAX.U.X.......UA.",
 "..X.XXX..AXX.U..XXU..X...A...UAXX..",
 ".U.A..A.XX....XC.XAUX..AXUX......A.",
 "...X.A..AX.UU.XU......A.........AA.",
 "...UXU..X...U..U.U.X.U...U......UX.",
 "A.U.UA...CA....X..UXUA..X..XX..U...",
 "XXUC.CAU..X.U.......A...U..X.....XA",
 "..XA...U...UXYC.CAU...UXA..A...A...",
 "...XA....U.A.A...CX...A...AX..U..AC",
 "U..X.AX..U..UXX............AA..A..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 52; verify_case(4, Arg1, fastest(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ParkingLot ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
