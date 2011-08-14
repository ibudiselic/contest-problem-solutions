#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <utility>

using namespace std;
typedef pair<int, int> pii;
vector<string> map;
int m, n;

const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };
bool valid(int i, int j) {
	return i>=0 && i<m && j>=0 && j<n;
}
template<class T> int bitcount(T x) {
	int ret = 0;
	while (x != 0) {
		++ret;
		x &= (x-1);
	}
	return ret;
}

bool used[40][40];
bool r[40], c[40];
bool bfs(int i, int j) {
	memset(used, 0, sizeof used);
					queue<pii> Q;
					Q.push(pii(i, j));
					used[i][j] = 1;
					bool escape = false;
					while (!Q.empty()) {
						int ii = Q.front().first;
						int jj = Q.front().second;
						Q.pop();
						for (int d=0; d<4; ++d) {
							const int rr = ii+di[d];
							const int cc = jj+dj[d];
							if (!valid(rr, cc))
								escape = true;
							if (valid(rr, cc) && map[rr][cc]!='#' && !used[rr][cc] && !r[rr] && !c[cc]) {
								used[rr][cc] = 1;
								Q.push(pii(rr, cc));
							}
						}
					}
					if (!escape)
						return true;


	return false;
}

class CageTheMonster {
	public:
	int capture(vector <string> labyrinth) {
		map = labyrinth;
		m = map.size();
		n = map[0].size();

		memset(r, 0, sizeof r);
		memset(c, 0, sizeof c);

		int sol = 10;
		for (int i=0; i<m; ++i)
			for (int j=0; j<n; ++j)
				if (map[i][j] == '^')
					for (int mask=0; mask<16; ++mask) {
						const int t = bitcount(mask);
						if (t >= sol) continue;
						if (mask & 1)
							if (i-1>=0)
								r[i-1] = 1;
						if (mask & 2)
							if (j-1>=0)
								c[j-1] = 1;
						if (mask & 4)
							if (i+1<m)
								r[i+1] = 1;
						if (mask & 8)
							if (j+1<n)
								c[j+1] = 1;
						if (bfs(i, j))
							sol = t;

						r[i-1] = 0;
						c[j-1] = 0;
						r[i+1] = 0;
						c[j+1] = 0;
					}
		return sol==10 ? -1:sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {
".######..",
".#^^^^#..",
".#^^^^#..",
".#^^^^#..",
".##^^##..",
"...^^...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, capture(Arg0)); }
	void test_case_1() { string Arr0[] = {
".....",
".^#^.",
".#^#.",
"..#.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, capture(Arg0)); }
	void test_case_2() { string Arr0[] = {
"#....",
"^#...",
"#...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(2, Arg1, capture(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    CageTheMonster ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
