#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class EngineersPrimes {
	public:
	bool is_prime(int x) {
		if (x%2 == 0) return 0;
		for (int i=3; i*i<=x; i+=2)
			if (x%i == 0)
				return 0;
		return 1;
	}
	long long smallestNonPrime(int N) {
		int num = 2;

		while (N--) {
			do {
				++num;
			} while (!is_prime(num));
		}
		return (long long)(num)*num;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; long long Arg1 = 49LL; verify_case(0, Arg1, smallestNonPrime(Arg0)); }
	void test_case_1() { int Arg0 = 1; long long Arg1 = 9LL; verify_case(1, Arg1, smallestNonPrime(Arg0)); }
	void test_case_2() { int Arg0 = 265; long long Arg1 = 2886601LL; verify_case(2, Arg1, smallestNonPrime(Arg0)); }
	void test_case_3() { int Arg0 = 1835; long long Arg1 = 247716121LL; verify_case(3, Arg1, smallestNonPrime(Arg0)); }
	void test_case_4() { int Arg0 = 10000; long long Arg1 = 10971096049LL; verify_case(4, Arg1, smallestNonPrime(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    EngineersPrimes ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
