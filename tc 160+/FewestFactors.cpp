#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int calc(const vector<int> &d) {
	int x = 0;
	for (int i=0; i<(int)d.size(); ++i)
		x = 10*x + d[i];

	return x;
}
int cntF(int x) {
	int ret = 0;
	for (int i=2; i<x; ++i)
		if (x%i == 0)
			++ret;

	return ret;
}
class FewestFactors {
	public:
	int number(vector <int> digits) {
		sort(digits.begin(), digits.end());
		int sol = -1;
		int cnt = 1234567890;
		do {
			int u = calc(digits);
			int v = cntF(u);
			if (v<cnt || (v==cnt && u<sol)) {
				cnt = v;
				sol = u;
			}
		} while (next_permutation(digits.begin(), digits.end()));

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 21; verify_case(0, Arg1, number(Arg0)); }
	void test_case_1() { int Arr0[] = {6, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(1, Arg1, number(Arg0)); }
	void test_case_2() { int Arr0[] = {4, 7, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 447; verify_case(2, Arg1, number(Arg0)); }
	void test_case_3() { int Arr0[] = {1, 3, 7, 9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1973; verify_case(3, Arg1, number(Arg0)); }
	void test_case_4() { int Arr0[] = {7, 5, 4, 3, 6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 36457; verify_case(4, Arg1, number(Arg0)); }
	void test_case_5() { int Arr0[] = {1,2,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 241; verify_case(5, Arg1, number(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    FewestFactors ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
