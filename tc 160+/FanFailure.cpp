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

class FanFailure {
	public:
	vector <int> getRange(vector <int> capacities, int minCooling) {
		sort(capacities.begin(), capacities.end());

		int cur = 0;
		int right = capacities.size()-1;
		for (; right>=0 && cur<minCooling; --right)
			cur += capacities[right];

		int left = 0;
		cur = 0;
		for (; left<(int)capacities.size() && cur<minCooling; ++left)
			cur += capacities[left];

		vector<int> sol(2, 0);
		sol[0] = right+1;
		sol[1] = capacities.size()-left;

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arr2[] = { 2,  1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, getRange(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {8,5,6,7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 22; int Arr2[] = { 0,  0 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, getRange(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {676, 11, 223, 413, 823, 122, 547, 187, 28}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000; int Arr2[] = { 7,  2 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, getRange(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {955, 96, 161, 259, 642, 242, 772, 369, 311, 785,
 92, 991, 620, 394, 128, 774, 973, 94, 681, 771,
 916, 373, 523, 100, 220, 993, 472, 798, 132, 361,
 33, 362, 573, 624, 722, 520, 451, 231, 37, 921,
 408, 170, 303, 559, 866, 412, 339, 757, 822, 192}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3619; int Arr2[] = { 46,  30 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, getRange(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    FanFailure ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
