#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

double calc(int n, int t0, int tp, int ts) {
	if (n == 1)
		return t0+tp;
	else
		return max(double(t0), double(tp)/(n-1) + double(ts)*(n-1));
}
class MultiprocessorProgramming {
	public:
	long long optimalNumberOfProcessors(int t0, int tp, int ts) {
		int lo = 2, hi = 1234567890;

		while (hi - lo > 1000000) {
			int mid1 = lo + (hi-lo)/3;
			int mid2 = mid1 + (hi-lo)/3;

			if (calc(mid1, t0, tp, ts) > calc(mid2, t0, tp, ts))
				lo = mid1;
			else
				hi = mid2;
		}

		double best = t0+tp;
		int sol = 1;

		while (lo <= hi) {
			double t = calc(lo, t0, tp, ts);
			if (t < best) {
				best = t;
				sol = lo;
			}
			++lo;
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 10; int Arg2 = 1; long long Arg3 = 4LL; verify_case(0, Arg3, optimalNumberOfProcessors(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 8; int Arg1 = 10; int Arg2 = 1; long long Arg3 = 3LL; verify_case(1, Arg3, optimalNumberOfProcessors(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 10; int Arg2 = 5; long long Arg3 = 1LL; verify_case(2, Arg3, optimalNumberOfProcessors(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    MultiprocessorProgramming ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
