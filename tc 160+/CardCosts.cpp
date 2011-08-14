#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

long long cnt[1000000];
long long potK[1000000];

long long calc(int x) {
	assert(potK[x] != -1);
	return (2*cnt[x] + 1)*potK[x];
}
class CardCosts {
	public:
	long long mincost(int n, int k) {
		if (k == 1)
			return n;

		memset(potK, 0xff, sizeof potK);
		potK[0] = 1;
		int pos = 0;
		while (((1LL<<62)-1)/k >= potK[pos]) {
			potK[pos+1] = potK[pos]*k;
			++pos;
		}

		memset(cnt, 0, sizeof cnt);
		long long val = 0;
		for (int i=0; i<n; ++i) {
			long long best = (1LL<<62)-1;
			int x = -1;
			for (int j=0; j==0 || cnt[j-1]>0; ++j)
				if (calc(j) < best) {
					best = calc(j);
					x = j;
				}
			assert(x != -1);
			val += best;
			++cnt[x];
		}

		return val;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 6; int Arg1 = 2; long long Arg2 = 21LL; verify_case(0, Arg2, mincost(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 400; int Arg1 = 1000; long long Arg2 = 160000LL; verify_case(1, Arg2, mincost(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1000000; int Arg1 = 1000; long long Arg2 = 999000001000LL; verify_case(2, Arg2, mincost(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 113772; int Arg1 = 188; long long Arg2 = 12875219937LL; verify_case(3, Arg2, mincost(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 0; int Arg1 = 654; long long Arg2 = 0LL; verify_case(4, Arg2, mincost(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 1000000; int Arg1 = 1; long long Arg2 = 1000000LL; verify_case(5, Arg2, mincost(Arg0, Arg1)); }
	void test_case_6() { int Arg0 = 1000000; int Arg1 = 2; long long Arg2 = 500000500000LL; verify_case(6, Arg2, mincost(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    CardCosts ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
