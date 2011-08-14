#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int minCost[1101];
class Hotel {
	public:
	int marketCost(int minCustomers, vector <int> customers, vector <int> cost) {
		memset(minCost, 0x3f, sizeof minCost);

		minCost[0] = 0;
		for (int i=1; i<=minCustomers+100; ++i) {
			for (int j=0; j<(int)cost.size(); ++j)
				if (customers[j] <= i)
					minCost[i] = min(minCost[i], minCost[i-customers[j]]+cost[j]);
		}

		return *min_element(minCost+minCustomers, minCost+minCustomers+101);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arr1[] = {1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3,2,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 4; verify_case(0, Arg3, marketCost(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 10; int Arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 10; verify_case(1, Arg3, marketCost(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 12; int Arr1[] = {5, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 8; verify_case(2, Arg3, marketCost(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 100; int Arr1[] = {9, 11, 4, 7, 2, 8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {4, 9, 3, 8, 1, 9}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 45; verify_case(3, Arg3, marketCost(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Hotel ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
