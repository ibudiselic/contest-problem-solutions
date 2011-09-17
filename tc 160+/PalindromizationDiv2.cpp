#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

bool is_palin(const string &s) {
    for (int i=0; 2*i<(int)s.size(); ++i) {
        if (s[i] != s[(int)s.size()-1-i]) {
            return false;
        }
    }
    return true;
}
bool is_palin(int x) {
    ostringstream os;
    os << x;
    return is_palin(os.str());
}
class PalindromizationDiv2 {
	public:
	int getMinimumCost(int X) {
        for (int i=0; i<=X; ++i) {
            if (is_palin(X+i) || is_palin(X-i)) {
                return i;
            }
        }
        return -1; // never happens
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 25; int Arg1 = 3; verify_case(0, Arg1, getMinimumCost(Arg0)); }
	void test_case_1() { int Arg0 = 12321; int Arg1 = 0; verify_case(1, Arg1, getMinimumCost(Arg0)); }
	void test_case_2() { int Arg0 = 40; int Arg1 = 4; verify_case(2, Arg1, getMinimumCost(Arg0)); }
	void test_case_3() { int Arg0 = 2011; int Arg1 = 9; verify_case(3, Arg1, getMinimumCost(Arg0)); }
	void test_case_4() { int Arg0 = 0; int Arg1 = 0; verify_case(4, Arg1, getMinimumCost(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    PalindromizationDiv2 ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
