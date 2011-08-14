#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool ok[1u<<8]; // true if mask has no adjecent 1 bits
long long dp[80][21][1u<<8]; // [i][j][k] number of seatings of the rows i trough N-1, with j cheaters and with the last row encoded with k
long long choose_[81][81];
int M, N;
int bitcount(unsigned x) {
	int ret = 0;
	while (x != 0) {
		x &= x-1;
		++ret;
	}
	return ret;
}
long long choose(int n, int k) {
	if (k > n) return 0;
	if (k==0 || k==n) return 1;
	if (k == 1) return n;

	if (choose_[n][k] != -1)
		return choose_[n][k];

	return choose_[n][k] = choose(n-1, k-1) + choose(n-1, k);
}
long long go(int r, int c, unsigned mask) {
	if (r == M)
		return (c==0);
	if (dp[r][c][mask] != -1)
		return dp[r][c][mask];

	long long ret = 0;
	for (unsigned m=0; m<(1u<<N); m = (mask+m+1) & ~mask)
		if (ok[m]) {
			const int bc = bitcount(m);
			if (c >= bc)
				ret += go(r+1, c-bc, m);
		}

	return dp[r][c][mask] = ret;
}
long long gcd(long long a, long long b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a%b);
}
class SeatingPlan {
	public:
	string expectedTrial(int m, int n, int k) {
		if (m < n)
			swap(m, n);
		M = m;
		N = n;

		memset(dp, 0xff, sizeof dp);
		memset(choose_, 0xff, sizeof choose_);
		for (unsigned mask=0; mask<(1u<<N); ++mask) {
			ok[mask] = true;
			for (int i=0; (3u<<i)<=mask; ++i)
				if (((3u<<i) & mask) == (3u<<i)) {
					ok[mask] = false;
					break;
				}
		}

		long long a = go(0, k, 0);
		long long b = choose(m*n, k);
		const long long d = gcd(a, b);
		a /= d;
		b /= d;

		if (a == 0)
			return "Impossible!";
		else {
			char buff[256];
			sprintf(buff, "%lld/%lld", b, a);
			return string(buff);
		}
		return ":cry";
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 4; int Arg2 = 3; string Arg3 = "Impossible!"; verify_case(0, Arg3, expectedTrial(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 3; int Arg2 = 0; string Arg3 = "1/1"; verify_case(1, Arg3, expectedTrial(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 3; int Arg2 = 2; string Arg3 = "15/8"; verify_case(2, Arg3, expectedTrial(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 2; string Arg3 = "3/2"; verify_case(3, Arg3, expectedTrial(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 8; int Arg1 = 7; int Arg2 = 18; string Arg3 = "70775996591300/172086661"; verify_case(4, Arg3, expectedTrial(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    SeatingPlan ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
