#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <numeric>

using namespace std;

long long mod = 1234567891LL;
long long inv[100001];
long long to_the(long long x, long long n) {
    if (n == 0) {
        return 1LL;
    } else {
        long long t = to_the(x, n/2);
        t = t*t % mod;
        if (n & 1) {
            t = t*x % mod;
        }
        return t;
    }
}
long long C(long long n, long long k) {
    if (n<0 || n<k) {
        return 0;
    }
    long long ret = 1;
    while (k > 0) {
        ret = (ret*((n-k+1)%mod) % mod) * inv[k] % mod;
        --k;
    }
    
    return ret;
}

class TheBeautifulBoard {
	public:
	int count(int n, vector <int> checkers) {
        long long N = ((long long)n)*n;
        long long total = accumulate(checkers.begin(), checkers.end(), 0LL);
        if (N < total) {
            return 0;
        }
        inv[0] = 1;
        inv[1] = 1;
		for (int i=2; i<100001; ++i) {
            inv[i] = to_the(i, mod-2);
            assert(i*inv[i] % mod == 1);
        }
        
        long long cur = 0;
        long long T4 = 1;
        for (int i=0; i<(int)checkers.size(); ++i) {
            T4 = T4 * C(N - cur, checkers[i]) % mod;
            cur += checkers[i];
        }
        
        long long T2 = 1;
        cur = 0;
        int special = 0;
        for (int i=0; i<(int)checkers.size(); ++i) {
            T2 = T2 * C(N/2 - cur, checkers[i]/2) % mod;
            cur += checkers[i]/2;
            special += checkers[i]%2;
        }
        if (N%2==1 && special>1 || N%2==0 && special>0) {
            T2 = 0;
        }
        
        long long T1 = 1;
        cur = 0;
        special = 0;
        int special2 = 0;
        for (int i=0; i<(int)checkers.size(); ++i) {
            T1 = T1 * C(N/4 - cur, checkers[i]/4) % mod;
            cur += checkers[i]/4;
            special += (checkers[i]%4 != 0);
            special2 += (checkers[i]%4 == 1);
        }
        if (N%2==0 && special>0 || N%2==1 && (special>1 || special==1 && special2==0)) {
            T1 = 0;
        }
        
        long long C1 = T1;
        long long C2 = T2 - T1;
        if (C2 < 0) {
            C2 += mod;
        }
        long long C4 = T4 - T2;
        if (C4 < 0) {
            C4 += mod;
        }
        return ((C4*inv[4]%mod + C2*inv[2]%mod)%mod + C1)%mod;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arr1[] = {1, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; int Arr1[] = {1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 18; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 3; int Arr1[] = {4, 2, 1, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(3, Arg2, count(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TheBeautifulBoard ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
