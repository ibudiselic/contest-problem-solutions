#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <utility>

using namespace std;

int gcd(int m, int n) {
	return (n==0 ? m : gcd(n, m%n));
}

int basic[201][201];
int bestX[201];
int bestY[201];
class ConvexHull {
	public:
	int intHull(int m, int n) {
		vector< pair<int, int> > V;
		V.push_back(make_pair(0, 1));
		V.push_back(make_pair(1, 1));
		for (int i=1; i<=200; ++i)
			for (int j=i+1; j<=200; ++j)
				if (gcd(j, i) == 1) {
					V.push_back(make_pair(i, j));
					V.push_back(make_pair(j, i));
				}

		memset(basic, 0xff, sizeof basic);
		basic[0][0] = 0;
		for (int i=0; i<(int)V.size(); ++i)
			for (int r=200; r>=V[i].first; --r)
				for (int c=200; c>=V[i].second; --c)
					if (basic[r-V[i].first][c-V[i].second] != -1)
						basic[r][c] = max(basic[r][c], basic[r-V[i].first][c-V[i].second] + 1);
		for (int i=0; i<=200; ++i)
			for (int j=0; j<=200; ++j) {
				if (i)
					basic[i][j] = max(basic[i][j], basic[i-1][j]);
				if (j)
					basic[i][j] = max(basic[i][j], basic[i][j-1]);
			}

		int sol = 0;
		for (int x=0; x<=m; ++x) {
			memset(bestY, 0xff, sizeof bestY);
			for (int y=0; y<=n; ++y)
				bestY[y] = basic[m-x][y];

			memset(bestX, 0xff, sizeof bestX);
			for (int x2=0; x2<=m; ++x2)
				for (int y=0; y<=n; ++y)
					bestX[x2] = max(bestX[x2], bestY[y] + basic[n-y][m-x2]);

			memset(bestY, 0xff, sizeof bestY);
			for (int y=0; y<=n; ++y)
				for (int x2=0; x2<=m; ++x2)
					bestY[y] = max(bestY[y], bestX[x2] + basic[x2][n-y] + basic[y][x]);

			sol = max(sol, *max_element(bestY, bestY+201));
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 8; verify_case(0, Arg2, intHull(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 50; int Arg2 = 8; verify_case(1, Arg2, intHull(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 4; int Arg2 = 9; verify_case(2, Arg2, intHull(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 5; int Arg2 = 10; verify_case(3, Arg2, intHull(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 50; int Arg1 = 200; int Arg2 = 74; verify_case(4, Arg2, intHull(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ConvexHull ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
