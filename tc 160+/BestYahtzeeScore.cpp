#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

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

int (*F[])(const string &) = { val4ok, valFH, valSS, valLS, valYahtzee };

int getScore(const string &s) {
	int best = 0;
	for (int i=0; i<5; ++i)
		best = max(best, F[i](s));
	return best;
}

string R;
int sol;
void go(int, int, string&);
void maskWith(int round, int next, string &s, int m, int pos) {
	if (pos == 5) {
		go(round+1, next, s);
		return;
	}
	if (m & (1<<pos)) {
		const char c = s[pos];
		s[pos] = R[next];
		maskWith(round, next+1, s, m, pos+1);
		s[pos] = c;
	} else {
		maskWith(round, next, s, m, pos+1);
	}
}
void go(int round, int next, string &s) {
	if (round == 3) {
		sol = max(sol, getScore(s));
		return;
	}

	for (int m=0; m<(1<<5); ++m)
		maskWith(round, next, s, m, 0);
}

class BestYahtzeeScore {
	public:
	int bestScore(string rolls) {
		R = rolls;

		sol = 0;
		string s = R.substr(0, 5);
		go(1, 5, s);

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "354621111111111"; int Arg1 = 50; verify_case(0, Arg1, bestScore(Arg0)); }
	void test_case_1() { string Arg0 = "666663213214444"; int Arg1 = 50; verify_case(1, Arg1, bestScore(Arg0)); }
	void test_case_2() { string Arg0 = "652353235164412"; int Arg1 = 40; verify_case(2, Arg1, bestScore(Arg0)); }
	void test_case_3() { string Arg0 = "265241155222313"; int Arg1 = 25; verify_case(3, Arg1, bestScore(Arg0)); }
	void test_case_4() { string Arg0 = "144165526421151"; int Arg1 = 0; verify_case(4, Arg1, bestScore(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    BestYahtzeeScore ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
