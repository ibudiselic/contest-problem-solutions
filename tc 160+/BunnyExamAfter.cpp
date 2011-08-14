#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class BunnyExamAfter {
	public:
	int getMaximum(string black, string gray, string white) {
		int sol = 0;
        for (int i=0; i<(int)black.size(); ++i) {
            sol += (gray[i]!=black[i] || white[i]!=black[i]) + (gray[i]==white[i] && gray[i]!=black[i]);
        }
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "ABC"; string Arg1 = "ABC"; string Arg2 = "ABC"; int Arg3 = 0; verify_case(0, Arg3, getMaximum(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "A"; string Arg1 = "B"; string Arg2 = "B"; int Arg3 = 2; verify_case(1, Arg3, getMaximum(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "ABC"; string Arg1 = "PQR"; string Arg2 = "XYZ"; int Arg3 = 3; verify_case(2, Arg3, getMaximum(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "AAAAA"; string Arg1 = "AABBB"; string Arg2 = "BBBAA"; int Arg3 = 6; verify_case(3, Arg3, getMaximum(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "TOPCODER"; string Arg1 = "TOPBUNNY"; string Arg2 = "THEHONEY"; int Arg3 = 9; verify_case(4, Arg3, getMaximum(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    BunnyExamAfter ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
