#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<int> pA, pB, rA, rB;
#define ZERO 500
double dp[301][1000][2]; // timeLeft, scoreDiff, aPlaying
bool done[301][1000][2];

double go(int timeLeft, int scoreDiff, bool aPlaying) {
	assert(scoreDiff>=0 && scoreDiff<1000);
	if (timeLeft < 0)
		return scoreDiff>ZERO ? 1.0 : 0.0;

	if (done[timeLeft][scoreDiff][aPlaying])
		return dp[timeLeft][scoreDiff][aPlaying];

	done[timeLeft][scoreDiff][aPlaying] = 1;
	double &ret = dp[timeLeft][scoreDiff][aPlaying];
	ret = (aPlaying ? 0.0 : 1.0);

	for (int i=0; i<(int)(aPlaying ? pA.size() : pB.size()) && i<=timeLeft; ++i) {
		double nextProb = double(aPlaying ? pA[i] : pB[i])/100 * go(timeLeft-i-2, scoreDiff + (aPlaying ? 2 : -2), !aPlaying) // score
							+
						  (1.0 - double(aPlaying ? pA[i] : pB[i])/100) // miss
						  		*
						  		(double(aPlaying ? rA[i] : rB[i])/100 * go(timeLeft-i-2, scoreDiff, aPlaying) // rebound
						  			+
						  		(1.0 - double(aPlaying ? rA[i] : rB[i])/100) * go(timeLeft-i-2, scoreDiff, !aPlaying)); // no rebound
		if (aPlaying)
			ret = max(ret, nextProb);
		else
			ret = min(ret, nextProb);
	}

	return ret;
}
class ClockManagement {
	public:
	double winProbability(vector <int> percentageA, vector <int> percentageB, vector <int> reboundA, vector <int> reboundB, int time, int scoreA, int scoreB) {
		pA = percentageA;
		pB = percentageB;
		rA = reboundA;
		rB = reboundB;

		memset(done, 0, sizeof done);
		return go(time-2, ZERO + scoreA-scoreB, 1);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {10,20,30,40}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10,20,30,40}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,3,4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,2,3,4}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 5; int Arg5 = 99; int Arg6 = 100; double Arg7 = 0.4; verify_case(0, Arg7, winProbability(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_1() { int Arr0[] = {10,20,30,40}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10,20,30,40}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,3,4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,2,3,4}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 5; int Arg5 = 98; int Arg6 = 100; double Arg7 = 0.0; verify_case(1, Arg7, winProbability(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_2() { int Arr0[] = {10,20,30,40}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10,20,30,40}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,3,4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,2,3,4}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 10; int Arg5 = 98; int Arg6 = 100; double Arg7 = 0.011519999999999997; verify_case(2, Arg7, winProbability(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_3() { int Arr0[] = {100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {100}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {100}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 31; int Arg5 = 65; int Arg6 = 66; double Arg7 = 1.0; verify_case(3, Arg7, winProbability(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ClockManagement ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
