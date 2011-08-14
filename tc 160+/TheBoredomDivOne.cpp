#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

double dp[2][100][100];
bool updated[100][100];
const int ITER = 40000;
class TheBoredomDivOne {
	public:
	double find(int m, int n) {
        memset(dp, 0, sizeof dp);
        int total = m+n;
        int choices = total*(total-1);
		dp[0][m][n] = 1.0;
        double sol = 0.0;
        for (int i=0; i<ITER; ++i) {
            sol += i*dp[i&1][total][0];
            dp[i&1][total][0] = 0.0;
            memset(dp[(i+1)&1], 0, sizeof dp[(i+1)&1]);
            for (int b=0; b<total; ++b) {
                const int nb = total-b;
                const double p = dp[i&1][b][nb];
                if (nb >= 2) {
                    dp[(i+1)&1][b+2][nb-2] += p*nb*(nb-1)/choices;
                }
                if (nb > 0) {
                    dp[(i+1)&1][b+1][nb-1] += p*2*b*nb/choices;
                }
                if (b >= 2) {
                    dp[(i+1)&1][b][nb] += p*b*(b-1)/choices;
                }
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
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; double Arg2 = 1.0; verify_case(0, Arg2, find(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 1; double Arg2 = 1.5; verify_case(1, Arg2, find(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 2; double Arg2 = 2.0; verify_case(2, Arg2, find(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 7; double Arg2 = 13.831068977298521; verify_case(3, Arg2, find(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TheBoredomDivOne ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
