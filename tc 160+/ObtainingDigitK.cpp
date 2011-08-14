#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class ObtainingDigitK {
	public:
	int minNumberToAdd(string n, int k) {
		if (n.find(k+'0') != string::npos)
			return 0;

		if (n[n.size()-1]-'0' <= k)
			return k - (n[n.size()-1]-'0');

		int add = 10 - (n[n.size()-1]-'0');
		n[n.size()-1] = '0';
		bool carry = 1;
		for (int i=1; i<(int)n.size(); ++i)
			if (n[n.size()-1-i] == '9') {
				n[n.size()-1-i] = '0';
			} else {
				++n[n.size()-1-i];
				carry = 0;
				break;
			}

		if (carry)
			n = string(1, '1') + n;

		if (n.find(k+'0') != string::npos)
			return add;

		return add + k;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "153"; int Arg1 = 7; int Arg2 = 4; verify_case(0, Arg2, minNumberToAdd(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "158"; int Arg1 = 7; int Arg2 = 9; verify_case(1, Arg2, minNumberToAdd(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "7853192"; int Arg1 = 2; int Arg2 = 0; verify_case(2, Arg2, minNumberToAdd(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "99999999999999999999999999999999999999999999999"; int Arg1 = 0; int Arg2 = 1; verify_case(3, Arg2, minNumberToAdd(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ObtainingDigitK ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
