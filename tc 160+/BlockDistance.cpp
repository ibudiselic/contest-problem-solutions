#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int dp[1000][1000][2]; // old, new, in_block
string O, N;
const int INF = 1000000;

int go(int o, int n, bool in_block) {
	if (o > n)
		return INF;
	if (o==-1 && n>=0)
		return !in_block;
	if (o+n == 0)
		return (O[0]==N[0] ? 0 : INF);

	if (dp[o][n][in_block] != -1)
		return dp[o][n][in_block];
	int ret = INF;
	ret = min(ret, (!in_block) + go(o, n-1, 1));

	if (O[o] == N[n])
		ret = min(ret, go(o-1, n-1, 0));

	return dp[o][n][in_block] = ret;
}


class BlockDistance {
	public:
	int minDist(vector <string> oldText, vector <string> newText) {
		memset(dp, 0xff, sizeof dp);
		O.clear();
		for (int i=0; i<(int)oldText.size(); ++i)
			O += oldText[i];
		N.clear();
		for (int i=0; i<(int)newText.size(); ++i)
			N += newText[i];

		const int sol = go(O.size()-1, N.size()-1, 0);
		return sol != INF ? sol : -1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"hello goodbye"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"hello, how are you? goodbye have a nice day"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(0, Arg2, minDist(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"aaaaa"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"ababababa"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(1, Arg2, minDist(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"aaaaaaaaaaaaaaaa"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"aaaaaaaaaaaaaaaa","t","aaaaaaaaaaaaaaaa"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(2, Arg2, minDist(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"no way"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"No way!"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(3, Arg2, minDist(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"abce","f","ij","klm","n","op","uvwx","z"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"ab","cdefg","hijklmnop","q","rs","tuv","wxyz"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(4, Arg2, minDist(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    BlockDistance ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
