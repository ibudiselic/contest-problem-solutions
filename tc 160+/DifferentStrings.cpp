#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int calc(const string &a, const string &b) {
    int ret = 0;
    for (int i=0; i<(int)a.size(); ++i) {
        ret += (a[i] != b[i]);
    }
    
    return ret;
}
class DifferentStrings {
	public:
	int minimize(string A, string B) {
		int sol = 123456789;
        for (int i=0; i<=(int)B.size()-(int)A.size(); ++i) {
            sol = min(sol, calc(A, B.substr(i, A.size())));
        }
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "koder"; string Arg1 = "topcoder"; int Arg2 = 1; verify_case(0, Arg2, minimize(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "hello"; string Arg1 = "xello"; int Arg2 = 1; verify_case(1, Arg2, minimize(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "abc"; string Arg1 = "topabcoder"; int Arg2 = 0; verify_case(2, Arg2, minimize(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "adaabc"; string Arg1 = "aababbc"; int Arg2 = 2; verify_case(3, Arg2, minimize(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "giorgi"; string Arg1 = "igroig"; int Arg2 = 6; verify_case(4, Arg2, minimize(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    DifferentStrings ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
