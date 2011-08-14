#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

#define MAX_NUM_ 10000001
// 6bits = 1parity bit + 32 different offsets in the same int
int P_[(MAX_NUM_>>6) + 1]; // negative logic (1 bit marks a non-prime)
// for x >= 0
inline bool is_prime(int x) { return x==2 ? true : (x&1 ? !((P_[(x>>6)]>>((x>>1)&0x1f))&1) : false); }
// only call for odd x
inline void mark_nonprime(int x) { x >>= 1; P_[x>>5] |= (1<<(x&0x1f)); }
void init_primes() { for (long long x=3; x<=MAX_NUM_; x+=2) { if (is_prime(x) && x<=MAX_NUM_/x) { const long long z = x<<1; for (long long y=x*x; y<=MAX_NUM_; y+=z) { mark_nonprime(y); } } } }

char cnt[10000001];
class PrimeSequences {
	public:
	int getLargestGenerator(int N, int D) {
		init_primes();
        memset(cnt, 0, sizeof cnt);
        cnt[2] = 1;
        for (int i=3; i<=N; ++i) {
            if (is_prime(i)) {
                const int x = i/2;
                cnt[i] = cnt[x] + 1;
            }
        }

        for (int i=N; i>=1; --i) {
            if (cnt[i] >= D) {
                return i;
            }
        }
        return -1;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arg1 = 2; int Arg2 = 7; verify_case(0, Arg2, getLargestGenerator(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 42; int Arg1 = 3; int Arg2 = 23; verify_case(1, Arg2, getLargestGenerator(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 666; int Arg1 = 7; int Arg2 = -1; verify_case(2, Arg2, getLargestGenerator(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 1337; int Arg1 = 5; int Arg2 = 47; verify_case(3, Arg2, getLargestGenerator(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 100000; int Arg1 = 5; int Arg2 = 2879; verify_case(4, Arg2, getLargestGenerator(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 40000; int Arg1 = 1; int Arg2 = 39989; verify_case(5, Arg2, getLargestGenerator(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    PrimeSequences ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
