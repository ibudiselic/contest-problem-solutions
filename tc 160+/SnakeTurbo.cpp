#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool done[52][52][2][52];
double dp[52][52][2][52];
vector<int> O;
int S, E;

double go(int l, int r, bool olb, int e) {
	if (olb && O[l]==E || !olb && O[r]==E)
		return 0;
	if (done[l][r][olb][e])
		return dp[l][r][olb][e];

	done[l][r][olb][e] = true;
	double &ret = dp[l][r][olb][e];
	ret = 1e32;
	if (olb) {
		if (l > 0)
			ret = min(ret, go(l-1, r, true, e+1) + double(O[l]-O[l-1])/(1LL << e));
		if (r+1 < (int)O.size())
			ret = min(ret, go(l, r+1, false, e+1) + double(O[r+1]-O[l])/(1LL << e));
	} else {
		if (l > 0)
			ret = min(ret, go(l-1, r, true, e+1) + double(O[r]-O[l-1])/(1LL << e));
		if (r+1 < (int)O.size())
			ret = min(ret, go(l, r+1, false, e+1) + double(O[r+1]-O[r])/(1LL << e));
	}

	return ret;
}

class SnakeTurbo {
	public:
	double finishTime(int startLocation, int endLocation, vector <int> orbs) {
		memset(done, 0, sizeof done);
		S = startLocation;
		E = endLocation;
		O = orbs;
		O.push_back(S);
		O.push_back(E);

		sort(O.begin(), O.end());

		for (int i=0; i<(int)O.size(); ++i)
			if (O[i] == S)
				return go(i, i, true, 0);

		return -1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arg1 = 20; int Arr2[] = {2, 18, 8}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 7.5; verify_case(0, Arg3, finishTime(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 0; int Arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 1.998046875; verify_case(1, Arg3, finishTime(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 77; int Arg1 = 77; int Arr2[] = {27, 127}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 0.0; verify_case(2, Arg3, finishTime(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 0; int Arg1 = 100000000; int Arr2[] = {99999999}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 9.99999995E7; verify_case(3, Arg3, finishTime(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 100; int Arg1 = 200; int Arr2[] = {99, 102, 96, 108, 84, 132, 36}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 8.375; verify_case(4, Arg3, finishTime(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    SnakeTurbo ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
