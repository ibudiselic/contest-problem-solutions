#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int gcd(int m, int n) {
	return n==0 ? m : gcd(n, m%n);
}
long long my_abs(long long x) {
	return x<0 ? -x : x;
}
class CalcRoot {
	public:
	string approximate(int N, int D) {
		long long dist = 1234567890123456LL;
		int nom = -1;
		int denom = 1;

		for (long long i=1; i<=D; ++i) {
			long long lo = 1, hi = 1000100;
			while (lo < hi) {
				long long m = lo + (hi-lo)/2;
				if (m*m >= N*i*i)
					hi = m;
				else
					lo = m+1;
			}
			for (--lo; lo<=hi+1; ++lo)
				if (my_abs(N*i*i - lo*lo)*denom*denom < dist*i*i) {
					dist = my_abs(N*i*i - lo*lo);
					nom = lo;
					denom = i;
				}
		}

		int d = gcd(nom, denom);
		nom/=d;
		denom/=d;

		ostringstream os;
		os << nom << '/' << denom;
		return os.str();
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 10; string Arg2 = "2/1"; verify_case(0, Arg2, approximate(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 3; string Arg2 = "7/3"; verify_case(1, Arg2, approximate(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 12; int Arg1 = 10; string Arg2 = "31/9"; verify_case(2, Arg2, approximate(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 23743; int Arg1 = 763; string Arg2 = "98462/639"; verify_case(3, Arg2, approximate(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    CalcRoot ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
