#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

const long long mod = 179424673LL;

int dp[4001][4001];

class NumJordanForms {
	public:
	int howMany(vector <int> charPoly, vector <int> minPoly) {
		for (int n=0; n<4001; ++n)
			for (int k=1; k<4001; ++k) {
				if (n==0 || k==1) {
					dp[n][k] = 1;
					continue;
				}
				dp[n][k] = 0;
				if (n >= k) dp[n][k] += dp[n-k][k];
				dp[n][k] += dp[n][k-1];
				dp[n][k] %= mod;
			}

		long long sol = 1;
		for (int i=0; i<(int)charPoly.size(); ++i)
			sol = (sol * dp[charPoly[i]-minPoly[i]][minPoly[i]]) % mod;

		return (int)sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(0, Arg2, howMany(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(1, Arg2, howMany(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1,2,3,4,5,6,7,8,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,3,3,3,3,3,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 840; verify_case(2, Arg2, howMany(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {4000,4000,4000,4000,4000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {500,1000,1500,2000,2500}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 41788067; verify_case(3, Arg2, howMany(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    NumJordanForms ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
