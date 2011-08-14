#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <utility>
using namespace std;
map< pair<int, long long>, long long> M;

long long go(long long n, int k) {
	if (n == 0)
		return 0;
	if (k == 1)
		return n;

	long long &ret = M[make_pair(k, n)];
	if (ret != 0)
		return ret;

	ret = n;
	for (int d=2; d<=5; ++d)
		ret = min(ret, n%d + go(n/d, k-1));

	return ret;
}

class NewMoneySystem {
	public:
	long long chooseBanknotes(string N, int K) {
		long long n;
		istringstream is(N);
		is >> n;
		M.clear();
		return go(n, K);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "1025"; int Arg1 = 6; long long Arg2 = 2LL; verify_case(0, Arg2, chooseBanknotes(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "1005"; int Arg1 = 5; long long Arg2 = 3LL; verify_case(1, Arg2, chooseBanknotes(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "12000"; int Arg1 = 14; long long Arg2 = 1LL; verify_case(2, Arg2, chooseBanknotes(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "924323565426323626"; int Arg1 = 1; long long Arg2 = 924323565426323626LL; verify_case(3, Arg2, chooseBanknotes(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "924323565426323626"; int Arg1 = 50; long long Arg2 = 10LL; verify_case(4, Arg2, chooseBanknotes(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    NewMoneySystem ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
