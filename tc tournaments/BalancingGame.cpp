#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int tx[1<<20];
int ty[1<<20];
bool done[1<<20];
bool dp[1<<20];
int N;
int T;

long long sqr(long long x) {
	return x*x;
}
long long magn(int mask) {
	return sqr(tx[mask]) + sqr(ty[mask]);
}
bool win(int mask) {
	if (mask == 0)
		return N%2;

	if (done[mask])
		return dp[mask];

	done[mask] = 1;
	for (int i=0; i<N; ++i)
		if (mask & (1<<i))
			if (magn(mask ^ (1<<i))<=sqr(T) && !win(mask ^ (1<<i)))
				return dp[mask] = 1;

	return dp[mask] = 0;
}
class BalancingGame {
	public:
	vector <int> winningMoves(vector <int> x, vector <int> y, vector <int> w, int threshold) {
		N = x.size();
		T = threshold;
		memset(tx, 0, sizeof tx);
		memset(ty, 0, sizeof ty);
		for (int i=0; i<N; ++i)
			for (int m=1; m<(1<<N); ++m)
				if (m & (1<<i)) {
					tx[m] -= y[i]*w[i];
					ty[m] += x[i]*w[i];
				}

		if (magn((1<<N)-1) > sqr(T))
			return vector<int> (1, -1);

		memset(done, 0, sizeof done);

		vector<int> sol;
		for (int i=0; i<N; ++i) {
			int mask = ((1<<N)-1) ^ (1<<i);
			if (magn(mask)<=sqr(T) && !win(mask))
				sol.push_back(i);
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = { -10, 0, 10 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 0, 0, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 5, 5, 5 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; int Arr4[] = {1 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(0, Arg4, winningMoves(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = { 1, -1, 1, -1 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { -1, -1, 1, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 2, 3, 4, 5 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 10000; int Arr4[] = { }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(1, Arg4, winningMoves(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = { 0 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 10 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 50 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 15; int Arr4[] = {-1 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(2, Arg4, winningMoves(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = { -20, -21, 60 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 0, 0, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 20, 20, 10 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 300; int Arr4[] = {0, 1 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(3, Arg4, winningMoves(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = { -3, -30, 0, 0, 3, 30 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { -2, 20, 3, -30, -2, 20 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 6, 50, 7, 51, 8, 52 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1000; int Arr4[] = {0, 2, 4 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(4, Arg4, winningMoves(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    BalancingGame ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
