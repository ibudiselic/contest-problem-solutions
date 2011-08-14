#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

struct BigInt {
	string repr;
	BigInt(const string &s=""): repr(s) { reverse(repr.begin(), repr.end()); }
	BigInt(long long x) { ostringstream os; os << x; BigInt(os.str()); }

	BigInt& operator+=(const BigInt &b_) {
		bool carry = 0;
		int i=0;
		string &a = repr;
		const string &b = b_.repr;

		while (i<(int)a.size() || i<(int)b.size() || carry) {
			const int d1 = (i>=(int)a.size() ? 0 : a[i]-'0');
			const int d2 = (i>=(int)b.size() ? 0 : b[i]-'0');
			const int d = d1+d2+carry;
			carry = d/10;
			if (i==(int)a.size())
				a += ' ';
			a[i++] = char(d%10 + '0');
		}

		return *this;
	}
	string str() { string ret = repr; reverse(ret.begin(), ret.end()); return ret; }
};

int N;
int K;

BigInt dp[100][1<<13];
bool done[100][1<<13];
BigInt go(int i, int mask) {
	if (i == N)
		return BigInt("1");

	if (done[i][mask])
		return dp[i][mask];

	done[i][mask] = 1;
	BigInt &ret = dp[i][mask];
	ret = BigInt("0");

	if (i-K>=0 && (mask & (1<<(2*K)))==0)
		return ret = go(i+1, mask<<1);

	for (int x=2*K-1; x>=0; --x)
		if (i-x+K>=0 && i-x+K<N && (mask & (1<<x))==0)
			ret += go(i+1, ((mask | (1<<x))<<1)&((1<<(2*K+1))-1));

	return ret;
}

class FairTournament {
	public:
	string countPermutations(int n, int k) {
		N = n;
		K = k;

		memset(done, 0, sizeof done);

		return go(0, 0).str();
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 1; string Arg2 = "3"; verify_case(0, Arg2, countPermutations(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 2; string Arg2 = "6"; verify_case(1, Arg2, countPermutations(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 3; string Arg2 = "19708"; verify_case(2, Arg2, countPermutations(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 100; int Arg1 = 1; string Arg2 = "573147844013817084101"; verify_case(3, Arg2, countPermutations(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    FairTournament ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
