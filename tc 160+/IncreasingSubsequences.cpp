#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

long long cnt[50];
bool okBetween(int l, int r, const vector<int> &a) {
	for (int i=l+1; i<r; ++i)
		if (a[l]<a[i] && a[i]<a[r])
			return false;
	return true;
}
bool okAfter(int l, const vector<int> &a) {
	for (int i=l+1; i<(int)a.size(); ++i)
		if (a[i] > a[l])
			return false;
	return true;
}
class IncreasingSubsequences {
	public:
	long long count(vector <int> a) {
		int n = a.size();

		cnt[0] = 1;
		for (int i=1; i<n; ++i) {
			cnt[i] = 0;
			for (int j=0; j<i; ++j)
				if (a[i]>a[j] && okBetween(j, i, a))
					cnt[i] += cnt[j];
			cnt[i] = max(cnt[i], 1LL);
		}

		long long sol = 0;
		for (int i=0; i<n; ++i)
			if (okAfter(i, a))
				sol += cnt[i];

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,3,2,6,4,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 4LL; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { int Arr0[] = {1000000000,100000000,10000000,1000000,100000,10000,1000,100,10,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 10LL; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { int Arr0[] = {1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 1LL; verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { int Arr0[] = {564,234,34,4365,424,2234,306,21,934,592,195,2395,2396,29345,13295423,23945,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 41LL; verify_case(3, Arg1, count(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    IncreasingSubsequences ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
