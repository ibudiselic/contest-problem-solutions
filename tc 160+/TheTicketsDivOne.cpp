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

double dp[2][1002][1001];
class TheTicketsDivOne {
	public:
	double find(int n, int m) {
		double sol = 0.0;
        memset(dp, 0, sizeof dp);
        dp[0][n][m-1] = 1.0;
        int t = 1;
        for (int iter=0; iter<130; ++iter, t=1-t) {
            memset(dp[t], 0, sizeof dp[t]);
            sol += dp[1-t][1][0];
            dp[t][1][0] = dp[1-t][2][1]/3;
            for (int cnt=2; cnt<=n; ++cnt) {
                sol += dp[1-t][cnt][0]/6;
                for (int pos=0; pos+1<cnt; ++pos) {
                    dp[t][cnt][pos] = dp[1-t][cnt+1][pos+1]/3 + dp[1-t][cnt][pos+1]/2;
                }
                dp[t][cnt][cnt-1] = dp[1-t][cnt+1][cnt]/3 + dp[1-t][cnt][0]/2;
            }
        }
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 1; double Arg2 = 0.4444444444444444; verify_case(0, Arg2, find(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; double Arg2 = 0.5555555555555556; verify_case(1, Arg2, find(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 1; double Arg2 = 1.0; verify_case(2, Arg2, find(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 3; int Arg1 = 2; double Arg2 = 0.31746031746031744; verify_case(3, Arg2, find(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TheTicketsDivOne ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
