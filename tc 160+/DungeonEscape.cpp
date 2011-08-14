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

int best[50][50];

struct state {
	int cost, i, j;
	state(int cost_, int i_, int j_): cost(cost_), i(i_), j(j_) {}
};
bool operator<(const state &a, const state &b) {
	if (a.cost != b.cost)
		return a.cost > b.cost;
	else if (a.i != b.i)
		return a.i < b.i;
	else
		return a.j < b.j;
}
class DungeonEscape {
	public:
	int exitTime(vector <string> up, vector <string> down, vector <string> east, vector <string> west, int startLevel, int startEasting) {
		int m, n;

		m = up.size();
		n = up[0].size();

		for (int i=0; i<m; ++i)
			west[i][0] = east[i][n-1] = 'x';

		for (int j=0; j<n; ++j)
			down[m-1][j] = 'x';

		for (int i=0; i<m; ++i)
			for (int j=0; j<n; ++j)
				best[i][j] = 1234567890;

		best[startLevel][startEasting] = 0;
		priority_queue<state> PQ;

		PQ.push(state(0, startLevel, startEasting));

		int sol = 1234567890;

		while (!PQ.empty()) {
			int cost = PQ.top().cost;
			int i = PQ.top().i;
			int j = PQ.top().j;
			PQ.pop();

			//cerr << cost << '\n';

			if (i == -1)
				return cost;

			// check drowning
			if (m-1-cost/n < i)
				continue;

			if (cost > best[i][j])
				continue;

			int ni, nj, nc;

			if (up[i][j] != 'x') {
				ni = i-1;
				nj = j;
				nc = cost + up[i][j]-'0';

				if (ni == -1) {
					if (nc < sol) {
						sol = nc;
						PQ.push(state(nc, ni, nj));
					}
				} else if (nc < best[ni][nj]) {
					best[ni][nj] = nc;
					PQ.push(state(nc, ni, nj));
				}
			}
			if (down[i][j] != 'x') {
				ni = i+1;
				nj = j;
				nc = cost + down[i][j]-'0';

				if (nc < best[ni][nj]) {
					best[ni][nj] = nc;
					PQ.push(state(nc, ni, nj));
				}
			}
			if (west[i][j] != 'x') {
				ni = i;
				nj = j-1;
				nc = cost + west[i][j]-'0';

				if (nc < best[ni][nj]) {
					best[ni][nj] = nc;
					PQ.push(state(nc, ni, nj));
				}
			}
			if (east[i][j] != 'x') {
				ni = i;
				nj = j+1;
				nc = cost + east[i][j]-'0';

				if (nc < best[ni][nj]) {
					best[ni][nj] = nc;
					PQ.push(state(nc, ni, nj));
				}
			}
		}

		return -1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"0x4",
 "0x3",
 "0x3"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0x9",
 "009",
 "0x9"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"0x9",
 "1x9",
 "009"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"0x9",
 "0x0",
 "009"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 2; int Arg5 = 2; int Arg6 = 10; verify_case(0, Arg6, exitTime(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_1() { string Arr0[] = {"xxxxxxxxx1",
 "1xxxxxxxxx",
 "xxxxxxxxx1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"xxxxxxxxxx",
 "xxxxxxxxxx",
 "xxxxxxxxxx"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"1111111111",
 "xxxxxxxxxx",
 "1111111111"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"xxxxxxxxxx",
 "1111111111",
 "xxxxxxxxxx"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 2; int Arg5 = 0; int Arg6 = 30; verify_case(1, Arg6, exitTime(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_2() { string Arr0[] = {"xxxxxxxxx1",
 "xxxx999991",
 "x999999991"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1111111111",
 "1111111111",
 "1111111111"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"1111122242",
 "2222222241",
 "2111111111"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"xxxxxxxxx1",
 "1111111111",
 "xxxxxxxxx1"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 2; int Arg5 = 0; int Arg6 = -1; verify_case(2, Arg6, exitTime(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_3() { string Arr0[] = {"1x2x3x4x5x6x7x8x9",
 "00000000000000000",
 "98765432223456789",
 "12345678987654321"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"00000000000000000",
 "00000000000000000",
 "00000000000000000",
 "00000000000000000"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"xxxxxxxxxxxxxxxxx",
 "xxxxxxxxxxxxxxxxx",
 "22222222222222222",
 "33333333333333333"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"xxxxxxxxxxxxxxxxx",
 "xxxxxxxxxxxxxxxxx",
 "22222222222222222",
 "33333333333333333"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 3; int Arg5 = 12; int Arg6 = 17; verify_case(3, Arg6, exitTime(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    DungeonEscape ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
