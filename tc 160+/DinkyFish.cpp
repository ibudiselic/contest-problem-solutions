#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class DinkyFish {
	public:
	int monthsUntilCrowded(int tankVolume, int maleNum, int femaleNum) {
		const int lim = 2 * tankVolume;
		long long m = maleNum;
		long long f = femaleNum;
		int sol = 0;
		long long cur = m+f;
		while (cur <= lim) {
			++sol;
			const long long d = min(m, f);
			cur += 2 * d;
			m += d;
			f += d;
		}
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arg1 = 4; int Arg2 = 6; int Arg3 = 2; verify_case(0, Arg3, monthsUntilCrowded(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 100; int Arg1 = 4; int Arg2 = 6; int Arg3 = 5; verify_case(1, Arg3, monthsUntilCrowded(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 6; int Arg2 = 4; int Arg3 = 1; verify_case(2, Arg3, monthsUntilCrowded(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 6; int Arg2 = 4; int Arg3 = 0; verify_case(3, Arg3, monthsUntilCrowded(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 1000000; int Arg1 = 3; int Arg2 = 2; int Arg3 = 19; verify_case(4, Arg3, monthsUntilCrowded(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 431131; int Arg1 = 764; int Arg2 = 249; int Arg3 = 11; verify_case(5, Arg3, monthsUntilCrowded(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    DinkyFish ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
