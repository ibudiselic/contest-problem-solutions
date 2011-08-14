#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

/*
    
An integer x is called a proper divisor of an integer y if x is a divisor of y and 1 <= x < y.
Let us denote as s(a) the sum of all proper divisors of a. An integer a is called almost perfect by k if |a-s(a)| <= k.
*/
int s(int x) {
	int ret = 0;
	for (int i=1; i<x; ++i)
		if (x%i == 0)
			ret += i;
	return ret;
}
class AlmostPerfectNumber {
	public:
	int count(int left, int right, int k) {
		int sol = 0;
		for (int i=left; i<=right; ++i)
			sol += (abs(i-s(i)) <= k);

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 10; int Arg2 = 1; int Arg3 = 4; verify_case(0, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 5; int Arg2 = 5; int Arg3 = 1; verify_case(1, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 11; int Arg1 = 20; int Arg2 = 50; int Arg3 = 10; verify_case(2, Arg3, count(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    AlmostPerfectNumber ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
