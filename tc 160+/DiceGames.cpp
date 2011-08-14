#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<int> S;
long long dp[32][32];
long long go(int pos, int start) {
	if (pos == (int)S.size())
		return 1;

	if (dp[pos][start] != -1)
		return dp[pos][start];

	dp[pos][start] = 0;
	for (int i=start; i<S[pos]; ++i)
		dp[pos][start] += go(pos+1, i);

	return dp[pos][start];
}
class DiceGames {
	public:
	long long countFormations(vector <int> sides) {
		sort(sides.begin(), sides.end());
		S = sides;
		memset(dp, 0xff, sizeof dp);

		return go(0, 0);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 4LL; verify_case(0, Arg1, countFormations(Arg0)); }
	void test_case_1() { int Arr0[] = {2, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 3LL; verify_case(1, Arg1, countFormations(Arg0)); }
	void test_case_2() { int Arr0[] = {4, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 10LL; verify_case(2, Arg1, countFormations(Arg0)); }
	void test_case_3() { int Arr0[] = {3, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 9LL; verify_case(3, Arg1, countFormations(Arg0)); }
	void test_case_4() { int Arr0[] = {4, 5, 6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 48LL; verify_case(4, Arg1, countFormations(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    DiceGames ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
