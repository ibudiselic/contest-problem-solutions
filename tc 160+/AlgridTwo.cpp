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

const long long mod = 1000000007LL;
long long dp[50][2];
class AlgridTwo {
	public:
	int makeProgram(vector <string> output) {
		long long sol = 1LL;
        int m = output.size();
        int n = output[0].size();
        for (int i=m-1; i>0; --i) {
            memset(dp, 0, sizeof dp);
            bool Ablack = (output[i-1][n-2]=='B');
            bool Bblack = (output[i-1][n-1]=='B');
            if (!Ablack && !Bblack) {
                dp[n-2][output[i][n-2]=='B'] = 1;
            } else if (Ablack && !Bblack && output[i][n-2]=='B' && output[i][n-1]=='B') {
                dp[n-2][0] = dp[n-2][1] = 2;
            } else if (!Ablack && Bblack && output[i][n-2]=='W' && output[i][n-1]=='W') {
                dp[n-2][0] = dp[n-2][1] = 2;
            } else if (Ablack && Bblack) {
                dp[n-2][output[i][n-1]=='B'] = 1;
            }
            for (int j=n-3; j>=0; --j) {
                Ablack = (output[i-1][j]=='B');
                Bblack = (output[i-1][j+1]=='B');
                if (!Ablack && !Bblack) {
                    dp[j][output[i][j]=='B'] = (dp[j+1][0] + dp[j+1][1])%mod;
                } else if (Ablack && !Bblack && output[i][j]=='B') {
                    dp[j][0] = dp[j][1] = 2*dp[j+1][1]%mod;
                } else if (!Ablack && Bblack && output[i][j]=='W') {
                    dp[j][0] = dp[j][1] = 2*dp[j+1][0]%mod;
                } else if (Ablack && Bblack) {
                    dp[j][0] = dp[j+1][0];
                    dp[j][1] = dp[j+1][1];
                }
            }
            sol = sol*((dp[0][0]+dp[0][1])%mod)%mod;
        }
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"BB",
 "WB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, makeProgram(Arg0)); }
	void test_case_1() { string Arr0[] = {"BBWBBB",
 "WBWBBW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(1, Arg1, makeProgram(Arg0)); }
	void test_case_2() { string Arr0[] = {"BWBWBW",
 "WWWWWW",
 "WBBWBW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, makeProgram(Arg0)); }
	void test_case_3() { string Arr0[] = {"WWBWBWBWBWBWBWBW",
 "BWBWBWBWBWBWBWBB",
 "BWBWBWBWBWBWBWBW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 73741817; verify_case(3, Arg1, makeProgram(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    AlgridTwo ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
