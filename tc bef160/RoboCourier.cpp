#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <cassert>

using namespace std;

int dx[] = {1, 1, 0, -1, -1, 0};
int dy[] = {1, 0, -1, -1, 0, 1};

struct Vertex {
	int x, y;
	int n;
	int a[6];
	Vertex() {
		for (int i=0; i<6; ++i)
			a[i] = -1;
	}
};
int n;
map<pair<int, int>, int> grid;
Vertex v[600];
class RoboCourier {
	public:
	int lookup(int x, int y) {
		if (grid.count(make_pair(x, y)) != 0)
			return grid[make_pair(x, y)];
		int t = grid[make_pair(x, y)] = ++n;
		for (int i=0; i<6; ++i)
			v[t].a[i] = -1;
		return t;
	}
	int timeToDeliver(vector <string> path) {
		int x, y, z, old, dir;

		n = -1;
		grid.clear();
		old = lookup(x=0, y=0);
		dir = 0;
		for (int i=0; i<(int)path.size(); ++i)
			for (int j=0; j<(int)path[i].size(); ++j)
				switch (path[i][j]) {
					case 'L': dir = (dir+5)%6; break;
					case 'R': dir = (dir+1)%6; break;
					case 'F':
						x += dx[dir]; y += dy[dir];
						z = lookup(x, y);
						v[old].a[dir] = z;
						v[z].a[(dir+3)%6] = old;
						old = z;
						break;
				}
		vector<bool> used(6*(n+1), false);
		vector<int> dist(6*(n+1), 1000000);
		dist[0] = 0;
		for (;;) {
			int next, best = 1000000;
			for (int i=0; i<6*(n+1); ++i)
				if (dist[i]<best && !used[i]) {
					best = dist[i];
					next = i;
				}
			assert(best != 1000000);
			z = next/6; dir = next%6;

			if (z==old)
				return best;
			used[next] = true;
			if (dist[6*z + (dir+1)%6] > best+3) dist[6*z + (dir+1)%6] = best+3;
			if (dist[6*z + (dir+5)%6] > best+3) dist[6*z + (dir+5)%6] = best+3;
			int cnt=0;
			while (v[z].a[dir] != -1) {
				++cnt;
				z = v[z].a[dir];
				int t = (cnt==1) ? (4):(8+(cnt-2)*2);
				if (dist[6*z + dir] > best+t)
					dist[6*z + dir] = best+t;
			}
		}
		return -1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = { "FRRFLLFLLFRRFLF" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 15; verify_case(0, Arg1, timeToDeliver(Arg0)); }
	void test_case_1() { string Arr0[] = { "RFLLF" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 17; verify_case(1, Arg1, timeToDeliver(Arg0)); }
	void test_case_2() { string Arr0[] = { "FLFRRFRFRRFLLFRRF" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, timeToDeliver(Arg0)); }
	void test_case_3() { string Arr0[] = { "FFFFFFFFFRRFFFFFFRRFFFFF",
  "FLLFFFFFFLLFFFFFFRRFFFF" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 44; verify_case(3, Arg1, timeToDeliver(Arg0)); }
	void test_case_4() { string Arr0[] = { "RFLLFLFLFRFRRFFFRFFRFFRRFLFFRLRRFFLFFLFLLFRFLFLRFF",
  "RFFLFLFFRFFLLFLLFRFRFLRLFLRRFLRFLFFLFFFLFLFFRLFRLF",
  "LLFLFLRLRRFLFLFRLFRF" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 24; verify_case(4, Arg1, timeToDeliver(Arg0)); }
	void test_case_5() { string Arr0[] = { "LLFLFRLRRLRFFLRRRRFFFLRFFRRRLLFLFLLRLRFFLFRRFFFLFL",
  "RLFFRRLRLRRFFFLLLRFRLLRFFLFRLFRRFRRRFRLRLRLFFLLFLF",
  "FRFLRFRRLLLRFFRRRLRFLFRRFLFFRLFLFLFRLLLLFRLLRFLLLF",
  "FFLFRFRRFLLFFLLLFFRLLFLRRFRLFFFRRFFFLLRFFLRFRRRLLR",
  "FFFRRLLFLLRLFRRLRLLFFFLFLRFFRLRLLFLRLFFLLFFLLFFFRR",
  "LRFRRFLRRLRRLRFFFLLLLRRLRFFLFRFFRLLRFLFRRFLFLFFLFR",
  "RFRRLRRFLFFFLLRFLFRRFRFLRLRLLLLFLFFFLFRLLRFRLFRLFR",
  "LLFLFRLFFFFFFFRRLRLRLLRFLRLRRRRRRRRLFLFLFLRFLFRLFF",
  "RLFRRLLRRRRFFFRRRLLLLRRLFFLLLLLRFFFFRFRRLRRRFFFLLF",
  "FFFFLRRLRFLLRRLRLRFRRRRLFLLRFLRRFFFRFRLFFRLLFFRRLL" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 169; verify_case(5, Arg1, timeToDeliver(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    RoboCourier ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
