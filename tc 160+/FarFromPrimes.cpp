#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

#define N 10000
unsigned primes[N];
void nprime(int x) {
	primes[x/16] |= (1u<<(x%16));
}
bool is_prime(int x) {
	return !((primes[x/16]>>(x%16)) & 1u);
}
class FarFromPrimes {
	public:
	int count(int A, int B) {
		memset(primes, 0, sizeof primes);
		nprime(0);
		nprime(1);

		for (int i=2; i*i<=B+10; ++i)
			for (int j=i; i*j<=B+10; ++j)
				nprime(i*j);

		int sol = 0;
		for (int i=A; i<=B; ++i) {
			for (int j=i-10; j<=i+10; ++j)
				if (is_prime(j))
					goto skip;
			++sol;
			skip: ;
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3328; int Arg1 = 4100; int Arg2 = 4; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 1000; int Arg2 = 0; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 19240; int Arg1 = 19710; int Arg2 = 53; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 23659; int Arg1 = 24065; int Arg2 = 20; verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 97001; int Arg1 = 97691; int Arg2 = 89; verify_case(4, Arg2, count(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    FarFromPrimes ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
