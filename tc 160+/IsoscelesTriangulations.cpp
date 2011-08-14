#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int dp[51][51];
int n;
bool test(int a, int b, int c) {
	assert(a!=b && b!=c && c!=a);
	int ba = (b+2*n-a)%n;
	int cb = (c+2*n-b)%n;
	int ac = (a+2*n-c)%n;

	return (ba==cb || cb==ac || ac==ba);
}
int go(int b, int k) {
	int a = 0;
	if ((a+1)%n == b) {
		return (k==0);
	}
	if ((a+2)%n == b) {
		return test(a, (a+1)%n, b) ? (k==1) : (k==0);
	}
	int &ret = dp[b][k];
	if (ret != -1) {
		return ret;
	}

	ret = 0;
	int m = (a+1)%n;
	while (m != b) {
		int nk = k - test(a, m, b);
		for (int l=0; l<=nk; ++l) {
			ret = (ret + (long long)go(m, l)*go((b+2*n-m)%n, nk-l)%123456789)%123456789;
		}
		m = (m+1)%n;
	}

	return ret;
}
class IsoscelesTriangulations {
	public:
	int getCount(int n, int k) {
		::n = n;
		memset(dp, 0xff, sizeof dp);

		return go(n-1, k);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 2; int Arg2 = 2; verify_case(0, Arg2, getCount(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 0; int Arg2 = 0; verify_case(1, Arg2, getCount(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 3; int Arg2 = 5; verify_case(2, Arg2, getCount(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 6; int Arg1 = 2; int Arg2 = 12; verify_case(3, Arg2, getCount(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 10; int Arg1 = 8; int Arg2 = 10; verify_case(4, Arg2, getCount(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    IsoscelesTriangulations ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
