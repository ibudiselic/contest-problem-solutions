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
// 6bits = 1parity bit + 32 different offsets in the same int
int P_[(MAX_NUM_>>6) + 1]; // negative logic (1 bit marks a non-prime)
// for x >= 0
inline bool is_prime(int x) { return x==2 ? true : (x&1 ? !((P_[(x>>6)]>>((x>>1)&0x1f))&1) : false); }
// only call for odd x
inline void mark_nonprime(int x) { x >>= 1; P_[x>>5] |= (1<<(x&0x1f)); }
void init_primes() { for (long long x=3; x<=MAX_NUM_; x+=2) { if (is_prime(x) && x<=MAX_NUM_/x) { const long long z = x<<1; for (long long y=x*x; y<=MAX_NUM_; y+=z) { mark_nonprime(y); } } } }

vector<int> P;
vector<int> primes;
int dp[100001];
class NewCoins {
	public:
	int minCoins(vector <int> price) {
        P = price;
        sort(P.begin(), P.end());
        if (primes.size() == 0) {
            init_primes();
            for (int i=2; i<100000; ++i) {
                if (is_prime(i)) {
                    primes.push_back(i);
                }
            }
        }
        memset(dp, 0x3f, sizeof dp);
        dp[0] = dp[1] = 0;
        for (int i=1; i<=P.back(); ++i) {
            for (int j=0; j<(int)primes.size(); ++j) {
                int k = i * primes[j];
                if (k > (int)P.back()) {
                    break;
                }
                int contrib = 0;
                for (int t=0; t<(int)P.size(); ++t) {
                    contrib += P[t]%k/i;
                }
                dp[k] = min(dp[k], dp[i] + contrib);
            }
        }
        
        int sol = 5000001;
        for (int i=1; i<=P.back(); ++i) {
            for (int j=0; j<(int)P.size(); ++j) {
                dp[i] += P[j]/i;
            }
            sol = min(sol, dp[i]);
        }
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {25, 102}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, minCoins(Arg0)); }
	void test_case_1() { int Arr0[] = {58}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, minCoins(Arg0)); }
	void test_case_2() { int Arr0[] = {1, 4, 5, 9, 16}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(2, Arg1, minCoins(Arg0)); }
	void test_case_3() { int Arr0[] = {1, 1, 1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(3, Arg1, minCoins(Arg0)); }
	void test_case_4() { int Arr0[] = {28, 569, 587, 256, 15, 87, 927, 4, 589, 73, 98, 87, 597, 163, 6, 498}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 62; verify_case(4, Arg1, minCoins(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    NewCoins ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
