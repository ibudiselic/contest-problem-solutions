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

bool done[101][101][2];
struct State {
	int m, c, side;
	State(int m_, int c_, int side_): m(m_), c(c_), side(side_) {}
};

class Cannibals {
	public:
	int minCrossings(int M, int C, int R) {
		memset(done, 0, sizeof done);
		queue<State> q;
		q.push(State(M, C, 0));
		done[M][C][0] = 1;
		int sol = -1;
		int t = 0;
		while (!q.empty()) {
			if (t == 0) {
				++sol;
				t = q.size();
			}
			--t;
			const State x = q.front(); q.pop();
			const int m = x.m;
			const int c = x.c;
			const int s = x.side;
			if (m==M && c==C && s==1)
				return sol;

			for (int i=0; i<=m && i<=R; ++i)
				for (int j=0; j<=c && i+j<=R; ++j)
					if (i+j != 0) {
						if (i>0 && j>i) break;
						if (m-i>0 && c-j>m-i) continue;
						if (M-(m-i)>0 && C-(c-j)>M-(m-i)) break;
						if (!done[M-(m-i)][C-(c-j)][!s]) {
							done[M-(m-i)][C-(c-j)][!s] = 1;
							q.push(State(M-(m-i), C-(c-j), !s));
						}
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
	void test_case_0() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 2; int Arg3 = 11; verify_case(0, Arg3, minCrossings(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 4; int Arg2 = 2; int Arg3 = -1; verify_case(1, Arg3, minCrossings(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 8; int Arg2 = 3; int Arg3 = 17; verify_case(2, Arg3, minCrossings(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 100; int Arg1 = 100; int Arg2 = 20; int Arg3 = 21; verify_case(3, Arg3, minCrossings(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 100; int Arg1 = 99; int Arg2 = 2; int Arg3 = 395; verify_case(4, Arg3, minCrossings(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Cannibals ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
