#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<int> S;
const int INF = 50001;
long long dp[2][11][INF+1];
class Polygons2 {
	public:
	long long number(vector <int> segments, int K) {
	    S = segments;
        if (K > (int)S.size()) {
            return 0;
        }
        
        sort(S.begin(), S.end());
        reverse(S.begin(), S.end());
        int t = 0;
        memset(dp[1], 0, sizeof dp[1]);
        for (int i=0; i<(int)S.size(); ++i) {
            for (int sum=0; sum<INF+1; ++sum) {
                dp[t][1][sum] = (S[i]<sum) + dp[1-t][1][sum];
                for (int k=2; k<=K; ++k) {
                    dp[t][k][sum] = dp[1-t][k][sum] + dp[1-t][k-1][min(sum+S[i], INF)];
                }
            }
            t = 1-t;
        }
        
        return dp[1-t][K][0];
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; long long Arg2 = 4LL; verify_case(0, Arg2, number(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {2,3,4,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; long long Arg2 = 3LL; verify_case(1, Arg2, number(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {4,4,4,2,2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; long long Arg2 = 11LL; verify_case(2, Arg2, number(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {10,1,4,9,20}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; long long Arg2 = 2LL; verify_case(3, Arg2, number(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {3310,1660,211,1260,160,213,884,539,17212,2025,105,120,5510}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; long long Arg2 = 532LL; verify_case(4, Arg2, number(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    Polygons2 ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
