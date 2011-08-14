#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <functional>
using namespace std;

vector<int> C;
string dp[51][10];

string go(int n, int d) {
	if (d<=0 || n==0) return "";
	if (dp[n][d] != "-")
		return dp[n][d];
	if (C[d] > n)
		return go(n, d-1);

	string cur;
	string best = go(n, d-1);
	int x = n;
	while (n > 0) {
		string t;
		if (C[d] > n) {
			t = cur+go(n, d-1);
		} else {
			cur += char(d+'0');
			t = cur+go(n-C[d], d-1);
		}
		if (t.size()>best.size() || t.size()==best.size() && t > best)
			best = t;
		n -= C[d];
		if (n > 0) {
			t = cur + string(n/C[0], '0');
			if (t.size()>best.size() || t.size()==best.size() && t > best)
				best = t;
		}
	}
	return dp[x][d] = best;
}
class MatchNumbersEasy {
	public:
	string maxNumber(vector <int> matches, int n) {
		C = matches;
		for (int i=0; i<51; ++i)
			for (int j=0; j<10; ++j)
				dp[i][j] = "-";

		string sol = go(n, C.size()-1);
		return (sol=="" ? "0":sol);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {6,7,8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 21; string Arg2 = "210"; verify_case(0, Arg2, maxNumber(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {5,23,24}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 30; string Arg2 = "20"; verify_case(1, Arg2, maxNumber(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1,5,3,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; string Arg2 = "0"; verify_case(2, Arg2, maxNumber(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1,1,1,1,1,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 50; string Arg2 = "99999999999999999999999999999999999999999999999999"; verify_case(3, Arg2, maxNumber(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    MatchNumbersEasy ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
