#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool is_palin(const string &s) {
    for (int i=0; 2*i+1<(int)s.size(); ++i) {
        if (s[i] != s[s.size()-1-i]) {
            return false;
        }
    }
    
    return true;
}
string rev(string s) {
    reverse(s.begin(), s.end());
    return s;
}
class ThePalindrome {
	public:
	int find(string s) {
        for (int i=0; i<(int)s.size(); ++i) {
            if (is_palin(s + rev(s.substr(0, i)))) {
                return s.size() + i;
            }
        }
        
        return 2*s.size();
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "abab"; int Arg1 = 5; verify_case(0, Arg1, find(Arg0)); }
	void test_case_1() { string Arg0 = "abacaba"; int Arg1 = 7; verify_case(1, Arg1, find(Arg0)); }
	void test_case_2() { string Arg0 = "qwerty"; int Arg1 = 11; verify_case(2, Arg1, find(Arg0)); }
	void test_case_3() { string Arg0 = "abdfhdyrbdbsdfghjkllkjhgfds"; int Arg1 = 38; verify_case(3, Arg1, find(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    ThePalindrome ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
