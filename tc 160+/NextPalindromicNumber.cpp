#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool is_palin(const string &s) {
	for (int i=0; i<(int)s.size()/2; ++i)
		if (s[i] != s[s.size()-1-i])
			return false;
	return true;
}
string inc(string s, int x) {
	int i = x;
	do {
		s[i] = '0' + ((s[i]-'0')+1)%10;
		--i;
	} while (i>=0 && s[i+1]=='0');
	if (i==-1 && s[0]=='0') {
		s = '1' + s;
		++x;
	}
	for (int i=x+1; i<(int)s.size(); ++i)
		s[i] = '0';
	return s;
}
string make_palin(string s) {
	for (int i=0; i<(int)s.size()/2; ++i)
		s[s.size()-1-i] = s[i];

	return s;
}
string clr(string s, int x) {
	for (int i=x; i<(int)s.size(); ++i)
		s[i] = '0';
	return s;
}
string go(string s) {
	for (int i=(s.size()-1)/2; i>=0; --i) {
		if (s[i] == s[s.size()-1-i]) continue;
		if (s[i] > s[s.size()-1-i]) {
			s[s.size()-1-i] = s[i];
			s = clr(s, s.size()-1-i+1);
		} else {
			s = inc(s, (s.size()-1)/2);
			break;
		}
	}
	return make_palin(s);
}
class NextPalindromicNumber {
	public:
	string getNext(string n) {
		if (is_palin(n))
			n = inc(n, n.size()-1);

		return go(n);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "12345"; string Arg1 = "12421"; verify_case(0, Arg1, getNext(Arg0)); }
	void test_case_1() { string Arg0 = "858"; string Arg1 = "868"; verify_case(1, Arg1, getNext(Arg0)); }
	void test_case_2() { string Arg0 = "1999"; string Arg1 = "2002"; verify_case(2, Arg1, getNext(Arg0)); }
	void test_case_3() { string Arg0 = "1"; string Arg1 = "2"; verify_case(3, Arg1, getNext(Arg0)); }
	void test_case_4() { string Arg0 = "9999"; string Arg1 = "10001"; verify_case(4, Arg1, getNext(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    NextPalindromicNumber ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
