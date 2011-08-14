#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

const long long mod = 500500573LL;
long long to_the(long long n, long long k) {
    long long ret = 1;
    while (k > 0) {
        if (k&1) {
            ret = (ret*n)%mod;
        }
        k >>= 1;
        n = n*n%mod;
    }
    return ret;
}
long long mul_inv(long long n) {
    return to_the(n, mod-2);
}

long long F[2501]; // mod factorials
long long invF[2501]; // multiplicative inverses of factorials in Z_mod
long long digval[2501]; // 11...1 % mod (n ones)

class ProductAndSum {
	public:
	int getSum(int p2, int p3, int p5, int p7, int S) {
        int total = S;
		S -= 5*p5 + 7*p7;
        if (S < 0) {
            return 0;
        }
        
        F[0] = 1;
        for (int i=1; i<2501; ++i) {
            F[i] = F[i-1]*i%mod;
        }
        invF[0] = 1;
        for (int i=1; i<2501; ++i) {
            invF[i] = invF[i-1]*mul_inv(i)%mod;
        }
        digval[0] = 0;
        for (int i=1; i<2501; ++i) {
            digval[i] = (digval[i-1]*10 + 1) % mod;
        }

        vector<int> cnt_dig(10, 0);
        cnt_dig[7] = p7;
        cnt_dig[5] = p5;
        const int lim6 = min(p2, p3);
        
        long long sol = 0;
        for (cnt_dig[6]=0; cnt_dig[6]<=lim6 && cnt_dig[6]*6<=S; ++cnt_dig[6]) {
            int lim2 = p2 - cnt_dig[6];
            int lim3 = p3 - cnt_dig[6];
            assert(lim2 >= 0);
            assert(lim3 >= 0);
            int six_sum = cnt_dig[6] * 6;
            for (cnt_dig[9]=0; 2*cnt_dig[9]<=lim3 && six_sum+cnt_dig[9]*9+(lim3-2*cnt_dig[9])*3<=S; ++cnt_dig[9]) {
                cnt_dig[3] = lim3 - 2*cnt_dig[9];
                int SS = S - (six_sum + cnt_dig[9]*9 + cnt_dig[3]*3);
                for (cnt_dig[2]=0; cnt_dig[2]<=lim2 && 2*cnt_dig[2]<=SS; ++cnt_dig[2]) {
                    int lim48 = lim2 - cnt_dig[2];
                    for (cnt_dig[4]=0; 2*cnt_dig[4]<=lim48 && 2*cnt_dig[2]+4*cnt_dig[4]<=SS; ++cnt_dig[4]) {
                        int lim8 = lim48 - 2*cnt_dig[4];
                        if (lim8%3 != 0) {
                            continue;
                        }
                        cnt_dig[8] = lim8/3;
                        cnt_dig[1] = SS - 2*cnt_dig[2] - 4*cnt_dig[4] - 8*cnt_dig[8];
                        if (cnt_dig[1] < 0) {
                            continue;
                        }
                        
                        int n = accumulate(cnt_dig.begin(), cnt_dig.end(), 0);
                        
                        long long ways = F[n-1];
                        for (int i=1; i<10; ++i) {
                            ways = ways*invF[cnt_dig[i]]%mod;
                        }
                        sol = (sol + ways*total%mod*digval[n])%mod;
                    }
                }
            }
        }
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 0; int Arg2 = 0; int Arg3 = 0; int Arg4 = 4; int Arg5 = 26; verify_case(0, Arg5, getSum(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 0; int Arg3 = 0; int Arg4 = 10; int Arg5 = 110109965; verify_case(1, Arg5, getSum(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 0; int Arg2 = 0; int Arg3 = 0; int Arg4 = 5; int Arg5 = 610; verify_case(2, Arg5, getSum(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1; int Arg3 = 1; int Arg4 = 10; int Arg5 = 0; verify_case(3, Arg5, getSum(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 5; int Arg1 = 5; int Arg2 = 5; int Arg3 = 5; int Arg4 = 100; int Arg5 = 61610122; verify_case(4, Arg5, getSum(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    ProductAndSum ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
