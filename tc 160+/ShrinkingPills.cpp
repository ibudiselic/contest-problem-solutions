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

const int di[] = { -1, 0, 1, 0, 0 };
const int dj[] = { 0, 1, 0, -1, 0 };

bool done[50][50][101][11][2];

struct State {
	int i, j, h, p;
	bool d;
	State(int ii, int jj, int hh, int pp, bool dd): i(ii), j(jj), h(hh), p(pp), d(dd) {}
};
class ShrinkingPills {
	public:
	int escape(int pills, int pspeed, int dspeed, int door, vector <string> lab) {
		int m = lab.size();
		int n = lab[0].size();
		memset(done, false, sizeof done);

		vector<State> a;
		for (int i=0; i<m; ++i)
			for (int j=0; j<n; ++j)
				if (lab[i][j] == '@') {
					a.push_back(State(i, j, 100, pills, false));
					done[i][j][100][pills][0] = true;
					if (pills > 0) {
						a.push_back(State(i, j, 100, pills-1, true));
						done[i][j][100][pills-1][1] = true;
					}
					break;
				}

		int time = 0;
		while (a.size() > 0) {
			vector<State> nextst;
			if (door > 0)
				door = max(0, door-dspeed);

			for (int s=0; s<(int)a.size(); ++s) {
			  int nexth = a[s].d ? (a[s].h<=pspeed ? 100 : a[s].h-pspeed) : 100;
				for (int dir=0; dir<5; ++dir) {
					const int i = a[s].i + di[dir];
					const int j = a[s].j + dj[dir];
					if (i>=0 && i<m && j>=0 && j<n) {
						if (lab[i][j] == 'E')
							return time+1;
						if (lab[i][j]=='#' || lab[i][j]=='X' && nexth>door)
							continue;
						for (int take=0; take<2; ++take) {
							if (take == 1)
								if (nexth!=100 || a[s].p==0)
									break;
							const State S(i, j, nexth, a[s].p-take, nexth!=100 || take);
							if (!done[S.i][S.j][S.h][S.p][S.d]) {
								done[S.i][S.j][S.h][S.p][S.d] = true;
								nextst.push_back(S);
							}
						}
					}
				}
			}
			a = nextst;
			++time;
		}

		return -1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 50; int Arg2 = 1; int Arg3 = 100; string Arr4[] = {"######################",
 "#@    X     X     X E#",
 "######################"}; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 19; verify_case(0, Arg5, escape(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 20; int Arg2 = 10; int Arg3 = 60; string Arr4[] = {"##########",
 "#   #    #",
 "# @ X E  #",
 "#   #    #",
 "##########"}; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 6; verify_case(1, Arg5, escape(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 0; int Arg1 = 1; int Arg2 = 10; int Arg3 = 200; string Arr4[] = {"#########",
 "#@   X  #",
 "####### #",
 "#E   X  #",
 "#########"}; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 14; verify_case(2, Arg5, escape(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 10; int Arg3 = 120; string Arr4[] = {"#############",
 "#   #####   #",
 "# @ XXXXX E #",
 "#   #####   #",
 "#############"}; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = -1; verify_case(3, Arg5, escape(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 10; int Arg3 = 120; string Arr4[] = {"#########",
 "#XX@XXXE#",
 "# ##### #",
 "#       #",
 "#########"}; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 12; verify_case(4, Arg5, escape(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ShrinkingPills ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
