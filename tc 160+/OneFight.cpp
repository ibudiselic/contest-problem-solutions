#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<int> L, D;
int MD;
int N;
int dp[1<<10];
int totalDmg[1<<10];
void calcTotal(int pos, int mask, int dmg) {
	if (pos == N) {
		totalDmg[mask] = dmg;
		return;
	}

	calcTotal(pos+1, mask, dmg);
	calcTotal(pos+1, mask|(1<<pos), dmg+D[pos]);
}

int go(int alive) {
	if (alive == 0)
		return 0;
	if (dp[alive] != -1)
		return dp[alive];

	int ret = 1234567890;
	for (int i=0; i<N; ++i)
		if (alive & (1<<i)) {
			int nTurns = (L[i]+MD-1) / MD;
			ret = min(ret, nTurns*totalDmg[alive] + go(alive ^ (1<<i)));
		}

	return (dp[alive] = ret);
}

class OneFight {
	public:
	int monsterKilling(vector <int> life, vector <int> damage, int yourDamage) {
		L = life;
		D = damage;
		N = L.size();
		MD = yourDamage;

		memset(totalDmg, 0, sizeof totalDmg);
		calcTotal(0, 0, 0);

		memset(dp, 0xff, sizeof dp);
		return go((1<<N)-1) + 1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 21; verify_case(0, Arg3, monsterKilling(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {5,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 19; verify_case(1, Arg3, monsterKilling(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {5,5,5,5,5,5,5,5,5,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10,20,30,40,50,60,70,80,90,100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 100; int Arg3 = 2201; verify_case(2, Arg3, monsterKilling(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {6,34,21,79,31,5,8,23,9,100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,65,95,32,48,9,3,13,100,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; int Arg3 = 6554; verify_case(3, Arg3, monsterKilling(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    OneFight ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
