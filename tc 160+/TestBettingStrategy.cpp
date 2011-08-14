#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

double dp[1001][51][51];
bool done[1001][51][51];
int goal;
double p;

double go(long long cur, int round, int losingStreak) {
	if (cur >= goal)
		return 1.0;
	if (round == 0)
		return 0.0;
	long long bet = 1LL<<losingStreak;
	if (cur < bet)
		return 0.0;
	if (done[cur][round][losingStreak])
		return dp[cur][round][losingStreak];



	done[cur][round][losingStreak] = 1;
	return dp[cur][round][losingStreak] = p*go(cur+bet, round-1, 0) + (1-p)*go(cur-bet, round-1, losingStreak+1);
}

class TestBettingStrategy {
	public:
	double winProbability(int initSum, int goalSum, int rounds, int prob) {
		memset(done, 0, sizeof done);

		goal = goalSum;
		p = prob/100.0;

		return go(initSum, rounds, 0);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arg1 = 11; int Arg2 = 4; int Arg3 = 50; double Arg4 = 0.875; verify_case(0, Arg4, winProbability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 20; int Arg2 = 20; int Arg3 = 50; double Arg4 = 0.3441343307495117; verify_case(1, Arg4, winProbability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 20; int Arg2 = 10; int Arg3 = 90; double Arg4 = 0.34867844010000015; verify_case(2, Arg4, winProbability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 24; int Arg1 = 38; int Arg2 = 24; int Arg3 = 60; double Arg4 = 0.5940784635646947; verify_case(3, Arg4, winProbability(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    TestBettingStrategy ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
