#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
int m, n;
int mini, minj, maxi, maxj, comp;

const int di[] = { -1,  0,  1,  0 };
const int dj[] = {  0,  1,  0, -1 };
inline bool valid(int i, int j) {
	return i>=0 && i<m && j>=0 && j<n;
}

void flood(int i, int j, const vector<string> &a, vector<vector<int> > &c) {
	c[i][j] = comp;
	if (i < mini)
		mini = i;
	if (i > maxi)
		maxi = i;
	if (j < minj)
		minj = j;
	if (j > maxj)
		maxj = j;

	for (int dir=0; dir<4; ++dir) {
		const int ii = i+di[dir];
		const int jj = j+dj[dir];

		if (valid(ii, jj) && a[ii][jj]=='X' && c[ii][jj]==-1)
			flood(ii, jj, a, c);
	}
}
class Amoebae {
	public:
	int cultureX(vector <string> known, vector <string> candidate) {
		m = known.size();
		n = known[0].size();
		vector<vector<string> > box1;
		vector<vector<int> > a(m, vector<int>(n, -1));
		comp = 0;
		for (int i=0; i<m; ++i)
			for (int j=0; j<n; ++j)
				if (known[i][j]=='X' && a[i][j]==-1) {
					mini = 10000;
					minj = 10000;
					maxi = -1;
					maxj = -1;
					flood(i, j, known, a);
					++comp;
					box1.push_back(vector<string>());
					vector<string> &t = box1[box1.size()-1];
					for (int ii=mini; ii<=maxi; ++ii) {
						t.push_back(string());
						string &s = t[t.size()-1];
						for (int jj=minj; jj<=maxj; ++jj)
							if (known[ii][jj]=='X' && a[ii][jj]==comp-1)
								s += 'X';
							else
								s += '.';
					}
				}

		m = candidate.size();
		n = candidate[0].size();
		vector<vector<string> > box2;
		a.assign(m, vector<int>(n, -1));
		comp = 0;
		for (int i=0; i<m; ++i)
			for (int j=0; j<n; ++j)
				if (candidate[i][j]=='X' && a[i][j]==-1) {
					mini = 10000;
					minj = 10000;
					maxi = -1;
					maxj = -1;
					flood(i, j, candidate, a);
					++comp;
					box2.push_back(vector<string>());
					vector<string> &t = box2[box2.size()-1];
					for (int ii=mini; ii<=maxi; ++ii) {
						t.push_back(string());
						string &s = t[t.size()-1];
						for (int jj=minj; jj<=maxj; ++jj)
							if (candidate[ii][jj]=='X' && a[ii][jj]==comp-1)
								s += 'X';
							else
								s += '.';
					}
				}

		vector<string> b1;

		for (int x=0; x<(int)box1.size(); ++x) {
			const vector<string> &t = box1[x];
			m = t.size();
			n = t[0].size();

			string s1, s2;
			for (int i=0; i<m; ++i) {
				for (int j=0; j<n; ++j)
					s1 += t[i][j];
				s1 += 'n';

				for (int j=n-1; j>=0; --j)
					s2 += t[i][j];
				s2 += 'n';
			}
			string best = s1;
			if (s2 < best) best = s2;
			s1.clear(); s2.clear();

			for (int i=m-1; i>=0; --i) {
				for (int j=0; j<n; ++j)
					s1 += t[i][j];
				s1 += 'n';

				for (int j=n-1; j>=0; --j)
					s2 += t[i][j];
				s2 += 'n';
			}
			if (s1 < best) best = s1;
			if (s2 < best) best = s2;
			s1.clear(); s2.clear();

			for (int j=0; j<n; ++j) {
				for (int i=0; i<m; ++i)
					s1 += t[i][j];
				s1 += 'n';

				for (int i=m-1; i>=0; --i)
					s2 += t[i][j];
				s2 += 'n';
			}
			if (s1 < best) best = s1;
			if (s2 < best) best = s2;
			s1.clear(); s2.clear();

			for (int j=n-1; j>=0; --j) {
				for (int i=0; i<m; ++i)
					s1 += t[i][j];
				s1 += 'n';

				for (int i=m-1; i>=0; --i)
					s2 += t[i][j];
				s2 += 'n';
			}

			if (s1 < best) best = s1;
			if (s2 < best) best = s2;
			s1.clear(); s2.clear();

			b1.push_back(best);
		}
		sort(b1.begin(), b1.end());

		vector<string> b2;

		for (int x=0; x<(int)box2.size(); ++x) {
			const vector<string> &t = box2[x];
			m = t.size();
			n = t[0].size();

			string s1, s2;
			for (int i=0; i<m; ++i) {
				for (int j=0; j<n; ++j)
					s1 += t[i][j];
				s1 += 'n';

				for (int j=n-1; j>=0; --j)
					s2 += t[i][j];
				s2 += 'n';
			}
			string best = s1;
			if (s2 < best) best = s2;
			s1.clear(); s2.clear();

			for (int i=m-1; i>=0; --i) {
				for (int j=0; j<n; ++j)
					s1 += t[i][j];
				s1 += 'n';

				for (int j=n-1; j>=0; --j)
					s2 += t[i][j];
				s2 += 'n';
			}
			if (s1 < best) best = s1;
			if (s2 < best) best = s2;
			s1.clear(); s2.clear();


			for (int j=0; j<n; ++j) {
				for (int i=0; i<m; ++i)
					s1 += t[i][j];
				s1 += 'n';

				for (int i=m-1; i>=0; --i)
					s2 += t[i][j];
				s2 += 'n';
			}
			if (s1 < best) best = s1;
			if (s2 < best) best = s2;
			s1.clear(); s2.clear();

			for (int j=n-1; j>=0; --j) {
				for (int i=0; i<m; ++i)
					s1 += t[i][j];
				s1 += 'n';

				for (int i=m-1; i>=0; --i)
					s2 += t[i][j];
				s2 += 'n';
			}
			if (s1 < best) best = s1;
			if (s2 < best) best = s2;
			s1.clear(); s2.clear();

			b2.push_back(best);
		}
		sort(b2.begin(), b2.end());

		int i1=0, i2=0, sol=0;

		while (i1<(int)b1.size() && i2<(int)b2.size()) {
			if (b1[i1] == b2[i2]) {
				++i1;
				++i2;
			} else {
				if (b1[i1] < b2[i2])
					++i1;
				else
					++i2;
				++sol;
			}
		}

		return sol + b1.size()-i1 + b2.size()-i2;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"...XXXXXXX.......",
 "....X.X.X........",
 "...XXXXXX........",
 "...............XX",
 "......X.....XX..X",
 ".XXXXX........X.X",
 ".X.XXX.......XXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"X.X..........XXXX",
 "XXX...XX......X.X",
 "X.X...XX........X",
 "XXX...XX.......XX",
 "X.X....X.X.......",
 "XXX...XX.X.......",
 "X.......X........"}
; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(0, Arg2, cultureX(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"...XXXXXXX.......",
 "....X.X.X........",
 "...XXXXXX........",
 "...............XX",
 "......X.....XX..X",
 ".XXXXX........X.X",
 ".X.XXX.......XXXX"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"X.X..........XXXX",
 "XXX...XX......X.X",
 "X.X...XX........X",
 "......XX.......XX",
 "X.X....X.X.......",
 "XXX...XX.X.......",
 "X.......X........"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(1, Arg2, cultureX(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"......................",
 "....XXX...............",
 "..X...X......XX.XX....",
 "..XX.........XX.XX....",
 "...XX.................",
 "..........X...X..XXXX.",
 "..XXX.....XX.XX.XX..XX",
 "..X........X.X..X....X",
 ".....XX....XXX..X....X",
 ".....XX.....X...XX..XX",
 "............X....XXXX."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"....X......XX.XX.XX...",
 "....XXX....XX.XX.XX...",
 ".........XX...........",
 ".........XX...........",
 "......................",
 "..X....XXXX....X......",
 "..X...XX..XX...X......",
 ".XXX..X....X..XXX.....",
 ".X.X..X....X..X.X.....",
 "XX.XX.XX..XX.XX.XX....",
 "X...X..XXXX..X...X...."}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(2, Arg2, cultureX(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {".XXXX.X...X...XXXX..",
"X..XXXXXXX.X.....XX.",
".X.X.XX....X..XXX..X",
"..XXX.X.X....X......",
".XXXXX...X.....XXXX.",
"..X.XXX..XX....XXX.X",
".......XXX..X.X...XX",
"XX....X.....X...X.X.",
".....X.....XX..XXX.X",
"X...XX.X.X..X....X.X",
".X........X.........",
".X..X.........X.....",
"..X.X..X..........XX",
"........X.X...X.XX..",
"....X.......X.X..X.X",
"....XX..X..X.X.X...X",
"X.....X.........X.X.",
"X.X...X.............",
"..XXX.X...X..X..XX..",
"X.......XX...X......"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {".X.....X.X......XX.X",
"X.X.X..X..XX........",
"X..XXX......X....XX.",
"XXXXX.............X.",
"XX.XXX...X.XX.XX..X.",
".XX.XX..XX.....X....",
"XXXX.X.X........XXX.",
".X....X..X..X.......",
".X.X..X......X.X...X",
".X..XXX..X.........X",
"X....X....X..X....X.",
".XX.....X......X....",
"......XXXX....X.....",
"...X...........X..XX",
"X.X...X....X.XX.....",
"X.X.XX..X......X....",
"X.X.XX.XX....X..X.X.",
"XX..XX..XX...XX...X.",
".X..X.XX....X...X...",
"..X..XX.XX..X.XX...."}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(3, Arg2, cultureX(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {".....XXX...X.....XX.....XX.XX..XX..",
"..X.XX.XX.X....XXX....X......X.....",
".....XX...X....X.X....X.X.X........",
"X.....X.......XXX.X....X..XX.X.....",
".X.X....X.X........X..........XX...",
"........XX........X.....X..X.X.....",
".X..X...X...XX.X..X.....X..........",
"..............X......X...X....X..X.",
"XX..X.....XX..X...X...X.X..X....X..",
".X....XX..X...............X.X.XXXX.",
"...XXXXX.....X...X....X.XX..XXX..X.",
".........X..XX....X.X......XXXX....",
"..XXXX.X..XXX.X...........X..X.XX..",
"X...X...........X..X.X..X.XX..X.X..",
"..X....X.....X..X.X....X..X.X..XXXX",
"X..XXX..X..XX.XX.X..X...X...X..X.XX",
"....X....X.X...X..X..X..XXX...XXXX.",
".X..XX.XX.....X..XX..............XX",
"X..........X..X......XXXX.....X..X.",
".X.XXX...X..X..XX.X.X.X.X..X.......",
"X....X.........X....XXXX..X....X..X",
"..X.XX...X......X.X.......XX....X..",
"X.XXXX....X.XXX..XX..XXXX.X.XX.....",
"XXX.X........X.X..X..X....X..X.....",
"......X..X..XX..X.....XX........X..",
"...X.....XX..X..X..X.X......XX..X.X",
"..X..X.......XX......X......X...XX.",
"..X.XX......XX.X..X.....X...X.X..X.",
".X.X.XX.XXX.X..X.X.................",
".......X.XX..X..X..X.....X.X..XX..X",
"X...XX.......X...X...X.X....X......",
"X.......X.X......X.X.X......X.....X",
"....X.X.X.X....XXX..XX.....XX.X..X.",
"...X..X.X.XX......X.....XX.XXXX....",
"..X......X...X.X...X...X.X.XXXX...X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"..XX......X..XX.X....X..X.XX..X....",
"...X.X.X.......X..X....X...........",
".XXX.X.XXX.....X.X.X..XX.XX.X.XX.XX",
"X...X......X.X........X...X.X.....X",
"X.....X....X...XX....X.X........XX.",
"..XXX...XXX............X.XX..XX..XX",
"....X.X..X..X.X...X.X....X.XX...X..",
".XX..X........XX..X......XX..X....X",
"...X......X...X..X...XX...XXX..X.X.",
"..XX...X..X...X...X.XX.....X.....X.",
".XX.X........X..X..X......XX.X.XX..",
".X.X..XX..X.XX......X....X.........",
"X..X.X..X........X.....X..X..XX...X",
"X.X.........X.XXX..XX..X.........X.",
".........X......XX.....X.....X..X.X",
"X..X.X.XXX.X.....X...X...X...X..X.X",
"X......X..X.XX.X......X....XX.....X",
"X.X...................X...X..X..XX.",
".........X........X..XX..X......X.X",
".X....X.X.X.......X..XX..XX.XXX...X",
".................XXX...XX...X..X...",
"..X...X...XX.....X.....X..XX....XX.",
".......XXX.XX....X...XX..XXX.X....X",
"........X...XXXX..X..........X.....",
"..........XX.X.XX.X.........XX....X",
"...X.....X.X.................X....X",
"...XX.X.....X.....XXXX...X...X.X...",
".............X.....X..X..X.X.X..X..",
"...............X....X....X..X.X.X.X",
".XX..XX........X.....X.XX....X....X",
"...X....X..X...XXX..X........X.....",
"X.XXX.XX..X......XX.X......X.X.X...",
".XX.X....X..X..X.X.................",
"....XXX.X.X......XX.....XX...X.XX..",
"......X....XX..X.....X...XX.X.....X"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 64; verify_case(4, Arg2, cultureX(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Amoebae ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
