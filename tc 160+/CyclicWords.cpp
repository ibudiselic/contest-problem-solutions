#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

void normalize(string &s) {
	string t = s;
	for (int i=0; i<(int)t.size(); ++i) {
		t = t.substr(1) + t[0];
		if (t < s)
			s = t;
	}
}
class CyclicWords {
	public:
	int differentCW(vector <string> words) {
		for (int i=0; i<(int)words.size(); ++i)
			normalize(words[i]);

		sort(words.begin(), words.end());
		return unique(words.begin(), words.end()) - words.begin();
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = { "picture", "turepic", "icturep", "word", "ordw" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, differentCW(Arg0)); }
	void test_case_1() { string Arr0[] = { "ast", "ats", "tas", "tsa", "sat", "sta", "ttt" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(1, Arg1, differentCW(Arg0)); }
	void test_case_2() { string Arr0[] = {"aaaa", "aaa", "aa", "aaaa", "aaaaa"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(2, Arg1, differentCW(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    CyclicWords ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
