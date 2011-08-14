#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<int> P, A;
double calcWin(int x, double p, int val, int winVal, int cntWinners) {
	if (x == (int)A.size()) {
		if (cntWinners == 1)
			val -= winVal;
		return p*val;
	}
	return calcWin(x+1, p*double(P[x])/100, val+A[x], winVal+A[x], cntWinners+1) + calcWin(x+1, p*(1-double(P[x])/100), val+A[x], winVal, cntWinners);
}
double calcLose(int x, double p, int val, int winVal, int cntWinners) {
	if (x == (int)A.size()) {
		if (cntWinners == 1)
			return p*winVal;
		return 0;
	}
	return calcLose(x+1, p*double(P[x])/100, val+A[x], winVal+A[x], cntWinners+1) + calcLose(x+1, p*(1-double(P[x])/100), val+A[x], winVal, cntWinners);
}
class RaceManagement {
	public:
	double getPayoutFactor(vector <int> probability, vector <int> amounts, int minimumMoney) {
		P = probability;
		A = amounts;

		double win = calcWin(0, 1.0, 0, 0, 0);
		double lose = calcLose(0, 1.0, 0, 0, 0);

		if (lose<=1e-9 && win>=minimumMoney-1e-9)
			return -2.0;

		if (win < minimumMoney-1e-9)
			return -1.0;

		return double(win-minimumMoney)/lose;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {30}	; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10; double Arg3 = 2.0; verify_case(0, Arg3, getPayoutFactor(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {50,40}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {300,200}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 100; double Arg3 = 2.076923076923077; verify_case(1, Arg3, getPayoutFactor(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {50}	; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1000; double Arg3 = -1.0; verify_case(2, Arg3, getPayoutFactor(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {100}	; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 100; double Arg3 = -2.0; verify_case(3, Arg3, getPayoutFactor(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    RaceManagement ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
