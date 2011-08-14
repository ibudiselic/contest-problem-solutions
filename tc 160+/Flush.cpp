#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

long long dp[14][14];
long long choose(int n, int k) {
	if (k > n)
		return 0;
	if (n == 0)
		return 1;
	if (k == 0)
		return 1;
	if (dp[n][k] != -1)
		return dp[n][k];
	return dp[n][k] = choose(n-1, k-1) + choose(n-1, k);
}
long long val;
long long cnt;
vector<int> S;
void go(int pos, int left, int curVal, long long curCnt) {
	if (pos == 4) {
		if (left == 0) {
			val += curVal*curCnt;
			cnt += curCnt;
		}
		return;
	}
	for (int i=0; i<=S[pos] && i<=left; ++i)
		go(pos+1, left-i, max(curVal, i), curCnt*choose(S[pos], i));
}
class Flush {
	public:
	double size(vector <int> suits, int number) {
		memset(dp, 0xff, sizeof dp);

		val = 0;
		cnt = 0;
		S = suits;
		go(0, number, 0, 1);

		return double(val)/cnt;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2,2,2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; double Arg2 = 1.1428571428571428; verify_case(0, Arg2, size(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,4,7,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 22; double Arg2 = 10.0; verify_case(1, Arg2, size(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {13, 13, 13, 13}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 49; double Arg2 = 13.0; verify_case(2, Arg2, size(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {13, 13, 13, 13}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 26; double Arg2 = 8.351195960938014; verify_case(3, Arg2, size(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {13,13,13,13}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; double Arg2 = 0.0; verify_case(4, Arg2, size(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Flush ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
