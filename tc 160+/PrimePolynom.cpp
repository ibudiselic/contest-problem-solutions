#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool isPrime(int x) {
	for (int i=2; i*i<=x; ++i)
		if (x%i == 0)
			return false;
	return true;
}
class PrimePolynom {
	public:
	int reveal(int A, int B, int C) {
		for (int i=0; i<=80; ++i) {
			int t = A * i*i + B * i + C;
			if (t<=1 || !isPrime(t))
				return i;
		}

		return -1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = -1; int Arg2 = 41; int Arg3 = 41; verify_case(0, Arg3, reveal(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 41; int Arg3 = 40; verify_case(1, Arg3, reveal(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 1; int Arg2 = -13; int Arg3 = 0; verify_case(2, Arg3, reveal(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 1; int Arg1 = -15; int Arg2 = 97; int Arg3 = 48; verify_case(3, Arg3, reveal(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 1; int Arg1 = -79; int Arg2 = 1601; int Arg3 = 80; verify_case(4, Arg3, reveal(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    PrimePolynom ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
