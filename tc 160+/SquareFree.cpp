#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;
class Sieve {
	public:
	Sieve(long long maxx) {
		maxx = max(maxx, 32ll);
		v.assign((maxx+32-1)/32, 0); // 0 means is_prime

		mark_nonprime(0);
		mark_nonprime(1);
		for (long long x=2; x<=maxx; ++x)
			if (is_prime(x))
				for (long long y=2*x; y<=maxx; y+=x)
					mark_nonprime(y);
	}
	bool is_prime(long long x) {
		long long cell = x/32;
		int offset = x%32;
		return !((v[cell]>>offset)&1);
	}
	private:
	void mark_prime(long long x) {
		long long cell = x/32;
		int offset = x%32;
		v[cell] &= ~(1<<offset);
	}
	void mark_nonprime(long long x) {
		long long cell = x/32;
		int offset = x%32;
		v[cell] |= (1<<offset);
	}

	vector<int> v;
};

vector<int> p;
int with_sq_lte_n(int n, int x, long long cur) {
	assert(x < (int)p.size());

	if (p[x]*cur > n)
		return 0;

	return n/(p[x]*cur) + with_sq_lte_n(n, x+1, cur) - with_sq_lte_n(n, x+1, cur*p[x]);
}
class SquareFree {
	public:
	int getNumber(int n) {
		Sieve S(46340);

		p.clear();
		for (int i=0; i<=46340; ++i)
			if (S.is_prime(i))
				p.push_back(i*i);


		int lo = 0;
		int hi = (1<<31)-1;

		while (lo < hi) {
			int mid = lo + (hi-lo)/2;

			if (mid - with_sq_lte_n(mid, 0, 1) >= n)
				hi = mid;
			else
				lo = mid+1;
		}

		return lo;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; verify_case(0, Arg1, getNumber(Arg0)); }
	void test_case_1() { int Arg0 = 13; int Arg1 = 19; verify_case(1, Arg1, getNumber(Arg0)); }
	void test_case_2() { int Arg0 = 100; int Arg1 = 163; verify_case(2, Arg1, getNumber(Arg0)); }
	void test_case_3() { int Arg0 = 1234567; int Arg1 = 2030745; verify_case(3, Arg1, getNumber(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    SquareFree ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
