#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;


const char *phone[] = { "123", "456", "789", "*0#" };
void getInd(char c, int &i, int &j) {
	for (i=0; i<4; ++i)
		for (j=0; j<3; ++j)
			if (c == phone[i][j])
				return;
}
class PhonePad {
	public:
	int fingerMovement(string phoneNumber) {
		int i=1, j=1;
		int sol = 0;
		for (int t=0; t<(int)phoneNumber.size(); ++t) {
			int r=i, c=j;
			getInd(phoneNumber[t], i, j);
			sol += abs(r-i)+abs(c-j);
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "911"; int Arg1 = 6; verify_case(0, Arg1, fingerMovement(Arg0)); }
	void test_case_1() { string Arg0 = "5555555"; int Arg1 = 0; verify_case(1, Arg1, fingerMovement(Arg0)); }
	void test_case_2() { string Arg0 = "8606335540"; int Arg1 = 16; verify_case(2, Arg1, fingerMovement(Arg0)); }
	void test_case_3() { string Arg0 = "8606574276"; int Arg1 = 21; verify_case(3, Arg1, fingerMovement(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    PhonePad ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
