#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

struct State {
	int i, j, vi, vj;
	State(int i_, int j_, int vi_, int vj_): i(i_), j(j_), vi(vi_), vj(vj_) {}
};
bool done[52][52][103][103];
vector<string> T;
bool isDone(const State &s) {
	return done[s.i][s.j][s.vi+51][s.vj+51];
}
void setDone(const State &s) {
	done[s.i][s.j][s.vi+51][s.vj+51] = 1;
}
int getDir(int x) {
	return x<0 ? -1 : (x>0 ? 1 : 0);
}
int move(int i, int j, int vi, int vj) {
	int ti = i+vi;
	int tj = j+vj;
	int di = getDir(ti-i);
	int dj = getDir(tj-j);
	int a = tj-j;
	int b = i-ti;
	int c = -(a*i + b*j);
	int iSide = getDir(a*(2*i + di) + b*(2*j     ) + 2*c);
	int jSide = getDir(a*(2*i     ) + b*(2*j + dj) + 2*c);

	while (1) {
		if (T[i][j] == 'X')
			return 0;
		if (T[i][j] == 'F')
			return 1;
		if (i==ti && j==tj)
			return 2;

		if (di == 0) {
			j += dj;
		} else if (dj == 0) {
			i += di;
		} else {
			int diagSide = getDir(a*(2*i + di) + b*(2*j + dj) + 2*c);

			if (diagSide == iSide) {
				j += dj;
			} else if (diagSide == jSide) {
				i += di;
			} else {
				assert(diagSide == 0);
				if (T[i+di][j]=='F' || T[i][j+dj]=='F')
					return 1;
				i += di;
				j += dj;
			}
		}
	}
}

class PaperRacing {
	public:
	int minMoves(vector <string> track, int vRow, int vCol) {
		for (int i=0; i<(int)track.size(); ++i)
			track[i] = "X" + track[i] + "X";
		track.insert(track.begin(), string(track[0].size(), 'X'));
		track.push_back(track[0]);
		T = track;

		memset(done, 0, sizeof done);
		queue<State> Q;
		for (int i=0; i<(int)track.size(); ++i)
			for (int j=0; j<(int)track[i].size(); ++j)
				if (track[i][j] == 'S') {
					Q.push(State(i, j, vRow, vCol));
					setDone(State(i, j, vRow, vCol));
					break;
				}

		int t = 0;
		int sol = 0;
		while (!Q.empty()) {
			if (t == 0) {
				t = Q.size();
				++sol;
			}
			--t;

			int i = Q.front().i;
			int j = Q.front().j;
			int vi = Q.front().vi;
			int vj = Q.front().vj;
			Q.pop();

			for (int dvi=-1; dvi<=1; ++dvi)
				for (int dvj=-1; dvj<=1; ++dvj)
					switch (move(i, j, vi+dvi, vj+dvj)) {
						case 0: break;
						case 1: return sol; break;
						case 2: if (!isDone(State(i+vi+dvi, j+vj+dvj, vi+dvi, vj+dvj))) { setDone(State(i+vi+dvi, j+vj+dvj, vi+dvi, vj+dvj)); Q.push(State(i+vi+dvi, j+vj+dvj, vi+dvi, vj+dvj)); } break;
					}
		}

		return -1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"S.................F"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 0; int Arg3 = 6; verify_case(0, Arg3, minMoves(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"S.................F"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 8; int Arg3 = 2; verify_case(1, Arg3, minMoves(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"FX",
 "X.",
 ".X",
 "X.",
 "SX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 0; int Arg3 = 8; verify_case(2, Arg3, minMoves(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"S..X",
 "X..X",
 "XX.X",
 "XXFX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 50; int Arg2 = 50; int Arg3 = 1; verify_case(3, Arg3, minMoves(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"S.......X.........F"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 0; int Arg3 = -1; verify_case(4, Arg3, minMoves(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    PaperRacing ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
