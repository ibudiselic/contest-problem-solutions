#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class BeautifulString {
	public:
	int maximumLength(long long countA, long long countB, long long maxA, long long maxB) {
		if (maxA==0 || maxB==0) {
			return max(min(maxA, countA), min(maxB, countB));
		}

		long long a = (countA+maxA-1)/maxA;
		long long b = (countB+maxB-1)/maxB;
		if (abs(a-b) <= 1) {
			return countA + countB;
		}

		return (a<b ? countA + min((countA+1)*maxB, countB) : countB + min((countB+1)*maxA, countA));
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 10; int Arg3 = 10; int Arg4 = 0; verify_case(0, Arg4, maximumLength(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 10; int Arg2 = 0; int Arg3 = 0; int Arg4 = 0; verify_case(1, Arg4, maximumLength(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 5; int Arg2 = 1; int Arg3 = 1; int Arg4 = 7; verify_case(2, Arg4, maximumLength(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 677578; int Arg1 = 502524; int Arg2 = 989951; int Arg3 = 504698; int Arg4 = 1180102; verify_case(3, Arg4, maximumLength(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    BeautifulString ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
