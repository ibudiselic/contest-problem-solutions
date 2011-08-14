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
Remove all punctuation symbols ('.', ',', '?' and '!').
Replace all uppercase letters with their lowercase equivalents.
Replace all occurrences of "and" with '&'.
Replace all occurrences of "ate" with '8'.
Replace all occurrences of "at" with '@'.
Replace all occurrences of "you" with 'U'.
*/
class SMSLanguage {
	public:
	string translate(string text) {
		string::size_type t;
		while ((t = text.find_first_of(".,?!")) != string::npos)
			text.erase(text.begin()+t);
		for (int i=0; i<(int)text.size(); ++i)
			text[i] = tolower(text[i]);

		while ((t = text.find("and")) != string::npos)
			text.replace(t, 3, "&");
		while ((t = text.find("ate")) != string::npos)
			text.replace(t, 3, "8");
		while ((t = text.find("at")) != string::npos)
			text.replace(t, 2, "@");
		while ((t = text.find("you")) != string::npos)
			text.replace(t, 3, "U");

		return text;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "I HATE rats, and you?"; string Arg1 = "i h8 r@s & U"; verify_case(0, Arg1, translate(Arg0)); }
	void test_case_1() { string Arg0 = "What is the weather like today?"; string Arg1 = "wh@ is the we@her like today"; verify_case(1, Arg1, translate(Arg0)); }
	void test_case_2() { string Arg0 = "It is not too late to.."; string Arg1 = "it is not too l8 to"; verify_case(2, Arg1, translate(Arg0)); }
	void test_case_3() { string Arg0 = "this text is already in sms language"; string Arg1 = "this text is already in sms language"; verify_case(3, Arg1, translate(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    SMSLanguage ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
