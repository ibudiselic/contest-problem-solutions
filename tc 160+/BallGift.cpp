#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

double prob[31][30][16][16][16];

class BallGift {
	public:
	double go(int n, int p, int g, int r, int b) {
		if (g+r+b == 0)
			return p == 0;
		if (prob[n][p][g][r][b] > -0.5)
			return prob[n][p][g][r][b];

		double ret = 0.0;
		if (g > 0) ret += g * go(n, (p-1+n)%n, g-1, r, b);
		if (r > 0) ret += r * go(n, (n-p-1)%n, g, r-1, b);
		if (b>0 && p!=0) ret += b * go(n-1, (p-1+n)%n, g, r, b-1);

		return prob[n][p][g][r][b] = ret/(g+r+b);
	}
	int bestPosition(int players, int green, int red, int black) {
		for (int n=0; n<=players; ++n)
			for (int i=0; i<n; ++i)
				for (int g=0; g<=green; ++g)
					for (int r=0; r<=red; ++r)
						for (int b=0; b<=black; ++b)
							prob[n][i][g][r][b] = -1.0;

		double best = -2.0;
		int sol = -1;
		for (int i=0; i<players; ++i) {
			const double t = go(players, i, green, red, black);
			if (t - 1e-10 > best) {
				best = t;
				sol = i;
			}
		}
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 3; int Arg2 = 0; int Arg3 = 0; int Arg4 = 3; verify_case(0, Arg4, bestPosition(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 0; int Arg2 = 1; int Arg3 = 0; int Arg4 = 3; verify_case(1, Arg4, bestPosition(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 1; int Arg2 = 1; int Arg3 = 0; int Arg4 = 0; verify_case(2, Arg4, bestPosition(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 1; int Arg2 = 1; int Arg3 = 1; int Arg4 = 1; verify_case(3, Arg4, bestPosition(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 4; int Arg1 = 2; int Arg2 = 2; int Arg3 = 2; int Arg4 = 0; verify_case(4, Arg4, bestPosition(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    BallGift ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
