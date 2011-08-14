#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int L[10], R[10];
int N;
int dp[1<<10][7][7][2][2];
int go(int mask, int l, int r, bool ld, bool rd, int sz) {
	int add = l + r + (sz>1)*ld*l + (sz>1)*rd*r;
	if (add%5 != 0)
		add = 0;

	if (mask == 0)
		return add;
	int &ret = dp[mask][l][r][ld][rd];
	if (ret != -1)
		return ret;

	ret = 0;
	for (int i=0; i<N; ++i)
		if (mask & (1<<i)) {
			if (L[i] == l)
				ret = max(ret, go(mask ^ (1<<i), R[i], r, (L[i]==R[i]), rd, sz+1));
			if (L[i] == r)
				ret = max(ret, go(mask ^ (1<<i), l, R[i], ld, (L[i]==R[i]), sz+1));
			if (R[i] == l)
				ret = max(ret, go(mask ^ (1<<i), L[i], r, (L[i]==R[i]), rd, sz+1));
			if (R[i] == r)
				ret = max(ret, go(mask ^ (1<<i), l, L[i], ld, (L[i]==R[i]), sz+1));
		}
	ret += add;
	return ret;
}
class DominoesGame {
	public:
	int largestTotal(vector <string> tiles) {
		N = tiles.size();
		for (int i=0; i<N; ++i)
			sscanf(tiles[i].c_str(), "%d:%d", &L[i], &R[i]);

		memset(dp, 0xff, sizeof dp);
		int sol = 0;
		for (int i=0; i<N; ++i)
			sol = max(sol, go(((1<<N)-1) ^ (1<<i), L[i], R[i], (L[i]==R[i]), (L[i]==R[i]), 1));

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"0:0","0:5","5:5"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 30; verify_case(0, Arg1, largestTotal(Arg0)); }
	void test_case_1() { string Arr0[] = {"5:3","3:4","4:4","4:6","6:6","6:5","5:5"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 70; verify_case(1, Arg1, largestTotal(Arg0)); }
	void test_case_2() { string Arr0[] = {"0:0","0:1","0:2","0:3","0:4","0:5","0:6","1:1","1:2","1:3"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 20; verify_case(2, Arg1, largestTotal(Arg0)); }
	void test_case_3() { string Arr0[] = {"0:0","1:1","2:2","3:3","4:4","5:5","6:6"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(3, Arg1, largestTotal(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    DominoesGame ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
