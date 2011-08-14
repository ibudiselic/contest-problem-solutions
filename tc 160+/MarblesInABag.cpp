#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

double dp[2][4001];

class MarblesInABag {
	public:
	double getProbability(int r, int b) {
        memset(dp, 0, sizeof dp);
        for (int i=1; i<=b; ++i) {
            dp[0][i] = 1.0;
        }

        for (int i=1; i<=r; ++i) {
            dp[i&1][0] = 0.0;
            for (int j=1; j<=b; ++j) {
                const double total = i + j;
                if ((i+j) & 1) { 
                    dp[i&1][j] = (i * dp[(i-1)&1][j] + j * dp[i&1][j-1]) / total;
                } else {
                    dp[i&1][j] = dp[i&1][j-1];
                }
            }
        }

        return dp[r&1][b];
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 2; double Arg2 = 0.3333333333333333; verify_case(0, Arg2, getProbability(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 3; double Arg2 = 0.13333333333333333; verify_case(1, Arg2, getProbability(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 5; double Arg2 = 0.22857142857142856; verify_case(2, Arg2, getProbability(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 11; int Arg1 = 6; double Arg2 = 0.0; verify_case(3, Arg2, getProbability(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 4; int Arg1 = 11; double Arg2 = 0.12183372183372182; verify_case(4, Arg2, getProbability(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    MarblesInABag ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
