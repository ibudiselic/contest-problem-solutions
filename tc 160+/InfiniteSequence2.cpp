#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

const int LIM = 4000000;
long long dp[LIM];
class InfiniteSequence2 {
	public:
	long long calc(long long n, int p, int q, int x, int y) {
        if (n <= 0) {
            return 1;
        }
		if (n < LIM) {
            if (dp[n] != 0) {
                return dp[n];
            }
        }

        long long ret = calc(n/p-x, p, q, x, y) + calc(n/q-y, p, q, x, y);

        if (n < LIM) {
            dp[n] = ret;
        }

        return ret;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 10000000LL; int Arg1 = 2; int Arg2 = 3; int Arg3 = 10000000; int Arg4 = 10000000; long long Arg5 = 2LL; verify_case(0, Arg5, calc(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { long long Arg0 = 12LL; int Arg1 = 2; int Arg2 = 3; int Arg3 = 1; int Arg4 = 0; long long Arg5 = 8LL; verify_case(1, Arg5, calc(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { long long Arg0 = 0LL; int Arg1 = 2; int Arg2 = 2; int Arg3 = 0; int Arg4 = 0; long long Arg5 = 1LL; verify_case(2, Arg5, calc(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { long long Arg0 = 123LL; int Arg1 = 45; int Arg2 = 67; int Arg3 = 8; int Arg4 = 9; long long Arg5 = 2LL; verify_case(3, Arg5, calc(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    InfiniteSequence2 ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
