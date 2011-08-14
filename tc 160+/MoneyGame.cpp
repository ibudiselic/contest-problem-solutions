#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<int> V;
bool done[11][11][11][11][11][11];
int dp[11][11][11][11][11][11];
int go(vector<int> &, vector<int> &, vector<int> &);
int doit(vector<int> &p1, vector<int> &p2, vector<int> &pot, int valLeft, int start) {
	if (start == 3)
		return -go(p2, p1, pot);

	int ret = doit(p1, p2, pot, valLeft, start+1);
	for (int i=1; valLeft>=i*V[start] && i<=pot[start]; ++i) {
		p1[start] += i;
		pot[start] -= i;
		ret = max(ret, doit(p1, p2, pot, valLeft-i*V[start], start+1));
		pot[start] += i;
		p1[start] -= i;
	}

	return ret;
}
bool endCond(const vector<int> &coins) {
	return coins[0]+coins[1]+coins[2] == 0;
}
int go(vector<int> &p1, vector<int> &p2, vector<int> &pot) {
		int &ret = dp[p1[0]][p1[1]][p1[2]][p2[0]][p2[1]][p2[2]];

		bool &retDone = done[p1[0]][p1[1]][p1[2]][p2[0]][p2[1]][p2[2]];
		if (retDone)
			return ret;

		retDone = 1;
		if (endCond(p1))
			return ret = -(p2[0]*V[0]+p2[1]*V[1]+p2[2]*V[2]);

		ret = -1234567890;

		for (int i=0; i<3; ++i)
			if (p1[i] > 0) {
				--p1[i];
				++pot[i];
				ret = max(ret, doit(p1, p2, pot, V[i]-1, 0));
				--pot[i];
				++p1[i];
			}

		return ret;
	}
class MoneyGame {
	public:
	int play(vector <int> lennysCoins, vector <int> fredsCoins, vector <int> values) {
		V = values;

		memset(done, 0, sizeof done);

		vector<int> pot(3, 0);
		return go(lennysCoins, fredsCoins, pot);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {20,10,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -2; verify_case(0, Arg3, play(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {0,1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {20,10,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(1, Arg3, play(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {1,1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,5,10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(2, Arg3, play(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {4,4,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4,3,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {100,753,100}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 600; verify_case(3, Arg3, play(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5,5,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1000,1000,1000}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -15000; verify_case(4, Arg3, play(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arr0[] = {3,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {6,8,14}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 42; verify_case(5, Arg3, play(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    MoneyGame ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
