#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

const long long mod = 1000000007LL;
long long fastpow(long long k, long long n) {
    long long ret = 1;
    while (n > 0) {
        if (n & 1) {
            ret = ret*k%mod;
        }
        k = k*k%mod;
        n >>= 1;
    }
    
    return ret;
}
long long inv(long long k) {
    return fastpow(k, mod-2);
}
int calc(long long n, long long k) {
    if (k == 0) {
        return 1;
    }
    if (k == 1) {
        return n;
    }
    long long ret = 1;
    for (int i=0; i<k; ++i) {
        ret = (ret * (n-i)) % mod;
        ret = (ret * inv(i+1)) % mod;
    }
    return int(ret);
}
class SuperSum {
	public:
	int calculate(int k, int n) {
		return calc(k+n, k+1);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 3; int Arg2 = 6; verify_case(0, Arg2, calculate(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 3; int Arg2 = 10; verify_case(1, Arg2, calculate(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 10; int Arg2 = 2002; verify_case(2, Arg2, calculate(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 35; int Arg2 = 150595840; verify_case(3, Arg2, calculate(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    SuperSum ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
