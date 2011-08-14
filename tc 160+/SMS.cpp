#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <cctype>

using namespace std;

string vowels = "aeiou";
bool isVowel(char c) {
	return vowels.find(tolower(c)) != string::npos;
}
bool g(const string &s, int l, int r) {
	for (int i=l; i<r; ++i)
		if (!isVowel(s[i]))
			return true;
	return false;
}
void f(string &s) {
	for (int i=1; i+1<(int)s.size(); ++i)
		if (isVowel(s[i]) && g(s, 0, i) && g(s, i+1, s.size())) {
			s.erase(s.begin()+i);
			--i;
		}
}

class SMS {
	public:
	string compress(string orig) {
		string s;
		string cur;
		bool inWord = false;
		orig += ' ';
		for (int i=0; i<(int)orig.size(); ++i)
			if (inWord) {
				if (orig[i] == ' ') {
					inWord = 0;
					f(cur);
					s += cur + ' ';
					cur = "";
				} else {
					cur += orig[i];
				}
			} else {
				if (orig[i] == ' ')
					s += ' ';
				else {
					inWord = 1;
					cur += orig[i];
				}
			}

		return s.substr(0, s.size()-1);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "Lets meet tomorrow"; string Arg1 = "Lts mt tmrrw"; verify_case(0, Arg1, compress(Arg0)); }
	void test_case_1() { string Arg0 = "Please come to my party"; string Arg1 = "Plse cme to my prty"; verify_case(1, Arg1, compress(Arg0)); }
	void test_case_2() { string Arg0 = " I  like your   style "; string Arg1 = " I  lke yr   style "; verify_case(2, Arg1, compress(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    SMS ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
