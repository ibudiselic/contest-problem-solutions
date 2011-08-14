#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class DivToZero {
	public:
	string lastTwo(int num, int factor) {
		for (int i=0; i<100; ++i) {
			if ((num/100*100 + i) % factor == 0) {
				char buff[10];
				sprintf(buff, "%02d", i);
				return string(buff);
			}
		}
		return "";
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2000000000; int Arg1 = 100; string Arg2 = "00"; verify_case(0, Arg2, lastTwo(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 1000; int Arg1 = 3; string Arg2 = "02"; verify_case(1, Arg2, lastTwo(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 23442; int Arg1 = 75; string Arg2 = "00"; verify_case(2, Arg2, lastTwo(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 428392; int Arg1 = 17; string Arg2 = "15"; verify_case(3, Arg2, lastTwo(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 32442; int Arg1 = 99; string Arg2 = "72"; verify_case(4, Arg2, lastTwo(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    DivToZero ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
