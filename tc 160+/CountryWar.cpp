#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

double dp[1u<<15][21];
double prob[21][21][21]; // prob[i][j][k] i units vs j units left with k units after war
unsigned adj[15];
int army[15];
double temp[21][21];
unsigned enemy;
int n;

double go(unsigned own, int units) {
	if ((own | enemy) == own)
		return 1.0;
	if (dp[own][units] > -0.5)
		return dp[own][units];

	double best = 0.0;
	for (int i=0; i<n; ++i) {
		if (((own>>i) & 1)==0 && (adj[i]&own)!=0) {
			double d = 0.0;
			for (int k=1; k<=units; ++k)
				d += prob[units][army[i]][k] * go(own | (1<<i), k);
			best = max(best, d);
		}
	}
	return dp[own][units] = best;
}
class CountryWar {
	public:
	double defeatAll(vector <string> armies) {
		memset(adj, 0, sizeof adj);
		n = armies.size();
		for (int i=0; i<(1<<15); ++i)
			for (int j=0; j<21; ++j)
				dp[i][j] = -1.0;

		unsigned own = 0;
		enemy = 0;
		int start = -1;
		for (int i=0; i<n; ++i) {
			istringstream is(armies[i]);
			char c;
			int x;
			is >> c >> x;
			army[i] = x;
			if (c == 'Y') {
				own |= (1<<i);
				start = x;
			} else if (c == 'E')
				enemy |= (1<<i);
			while (is >> x)
				adj[i] |= (1<<x);
		}

		for (int i=1; i<21; ++i)
			for (int j=1; j<21; ++j) {
				for (int x=0; x<=i; ++x)
					for (int y=0; y<=j; ++y)
						temp[x][y] = 0.0;
				temp[i][j] = 1.0;
				for (int x=i; x>0; --x)
					for (int y=j; y>0; --y) {
						const double dy = (double)x*x/(x*x+x*y+y*y);
						const double dx = 1.0 - dy;
						temp[  x][y-1] += dy * temp[x][y];
						temp[x-1][  y] += dx * temp[x][y];
					}
				for (int k=0; k<=i; ++k)
					prob[i][j][k] = temp[k][0];
			}
		return go(own, start);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"Y 1 1",
 "E 1 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.3333333333333333; verify_case(0, Arg1, defeatAll(Arg0)); }
	void test_case_1() { string Arr0[] = {"Y 2 1",
 "E 1 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.7142857142857142; verify_case(1, Arg1, defeatAll(Arg0)); }
	void test_case_2() { string Arr0[] = {"Y 1 1",
 "E 1 0 2",
 "N 1 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.3333333333333333; verify_case(2, Arg1, defeatAll(Arg0)); }
	void test_case_3() { string Arr0[] = {"Y 1 1",
 "N 1 0 2",
 "E 1 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.1111111111111111; verify_case(3, Arg1, defeatAll(Arg0)); }
	void test_case_4() { string Arr0[] = {"Y 2 1 2",
 "E 2 0 2",
 "E 1 0 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.16250944822373392; verify_case(4, Arg1, defeatAll(Arg0)); }
	void test_case_5() { string Arr0[] = {"Y 1",
 "E 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.0; verify_case(5, Arg1, defeatAll(Arg0)); }
	void test_case_6() { string Arr0[] = {"Y 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1.0; verify_case(6, Arg1, defeatAll(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    CountryWar ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
