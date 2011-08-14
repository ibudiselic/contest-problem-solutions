#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

long long pot10[11];
long long mem[10];
int is_pot10(long long x) {
	for (int i=1; i<10; ++i)
		if (pot10[i] == x)
			return i;
	return 0;
}
long long cnt(long long x) {
	if (x <= 0) return 0;
	if (x < 10) return x*(x+1)/2;
	if (is_pot10(x)) {
		const int t = is_pot10(x);
		if (mem[t] != 0)
			return mem[t];
		else
			return mem[t] = 1 + cnt(x-1);
	}

	long long ret = 0;
	int d = 0;
	for (d=1; pot10[d]<x; ++d)
		;
	--d;
	long long first = x/pot10[d];
	long long rem = x%pot10[d];
	ret += first*(rem+1) + cnt(rem);
	ret += (first-1)*first/2 * pot10[d];
	ret += first*(cnt(pot10[d])-1);
	return ret;
}

class SumThemAll {
	public:
	long long getSum(int lowerBound, int upperBound) {
		pot10[0] = 1;
		for (int i=1; i<11; ++i)
			pot10[i] = pot10[i-1]*10;

		memset(mem, 0, sizeof mem);
		return cnt(upperBound) - cnt(max(lowerBound-1, 0));
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 0; int Arg1 = 3; long long Arg2 = 6LL; verify_case(0, Arg2, getSum(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 14; long long Arg2 = 15LL; verify_case(1, Arg2, getSum(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 0; int Arg1 = 0; long long Arg2 = 0LL; verify_case(2, Arg2, getSum(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 14; int Arg1 = 53; long long Arg2 = 296LL; verify_case(3, Arg2, getSum(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 24660; int Arg1 = 308357171; long long Arg2 = 11379854844LL; verify_case(4, Arg2, getSum(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    SumThemAll ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
