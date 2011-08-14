#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

const long long mod = 1000000000;
long long ncr[501][501];
int gcd(int m, int n) {
	return (n==0 ? m : gcd(n, m%n));
}
class BackyardTrees {
	public:
	int countWays(int n, int w, int h, int dist) {
		if (n == 1)
			return (w+1)*(h+1);

		for (int i=0; i<=max(w, h); ++i) {
			ncr[i][0] = 1;
			ncr[i][i] = 1;
			for (int j=1; j<i; ++j)
				ncr[i][j] = (ncr[i-1][j-1] + ncr[i-1][j])%mod;
		}

		int sol = 0;
		for (int x=0; x<=w; ++x)
			for (int y=0; y<=h; ++y)
				if (x+y != 0) {
					int g = gcd(x, y);
					int ux = x/g;
					int uy = y/g;
					int gap = (int)ceil(dist/sqrt(ux*ux + uy*uy));
					int avail = g+1 - (gap-1)*(n-1) - 2; // g+1 places overall, lose (gap-1) integer locations per each of the (n-1) gaps, fix (0, 0) and (x, y) (-2)
					if (avail >= n-2)
						sol = (sol + (x==0||y==0 ? 1 : 2) * ncr[avail][n-2]*(w-x+1)*(h-y+1))%mod; // translate (0, 0) on x and/or on y
				}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 4; int Arg2 = 4; int Arg3 = 1; int Arg4 = 300; verify_case(0, Arg4, countWays(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 13; int Arg1 = 36; int Arg2 = 48; int Arg3 = 5; int Arg4 = 2; verify_case(1, Arg4, countWays(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 5; int Arg2 = 5; int Arg3 = 1; int Arg4 = 88; verify_case(2, Arg4, countWays(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 50; int Arg1 = 49; int Arg2 = 49; int Arg3 = 1; int Arg4 = 102; verify_case(3, Arg4, countWays(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 6; int Arg1 = 5; int Arg2 = 5; int Arg3 = 2; int Arg4 = 0; verify_case(4, Arg4, countWays(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arg0 = 10; int Arg1 = 55; int Arg2 = 75; int Arg3 = 5; int Arg4 = 490260662; verify_case(5, Arg4, countWays(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    BackyardTrees ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
