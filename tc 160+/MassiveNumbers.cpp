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

void parse(const string &s, int &x, int &y) {
	sscanf(s.c_str(), "%d^%d", &x, &y);
}
class MassiveNumbers {
	public:
	string getLargest(string numberA, string numberB) {
		int a, ea, b, eb;
		parse(numberA, a, ea);
		parse(numberB, b, eb);

		if (ea*log(a) > eb*log(b))
			return numberA;
		else
			return numberB;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "3^100"; string Arg1 = "2^150"; string Arg2 = "3^100"; verify_case(0, Arg2, getLargest(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "1^1000"; string Arg1 = "2^1"; string Arg2 = "2^1"; verify_case(1, Arg2, getLargest(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "893^605"; string Arg1 = "396^906"; string Arg2 = "396^906"; verify_case(2, Arg2, getLargest(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "999^1000"; string Arg1 = "1000^999"; string Arg2 = "999^1000"; verify_case(3, Arg2, getLargest(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    MassiveNumbers ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
