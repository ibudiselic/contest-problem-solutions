#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int cnt[20];
string chars = "abcdefghijklmnopqrstuvwxyz";
int tree_cnt(int n) {
	if (n == 0)
		return 1;
	if (cnt[n] != -1)
		return cnt[n];

	int ret = 0;
	for (int i=0; i<n; ++i)
		ret += tree_cnt(i) * tree_cnt(n-1-i);

	return (cnt[n] = ret);
}
string go(int start, int n, int index) {
	for (int i=0; i<n; ++i) {
		int t = tree_cnt(i) * tree_cnt(n-1-i);
		if (index >= t) {
			index -= t;
		} else {
			t = tree_cnt(n-1-i);
			return chars[start+i] + go(start, i, index/t) + go(start+1+i, n-1-i, index%t);
		}
	}
	return "";
}
class EncodingTrees {
	public:
	string getCode(int N, int index) {
		memset(cnt, 0xff, sizeof cnt);

		if (tree_cnt(N) < index)
			return "";

		return go(0, N, index-1);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 1; string Arg2 = "ab"; verify_case(0, Arg2, getCode(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; string Arg2 = "ba"; verify_case(1, Arg2, getCode(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 3; string Arg2 = ""; verify_case(2, Arg2, getCode(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 9; string Arg2 = "cbad"; verify_case(3, Arg2, getCode(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 15; int Arg1 = 14023; string Arg2 = "abcdeohgfniljkm"; verify_case(4, Arg2, getCode(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    EncodingTrees ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
