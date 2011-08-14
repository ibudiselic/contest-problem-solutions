#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int one[1u<<16];
int two[1u<<16];
class BiggestRectangleHard {
	public:
	int findArea(vector <int> lengths) {
		memset(one, 0, sizeof one);
		memset(two, 0, sizeof two);
		vector<int> L = lengths;
		const int n = L.size();
		const unsigned lim = 1u<<n;

		for (unsigned m=1; m<lim; ++m)
			for (int i=0; (1u<<i)<=m; ++i)
				if (m & (1u<<i))
					one[m] += L[i];

		for (unsigned m1=1; m1<lim; ++m1)
			for (unsigned m2=0; m2<m1; m2 = (m1+m2+1) & (~m1))
				if (one[m1] == one[m2])
					two[m1|m2] = max(two[m1|m2], one[m1]);

		int sol = 0;
		for (unsigned m1=1; m1<lim; ++m1)
			for (unsigned m2=0; m2<m1; m2 = (m1+m2+1) & (~m1))
				sol = max(sol, two[m1]*two[m2]);

		return sol==0 ? -1 : sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 3, 3, 4, 5, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 15; verify_case(0, Arg1, findArea(Arg0)); }
	void test_case_1() { int Arr0[] = {9, 9, 5, 6, 2, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(1, Arg1, findArea(Arg0)); }
	void test_case_2() { int Arr0[] = {3, 4, 7, 8, 10, 2, 9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 70; verify_case(2, Arg1, findArea(Arg0)); }
	void test_case_3() { int Arr0[] = {9, 2, 7, 9, 4, 9, 7, 10, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 224; verify_case(3, Arg1, findArea(Arg0)); }
	void test_case_4() { int Arr0[] = {9, 9, 10, 7, 7, 8, 7, 5, 8, 6, 9, 7, 7, 10, 9, 6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 961; verify_case(4, Arg1, findArea(Arg0)); }
	void test_case_5() { int Arr0[] = {2, 6, 4, 10, 2, 8, 1, 8, 2, 1, 4, 8, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 272; verify_case(5, Arg1, findArea(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    BiggestRectangleHard ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
