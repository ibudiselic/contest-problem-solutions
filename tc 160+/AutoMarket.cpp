#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<int> cost, feat, Time;
int n;

int dp[51];
int go(int x) {
	if (dp[x] != -1)
		return dp[x];

	dp[x] = 0;
	for (int i=0; i<n; ++i)
		if (cost[i]>cost[x] && feat[i]<feat[x] && Time[i]>Time[x])
			dp[x] = max(dp[x], 1+go(i));

	return dp[x];
}
class AutoMarket {
	public:
	int maxSet(vector <int> c, vector <int> features, vector <int> fixTimes) {
		cost = c;
		feat = features;
		Time = fixTimes;
		n = cost.size();
		cost.push_back(0);
		feat.push_back(101);
		Time.push_back(0);

		memset(dp, 0xff, sizeof dp);
		return go(n);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {10000, 14000, 8000, 12000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 4, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {17, 15, 8, 11}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; verify_case(0, Arg3, maxSet(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {1,2,3,4,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,3,4,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(1, Arg3, maxSet(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {9000, 6000, 5000, 5000, 7000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 3, 4, 5, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10, 6, 6, 5, 9}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 4; verify_case(2, Arg3, maxSet(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 20; verify_case(3, Arg3, maxSet(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {1000, 1000, 1000, 1000, 2000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3,3,4,3,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3,3,3,4,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(4, Arg3, maxSet(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    AutoMarket ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
