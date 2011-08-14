#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int m, n;
int Gi, Gj;
vector<string> C;
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };

bool done[50][50][4][2];
bool reach[50][50][4][2];
bool vis[50][50][4][2];

bool garage(int i, int j, int d, bool t90) {
	if (done[i][j][d][t90])
		return reach[i][j][d][t90];

	if (i==Gi && j==Gj)
		return 1;

	vis[i][j][d][t90] = 1;

	int r = i + di[d];
	int c = j + dj[d];
	if (r>=0 && r<m && c>=0 && c<n && (C[r][c]=='|' || C[r][c]=='-')) {
		r += di[d];
		c += dj[d];
		if (!vis[r][c][d][0] && garage(r, c, d, 0)) {
			vis[i][j][d][t90] = 0;
			done[i][j][d][t90] = 1;
			return reach[i][j][d][t90] = 1;
		}
	}
	if (!t90) {
		if (!vis[i][j][(d+1)%4][1] && garage(i, j, (d+1)%4, 1)) {
			vis[i][j][d][t90] = 0;
			done[i][j][d][t90] = 1;
			return reach[i][j][d][t90] = 1;
		}
		if (!vis[i][j][(d+3)%4][1] && garage(i, j, (d+3)%4, 1)) {
			vis[i][j][d][t90] = 0;
			done[i][j][d][t90] = 1;
			return reach[i][j][d][t90] = 1;
		}
	}
	vis[i][j][d][t90] = 0;
	done[i][j][d][t90] = 1;
	return reach[i][j][d][t90] = 0;
}
bool canReach(int i, int j, int finDir) {
	memset(done, 0, sizeof done);
	return garage(i, j, (finDir+2)%4, 0);
}
class SnowClearing {
	public:
	int unreachable(vector <string> citymap, int row, int column) {
		int sol = 0;
		C = citymap;
		m = C.size();
		n = C[0].size();

		Gi = 2*(--row);
		Gj = 2*(--column);

		memset(vis, 0, sizeof vis);

		for (int i=0; i<m; ++i)
			for (int j=1-(i%2); j<n; j+=2)
				if (C[i][j] == '-') {
					if (!canReach(i, j-1, 1) || !canReach(i, j+1, 3))
						++sol;
				} else if (C[i][j] == '|') {
					if (!canReach(i-1, j, 2) || !canReach(i+1, j, 0))
						++sol;
				}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"+-+-+-+-+-+-+"
,"| | | | | | |"
,"+-+ +-+ +-+ +"
,"|   |   |    "
,"+-+-+-+-+-+-+"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 7; int Arg3 = 2; verify_case(0, Arg3, unreachable(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"+-+"
,"| |"
,"+ +"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 1; int Arg3 = 3; verify_case(1, Arg3, unreachable(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"+-+-+"
,"| | |"
,"+-+ +"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 3; int Arg3 = 1; verify_case(2, Arg3, unreachable(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"+-+-+"
,"|   |"
,"+-+-+"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 2; int Arg3 = 0; verify_case(3, Arg3, unreachable(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"+ +-+ +-+-+ +-+-+ +-+-+-+-+-+-+-+-+-+-+ +-+-+-+ +"
,"| |   | |     |   |   |         |     | |     | |"
,"+ +-+-+-+ +-+-+-+ +-+ +-+-+-+-+ +-+-+-+ +-+ +-+-+"
,"| | |       |   | |   |   |   |   |     | |   |  "
,"+ +-+-+ +-+-+ +-+-+-+-+-+-+-+ +-+ +-+ +-+ +-+ +-+"
,"|     | | | | |   |             |     |   | |   |"
,"+-+-+ +-+-+-+ +-+ +-+ + +-+-+-+-+-+ +-+-+ +-+-+-+"
,"|       | |     |     |   |         |   | |     |"
,"+-+-+-+ +-+-+-+-+-+-+-+-+-+-+ +-+ +-+ +-+-+-+-+-+"
,"      |   | |     |   | |     | | |   | |       |"
,"+ +-+-+-+-+ + +-+ +-+ +-+ +-+-+ +-+-+-+-+-+ +-+-+"
,"| |   | |     |   |         |   | | |     |   | |"
,"+-+-+-+-+-+ +-+-+ +-+-+-+ +-+-+ +-+-+ +-+-+ +-+-+"
,"          |   |   |   |   | |                    "
,"+-+-+-+-+-+-+ +-+-+-+ + +-+-+ +-+ +-+-+-+ +-+-+ +"
,"|                     | |     |   |   | |   | | |"
,"+ +-+-+-+-+-+-+ + +-+-+-+-+-+-+-+-+ +-+-+-+ + +-+"
,"| |     |   | | |   | | | |       | |   | | | | |"
,"+-+-+-+ +-+-+-+-+ +-+ + +-+ +-+-+-+ +-+-+ +-+ +-+"
,"    | |   | | |   |               |   |          "
,"+-+ +-+-+-+-+-+ +-+ + +-+-+-+-+-+-+ + + +-+-+ +-+"
,"  | | |         | | | |   |   | | | | | | | | |  "
,"+-+-+ + +-+ +-+ +-+-+-+-+ + + + +-+-+ +-+-+-+-+-+"
,"    | | | | | | |         | | |       |     | |  "
,"+ +-+ + + +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ +-+-+"
,"| |   | |     | |   |   |   |   |   | |         |"
,"+-+-+ +-+-+-+-+ +-+ + +-+-+-+-+ +-+ +-+-+-+-+-+-+"
,"      | |   | | | |     |       | |         | |  "
,"+-+ + +-+-+-+-+ + +-+-+-+ +-+-+-+-+ +-+ +-+-+-+-+"
,"  | | | |   |   |     | |   |   | |   | | |   |  "
,"+-+-+-+-+-+-+ +-+-+-+-+-+-+ +-+ +-+ +-+ +-+-+ +-+"
,"|     | | |   |     |     |   | | |   |   | | | |"
,"+-+-+-+-+-+-+ + +-+-+-+-+-+ +-+-+-+-+ +-+ + +-+-+"
,"| | | | |   | | |   | |         |     | | | |   |"
,"+ +-+ +-+-+ + + +-+-+ + + +-+-+-+-+ +-+ +-+-+-+-+"
,"  | | |   |     | |     |         |   | |   | | |"
,"+ +-+ +-+-+-+ +-+-+-+-+ +-+-+-+ +-+-+-+ +-+-+ + +"
,"|     | |     |   |           |   | | |   | | |  "
,"+-+-+-+-+-+-+-+ +-+-+ +-+-+-+-+-+ +-+-+ +-+-+ +-+"
,"|         |     |       | |   |       | | | | |  "
,"+-+-+-+ +-+-+-+-+-+-+-+-+ +-+ +-+ +-+-+ +-+-+-+-+"
,"        |   |   | | | | | | | | | | | | | |     |"
,"+-+-+-+-+-+-+-+ +-+-+ +-+-+ +-+-+-+ +-+ + +-+-+ +"
,"      | | | |       | |     | |   |       |   | |"
,"+ +-+-+-+-+-+ +-+ +-+ +-+-+-+ +-+-+-+-+-+ + +-+-+"
,"| | |       | | | |       |     | | | |       | |"
,"+-+-+-+-+-+-+-+ + +-+-+-+ + +-+-+-+-+-+-+-+ +-+ +"
,"      |   |   | |   | |         |     | | | | | |"
,"+-+-+-+-+-+-+-+-+-+ +-+-+-+-+ +-+-+-+ + + +-+-+ +"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 12; int Arg3 = 160; verify_case(4, Arg3, unreachable(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    SnowClearing ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
