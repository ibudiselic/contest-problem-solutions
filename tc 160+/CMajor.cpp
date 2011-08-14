#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

bool done[1<<19][12];
int cnt[1<<19];
enum {
	NEG_FIX = 12000
};
int sol;
int n;
const unsigned black = 0x54A;
int next[19][12];

int bitcount(unsigned x) {
	int ret = 0;
	while (x != 0) {
		++ret;
		x &= (x-1);
	}
	return ret;
}
void go(unsigned state, int cur) {
	if (done[state][cur])
		return;
	done[state][cur] = true;
	sol = max(sol, cnt[state]);
	for (int i=n-1; i>=0; --i)
		if ((state & (1<<i))==0 && next[i][cur]!=-1)
			go(state | (1<<i), next[i][cur]);
}
class CMajor {
	public:
	int getLongest(vector <string> fragments) {
		n = fragments.size();
		memset(done, 0, sizeof done);
		unsigned frag[19] = { 0 };
		int move[19] = { 0 };

		for (int i=0; i<(1<<n); ++i)
			cnt[i] = bitcount(i);
		for (int i=0; i<n; ++i) {
			istringstream is(fragments[i]);
			int t;
			while (is >> t) {
				if (t >= 0) {
					move[i] = (move[i]+t) % 12;
					frag[i] |= (1<<move[i]);
				} else {
					move[i] = (move[i] + (t+NEG_FIX)%12) % 12;
					frag[i] |= (1<<move[i]);
				}
			}
		}
		for (int i=0; i<n; ++i)
			for (int j=0; j<12; ++j)
				if ((((frag[i]<<j)+(frag[i]>>(12-j))) & black) == 0)
					next[i][j] = (j+move[i])%12;
				else
					next[i][j] = -1;

		sol = 0;
		go(0u, 0); go(0u, 2); go(0u, 4); go(0u, 5); go(0u, 7); go(0u, 9); go(0u, 11);
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"2 2 1 2 2 2 1","2 1 2 2 2 1 2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, getLongest(Arg0)); }
	void test_case_1() { string Arr0[] = {"2","2","1","2","2","2","1","2","2","1","2","2","2","1","2","2","1","2","2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 19; verify_case(1, Arg1, getLongest(Arg0)); }
	void test_case_2() { string Arr0[] = {"2 2 2 2","1 1","5 -4 12 -11","0 2 -2 5 -1 -4 2 -2 7 -2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, getLongest(Arg0)); }
	void test_case_3() { string Arr0[] = {"2 0 2 0 -2 -2 -1 5 1 2 2 2 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(3, Arg1, getLongest(Arg0)); }
	void test_case_4() { string Arr0[] = {"5748 -4385 -790 5294 3349","-3279 -1783 3768 -2459 6066 2556 -8138 -4982 1435",
 "2951","-2405 2104 3756","5578 -5040 -9497 -4868 7407 9305 -6701",
 "-3339 9514 -787 7209 7467 -4467", "7496 3011 9941 -8340 3012"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(4, Arg1, getLongest(Arg0)); }
	void test_case_5() { string Arr0[] = {"72","1872","8916","-288","2208","-4716","2328","9516",
 "-5472","9840","6420","3492","-1608","4176","264","-6264",
 "1176","-684","3984"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 19; verify_case(5, Arg1, getLongest(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    CMajor ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
