#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class InverseFactoring {
	public:
	int getTheNumber(vector <int> factors) {
		sort(factors.begin(), factors.end());
        return factors[0]*factors.back();
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, getTheNumber(Arg0)); }
	void test_case_1() { int Arr0[] = {4,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(1, Arg1, getTheNumber(Arg0)); }
	void test_case_2() { int Arr0[] = {3,4,2,12,6,8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 24; verify_case(2, Arg1, getTheNumber(Arg0)); }
	void test_case_3() { int Arr0[] = {14,26456,2,28,13228,3307,7,23149,8,6614,46298,56,4,92596}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 185192; verify_case(3, Arg1, getTheNumber(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    InverseFactoring ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
