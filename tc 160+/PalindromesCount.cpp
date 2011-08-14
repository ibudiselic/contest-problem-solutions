#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool is_palindrome(const string &s) {
    for (int i=0; 2*i<(int)s.size(); ++i) {
        if (s[i] != s[s.size()-1-i]) {
            return false;
        }
    }
    return true;
}
class PalindromesCount {
	public:
	int count(string A, string B) {
	    int sol = 0;
        for (int i=0; i<(int)A.size(); ++i) {
            sol += is_palindrome(A.substr(0, i) + B + A.substr(i));
        }
        return sol + is_palindrome(A + B);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "aba"; string Arg1 = "b"; int Arg2 = 2; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "aa"; string Arg1 = "a"; int Arg2 = 3; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "aca"; string Arg1 = "bb"; int Arg2 = 0; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "abba"; string Arg1 = "abba"; int Arg2 = 3; verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "topcoder"; string Arg1 = "coder"; int Arg2 = 0; verify_case(4, Arg2, count(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    PalindromesCount ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
