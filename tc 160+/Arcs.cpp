#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <utility>
#include <queue>

using namespace std;

vector<string> G;
int M, N;
bool done[51][51];
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };

int sqr(int x) { return x*x; }
bool canGo(int ci, int cj, int a, int b, int c, int d, int r) {
	int rr = r*r;
	//cerr << "center: " << ci << ' ' << cj << " from: " << a << ' ' << b << " to: " << c << ' ' << d << " radius: " << r << '\n';
	if (a > c)
		swap(a, c);
	if (b > d)
		swap(b, d);

	for (int i=a; i<c; ++i)
		for (int j=b; j<d; ++j)
			if (G[i][j] == '#') {
				bool in = false;
				bool out = false;

				for (int ii=0; ii<2; ++ii)
					for (int jj=0; jj<2; ++jj) {
						const int ni = i + ii;
						const int nj = j + jj;

						const int dist = sqr(ci-ni)+sqr(cj-nj);
						if (dist > rr)
							out = true;
						else if (dist < rr)
							in = true;
					}
				if (in && out)
					return false;
			}
	return true;
}
int bfs(int i, int j) {
	int ret = -1;
	int t = 0;
	queue< pair<int, int> > Q;
	Q.push(make_pair(i, j));
	done[i][j] = 1;

	while (!Q.empty()) {
		if (t == 0) {
			t = Q.size();
			++ret;
		}
		--t;
		i = Q.front().first;
		j = Q.front().second;
		Q.pop();

		bool goNext = true;
		for (int r=1; goNext; ++r) {
			goNext = false;
			for (int d=0; d<4; ++d) {
				int ci = i + r*di[d];
				int cj = j + r*dj[d];
				if (ci<0 || ci>=M || cj<0 || cj>=N)
					continue;

				for (int dd=-1; dd<2; ++dd)
					if (dd != 0) {
						int nd = (d+dd+4)%4;
						int ei = ci + r*di[nd];
						int ej = cj + r*dj[nd];

						if (ei<0 || ei>=M || ej<0 || ej>=N)
							continue;

						goNext = 1;

						if (done[ei][ej])
							continue;

						if (!canGo(ci, cj, i, j, ei, ej, r))
							continue;

						if (ei==M-1 && ej==N-1)
							return ret+1;

						done[ei][ej] = 1;
						Q.push(make_pair(ei, ej));
					}
			}
		}
	}

	return -1;
}
class Arcs {
	public:
	int numArcs(vector <string> grid) {
		G = grid;
		M = G.size()+1;
		N = G[0].size()+1;

		memset(done, 0, sizeof done);

		return bfs(0, 0);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = { "..",
  ".." }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, numArcs(Arg0)); }
	void test_case_1() { string Arr0[] = { "...",
  "..." }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(1, Arg1, numArcs(Arg0)); }
	void test_case_2() { string Arr0[] = { "....",
  ".##.",
  ".##.",
  ".##.",
  ".##.",
  "...." }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(2, Arg1, numArcs(Arg0)); }
	void test_case_3() { string Arr0[] =   { "....########",
    "###..###...#",
    "..##..#.##.#",
    "...##..#...#",
    "....#..#...#",
    "....#..###..",
    "....####.##.",
    "..........#." }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(3, Arg1, numArcs(Arg0)); }
	void test_case_4() { string Arr0[] = { ".....#................",
  "....#.................",
  "....#.................",
  "....#.....#...........",
  "....#.................",
  "....#....#.#..........",
  "....#.......#####.....",
  "....#.....#.....#.....",
  "....#.....#.....#.....",
  "....#....#.#....#.....",
  "....#....#.#.....#....",
  "....#....#.#......#...",
  "....#....#.#.##.#..###",
  "....#....#....#......." }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(4, Arg1, numArcs(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Arcs ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
