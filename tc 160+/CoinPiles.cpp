#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<int> L, A;
int dp[50][50][50];
int go(int pos, int top, int rem) {
	if (rem < 0)
		return -1;
	if (top == (int)A.size())
		return pos;

	int &ret = dp[pos][top][rem];
	if (ret != -1)
		return ret;

	rem += L[top];
	ret = go(pos+1, top+1, rem-pos);

	for (int i=top+1; i<(int)A.size(); ++i) {
		rem += L[i]+1;
		ret = max(ret, go(pos+1, i+1, rem-pos));
	}

	return ret;
}
class CoinPiles {
	public:
	int organize(vector <int> sizes) {
		sort(sizes.begin(), sizes.end());
		L.clear();
		A.clear();
		L.push_back(0);
		A.push_back(sizes[0]);

		int last = 0;
		for (int i=1; i<(int)sizes.size(); ++i)
			if (sizes[i] != sizes[i-1]) {
				A.push_back(sizes[i]);
				L.push_back(i-last-1);
				last = i;
			}

		memset(dp, 0xff, sizeof dp);
		return go(0, 0, 0);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 2, 2, 2, 2, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, organize(Arg0)); }
	void test_case_1() { int Arr0[] = {1, 1, 2, 2, 2, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(1, Arg1, organize(Arg0)); }
	void test_case_2() { int Arr0[] = {1, 2, 2, 2, 3, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(2, Arg1, organize(Arg0)); }
	void test_case_3() { int Arr0[] = {701, 701, 646, 701, 559, 559, 646, 701, 646, 881}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(3, Arg1, organize(Arg0)); }
	void test_case_4() { int Arr0[] = {701, 701, 646, 701, 559, 559, 646, 701, 701, 881}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(4, Arg1, organize(Arg0)); }
	void test_case_5() { int Arr0[] = {60, 348, 60, 18, 60, 60, 400, 38, 211, 150, 348, 348,
 60, 400, 462, 60, 97, 400, 164}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(5, Arg1, organize(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    CoinPiles ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
