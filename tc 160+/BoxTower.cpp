#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<int> X, Y, Z;
int dp[1<<15][16][3];

bool test(int a, int b, int c, int d) {
	return a<=c && b<=d || a<=d && b<=c;
}
bool fit(int i, int mi, int j, int mj) {
	if (mi == 0) {
		if (mj == 0) return test(X[i], Y[i], X[j], Y[j]);
		else if (mj == 1) return test(X[i], Y[i], X[j], Z[j]);
		else if (mj == 2) return test(X[i], Y[i], Y[j], Z[j]);
		else assert(0);
	} else if (mi == 1) {
		if (mj == 0) return test(X[i], Z[i], X[j], Y[j]);
		else if (mj == 1) return test(X[i], Z[i], X[j], Z[j]);
		else if (mj == 2) return test(X[i], Z[i], Y[j], Z[j]);
		else assert(0);
	} else if (mi == 2) {
		if (mj == 0) return test(Y[i], Z[i], X[j], Y[j]);
		else if (mj == 1) return test(Y[i], Z[i], X[j], Z[j]);
		else if (mj == 2) return test(Y[i], Z[i], Y[j], Z[j]);
		else assert(0);
	} else {
		assert(0);
	}
	return false;
}
int h(int i, int mode) {
	switch (mode) {
		case 0: return Z[i];
		case 1: return Y[i];
		case 2: return X[i];
		default: assert(0);
	}
	return -1;
}

int go(unsigned mask, int last, int lm) {
	if (dp[mask][last][lm] != -1)
		return dp[mask][last][lm];
	if (mask == 0)
		return dp[mask][last][lm] = 0;

	int ret = 0;
	for (int i=0; i<(int)X.size()-1; ++i)
		if ((mask & (1u<<i))!=0)
			for (int nm=0; nm<3; ++nm)
				if (fit(i, nm, last, lm))
					ret = max(ret, h(i, nm) + go(mask ^ (1u<<i), i, nm));
	return dp[mask][last][lm] = ret;
}
class BoxTower {
	public:
	int tallestTower(vector <int> x, vector <int> y, vector <int> z) {
		memset(dp, 0xff, sizeof dp);
		X = x, Y = y, Z = z;
		X.push_back(10000000);
		Y.push_back(10000000);
		Z.push_back(0);
		return go((1u<<(int)X.size()-1) - 1, X.size()-1, 0);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {10, 50, 40, 20, 30}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10, 50, 40, 20, 30}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10, 50, 40, 20, 30}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 150; verify_case(0, Arg3, tallestTower(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {20, 30}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {20, 30}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {20, 10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 30; verify_case(1, Arg3, tallestTower(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {20, 30}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {20, 33}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {20, 10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 33; verify_case(2, Arg3, tallestTower(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {100, 100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10, 12}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10, 8}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 110; verify_case(3, Arg3, tallestTower(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    BoxTower ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
