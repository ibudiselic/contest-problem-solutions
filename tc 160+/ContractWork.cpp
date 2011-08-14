#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int cost[50][50];
int numComp;
int numTasks;
int dp[50][51][51];
int go(int task, int last, int prelast) {
	if (task == numTasks)
		return 0;

	if (dp[task][last][prelast] != -1)
		return dp[task][last][prelast];

	dp[task][last][prelast] = 1234567890;
	for (int i=0; i<numComp; ++i)
		if (last!=prelast || i!=last)
			dp[task][last][prelast] = min(dp[task][last][prelast], cost[i][task] + go(task+1, i, last));

	return dp[task][last][prelast];
}
class ContractWork {
	public:
	int minimumCost(vector <string> costs, int nt) {
		numTasks = nt;
		numComp = costs.size();

		for (int i=0; i<numComp; ++i) {
			istringstream is(costs[i]);
			for (int j=0; j<numTasks; ++j)
				is >> cost[i][j];
		}

		memset(dp, 0xff, sizeof dp);

		return go(0, 50, 50);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"1 2 3", "4 5 6"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 9; verify_case(0, Arg2, minimumCost(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"1 1 1 1", "1 1 1 1", "1 1 1 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 4; verify_case(1, Arg2, minimumCost(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"12 14 4 11 0 35", "44 41 1 1 0 15", "35 1 35 55 1 13", "0 0 0 0 0 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; int Arg2 = 1; verify_case(2, Arg2, minimumCost(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"44 92 2 78 13",
"36 47 76 41 71",
"59 27 59 35 16",
"40 63 7 72 76",
"49 80 45 67 33"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 113; verify_case(3, Arg2, minimumCost(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ContractWork ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
