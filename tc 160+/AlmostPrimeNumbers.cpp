#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool f(int x) {
	for (int d=2; d*d <= x; ++d) {
		if (x%d == 0) {
			return (d > 10);
		}
	}
	return false;
}
class AlmostPrimeNumbers {
	public:
	int getNext(int m) {
		while (1) {
			++m;
			if (f(m)) {
				return m;
			}
		}

		return -1;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 200; int Arg1 = 209; verify_case(0, Arg1, getNext(Arg0)); }
	void test_case_1() { int Arg0 = 666; int Arg1 = 667; verify_case(1, Arg1, getNext(Arg0)); }
	void test_case_2() { int Arg0 = 1000; int Arg1 = 1003; verify_case(2, Arg1, getNext(Arg0)); }
	void test_case_3() { int Arg0 = 1591; int Arg1 = 1633; verify_case(3, Arg1, getNext(Arg0)); }
	void test_case_4() { int Arg0 = 6; int Arg1 = 121; verify_case(4, Arg1, getNext(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    AlmostPrimeNumbers ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
