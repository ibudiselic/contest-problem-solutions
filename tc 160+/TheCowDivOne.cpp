#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

map< vector<int>, int > dp;
long long mod = 1000000007LL;
long long N;
long long to_the(long long n, long long k) {
    long long ret = 1;
    while (k > 0) {
        if (k & 1) {
            ret = ret*n%mod;
        }
        n = n*n%mod;
        k >>= 1;
    }
    return ret;
}
long long mod_inv(long long x) {
    return to_the(x, mod-2);
}
int gcd(int m, int n) {
    return m==0 ? n : gcd(n%m, m);
}

int F(int d, int k, int a) {
    if (k == 0) {
        return 1; // sum = 0
    }
    vector<int> state(3);
    state[0] = d; state[1] = k; state[2] = a;
    if (dp.count(state)) {
        return dp[state];
    }
    int &ret = dp[state];
    
    int g = gcd(d, a);
    long long val = (N/d*g%mod*F(g, k-1, 1)%mod - (long long)(k-1)*F(d, k-1, (a+1)%d)%mod + mod) % mod;
    return (ret = int(val));
}

class TheCowDivOne {
	public:
	int find(int N, int K) {
        ::N = N;
        dp.clear();
        int val = F(N, K, 1);
        long long fact = 1;
        for (int i=2; i<=K; ++i) {
            fact = (fact*i)%mod;
        }
        return int(val*mod_inv(fact)%mod);
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
	void test_case_3() { int Arg0 = 1000; int Arg1 = 47; int Arg2 = 219736903; verify_case(3, Arg2, find(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 1000000000; int Arg1 = 1000; int Arg2 = 666683069; verify_case(4, Arg2, find(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TheCowDivOne ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
