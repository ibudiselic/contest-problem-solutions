#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

long long dp[31][4][4];
long long go(int p, int a, int b) {
    long long &ret = dp[p][a][b];
    if (ret != -1) {
        return ret;
    }
    if (p == 0) {
        return (ret = 1);
    }
    ret = 0;
    for (int i=0; i<3; ++i) {
        if (a==3 || b==3 || a+b+i!=3 || a==b || a==i || b==i) {
            ret += go(p-1, b, i);
        }
    }
    return ret;
}
class ForbiddenStrings {
	public:
	long long countNotForbidden(int n) {
	    memset(dp, 0xff, sizeof dp);

        return go(n, 3, 3);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; long long Arg1 = 9LL; verify_case(0, Arg1, countNotForbidden(Arg0)); }
	void test_case_1() { int Arg0 = 3; long long Arg1 = 21LL; verify_case(1, Arg1, countNotForbidden(Arg0)); }
	void test_case_2() { int Arg0 = 4; long long Arg1 = 51LL; verify_case(2, Arg1, countNotForbidden(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    ForbiddenStrings ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
