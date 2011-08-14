#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

double dp[21][21];
int n, w;
double p;
class ScrabbleBet {
	public:
	double estimate(int trials, int games, int winsNeeded, int winChance) {
		for (int i=0; i<21; ++i)
			for (int j=0; j<21; ++j)
				dp[i][j] = 0.0;
		p = double(winChance)/100;
		n = games;
		w = winsNeeded;

		dp[0][0] = 1;
		for (int i=1; i<=n; ++i)
			for (int cnt=0; cnt<=i; ++cnt) {
				dp[i][cnt] = 0;
				if (cnt > 0)
					dp[i][cnt] += p*dp[i-1][cnt-1];
				dp[i][cnt] += (1-p)*dp[i-1][cnt];
			}

		double single = 0.0;
		for (int cnt=w; cnt<=n; ++cnt)
			single += dp[n][cnt];
		single = 1 - single;
		double sol = 1.0;
		while (trials--)
			sol *= single;

		return 1-sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 1; int Arg3 = 50; double Arg4 = 0.9375; verify_case(0, Arg4, estimate(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 2; int Arg3 = 50; double Arg4 = 0.4375; verify_case(1, Arg4, estimate(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 10; int Arg2 = 5; int Arg3 = 25; double Arg4 = 0.5566860567603682; verify_case(2, Arg4, estimate(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 2; int Arg1 = 20; int Arg2 = 5; int Arg3 = 10; double Arg4 = 0.08448495352665641; verify_case(3, Arg4, estimate(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 50; int Arg1 = 15; int Arg2 = 1; int Arg3 = 0; double Arg4 = 0.0; verify_case(4, Arg4, estimate(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arg0 = 50; int Arg1 = 17; int Arg2 = 16; int Arg3 = 100; double Arg4 = 1.0; verify_case(5, Arg4, estimate(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_6() { int Arg0 = 50; int Arg1 = 10; int Arg2 = 10; int Arg3 = 75; double Arg4 = 0.9448701546682944; verify_case(6, Arg4, estimate(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ScrabbleBet ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
