#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

long long gcd(long long m, long long n) {
	return (n==0 ? m : gcd(n, m%n));
}
class CommonMultiples {
	public:
	int countCommMult(vector <int> a, int lower, int upper) {
		long long lcm = 1;
		for (int i=0; i<(int)a.size(); ++i)
			lcm = lcm/gcd(lcm, a[i]) * a[i];

		return upper/lcm - (lower-1)/lcm;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 15; int Arg3 = 2; verify_case(0, Arg3, countCommMult(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {1,2,4,8,16,32,64}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 128; int Arg2 = 128; int Arg3 = 1; verify_case(1, Arg3, countCommMult(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,49}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2000000000; int Arg3 = 0; verify_case(2, Arg3, countCommMult(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2000000000; int Arg3 = 2000000000; verify_case(3, Arg3, countCommMult(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    CommonMultiples ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
