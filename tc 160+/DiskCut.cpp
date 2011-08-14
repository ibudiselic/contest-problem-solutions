#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

double dp[50][50];
bool done[50][50];
int sum[50];
int N;
int A;
double go(int l, int r) {
	if (l == r)
		return 0.0;
	if (done[l][r])
		return dp[l][r];

	const int p = sum[r]-(l==0 ? 0 : sum[l-1]);
	done[l][r] = 1;
	dp[l][r] = 1e30;
	for (int i=l; i<r; ++i)
		dp[l][r] = min(dp[l][r], (A*p/100.0) + go(l, i) + go(i+1, r));

	return dp[l][r];
}

class DiskCut {
	public:
	double minCost(int area, vector <int> percent) {
		A = area;
		N = percent.size();

		sort(percent.begin(), percent.end());
		sum[0] = percent[0];
		for (int i=1; i<N; ++i)
			sum[i] = sum[i-1]+percent[i];

		memset(done, 0, sizeof done);

		return area + go(0, N-1);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arr1[] = {25,25,25,25}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 12.0; verify_case(0, Arg2, minCost(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 5; int Arr1[] = {20,20,20,20,20}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 17.0; verify_case(1, Arg2, minCost(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1; int Arr1[] = {10, 40, 30, 20}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 2.9; verify_case(2, Arg2, minCost(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    DiskCut ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
