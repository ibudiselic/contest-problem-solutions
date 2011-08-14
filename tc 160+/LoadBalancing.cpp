#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <numeric>

using namespace std;

bool dp[204801];
class LoadBalancing {
	public:
	int minTime(vector <int> v) {
		for (int i=0; i<(int)v.size(); ++i)
			v[i] /= 1024;

		int sum = accumulate(v.begin(), v.end(), 0);
		memset(dp, 0, sizeof dp);
		dp[0] = 1;
		for (int i=0; i<(int)v.size(); ++i)
			for (int j=sum-1; j>=0; --j)
				if (dp[j])
					dp[j+v[i]] = 1;

		int sol = 1234567890;
		for (int i=0; i<=sum; ++i)
			if (dp[i])
				sol = min(sol, max(i, sum-i));

		return sol*1024;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3072, 3072, 7168, 3072, 1024}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9216; verify_case(0, Arg1, minTime(Arg0)); }
	void test_case_1() { int Arr0[] = {2048}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2048; verify_case(1, Arg1, minTime(Arg0)); }
	void test_case_2() { int Arr0[] = {2048, 1024, 1024, 2048}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3072; verify_case(2, Arg1, minTime(Arg0)); }
	void test_case_3() { int Arr0[] = {4194304, 4194304, 4194304, 4194304, 4194304,
 4194304, 4194304, 4194304, 4194304, 4194304,
 4194304, 4194304, 4194304, 4194304, 4194304,
 4194304, 4194304, 4194304, 4194304, 4194304,
 4194304, 4194304, 4194304, 4194304, 4194304,
 4194304, 4194304, 4194304, 4194304, 4194304,
 4194304, 4194304, 4194304, 4194304, 4194304,
 4194304, 4194304, 4194304, 4194304, 4194304,
 4194304, 4194304, 4194304, 4194304, 4194304,
 4194304, 4194304, 4194304, 4194304, 4194304}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 104857600; verify_case(3, Arg1, minTime(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    LoadBalancing ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
