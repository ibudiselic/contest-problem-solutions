#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

double dp[51];
class StockHistory {
	public:
	int maximumEarnings(int ii, int mc, vector <string> stockPrices) {
		vector< vector<int> > P;
		for (int i=0; i<(int)stockPrices.size(); ++i) {
			istringstream is(stockPrices[i]);
			int x;
			P.push_back(vector<int> ());
			while (is >> x)
				P.back().push_back(x);
		}

		int cntStock = P[0].size();
		int maxT = P.size();

		dp[0] = 0.0;
		for (int t=1; t<=maxT; ++t) {
			dp[t] = 0;
			for (int i=0; i<t; ++i) {
				double have = (i==0)*ii + (t-(i==0)-i)*mc;
				for (int x=0; x<cntStock; ++x)
					dp[t] = max(dp[t], dp[i] + (P.back()[x]-P[t-1][x]) * (have/P[t-1][x]));
			}
		}

		double x = *max_element(dp, dp+maxT+1);

		return (int)x + (x-(int)x >= 0.5);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1000; int Arg1 = 0; string Arr2[] = {"10 20 30", "15 24 32"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 500; verify_case(0, Arg3, maximumEarnings(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 1000; int Arg1 = 0; string Arr2[] = {"10", "9"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(1, Arg3, maximumEarnings(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 100; int Arg1 = 20; string Arr2[] = {"40 50 60",
 "37 48 55",
 "100 48 50",
 "105 48 47",
 "110 50 52",
 "110 50 52",
 "110 51 54",
 "109 49 53"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 239; verify_case(2, Arg3, maximumEarnings(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    StockHistory ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
