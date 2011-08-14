#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

string N;
int dp[16][10][3][2][2];
int go(int pos, int last, int cnt, bool isFinal, bool any) {
	if (!isFinal && pos+1==(int)N.size())
		return 1;
	if (pos == (int)N.size())
		return 1;

	if (dp[pos][last][cnt][isFinal][any] != -1)
		return dp[pos][last][cnt][isFinal][any];

	int &ret = dp[pos][last][cnt][isFinal][any];
	ret = !isFinal;
	for (int d=(pos==0); d<10; ++d) {
		if (isFinal && !any && d>N[pos]-'0')
			break;
		if (isFinal && (d!=last || cnt+1<3))
			ret += go(pos+1, d, (d==last ? cnt+1 : 1), true, any || (d<N[pos]-'0'));
		if (!isFinal && (d!=last || cnt+1<3))
			ret += go(pos+1, d, (d==last ? cnt+1 : 1), false, true);
	}

	return ret;
}
bool isGood(const string &s) {
	for (int i=0; i+3<=(int)s.size(); ++i)
		if (s[i+1]==s[i] && s[i+2]==s[i+1])
			return false;
	return true;
}
class PluCodeGenerator {
	public:
	int countInvalidCodes(int n) {
		{
			ostringstream os;
			os << n;
			N = os.str();
		}
		if (N.size() < 3)
			return 0;

		memset(dp, 0xff, sizeof dp);

		return n+isGood(N) - (go(0, 0, 0, false, true) + go(0, 0, 0, true, false));
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 111; int Arg1 = 0; verify_case(0, Arg1, countInvalidCodes(Arg0)); }
	void test_case_1() { int Arg0 = 556; int Arg1 = 5; verify_case(1, Arg1, countInvalidCodes(Arg0)); }
	void test_case_2() { int Arg0 = 1113; int Arg1 = 13; verify_case(2, Arg1, countInvalidCodes(Arg0)); }
	void test_case_3() { int Arg0 = 7346556; int Arg1 = 323647; verify_case(3, Arg1, countInvalidCodes(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    PluCodeGenerator ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
