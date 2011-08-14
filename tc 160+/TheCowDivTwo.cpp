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

int dp[2][1000][50];
int mod = 1000000007;
inline void inc(int &a, int b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}
class TheCowDivTwo {
	public:
	int find(int N, int K) {
		memset(dp, 0, sizeof dp);
        dp[0][0][0] = 1;
        for (int i=0; i<N; ++i) {
            memset(dp[(i+1)&1], 0, sizeof dp[(i+1)&1]);
            for (int m=0; m<N; ++m) {
                for (int k=0; k<=K; ++k) {
                    inc(dp[(i+1)&1][m][k], dp[i&1][m][k]);
                    if (dp[i&1][m][k]>0 && k<K) {
                        int m2 = m + i;
                        if (m2 >= N) {
                            m2 -= N;
                        }
                        inc(dp[(i+1)&1][m2][k+1], dp[i&1][m][k]);
                    }
                }
            }
        }
        return dp[N&1][0][K];
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 7; int Arg1 = 4; int Arg2 = 5; verify_case(0, Arg2, find(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1; verify_case(1, Arg2, find(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 58; int Arg1 = 4; int Arg2 = 7322; verify_case(2, Arg2, find(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 502; int Arg1 = 7; int Arg2 = 704466492; verify_case(3, Arg2, find(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 1000; int Arg1 = 47; int Arg2 = 219736903; verify_case(4, Arg2, find(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TheCowDivTwo ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
