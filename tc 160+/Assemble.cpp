#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<int> inp, out;
int n;

int dp[50][50];

class Assemble {
	public:
	int minCost(vector <int> connect) {
		n = connect.size()-1;
		inp.assign(n, 0);
		out.assign(n, 0);

		for (int i=0; i<n; ++i) {
			inp[i] = connect[i];
			out[i] = connect[i+1];
		}

		memset(dp, 0, sizeof dp);

		for (int len=1; len<n; ++len)
			for (int left=0; left+len<n; ++left) {
				const int right = left+len;
				dp[left][right] = 1234567890;

				for (int split=left; split<right; ++split)
					dp[left][right] = min(dp[left][right], dp[left][split] + (inp[left] + (split-left+1)) * out[split] * (out[right] + (right-split)) + dp[split+1][right]);
			}

		return dp[0][n-1];
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {19,50,10,39}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 19400; verify_case(0, Arg1, minCost(Arg0)); }
	void test_case_1() { int Arr0[] = {13,18,24,11,25,100,93,92,79}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 407518; verify_case(1, Arg1, minCost(Arg0)); }
	void test_case_2() { int Arr0[] = {1,1,1,1,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 59; verify_case(2, Arg1, minCost(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Assemble ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
