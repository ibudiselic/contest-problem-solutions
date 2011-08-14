#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int dp[1000];
int Q[5], C[5];
class VolumeDiscount {
	public:
	int bestDeal(vector <string> priceList, int quantity) {
		memset(dp, 0x3f, sizeof dp);
		dp[0] = 0;

		const int n = priceList.size();
		for (int i=0; i<n; ++i)
			sscanf(priceList[i].c_str(), "%d %d", &Q[i], &C[i]);

		for (int q=1; q<1000; ++q)
			for (int i=0; i<n; ++i)
				if (Q[i] <= q)
					dp[q] = min(dp[q], dp[q-Q[i]] + C[i]);

		return *min_element(dp+quantity, dp+1000);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"1 10", "5 45"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 90; verify_case(0, Arg2, bestDeal(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"1 8", "5 45"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 80; verify_case(1, Arg2, bestDeal(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"99 913", "97 173", "50 464", "80 565"} 	; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 18; int Arg2 = 173; verify_case(2, Arg2, bestDeal(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"2 272","1 166","10 993"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 81; int Arg2 = 8110; verify_case(3, Arg2, bestDeal(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    VolumeDiscount ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
