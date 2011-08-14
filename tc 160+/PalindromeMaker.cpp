#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int cnt[26];
class PalindromeMaker {
	public:
	string make(string s) {
		memset(cnt, 0, sizeof cnt);
		for (int i=0; i<(int)s.size(); ++i)
			++cnt[s[i]-'A'];

		int cntOdd = 0;
		for (int i=0; i<26; ++i)
			cntOdd += cnt[i]%2;

		if (cntOdd > 1)
			return "";

		string sol;
		for (int i=0; i<26; ++i)
			if (cnt[i]) {
				sol += string(cnt[i]/2, 'A'+i);
				cnt[i] -= cnt[i]/2 * 2;
			}

		string t;
		reverse_copy(sol.begin(), sol.end(), back_inserter(t));

		if (cntOdd == 0)
			return sol + t;

		for (int i=0; i<26; ++i)
			if (cnt[i])
				return sol + string(cnt[i], 'A'+i) + t;


		assert(0);
		return "";
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "AABB"; string Arg1 = "ABBA"; verify_case(0, Arg1, make(Arg0)); }
	void test_case_1() { string Arg0 = "AAABB"; string Arg1 = "ABABA"; verify_case(1, Arg1, make(Arg0)); }
	void test_case_2() { string Arg0 = "ABACABA"; string Arg1 = "AABCBAA"; verify_case(2, Arg1, make(Arg0)); }
	void test_case_3() { string Arg0 = "ABCD"; string Arg1 = ""; verify_case(3, Arg1, make(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    PalindromeMaker ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
