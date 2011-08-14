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

class ArithSeq {
	public:
	long long minStart(int n, int delta) {
		long long D = delta;

		long long def = (n-1)*D + 1;

		long long lim = (D-1)*D + 1;

		long long skip = 0;
		for (long long i=1; i<=lim; i+=skip) {
			long long j = i+def-1;
			for (; j>=i; j-=D) {
				long long k = (long long)ceil(sqrt(j));
				if (j <= k*(k-1)) {
                	skip = k*(k-1)+1 - j;
                	break;
                }
			}
          	if (j < i)
            	return i;
       	}
       	return def*(def-1)+1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 3; long long Arg2 = 1LL; verify_case(0, Arg2, minStart(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 12; long long Arg2 = 9LL; verify_case(1, Arg2, minStart(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 6; int Arg1 = 12; long long Arg2 = 3661LL; verify_case(2, Arg2, minStart(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 30; int Arg1 = 4130; long long Arg2 = 1001001LL; verify_case(3, Arg2, minStart(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 30; int Arg1 = 100000000; long long Arg2 = 670380219057LL; verify_case(4, Arg2, minStart(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ArithSeq ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
