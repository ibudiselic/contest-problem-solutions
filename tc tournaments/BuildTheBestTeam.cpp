#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <set>

using namespace std;

int N, I;
struct Player {
	int norm, pp;
	Player(int norm_, int pp_): norm(norm_), pp(pp_) {}
};
bool operator<(const Player &a, const Player &b) {
	if (a.norm != b.norm)
		return a.norm > b.norm;
	else
		return a.pp > b.pp;
}
vector<Player> v;
int dp[50][50][2];
int go(int rStart, int iStart, bool up) {
	if (iStart == (int)v.size())
		return 0;

	if (dp[rStart][iStart][up] != -1)
		return dp[rStart][iStart][up];

	dp[rStart][iStart][up] = 0;
	for (int i=max(rStart+(up ? I-1 : N-I), iStart); i<(int)v.size(); ++i)
		dp[rStart][iStart][up] = max(dp[rStart][iStart][up], v[i].pp + go(rStart+N, i+1, 1-up));

	return dp[rStart][iStart][up];
}

class BuildTheBestTeam {
	public:
	int maximalStrength(vector <int> usualSkills, vector <int> powerplaySkills, int teams, int ind) {
		N = teams;
		I = ind;

		v.clear();
		for (int i=0; i<(int)usualSkills.size(); ++i)
			v.push_back(Player(usualSkills[i], powerplaySkills[i]));

		sort(v.begin(), v.end());

		memset(dp, 0xff, sizeof dp);
		return go(0, 0, 1);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {10, 10, 10, 10, 10, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {20, 20, 20, 20, 20, 20}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 2; int Arg4 = 40; verify_case(0, Arg4, maximalStrength(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {10, 10, 10, 10, 10, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10, 30, 10, 10, 30, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 3; int Arg4 = 20; verify_case(1, Arg4, maximalStrength(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {1, 2, 3, 4, 5, 6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {6, 5, 4, 3, 2, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 1; int Arg4 = 11; verify_case(2, Arg4, maximalStrength(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {1, 2, 3, 4, 5, 6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {6, 2, 4, 3, 5, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 1; int Arg4 = 11; verify_case(3, Arg4, maximalStrength(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = {88, 82, 82, 73}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {68, 74, 14, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 1; int Arg4 = 75; verify_case(4, Arg4, maximalStrength(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    BuildTheBestTeam ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
