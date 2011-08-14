#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <numeric>

using namespace std;

int dp[2500][51][2];
string S;
int R, W;

int go(int d, int cnt, bool cntWrong) {
	if (d == (int)S.size())
		return 0;

	int &ret = dp[d][cnt][cntWrong];
	if (ret != -1)
		return ret;

	ret = 0;
	if (cntWrong && cnt<W)
		ret = max(ret, go(d+1, cnt+1, true) + (S[d]=='B'));
	if (!cntWrong && cnt<R)
		ret = max(ret, go(d+1, cnt+1, false) + (S[d]=='G'));

	if (cntWrong)
		ret = max(ret, go(d+1, 1, false) + (S[d]=='G'));
	else
		ret = max(ret, go(d+1, 1, true) + (S[d]=='B'));

	return ret;
}

class Horoscope {
	public:
	int maxGoodDays(vector <string> predictions, int R_, int W_) {
		S = accumulate(predictions.begin(), predictions.end(), string());
		R = R_;
		W = W_;
		memset(dp, 0xff, sizeof dp);

		return go(0, 0, 0);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"GGGG"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 1; int Arg3 = 4; verify_case(0, Arg3, maxGoodDays(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"GGGG"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 2; int Arg3 = 3; verify_case(1, Arg3, maxGoodDays(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"GBGBBB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 4; int Arg3 = 6; verify_case(2, Arg3, maxGoodDays(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"GGGBBBGBGGGB", "GGBBBBBBBBBGBGBGBGBGBGBGBGBBBBBBBBBBBBBBGGGG", "G"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 35; int Arg3 = 56; verify_case(3, Arg3, maxGoodDays(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Horoscope ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
