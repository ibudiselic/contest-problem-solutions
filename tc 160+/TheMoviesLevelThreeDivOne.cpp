#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int n;
const int ZERO = 20*47;
long long dp[2][ZERO+60][2*ZERO+60];

long long calc(const vector<int> &A, const vector<int> &B) {
    memset(dp, 0, sizeof dp);
    for (int i=1; i<=ZERO; ++i) {
        for (int j=0; j<=2*ZERO; ++j) {
            dp[0][i][j] = 1;
        }
    }
    for (int k=0; k<n; ++k) {
        int R = (n-k)*20;
        int L = -R;
        for (int low=L; low<=0; ++low) {
            for (int sum=L; sum<=R; ++sum) {
                long long a = 0, b = 0;
                int nlow, nsum;
                nlow = min(0, low+A[n-1-k]);
                nsum = sum + A[n-1-k];
                a = dp[k&1][-nlow][nsum+ZERO];
                nlow = min(low, sum - B[n-1-k]);
                nsum = sum + A[n-1-k] - B[n-1-k];
                b = dp[k&1][-nlow][nsum+ZERO];
                
                dp[(k+1)&1][-low][sum+ZERO] = a + b;
            }
        }
    }
    
    return dp[n&1][0][ZERO];
}
class TheMoviesLevelThreeDivOne {
	public:
	long long find(vector <int> timeJ, vector <int> timeB) {
        n = timeJ.size();
		return (1LL<<n) - calc(timeJ, timeB) - calc(timeB, timeJ);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {4, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 2LL; verify_case(0, Arg2, find(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 1LL; verify_case(1, Arg2, find(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {10, 10, 10, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1, 1, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 3LL; verify_case(2, Arg2, find(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1, 2, 3, 4, 5, 6, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {7, 6, 5, 4, 3, 2, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 98LL; verify_case(3, Arg2, find(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TheMoviesLevelThreeDivOne ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
