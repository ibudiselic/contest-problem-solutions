#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class CellularPhoneTarif {
	public:
	int calculatePrice(int seconds) {
		int ret = 5;

		if (seconds >= 300) {
			ret += 50 + (seconds-300+60)/60 * 3;
		} else {
			ret += (seconds+60)/60 * 10;
		}

		return ret;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 65; int Arg1 = 25; verify_case(0, Arg1, calculatePrice(Arg0)); }
	void test_case_1() { int Arg0 = 300; int Arg1 = 58; verify_case(1, Arg1, calculatePrice(Arg0)); }
	void test_case_2() { int Arg0 = 100; int Arg1 = 25; verify_case(2, Arg1, calculatePrice(Arg0)); }
	void test_case_3() { int Arg0 = 0; int Arg1 = 15; verify_case(3, Arg1, calculatePrice(Arg0)); }
	void test_case_4() { int Arg0 = 301; int Arg1 = 58; verify_case(4, Arg1, calculatePrice(Arg0)); }
	void test_case_5() { int Arg0 = 240; int Arg1 = 55; verify_case(5, Arg1, calculatePrice(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    CellularPhoneTarif ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
