#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int P[60];
int is_prime(int n) {
	if (P[n] != -1)
		return P[n];
	for (int i=2; i*i<=n; ++i)
		if (n%i == 0)
			return P[n] = 0;
	return P[n] = 1;
}
long long root(int k, long long n) {
	long long lo = 1;
	long long hi = 1000000001;
	while (hi > lo) {
		long long mid = lo + (hi-lo+1)/2;
		long long x = 1;
		bool ok = true;
		for (int i=0; i<k; ++i) {
			if (x <= n/mid) {
				x *= mid;
			} else {
				ok = false;
				break;
			}
		}
		if (ok)
			lo = mid;
		else
			hi = mid-1;
	}
	return lo;
}
long long calc(long long n, int p) {
	long long ret = 1;
	for (int k=2; k<p; ++k)
		if (is_prime(k)) {
			long long r = root(k, n);
			if (r == 1) break;
			ret += r - calc(r, k);
		}
	return ret;
}
class PowerCollector {
	public:
	string countPowers(string N) {
		fill(P, P+60, -1);
		long long n;
		istringstream is(N);
		is >> n;
		n = calc(n, 60);
		ostringstream os;
		os << n;
		return os.str();
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "10"; string Arg1 = "4"; verify_case(0, Arg1, countPowers(Arg0)); }
	void test_case_1() { string Arg0 = "36"; string Arg1 = "9"; verify_case(1, Arg1, countPowers(Arg0)); }
	void test_case_2() { string Arg0 = "1000000000000000000"; string Arg1 = "1001003332"; verify_case(2, Arg1, countPowers(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    PowerCollector ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
