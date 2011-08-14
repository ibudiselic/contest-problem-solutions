#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

long long fact[21];
int cnt[21];
string alph;

bool ok;

long long calc() {
	long long nom_cnt = 0, denom = 1;

	for (int i=0; i<(int)alph.size(); ++i) {
		nom_cnt += cnt[i];
		denom *= fact[cnt[i]];
	}

	return fact[nom_cnt]/denom;
}
string go(int pos, long long n) {
	if (pos == 1) {
		ok = (n==1);
		for (int i=0; i<(int)alph.size(); ++i)
			if (cnt[i] > 0)
				return string(1, alph[i]);
	}
	for (int i=0; i<(int)alph.size(); ++i) {
		if (cnt[i] > 0) {
			--cnt[i];
			long long val = calc();
			if (val < n) {
				n -= val;
				++cnt[i];
				continue;
			} else { // val >= n
				return string(1, alph[i]) + go(pos-1, n);
			}
		}
	}
	ok = false;
	return "";
}
class AnagramList {
	public:
	string getAnagram(string s, int n) {
		alph.clear();
		sort(s.begin(), s.end());
		unique_copy(s.begin(), s.end(), back_inserter(alph));

		fact[0] = fact[1] = 1;
		for (int x=2; x<=(int)s.size(); ++x)
			fact[x] = fact[x-1]*x;

		for (int i=0; i<(int)alph.size(); ++i)
			cnt[i] = count(s.begin(), s.end(), alph[i]);

		ok = false;
		const string sol = go(s.size(), n+1);

		return ok ? sol : "";
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "tree"; int Arg1 = 1; string Arg2 = "eetr"; verify_case(0, Arg2, getAnagram(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "tree"; int Arg1 = 6; string Arg2 = "reet"; verify_case(1, Arg2, getAnagram(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "tree"; int Arg1 = 12; string Arg2 = ""; verify_case(2, Arg2, getAnagram(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "abcabfebda"; int Arg1 = 5000; string Arg2 = "aadfcabbbe"; verify_case(3, Arg2, getAnagram(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "sdoijgfasdkhaiw"; int Arg1 = 2000000000; string Arg2 = "adsdghwiiokfjas"; verify_case(4, Arg2, getAnagram(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    AnagramList ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
