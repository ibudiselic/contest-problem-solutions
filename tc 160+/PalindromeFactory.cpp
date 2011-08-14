#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int dp[50][50];
string T;
int go(int l, int r) {
    if (l >= r) {
        return 0;
    }
    int &ret = dp[l][r];
    if (ret != -1) {
        return ret;
    }
    
    ret = 1234567890;
    if (T[l] == T[r]) {
        ret = go(l+1, r-1);
    }
    
    ret = min(ret, 1 + go(l, r-1));
    ret = min(ret, 1 + go(l+1, r));
    ret = min(ret, 1 + go(l+1, r-1));
    
    return ret;
}
class PalindromeFactory {
	public:
	int getEditDistance(string initial) {
        memset(dp, 0xff, sizeof dp);
        T = initial;
		int sol = go(0, T.size()-1);
        for (int i=0; i<(int)initial.size(); ++i) {
            for (int j=i+1; j<(int)initial.size(); ++j) {
                swap(initial[i], initial[j]);
                T = initial;
                memset(dp, 0xff, sizeof dp);
                sol = min(sol, 1 + go(0, T.size()-1));
                swap(initial[i], initial[j]);
            }
        }
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "abba"; int Arg1 = 0; verify_case(0, Arg1, getEditDistance(Arg0)); }
	void test_case_1() { string Arg0 = "dabba"; int Arg1 = 1; verify_case(1, Arg1, getEditDistance(Arg0)); }
	void test_case_2() { string Arg0 = "babacvabba"; int Arg1 = 2; verify_case(2, Arg1, getEditDistance(Arg0)); }
	void test_case_3() { string Arg0 = "abc"; int Arg1 = 1; verify_case(3, Arg1, getEditDistance(Arg0)); }
	void test_case_4() { string Arg0 = "acxcba"; int Arg1 = 1; verify_case(4, Arg1, getEditDistance(Arg0)); }
	void test_case_5() { string Arg0 = "abcacbd"; int Arg1 = 1; verify_case(5, Arg1, getEditDistance(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    PalindromeFactory ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
