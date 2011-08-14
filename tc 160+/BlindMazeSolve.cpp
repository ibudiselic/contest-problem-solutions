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

int I, J;
vector<string> a;
bool done[1<<20];
int dir[1<<20];
unsigned from[1<<20];

const int di[] = { 1, 0, 0, -1 };
const int dj[] = { 0, -1, 1, 0 };
const string dirs = "DLRU";

inline int pos(int i, int j) {
	return i*J + j;
}
unsigned next(unsigned cur, int d) {
	unsigned ret = 0;
	for (int i=0; i<I; ++i)
		for (int j=0; j<J; ++j)
			if (cur & (1u<<pos(i, j))) {
				int ii = i + di[d];
				int jj = j + dj[d];
				if (jj < 0) continue;
				if (!(ii>=0 && ii<I && jj>=0 && jj<J) || a[ii][jj]=='X') {
					ii = i;
					jj = j;
				}
				ret |= 1u<<pos(ii, jj);
			}
	return ret;
}
string reconst(unsigned cur) {
	if (from[cur] == 0) return "";
	else return reconst(from[cur]) + dirs[dir[cur]];
}
class BlindMazeSolve {
	public:
	string getSolution(vector <string> maze) {
		a = maze;
		I = maze.size();
		J = maze[0].size();

		unsigned not_done = 0;
		for (int i=0; i<I; ++i)
			for (int j=0; j<J; ++j)
				if (a[i][j] != 'X')
					not_done |= 1u<<pos(i, j);

		memset(done, 0, sizeof done);
		memset(dir, 0, sizeof dir);
		memset(from, 0, sizeof from);

		queue<unsigned> Q;
		Q.push(not_done);
		done[not_done] = true;
		while (!Q.empty()) {
			not_done = Q.front();
			if (not_done == 0)
				break;
			Q.pop();
			for (int d=0; d<4; ++d) {
				unsigned ns = next(not_done, d);
				if (!done[ns]) {
					done[ns] = 1;
					Q.push(ns);
					dir[ns] = d;
					from[ns] = not_done;
				}
			}
		}
		if (!done[0])
			return "";
		else
			return reconst(0);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "L"; verify_case(0, Arg1, getSolution(Arg0)); }
	void test_case_1() { string Arr0[] = {
"..",
".."
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "LL"; verify_case(1, Arg1, getSolution(Arg0)); }
	void test_case_2() { string Arr0[] = {
"X..",
"X..",
"XXX"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = ""; verify_case(2, Arg1, getSolution(Arg0)); }
	void test_case_3() { string Arr0[] = {
"X...",
"XXX.",
"X...",
"X.XX",
"..XX"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "RRDDLLDDLL"; verify_case(3, Arg1, getSolution(Arg0)); }
	void test_case_4() { string Arr0[] = {".XX."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = ""; verify_case(4, Arg1, getSolution(Arg0)); }
	void test_case_5() { string Arr0[] = {
"XXX.",
"..X.",
"X...",
"XX..",
"X..."
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "DDDRULULULL"; verify_case(5, Arg1, getSolution(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    BlindMazeSolve ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
