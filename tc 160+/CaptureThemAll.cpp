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

const int di[] = { -2, -2, -1, 1, 2, 2, 1, -1 };
const int dj[] = { -1, 1, 2, 2, 1, -1, -2, -2 };
bool done[8][8][2][2];
struct state {
	int i, j;
	bool r, q;
	state(int i_, int j_, bool r_, bool q_): i(i_), j(j_), r(r_), q(q_) {}
};
class CaptureThemAll {
	public:
	int fastKnight(string knight, string rook, string queen) {
		int ki = knight[1]-'1';
		int kj = knight[0]-'a';
		int ri = rook[1]-'1';
		int rj = rook[0]-'a';
		int qi = queen[1]-'1';
		int qj = queen[0]-'a';

		memset(done, 0, sizeof done);
		done[ki][kj][0][0] = 1;
		queue<state> Q;
		Q.push(state(ki, kj, 0, 0));

		int t = 0;
		int sol = -1;
		while (!Q.empty()) {
			if (t == 0) {
				t = Q.size();
				++sol;
			}
			--t;
			int i = Q.front().i;
			int j = Q.front().j;
			bool r = Q.front().r;
			bool q = Q.front().q;
			Q.pop();

			for (int d=0; d<8; ++d) {
				const int ii = i + di[d];
				const int jj = j + dj[d];
				if (ii<0 || ii>7 || jj<0 || jj>7)
					continue;
				bool nr = r || (ii==ri && jj==rj);
				bool nq = q || (ii==qi && jj==qj);
				if (nr && nq)
					return sol+1;
				if (!done[ii][jj][nr][nq]) {
					done[ii][jj][nr][nq] = 1;
					Q.push(state(ii, jj, nr, nq));
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
	void test_case_0() { string Arg0 = "a1"; string Arg1 = "b3"; string Arg2 = "c5"; int Arg3 = 2; verify_case(0, Arg3, fastKnight(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "b1"; string Arg1 = "c3"; string Arg2 = "a3"; int Arg3 = 3; verify_case(1, Arg3, fastKnight(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "a1"; string Arg1 = "a2"; string Arg2 = "b2"; int Arg3 = 6; verify_case(2, Arg3, fastKnight(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "a5"; string Arg1 = "b7"; string Arg2 = "e4"; int Arg3 = 3; verify_case(3, Arg3, fastKnight(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "h8"; string Arg1 = "e2"; string Arg2 = "d2"; int Arg3 = 6; verify_case(4, Arg3, fastKnight(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    CaptureThemAll ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
