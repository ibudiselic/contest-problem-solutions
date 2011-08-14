#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

/*
3 of a kind - 3 or more dice the same, scores the face value of ALL the dice.
4 of a kind - 4 or more dice the same, scores the face value of ALL the dice.
full house - 3 dice equal to each other with the other 2 dice equal to each other as well. Scores 25 points.
small straight - Any 4 of the dice in consecutive order, scores 30 points.
large straight - All 5 dice in consecutive order, scores 40 points.
yahtzee - All 5 dice equal to each other, scores 50 points.
chance - No requirements, scores the face value of ALL the dice.
*/

int sum(const string &s) {
	int ret = 0;
	for (int i=0; i<5; ++i)
		ret += (s[i]-'0');
	return ret;
}
void makeCnt(const string &s, vector<int> &cnt) {
	for (int i=0; i<5; ++i)
		++cnt[s[i]-'0'];
}
bool is3ok(const string &s) {
	vector<int> cnt(7, 0);
	makeCnt(s, cnt);
	for (int i=1; i<7; ++i)
		if (cnt[i] >= 3)
			return true;
	return false;
}
bool is4ok(const string &s) {
	vector<int> cnt(7, 0);
	makeCnt(s, cnt);
	for (int i=1; i<7; ++i)
		if (cnt[i] >= 4)
			return true;
	return false;
}
bool isFH(const string &s) {
	vector<int> cnt(7, 0);
	makeCnt(s, cnt);
	for (int i=1; i<7; ++i) {
		if (cnt[i] == 5)
			return true;
		for (int j=i+1; j<7; ++j)
			if (cnt[i]==3 && cnt[j]==2 || cnt[i]==2 && cnt[j]==3)
				return true;
	}
	return false;
}
bool isSS(const string &s) {
	vector<int> cnt(7, 0);
	makeCnt(s, cnt);
	for (int i=1; i+3<7; ++i)
		if (cnt[i]>0 && cnt[i+1]>0 && cnt[i+2]>0 && cnt[i+3]>0)
			return true;
	return false;
}
bool isLS(const string &s) {
	vector<int> cnt(7, 0);
	makeCnt(s, cnt);
	for (int i=1; i+4<7; ++i)
		if (cnt[i]>0 && cnt[i+1]>0 && cnt[i+2]>0 && cnt[i+3]>0 && cnt[i+4]>0)
			return true;
	return false;
}
bool isYahtzee(const string &s) {
	vector<int> cnt(7, 0);
	makeCnt(s, cnt);
	for (int i=1; i<7; ++i)
		if (cnt[i] == 5)
			return true;
	return false;
}
bool isChance(const string &s) {
	return true;
}
int val3ok(const string &s) {
	return is3ok(s) ? sum(s) : 0;
}
int val4ok(const string &s) {
	return is4ok(s) ? sum(s) : 0;
}
int valFH(const string &s) {
	return isFH(s) ? 25 : 0;
}
int valSS(const string &s) {
	return isSS(s) ? 30 : 0;
}
int valLS(const string &s) {
	return isLS(s) ? 40 : 0;
}
int valYahtzee(const string &s) {
	return isYahtzee(s) ? 50 : 0;
}
int valChance(const string &s) {
	return isChance(s) ? sum(s) : 0;
}

int (*F[])(const string &) = { val3ok, val4ok, valFH, valSS, valLS, valYahtzee, valChance };
vector<string> H;
int dp[7][1<<7];
int go(int pos, int mask) {
	if (pos == 7)
		return 0;
	if (dp[pos][mask] != -1)
		return dp[pos][mask];

	int ret = 0;
	for (int i=0; i<7; ++i)
		if ((mask & (1<<i)) == 0)
			ret = max(ret, F[i](H[pos]) + go(pos+1, mask | (1<<i)));

	return (dp[pos][mask] = ret);
}
class YahtzeeBestScore {
	public:
	int bestLowerScore(vector <string> hands) {
		H = hands;
		memset(dp, 0xff, sizeof dp);

		return go(0, 0);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = { "66666", "66666", "66655", "12345", "12345", "66666", "66666" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 235; verify_case(0, Arg1, bestLowerScore(Arg0)); }
	void test_case_1() { string Arr0[] = { "12345", "12345", "12345", "12345", "12345", "12345", "12345" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 85; verify_case(1, Arg1, bestLowerScore(Arg0)); }
	void test_case_2() { string Arr0[] = { "12121", "12344", "42365", "22222", "66666", "66666", "66666" }	; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 235; verify_case(2, Arg1, bestLowerScore(Arg0)); }
	void test_case_3() { string Arr0[] = { "13144", "32342", "66554", "12321", "65456", "45654", "33445" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 26; verify_case(3, Arg1, bestLowerScore(Arg0)); }
	void test_case_4() { string Arr0[] = { "11223", "11223", "11223", "11223", "11223", "11223", "11223" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(4, Arg1, bestLowerScore(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    YahtzeeBestScore ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
