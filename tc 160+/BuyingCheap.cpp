#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class BuyingCheap {
	public:
	int thirdBestPrice(vector <int> prices) {
		sort(prices.begin(), prices.end());
		prices.erase(unique(prices.begin(), prices.end()), prices.end());

		return (prices.size()>=3 ? prices[2] : -1);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {10, 40, 50, 20, 70,
 80, 30, 90, 60}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 30; verify_case(0, Arg1, thirdBestPrice(Arg0)); }
	void test_case_1() { int Arr0[] = {10, 10, 10, 10, 20,
 20, 30, 30, 40, 40}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 30; verify_case(1, Arg1, thirdBestPrice(Arg0)); }
	void test_case_2() { int Arr0[] = {10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(2, Arg1, thirdBestPrice(Arg0)); }
	void test_case_3() { int Arr0[] = {80, 90, 80, 90, 80}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(3, Arg1, thirdBestPrice(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    BuyingCheap ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
