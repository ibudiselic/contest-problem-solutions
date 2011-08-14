#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

double dp[51][2][2501];
class Conditional {
	public:
	double probability(int nDice, int maxSide, int V, int theSum) {
		const double p = 1.0/maxSide;
		for (int i=0; i<51; ++i)
			for (int j=0; j<2; ++j)
				for (int k=0; k<2501; ++k)
					dp[i][j][k] = 0.0;
		for (int i=1; i<=maxSide; ++i) {
			dp[1][0][i] = (i!=V) * p;
			dp[1][1][i] = (i==V) * p;
		}

		for (int i=2; i<=nDice; ++i)
			for (int sum=1; sum<=nDice*maxSide; ++sum)
				for (int x=1; x<=min(sum, maxSide); ++x)
					if (x==V)
						dp[i][1][sum] += (dp[i-1][0][sum-x] + dp[i-1][1][sum-x])*p;
					else {
						dp[i][0][sum] += dp[i-1][0][sum-x]*p;
						dp[i][1][sum] += dp[i-1][1][sum-x]*p;
					}

		double sol = 0.0;
		for (int s=theSum; s<=nDice*maxSide; ++s)
			sol += dp[nDice][1][s];

		double cond = 1.0;
		for (int i=0; i<nDice; ++i)
			cond *= double(maxSide-1)/maxSide;
		return sol/(1-cond);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 6; int Arg2 = 6; int Arg3 = 12; double Arg4 = 0.09090909090909091; verify_case(0, Arg4, probability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 6; int Arg2 = 6; int Arg3 = 6; double Arg4 = 1.0; verify_case(1, Arg4, probability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 9; int Arg2 = 3; int Arg3 = 3; double Arg4 = 1.0; verify_case(2, Arg4, probability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 2; int Arg1 = 3; int Arg2 = 2; int Arg3 = 4; double Arg4 = 0.6; verify_case(3, Arg4, probability(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Conditional ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
