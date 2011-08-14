#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <cctype>

using namespace std;

int bc[1<<16];
int N;
int M;
vector<string> C;
int getCost(int a, int b) {
	if (isdigit(C[a][b]))
		return C[a][b] - '0';
	return C[a][b]-'A' + 10;
}
int dp[16][1<<16];
int INF = 123456789;
int go(int pos, int active) {
	if (pos == N)
		return (bc[active]>=M ? 0 : INF);
	if (active & (1<<pos))
		return go(pos+1, active);

	if (dp[pos][active] != -1)
		return dp[pos][active];

	int ret = go(pos+1, active);
	int bestCost = INF;
	for (int i=0; i<N; ++i)
		if (active & (1<<i))
			bestCost = min(bestCost, getCost(i, pos));

	ret = min(ret, bestCost + go(0, active | (1<<pos)));

	return (dp[pos][active] = ret);
}
class PowerPlants {
	public:
	int minCost(vector <string> connectionCost, string plantList, int numPlants) {
		bc[0] = 0;
		for (int m=1; m<(1<<16); ++m)
			bc[m] = bc[m>>1] + (m&1);

		int active = 0;
		C = connectionCost;
		N = C.size();
		for (int i=0; i<N; ++i)
			if (plantList[i] == 'Y')
				active |= (1<<i);
		M = numPlants;

		memset(dp, 0xff, sizeof dp);
		return go(0, active);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"024",
 "203",
 "430"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YNN"; int Arg2 = 3; int Arg3 = 5; verify_case(0, Arg3, minCost(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"0AB",
 "A0C",
 "CD0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YNN"; int Arg2 = 3; int Arg3 = 21; verify_case(1, Arg3, minCost(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"1ABCD",
 "35HF8",
 "FDM31",
 "AME93",
 "01390"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NYNNN"; int Arg2 = 5; int Arg3 = 14; verify_case(2, Arg3, minCost(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"012",
 "123",
 "234"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NNY"; int Arg2 = 2; int Arg3 = 2; verify_case(3, Arg3, minCost(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"1309328",
 "DS2389U",
 "92EJFAN",
 "928FJNS",
 "FJS0DJF",
 "9FWJW0E",
 "23JFNFS"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YYNYYNY"; int Arg2 = 4; int Arg3 = 0; verify_case(4, Arg3, minCost(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arr0[] = {"01","20"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YN"; int Arg2 = 2; int Arg3 = 1; verify_case(5, Arg3, minCost(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    PowerPlants ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
