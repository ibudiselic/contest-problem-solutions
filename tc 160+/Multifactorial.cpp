#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class Multifactorial {
	public:
	string calcMultiFact(int n, int k) {
		long long lim = 1000000000000000000ll;

		long long sol = 1;
		for (long long x=n; x>0; x-=k)
			if (lim/x < sol)
				return "overflow";
			else
				sol *= x;

		ostringstream ret;
		ret << sol;
		return ret.str();
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 14; int Arg1 = 3; string Arg2 = "12320"; verify_case(0, Arg2, calcMultiFact(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 4; string Arg2 = "5"; verify_case(1, Arg2, calcMultiFact(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1000; int Arg1 = 2; string Arg2 = "overflow"; verify_case(2, Arg2, calcMultiFact(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 2000000000; int Arg1 = 1900000000; string Arg2 = "200000000000000000"; verify_case(3, Arg2, calcMultiFact(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 1000; int Arg1 = 256; string Arg2 = "84232704000"; verify_case(4, Arg2, calcMultiFact(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 2000000000; int Arg1 = 1; string Arg2 = "overflow"; verify_case(5, Arg2, calcMultiFact(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Multifactorial ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
