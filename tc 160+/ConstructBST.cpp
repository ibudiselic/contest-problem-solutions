#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <set>
#include <map>

using namespace std;

long long choose[26][26];
set<int> S;
map<int, long long> M;
map<int, int> cnt;

int get_cnt(int x) {
	if (!S.count(x))
		return 0;
	if (cnt[x] != 0)
		return cnt[x];

	return cnt[x] = 1 + get_cnt(2*x) + get_cnt(2*x + 1);
}
long long go(int x) {
	if (!S.count(x))
		return 1;
	if (M[x] != 0)
		return M[x];

	int n = get_cnt(x);
	const int l = get_cnt(2*x);

	return M[x] = go(2*x)*go(2*x + 1)*choose[n-1][l];
}
class ConstructBST {
	public:
	long long numInputs(vector <int> tree) {
		memset(choose, 0, sizeof choose);
		for (int i=0; i<26; ++i)
			choose[i][0] = 1;
		choose[1][1] = 1;
		for (int i=1; i<26; ++i)
			for (int j=1; j<26; ++j)
				choose[i][j] = choose[i-1][j-1] + choose[i-1][j];

		S = set<int>(tree.begin(), tree.end());
		cnt.clear();
		M.clear();

		return go(1);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 1LL; verify_case(0, Arg1, numInputs(Arg0)); }
	void test_case_1() { int Arr0[] = {1, 3, 6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 1LL; verify_case(1, Arg1, numInputs(Arg0)); }
	void test_case_2() { int Arr0[] = {1, 2, 5, 3, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 8LL; verify_case(2, Arg1, numInputs(Arg0)); }
	void test_case_3() { int Arr0[] = {1, 2, 4, 6, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 6LL; verify_case(3, Arg1, numInputs(Arg0)); }
	void test_case_4() { int Arr0[] = {2, 4, 3, 62, 7, 15, 1, 31, 5, 14, 28, 57, 56, 114}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 96096LL; verify_case(4, Arg1, numInputs(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ConstructBST ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
