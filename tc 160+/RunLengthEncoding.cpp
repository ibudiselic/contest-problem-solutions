#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

class RunLengthEncoding {
	public:
	string decode(string text) {
		string sol;

		for (int i=0; i<(int)text.size(); ++i) {
			int cur = 0;
			if (isdigit(text[i])) {
				cur = text[i]-'0';
				while (cur<=50 && isdigit(text[++i]))
					cur = cur*10 + text[i]-'0';
				if (sol.size()+cur > 50)
					return "TOO LONG";
				sol += string(cur, text[i]);
			} else
				sol += text[i];
			if (sol.size()>50)
				return "TOO LONG";
		}
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "4A3BC2DE"; string Arg1 = "AAAABBBCDDE"; verify_case(0, Arg1, decode(Arg0)); }
	void test_case_1() { string Arg0 = "1A1B1C1D1E"; string Arg1 = "ABCDE"; verify_case(1, Arg1, decode(Arg0)); }
	void test_case_2() { string Arg0 = "1A3A5A4BCCCC"; string Arg1 = "AAAAAAAAABBBBCCCC"; verify_case(2, Arg1, decode(Arg0)); }
	void test_case_3() { string Arg0 = "50A"; string Arg1 = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"; verify_case(3, Arg1, decode(Arg0)); }
	void test_case_4() { string Arg0 = "21Z13S9A8M"; string Arg1 = "TOO LONG"; verify_case(4, Arg1, decode(Arg0)); }
	void test_case_5() { string Arg0 = "123456789012345678901234567890B"; string Arg1 = "TOO LONG"; verify_case(5, Arg1, decode(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    RunLengthEncoding ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
