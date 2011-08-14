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

bool done[9765625];
int M, N, C;
typedef pair<int, int> pii;
int encode(const vector<pii> &v) {
	int ret = 0;
	for (int i=0; i<C; ++i) {
		ret = ret*5 + v[i].first;
		ret = ret*5 + v[i].second;
	}
	return ret;
}
void decode(int code, vector<pii> &v) {
	for (int i=C-1; i>=0; --i) {
		v[i].second = code%5;
		code /= 5;
		v[i].first = code%5;
		code /= 5;
	}
}
int di[] = { -1, 0, 1, 0 };
int dj[] = { 0, 1, 0, -1 };
bool vis[5];
bool adj(const pii &a, const pii &b) {
	return abs(a.first-b.first)+abs(a.second-b.second) == 1;
}
bool endstate(const vector<pii> &v) {
	memset(vis, 0, sizeof vis);
	queue<int> Q;
	Q.push(0);
	vis[0] = 1;
	int cnt = 1;

	while (!Q.empty()) {
		int x = Q.front();
		//cerr << x << ' ' << cnt << '\n';
		Q.pop();
		for (int y=1; y<C; ++y) {
			if (!vis[y] && adj(v[x], v[y])) {
				vis[y] = 1;
				++cnt;
				Q.push(y);
			}
		}
	}
	
	return cnt == C;
}

bool valid(const pii &a, const vector<pii> &v) {
	if (a.first<0 || a.second<0 || a.first>=M || a.second>=N) {
		return false;
	}
	for (int i=0; i<C; ++i) {
		if (a == v[i]) {
			return false;
		}
	}
	
	return true;
}

class PiecesMover {
	public:
	int getMinimumMoves(vector <string> board) {
		M = board.size();
		N = board.size();
		vector< pair<int, int> > v;
		for (int i=0; i<M; ++i) {
			for (int j=0; j<N; ++j) {
				if (board[i][j] == '*') {
					v.push_back(make_pair(i, j));
				}
			}
		}

		C = v.size();
		memset(done, 0, sizeof done);
		int code = encode(v);
		done[code] = 1;
		int t = 0;
		int sol = -1;
		queue<int> Q;
		Q.push(code);
		while (!Q.empty()) {
			if (t == 0) {
				t = Q.size();
				++sol;
			}
			--t;
			code = Q.front();
			Q.pop();
			decode(code, v);
			/*for (int i=0; i<C; ++i) {
				cerr << v[i].first << ' ' << v[i].second << " | ";
			}
			cerr << '\n';*/
			if (endstate(v)) {
				return sol;
			}

			for (int i=0; i<C; ++i) {
				for (int d=0; d<4; ++d) {
					const int r = v[i].first + di[d];
					const int c = v[i].second + dj[d];
					const pii t(r, c);
					if (valid(t, v)) {
						vector<pii> vv = v;
						vv[i] = t;
						sort(vv.begin(), vv.end());
						int nc = encode(vv);
						if (!done[nc]) {
							done[nc] = 1;
							Q.push(nc);
						}
					}
				}
			}
		}

		return -1; // crai
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".....",
 "..**.",
 ".....",
 "...*.",
 "....."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, getMinimumMoves(Arg0)); }
	void test_case_1() { string Arr0[] = {".....",
 ".....",
 ".**..",
 ".*...",
 "**..."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, getMinimumMoves(Arg0)); }
	void test_case_2() { string Arr0[] = {"*...*",
 ".....",
 ".....",
 ".....",
 "*...*"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(2, Arg1, getMinimumMoves(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    PiecesMover ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
