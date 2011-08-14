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

/*
  http://
    http://www.
    www.
The domain is a sequence of one or more characters, each of which is a letter (a character from 'a' to 'z' or from 'A' to 'Z'), a numeral ('0' to '9'), or a period (the character '.').
The suffix is one of the five following strings.

    .com
    .org
    .edu
    .info
    .tv
*/

string start[] = { "http://", "http://www.", "www." };
string end[] = { ".com", ".org", ".edu", ".info", ".tv" };
bool sw(const string &s, const string &t) {
	if (t.size() > s.size())
		return false;
	for (int i=0; i<(int)t.size(); ++i)
		if (s[i] != t[i])
			return false;
	return true;
}
bool ew(const string &s, const string &t) {
	if (t.size() > s.size())
		return false;

	for (int i=0; i<(int)t.size(); ++i)
		if (s[s.size()-1-i] != t[t.size()-1-i])
			return false;
	return true;
}
bool valid(const string &s) {
	if (s.size() <= 0)
		return false;

	for (int i=0; i<(int)s.size(); ++i)
		if (!isalpha(s[i]) && s[i]!='.' && !isdigit(s[i]))
			return false;

	return true;
}
bool is_link(const string &s) {
	assert(s.size() >= 8);

	for (int i=0; i<3; ++i)
		if (sw(s, start[i]))
			for (int j=0; j<5; ++j)
				if (ew(s, end[j]))
					if (valid(s.substr(start[i].size(), max(0, (int)s.size()-(int)start[i].size()-(int)end[j].size()))))
						return true;

	return false;
}
class UnLinker {
	public:
	string clean(string text) {
		string t = text;
		for (int len=(int)text.size(); len>=8; len = min(len-1, (int)text.size()))
			for (int i=0; i+len<=(int)text.size(); ++i)
				if (is_link(text.substr(i, len))) {
					text = text.substr(0, i) + "OMIT" + (i+len<(int)text.size() ? text.substr(i+len) : "");
					t = t.substr(0, i) + "    " + (i+len<(int)t.size() ? t.substr(i+len) : "");
				}

		int cnt = 1;
		for (int i=0; i+4<=(int)text.size(); ++i)
			if (text.substr(i, 4) == "OMIT" && t.substr(i, 4) != "OMIT") {
				text.insert(text.begin()+i+4, char('0'+cnt));
				++cnt;
				i += 4;
			}

		return text;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "espihttp://www.tv.org.superwww.cali.comaladocious"; string Arg1 = "espiOMIT1aladocious"; verify_case(0, Arg1, clean(Arg0)); }
	void test_case_1() { string Arg0 = "check www.foo.com 4 www.foo.com www.scoopz.com"; string Arg1 = "check OMIT1 4 OMIT2 OMIT3"; verify_case(1, Arg1, clean(Arg0)); }
	void test_case_2() { string Arg0 = "check www.foo.com 4 www.foo.comwww.scoopz.com"; string Arg1 = "check OMIT1 4 OMIT2"; verify_case(2, Arg1, clean(Arg0)); }
	void test_case_3() { string Arg0 = "check www.foo.com 4 www.foo.comhttp://scoopz.com"; string Arg1 = "check OMIT1 4 OMIT2OMIT3"; verify_case(3, Arg1, clean(Arg0)); }
	void test_case_4() { string Arg0 = "http://411.com goodz 4 www.733t.com, 2http://..com"; string Arg1 = "OMIT1 goodz 4 OMIT2, 2OMIT3"; verify_case(4, Arg1, clean(Arg0)); }
	void test_case_5() { string Arg0 = "http.//say.org,www.jeeves.x.info,www.comhttp://.tv"; string Arg1 = "http.//say.org,OMIT1,www.comhttp://.tv"; verify_case(5, Arg1, clean(Arg0)); }
	void test_case_6() { string Arg0 = "http://www.www.com/www"; string Arg1 = "OMIT1/www"; verify_case(6, Arg1, clean(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    UnLinker ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
