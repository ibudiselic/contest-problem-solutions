#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <functional>

using namespace std;

class SkipRope {
	public:
	vector <int> partners(vector <int> candidates, int height) {
		int prvi=10000;
		int drugi=10000;

		sort(candidates.begin(), candidates.end(), greater<int>());

		for (int i=0; i<(int)candidates.size(); ++i) {
			if (abs(height-candidates[i]) < abs(height-prvi)) {
				drugi = prvi;
				prvi = candidates[i];
			} else if (abs(height-candidates[i]) < abs(height-drugi)) {
				drugi = candidates[i];
			}
		}
		vector<int> sol(2,0);
		sol[0] = (prvi<drugi ? prvi:drugi);
		sol[1] = (prvi<drugi ? drugi:prvi);
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {102, 99, 104}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; int Arr2[] = { 99,  102 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, partners(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {102, 97, 104}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; int Arr2[] = { 97,  102 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, partners(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {101, 100, 99}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; int Arr2[] = { 100,  101 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, partners(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {75, 117, 170, 175, 168, 167, 167, 142, 170, 85, 89, 170}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 169; int Arr2[] = { 170,  170 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, partners(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {134, 79, 164, 86, 131, 78, 99, 150, 105, 163, 150, 110, 90, 137, 127, 130, 121,
 93, 97, 131, 170, 137, 171, 153, 137, 138, 92, 103, 149, 110, 156}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 82; int Arr2[] = { 79,  86 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, partners(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    SkipRope ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
