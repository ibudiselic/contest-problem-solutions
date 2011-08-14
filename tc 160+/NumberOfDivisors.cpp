#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

const int max_prime = 1000;
int P[(max_prime>>6) + 1];
bool is_prime(int x) {
	if (x == 2) {
		return true;
	}
	if (x<=1 || (x&1)==0) {
		return false;
	}
	x >>= 1;
	return ((P[x>>5] & (1 << (x&31))) == 0);
}
void set_not_prime(int x) {
	x >>= 1;
	P[x>>5] |= (1 << (x&31));
}
void prime_init() {
	P[0] = 1;
	for (int x=3; x<max_prime; ++x) {
		if (is_prime(x)) {
			for (int t=3*x; t<max_prime; t+=2*x) {
				set_not_prime(t);
			}
		}
	}
}

vector<int> primes;
long long dp[20][50001];
bool safe(long long x, long long y) {
	return x <= 1234567891234567890LL/y;
}
long long go(int p, int k) {
	if (k == 1) {
		return 1;
	}
	assert(p < 20);
	long long &ret = dp[p][k];
	if (ret != -1) {
		return ret;
	}

	ret = 1234567891234567890LL;
	long long pot = 1;
	for (int d=2; d<=k && safe(pot, primes[p]); ++d) {
		pot *= primes[p];
		if (k%d == 0) {
			long long t = go(p+1, k/d);
			if (safe(pot, t)) {
				ret = min(ret, pot*t);
			}
		}
	}
	
	return ret;
}

class NumberOfDivisors {
	public:
	long long smallestNumber(int k) {
		prime_init();
		primes.clear();
		for (int i=2; primes.size()<20; ++i) {
			if (is_prime(i)) {
				primes.push_back(i);
			}
		}

		memset(dp, 0xff, sizeof dp);
		long long sol = go(0, k);
		return sol<=1000000000000000000LL ? sol : -1;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; long long Arg1 = 1LL; verify_case(0, Arg1, smallestNumber(Arg0)); }
	void test_case_1() { int Arg0 = 2; long long Arg1 = 2LL; verify_case(1, Arg1, smallestNumber(Arg0)); }
	void test_case_2() { int Arg0 = 6; long long Arg1 = 12LL; verify_case(2, Arg1, smallestNumber(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    NumberOfDivisors ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
