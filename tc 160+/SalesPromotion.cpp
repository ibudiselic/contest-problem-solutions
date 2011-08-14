#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int pVal[50], price[50];
int dp[51][15001];
class SalesPromotion {
	public:
	int bestPrice(int points, int halfPrice, int discount, vector <string> items) {
		int n = items.size();
		for (int i=0; i<n; ++i)
			sscanf(items[i].c_str(), "%d %d", &pVal[i], &price[i]);

		memset(dp, 0x3f, sizeof dp);
		dp[0][0] = 0;
		for (int i=0; i<n; ++i)
			for (int hp=50; hp>=0; --hp)
				for (int pts=15000; pts>=0; --pts) {
					if (hp < 50)
						dp[hp+1][pts] = min(dp[hp+1][pts], dp[hp][pts] + (price[i]+1)/2);
					if (pts+pVal[i] <= 15000)
						dp[hp][pts+pVal[i]] = min(dp[hp][pts+pVal[i]], dp[hp][pts]);
					dp[hp][pts] += (price[i]*(100-discount)+99)/100;
				}

		return dp[halfPrice][points];
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 500; int Arg1 = 1; int Arg2 = 10; string Arr3[] = {"150 500", "350 1000", "500 600", "450 800"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 940; verify_case(0, Arg4, bestPrice(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 500; int Arg1 = 1; int Arg2 = 10; string Arr3[] = {"150 450", "350 700", "500 1200", "450 800"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1320; verify_case(1, Arg4, bestPrice(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 1000; int Arg1 = 0; int Arg2 = 0; string Arr3[] = {"200 500", "300 700", "400 900", "500 1100", "600 1300"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 2200; verify_case(2, Arg4, bestPrice(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 0; string Arr3[] = {"100 100", "100 200", "100 150", "150 300"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 750; verify_case(3, Arg4, bestPrice(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    SalesPromotion ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
