#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int sz[100];
class BankingArray {
	public:
	int addCost(int initialCapacity, int numAdds) {
		sz[0] = 0;
		sz[1] = initialCapacity;
		for (int i=2; sz[i-1] < 500000000; ++i)
			sz[i] = sz[i-1]*2;

		int sol = 0;
		int cursz = 1;
		for (;;) {
			if (numAdds <= sz[cursz]-sz[cursz-1]) {
				sol += sz[cursz-1] + numAdds;
				break;
			} else {
				sol += sz[cursz];
				numAdds -= sz[cursz]-sz[cursz-1];
				++cursz;
			}
		}
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 3; int Arg2 = 6; verify_case(0, Arg2, addCost(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 3; verify_case(1, Arg2, addCost(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 500000000; int Arg2 = 1036870911; verify_case(2, Arg2, addCost(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 1; int Arg1 = 0; int Arg2 = 0; verify_case(3, Arg2, addCost(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    BankingArray ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
