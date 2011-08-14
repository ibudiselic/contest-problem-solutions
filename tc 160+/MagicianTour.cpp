#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<string> adj;
vector<int> pop;
int comp[50];
int N;

int difference[50];
void go(int x, int &first, int &second) {
	first += pop[x];
	comp[x] = 0;
	for (int i=0; i<N; ++i)
		if (comp[i]==-1 && adj[x][i]=='1')
			go(i, second, first);
}

bool dp[50][1001];
bool done[50][1001];

bool canGet(int x, int amount) {
	if (x < 0)
		return amount==0;
	if (amount > 1000)
		return false;

	if (done[x][amount])
		return dp[x][amount];

	done[x][amount] = 1;
	return dp[x][amount] = canGet(x-1, amount+difference[x]) || canGet(x-1, abs(amount-difference[x]));
}
class MagicianTour {
	public:
	int bestDifference(vector <string> roads, vector <int> populations) {
		adj = roads;
		pop = populations;
		N = roads.size();

		memset(comp, 0xff, sizeof comp);
		int compCnt = 0;

		for (int i=0; i<N; ++i)
			if (comp[i] == -1) {
				int a = 0;
				int b = 0;
				go(i, a, b);
				difference[compCnt++] = abs(a-b);
			}

		memset(done, 0, sizeof done);
		for (int diff=0; diff<=1000; ++diff)
			if (canGet(compCnt-1, diff))
				return diff;

		return -1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"01","10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {15,20}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(0, Arg2, bestDifference(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"0100",
 "1000",
 "0001",
 "0010"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,4,2,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(1, Arg2, bestDifference(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"0010",
 "0001",
 "1000",
 "0100"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,2,2,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(2, Arg2, bestDifference(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"000",
 "000",
 "000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {6,7,15}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(3, Arg2, bestDifference(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"0000",
 "0010",
 "0101",
 "0010"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {8,10,15,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(4, Arg2, bestDifference(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"010",
 "101",
 "010"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5,1,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 9; verify_case(5, Arg2, bestDifference(Arg0, Arg1)); }
	void test_case_6() { string Arr0[] = {
"01000000000000000000000000000000000",
"10100000000000000000000000000000000",
"01010000000000000000000000000000000",
"00101000000000000000000000000000000",
"00010100000000000000000000000000000",
"00001010000000000000000000000000000",
"00000101000000000000000000000000000",
"00000010100000000000000000000000000",
"00000001010000000000000000000000000",
"00000000101000000000000000000000000",
"00000000010100000000000000000000000",
"00000000001010000000000000000000000",
"00000000000101000000000000000000000",
"00000000000010100000000000000000000",
"00000000000001010000000000000000000",
"00000000000000101000000000000000000",
"00000000000000010100000000000000000",
"00000000000000001010000000000000000",
"00000000000000000100000000000000000",
"00000000000000000000000000000000000",
"00000000000000000000010000000000000",
"00000000000000000000101000000000000",
"00000000000000000000010100000000000",
"00000000000000000000001010000000000",
"00000000000000000000000101000000000",
"00000000000000000000000010100000000",
"00000000000000000000000001010000000",
"00000000000000000000000000101000000",
"00000000000000000000000000010100000",
"00000000000000000000000000001010000",
"00000000000000000000000000000101000",
"00000000000000000000000000000010100",
"00000000000000000000000000000001010",
"00000000000000000000000000000000101",
"00000000000000000000000000000000010"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {8,15,12,9,12,6,4,6,16,1,15,3,18,15,14,8,6,6,12,13,14,15,17,15,3,8,7,8,3,19,12,9,14,19,9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 21; verify_case(6, Arg2, bestDifference(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    MagicianTour ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
