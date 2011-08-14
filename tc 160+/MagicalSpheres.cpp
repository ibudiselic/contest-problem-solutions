#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

#define MAX_NUM_ 100000
int P_[(MAX_NUM_>>6) + 1]; // negative logic (1 bit marks a non-prime)
// for x >= 0
inline bool is_prime(int x) { return x==2 ? true : (x&1 ? !((P_[(x>>6)]>>((x>>1)&0x1f))&1) : false); }
inline void mark_nonprime(int x) { x >>= 1; P_[x>>5] |= (1<<(x&0x1f)); }
void init_primes() { for (int x=3; x<=MAX_NUM_; x+=2) { if (is_prime(x)) { const int z = x<<1; for (int y=z+x; y<=MAX_NUM_; y+=z) { mark_nonprime(y); } } } }

int dp[3][100001];
int get_exp_in_fact(long long f, long long x, int t) {
    if (dp[t][x] != -1) {
        return dp[t][x];
    }

    long long y = x;
    int ret = 0;
    while (y <= f) {
        ret += f/y;
        y *= x;
    }

    return (dp[t][x] = ret);
}
class MagicalSpheres {
	public:
	int divideWork(int a, int f, int g) {
        init_primes();
        memset(dp, 0xff, sizeof dp);
        int t = a + f;
        while (g > 1) {
            int x = g;
            bool ok = true;
            int c2 = 0;
            while ((x&1) == 0) {
                ++c2;
                x >>= 1;
            }
            if (get_exp_in_fact(t, 2, 0) - get_exp_in_fact(f, 2, 1) - get_exp_in_fact(t-f, 2, 2) < c2) {
                --g;
                continue;
            }

            int d = 3;
            while (x > 1) {
                if (is_prime(d) && x%d==0) {
                    int cnt = 0;
                    do {
                        x /= d;
                        ++cnt;
                    } while (x%d == 0);
                    int in_combs = get_exp_in_fact(t, d, 0) - get_exp_in_fact(f, d, 1) - get_exp_in_fact(t-f, d, 2);
                    if (in_combs < cnt) {
                        ok = false;
                        break;
                    }
                }
                d += 2;
            }
            if (ok) {
                return g;
            }

            --g;
        }
		
        return 1;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 3; int Arg3 = 2; verify_case(0, Arg3, divideWork(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 50; int Arg3 = 20; verify_case(1, Arg3, divideWork(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 3; int Arg2 = 4; int Arg3 = 1; verify_case(2, Arg3, divideWork(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 15634; int Arg1 = 456; int Arg2 = 5000; int Arg3 = 4990; verify_case(3, Arg3, divideWork(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    MagicalSpheres ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
