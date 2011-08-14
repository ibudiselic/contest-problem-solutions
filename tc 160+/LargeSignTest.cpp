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

class LargeSignTest {
	public:
	string pvalue(int N, int K) {
		if (2*K == N)
			return "100.0%";

		double L = 0;
		double p = 0;

		for (int i=0; i<=min(K, N-K); ++i) {
			p += exp(L - (N-1) * log(2));
			L += log(N - i) - log(i + 1);
		}

		char buff[100];
		sprintf(buff, "%.1f%%", p*100);
		return string(buff);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 4; string Arg2 = "37.5%"; verify_case(0, Arg2, pvalue(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 5; string Arg2 = "100.0%"; verify_case(1, Arg2, pvalue(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1000000; int Arg1 = 400000; string Arg2 = "0.0%"; verify_case(2, Arg2, pvalue(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 20; int Arg1 = 5; string Arg2 = "4.1%"; verify_case(3, Arg2, pvalue(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    LargeSignTest ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
