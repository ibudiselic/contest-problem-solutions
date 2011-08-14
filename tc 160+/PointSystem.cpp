#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

double best[1000][1000];
class PointSystem {
	public:
	double oddsOfWinning(int pointsToWin, int pointsToWinBy, int skill) {
		for (int i=0; i<1000; ++i)
			for (int j=0; j<1000; ++j)
				best[i][j] = 0.0;

		double p = skill/100.0;

		best[0][0] = 1.0;
		double sol = 0.0;
		for (int i=0; i<999; ++i)
			for (int j=0; j<999; ++j) {
				if (j>=pointsToWin && j-i>=pointsToWinBy) continue;
				if (i>=pointsToWin && i-j>=pointsToWinBy) { sol += best[i][j]; continue; }
				best[i+1][j] += p*best[i][j]; best[i][j+1] += (1-p)*best[i][j];
			}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 1; int Arg2 = 40; double Arg3 = 0.352; verify_case(0, Arg3, oddsOfWinning(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 5; int Arg2 = 50; double Arg3 = 0.4999999999999998; verify_case(1, Arg3, oddsOfWinning(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 25; double Arg3 = 0.035714285714285705; verify_case(2, Arg3, oddsOfWinning(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    PointSystem ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
