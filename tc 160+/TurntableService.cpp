#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int dp[1<<15][15][2];
int n;
int favs[15];
int go(int need, int turn, bool canTurn) {
	if (need == 0)
		return 0;

	int &ret = dp[need][turn][canTurn];
	if (ret != -1)
		return ret;

	ret = 1234567890;

	if (canTurn)
		for (int i=1; i<n; ++i) {
			ret = min(ret, i+1 + go(need, (turn+i)%n, 0));
			ret = min(ret, i+1 + go(need, (turn+n-i)%n, 0));
		}

	int nNeed = need;
	for (int i=0; i<n; ++i)
		if (need & (1<<i)) {
			int infront = (i+turn)%n;
			if (favs[i] & (1<<infront))
				nNeed ^= (1<<i);
		}
	if (need == nNeed)
		return ret;

	return ret = min(ret, 15 + go(nNeed, turn, 1));
}

class TurntableService {
	public:
	int calculateTime(vector <string> favorites) {
		memset(favs, 0, sizeof favs);
		n = favorites.size();

		for (int i=0; i<n; ++i) {
			istringstream is(favorites[i]);
			int x;
			while (is >> x)
				favs[i] |= (1<<x);
		}

		memset(dp, 0xff, sizeof dp);
		return go((1<<n)-1, 0, 1);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"0 2", "1", "0 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 32; verify_case(0, Arg1, calculateTime(Arg0)); }
	void test_case_1() { string Arr0[] = {"0", "0", "0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 49; verify_case(1, Arg1, calculateTime(Arg0)); }
	void test_case_2() { string Arr0[] = {"4", "1", "2", "3", "0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 50; verify_case(2, Arg1, calculateTime(Arg0)); }
	void test_case_3() { string Arr0[] = {"0 004", "2 3", "0 01", "1 2 3 4", "1 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 35; verify_case(3, Arg1, calculateTime(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    TurntableService ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
