#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool is_lucky(const string &s) {
    for (int i=1; i<(int)s.size(); ++i) {
        if (s[i] == s[i-1]) {
            return false;
        }
    }
    
    return true;
}
class TheLuckyString {
	public:
	int count(string s) {
	    int sol = 0;
        sort(s.begin(), s.end());
        do {
            sol += is_lucky(s);
        } while (next_permutation(s.begin(), s.end()));
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "ab"; int Arg1 = 2; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { string Arg0 = "aaab"; int Arg1 = 0; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { string Arg0 = "aabbbaa"; int Arg1 = 1; verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { string Arg0 = "abcdefghij"; int Arg1 = 3628800; verify_case(3, Arg1, count(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TheLuckyString ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
