#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <utility>

using namespace std;

int calc(int left, int pot2) {
	int cnt_opt = 0;
	while (pot2 > 0) {
		const int cnt = left/(pot2+2);
		left -= cnt * (pot2+2);
		cnt_opt += 2*cnt;
		pot2 /= 2;
	}
	return cnt_opt + left;
}
class VectorCostSequence {
	public:
	int getSmallest(int d) {
		int best = d;
		for (int n=2; n<best; ++n) {
			int diff = d - n;
			int pot2 = 1;
			while (pot2 < n) {
				diff -= pot2;
				pot2 *= 2;
			}
			if (diff < 0)
				break;
			best = min(best, n + calc(diff, pot2/2));
		}

		return best;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; verify_case(0, Arg1, getSmallest(Arg0)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; verify_case(1, Arg1, getSmallest(Arg0)); }
	void test_case_2() { int Arg0 = 6; int Arg1 = 3; verify_case(2, Arg1, getSmallest(Arg0)); }
	void test_case_3() { int Arg0 = 9; int Arg1 = 5; verify_case(3, Arg1, getSmallest(Arg0)); }
	void test_case_4() { int Arg0 = 24; int Arg1 = 9; verify_case(4, Arg1, getSmallest(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    VectorCostSequence ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
