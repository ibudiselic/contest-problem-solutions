#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>
#include <iterator>

using namespace std;

class MissingLetters {
	public:
	string getMissingLetters(string sentence) {
		bool a[26] = {0};
		for (string::const_iterator i=sentence.begin(); i!=sentence.end(); ++i)
			if (isalpha(*i))
				a[toupper(*i)-'A'] = 1;

		string sol;
		for (int i=0; i<26; ++i)
			if (!a[i])
				sol += 'A'+i;

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "A quick brown fox jumps over the lazy dog"; string Arg1 = ""; verify_case(0, Arg1, getMissingLetters(Arg0)); }
	void test_case_1() { string Arg0 = "A slow yellow fox crawls under the proactive dog"; string Arg1 = "BJKMQZ"; verify_case(1, Arg1, getMissingLetters(Arg0)); }
	void test_case_2() { string Arg0 = "Lions, and tigers, and bears, oh my!"; string Arg1 = "CFJKPQUVWXZ"; verify_case(2, Arg1, getMissingLetters(Arg0)); }
	void test_case_3() { string Arg0 = ""; string Arg1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; verify_case(3, Arg1, getMissingLetters(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    MissingLetters ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
