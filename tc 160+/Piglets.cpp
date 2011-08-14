#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int dp[1<<15];
int N;
int bestPos(int mask) {
	if (mask == 0)
		return -1;
	if (dp[mask] != -1)
		return dp[mask];

	int ret = -1;
	int best = 0;

	for (int i=0; i<N; ++i)
		if (mask & (1<<i)) {
			assert(i>0 && i+1<N);
			int cnt = 1;
			int m = (mask ^ (1<<i));
			while ((m & (1<<(i-1))) || (m & (1<<(i+1)))) {
				++cnt;
				m ^= (1<<bestPos(m));
			}
			if (cnt > best) {
				best = cnt;
				ret = i;
			}
		}
	return dp[mask] = ret;
}
class Piglets {
	public:
	int choose(string trough) {
		if (trough == string(trough.size(), 'p'))
			return -1;
		if (trough[0] == '-')
			return 0;
		if (trough[trough.size()-1] == '-')
			return trough.size()-1;

		memset(dp, 0xff, sizeof dp);
		int mask = 0;
		N = trough.size();
		for (int i=0; i<N; ++i)
			if (trough[i] == '-')
				mask |= (1<<i);

		return bestPos(mask);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "--p--"; int Arg1 = 0; verify_case(0, Arg1, choose(Arg0)); }
	void test_case_1() { string Arg0 = "p-p-p"; int Arg1 = 1; verify_case(1, Arg1, choose(Arg0)); }
	void test_case_2() { string Arg0 = "p--p"; int Arg1 = 1; verify_case(2, Arg1, choose(Arg0)); }
	void test_case_3() { string Arg0 = "p---p"; int Arg1 = 2; verify_case(3, Arg1, choose(Arg0)); }
	void test_case_4() { string Arg0 = "ppp"; int Arg1 = -1; verify_case(4, Arg1, choose(Arg0)); }
	void test_case_5() { string Arg0 = "p----p"; int Arg1 = 3; verify_case(5, Arg1, choose(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Piglets ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
