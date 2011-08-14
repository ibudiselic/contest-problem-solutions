#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

//- number 8 uses seven matches. - numbers 0, 6 and 9 each use six matches. - numbers 2, 3 and 5 each use five matches. - numbers 4 and 7 each use four matches. - number 1 uses two matches.
const int cnt[] = { 6, 2, 5, 5, 4, 5, 6, 4, 7, 6 };
int calc(long long x) {
	int ret = (x==0 ? cnt[0] : 0);
	while (x > 0) {
		ret += cnt[x%10];
		x /= 10;
	}
	return ret;
}
long long dp[129];
class MatchCounting {
	public:
	long long go(int n) {
		if (n < 7) {
			int x = 0;
			while (calc(x) <= n)
				++x;
			return x;
		}
		if (dp[n]!= -1)
			return dp[n];

		int cur = 7;
		long long x = 8;
		long long pot10 = 10;
		while (cur+7 <= n) {
			x = x*10 + 8;
			pot10 *= 10;
			cur += 7;
		}

		cur = 1;
		while (1) {
			if (go(n-cnt[cur]) >= pot10) {
				++cur;
				continue;
			}
			x = pot10;
			int zeros = 0;
			vector<int> goodZeros;
			while (x >= 10) {
				long long t = go(n-zeros*cnt[0]-cnt[cur]);

				if (x/10<=t && t<x || (x==10 && t==0))
					goodZeros.push_back(zeros);

				x /= 10;
				++zeros;
			}
			if (goodZeros.size() > 0) {
				n -= goodZeros.back()*cnt[0];
				break;
			}
			++cur;
			assert(cur < 10);
		}

		return dp[n] = cur*pot10 + go(n-cnt[cur]);
	}
	long long count(int n) {
		if (n < 7) {
			int x = 1;
			while (calc(x) <= n)
				++x;
			return x;
		}

		memset(dp, 0xff, sizeof dp);
		return go(n);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; long long Arg1 = 1LL; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { int Arg0 = 2; long long Arg1 = 2LL; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { int Arg0 = 5; long long Arg1 = 6LL; verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { int Arg0 = 6; long long Arg1 = 8LL; verify_case(3, Arg1, count(Arg0)); }
	void test_case_4() { int Arg0 = 9; long long Arg1 = 20LL; verify_case(4, Arg1, count(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    MatchCounting ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
