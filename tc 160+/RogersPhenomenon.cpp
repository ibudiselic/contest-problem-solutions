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

class RogersPhenomenon {
	public:
	int countTriggers(vector <int> set1, vector <int> set2) {
		int a1, a2, b1, b2;

		a1 = accumulate(set1.begin(), set1.end(), 0);
		a2 = accumulate(set2.begin(), set2.end(), 0);
		b1 = set1.size();
		b2 = set2.size();

		int sol = 0;
		if (b1 > 1)
			for (int i=0; i<b1; ++i)
				if ((a1-set1[i])*b1 > a1*(b1-1) && (a2+set1[i])*b2 > a2*(b2+1))
					++sol;

		if (b2 > 1)
			for (int i=0; i<b2; ++i)
				if ((a2-set2[i])*b2 > a2*(b2-1) && (a1+set2[i])*b1 > a1*(b1+1))
					++sol;

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 1, 2, 3 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 4, 5, 6 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(0, Arg2, countTriggers(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = { 3, 100, 90 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 5, 1, 18, 29 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(1, Arg2, countTriggers(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = { 1, 1, 1, 1, 1, 5 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { -10, -9, -8, -7, -6 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(2, Arg2, countTriggers(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = { 12, 94, 53, 43, 58, 85, 55, 83, 47, 57 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 23, 100, 98, 27, 9, 70, 39, 39, 54 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(3, Arg2, countTriggers(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    RogersPhenomenon ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
