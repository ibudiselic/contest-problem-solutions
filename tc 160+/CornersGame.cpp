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

const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };
bool done[36][36][36][36];

inline int code(int i, int j) {
	return i*6 + j;
}
inline pii decode(int code) {
	return make_pair(code/6, code%6);
}
int CC(const vector<int> &v) {
	int ret = 0;
	for (int i=0; i<(int)v.size(); ++i)
		ret = ret*36 + v[i];
	return ret;
}
vector<int> DD(int code) {
	vector<int> v(4);
	for (int i=3; i>=0; --i) {
		v[i] = code%36;
		code /= 36;
	}
	return v;
}
inline void mark(const vector<int> &v) {
	done[v[0]][v[1]][v[2]][v[3]] = 1;
}
inline bool test(const vector<int> &v) {
	return done[v[0]][v[1]][v[2]][v[3]];
}
inline bool valid(int i, int j, int m, int n) {
	return i>=0 && i<m && j>=0 && j<n;
}
class CornersGame {
	public:
	int countMoves(vector <string> board) {
		memset(done, 0, sizeof done);
		const int m = board.size();
		const int n = board[0].size();
		vector<int> pos(4);
		pos[0] = code(m-2, n-2);
		pos[1] = code(m-2, n-1);
		pos[2] = code(m-1, n-2);
		pos[3] = code(m-1, n-1);

		vector<int> final(4);
		final[0] = code(0, 0);
		final[1] = code(0, 1);
		final[2] = code(1, 0);
		final[3] = code(1, 1);

		queue<int> Q;
		Q.push(CC(pos));
		vector<pii> pts(4);
		vector<pii> n_pts(4);
		vector<int> n_pos(4);
		vector<char> buff(4);
		int t = 0;
		int sol = -1;
		while (!Q.empty()) {
			if (t == 0) {
				++sol;
				t = Q.size();
			}
			--t;
			pos = DD(Q.front());
			Q.pop();
			if (pos == final)
				return sol;
			mark(pos);
			for (int i=0; i<4; ++i) { // mark them as stones for now
				pts[i] = decode(pos[i]);
				buff[i] = board[pts[i].first][pts[i].second];
				board[pts[i].first][pts[i].second] = 's';
			}
			for (int p=0; p<4; ++p) {
				for (int d=0; d<4; ++d) {
					int i = pts[p].first + di[d];
					int j = pts[p].second + dj[d];
					if (valid(i, j, m, n)) {
						if (board[i][j] == 'r') continue;
						if (board[i][j] == 's') {
							i += di[d];
							j += dj[d];
							if (!valid(i, j, m, n)) continue;
							if (board[i][j] != '.') continue;
						}
						n_pts = pts;
						n_pts[p] = pii(i, j);
						for (int k=0; k<4; ++k)
							n_pos[k] = code(n_pts[k].first, n_pts[k].second);
						sort(n_pos.begin(), n_pos.end()); // crutial - must be kept in sorted order to disregard order ;)
						if (test(n_pos)) continue;
						mark(n_pos);
						Q.push(CC(n_pos));
					}
				}
			}
			for (int i=0; i<4; ++i) // restore the board
				board[pts[i].first][pts[i].second] = buff[i];
		}
		return -1; // no way
	}









// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"......",
 "......",
 "......",
 "......",
 "......",
 "......"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 16; verify_case(0, Arg1, countMoves(Arg0)); }
	void test_case_1() { string Arr0[] = {".....s",
 "..s.r.",
 "r.....",
 ".srs..",
 "..r...",
 "......"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 19; verify_case(1, Arg1, countMoves(Arg0)); }
	void test_case_2() { string Arr0[] = {"......",
 "......",
 "....ss",
 "....ss",
 "...r..",
 "...r.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(2, Arg1, countMoves(Arg0)); }
	void test_case_3() { string Arr0[] = {"...s.r",
 "..r.s.",
 "rr.s..",
 "..s.rr",
 "s.rr..",
 ".s.s.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 54; verify_case(3, Arg1, countMoves(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    CornersGame ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
