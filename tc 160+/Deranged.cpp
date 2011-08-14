#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<int> a;
int n;
long long memo[1u<<15];

long long go(int x, unsigned used) {
	if (x == n)
		return 1;
	if (memo[used] >= 0)
		return memo[used];
	long long ret = 0;
	for (int i=0; i<n; ++i)
		if ((used & (1u<<i))==0 && a[x]!=a[i])
			ret += go(x+1, used | (1u<<i));
	return memo[used] = ret;
}
class Deranged {
	public:
	long long fact(int x) {
		if (x==0) return 1;
		else return x*fact(x-1);
	}
	long long numDerangements(vector <int> nums) {
		sort(nums.begin(), nums.end());
		n = nums.size();
		a = nums;
		memset(memo, 0xff, sizeof memo);

		long long t = go(0, 0);
		vector<int> app(15, 0);
		for (int i=0; i<(int)a.size(); ++i)
			++app[a[i]];
		for (int i=0; i<(int)a.size(); ++i) {
			t /= fact(app[a[i]]);
			app[a[i]] = 0;
		}
		return t;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,1,2,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 4LL; verify_case(0, Arg1, numDerangements(Arg0)); }
	void test_case_1() { int Arr0[] = {0,0,0,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 1LL; verify_case(1, Arg1, numDerangements(Arg0)); }
	void test_case_2() { int Arr0[] = {0,0,0,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 0LL; verify_case(2, Arg1, numDerangements(Arg0)); }
	void test_case_3() { int Arr0[] = {0,0,0,0,0,0,0,1,1,1,1,1,1,1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 14LL; verify_case(3, Arg1, numDerangements(Arg0)); }
	void test_case_4() { int Arr0[] = {0,5,4,2,3,6,6}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 640LL; verify_case(4, Arg1, numDerangements(Arg0)); }
	void test_case_5() { int Arr0[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 481066515734LL; verify_case(5, Arg1, numDerangements(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Deranged ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
