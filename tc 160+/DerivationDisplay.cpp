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
  S ::= T | bUa
  T ::= aTb | A | B
  U ::= aU | bU | a | b
  A ::= aA | a
  B ::= bB | b
*/
vector<string> sol;
string T;

#define MKSTR(s, i, str) ((i>0 ? s.substr(0, i) : "") + str + (i+1<(int)s.size() ? s.substr(i+1) : ""))

bool go(const string &s, int cnt) {
	if (s.size() > T.size())
		return false;
	if (cnt == 0) {
		if (s == T) {
			sol.push_back(T);
			return true;
		}
	} else {
		int i=0;
		while (islower(s[i]))
			++i;

		if (s.substr(0, i) != T.substr(0, i))
			return false;

		switch (s[i]) {
			case 'S':
				if (go(MKSTR(s, i, "T"), cnt)) {
					sol.push_back(s);
					return true;
				}
				if (go(MKSTR(s, i, "bUa"), cnt)) {
					sol.push_back(s);
					return true;
				}
				break;
			case 'T':
				if (go(MKSTR(s, i, "aTb"), cnt)) {
					sol.push_back(s);
					return true;
				}
				if (go(MKSTR(s, i, "A"), cnt)) {
					sol.push_back(s);
					return true;
				}
				if (go(MKSTR(s, i, "B"), cnt)) {
					sol.push_back(s);
					return true;
				}
				break;
			case 'U':
				if (go(MKSTR(s, i, "a"), cnt-1)) {
					sol.push_back(s);
					return true;
				}
				if (go(MKSTR(s, i, "b"), cnt-1)) {
					sol.push_back(s);
					return true;
				}
				if (go(MKSTR(s, i, "aU"), cnt)) {
					sol.push_back(s);
					return true;
				}
				if (go(MKSTR(s, i, "bU"), cnt)) {
					sol.push_back(s);
					return true;
				}
				break;
			case 'A':
				if (go(MKSTR(s, i, "a"), cnt-1)) {
					sol.push_back(s);
					return true;
				}
				if (go(MKSTR(s, i, "aA"), cnt)) {
					sol.push_back(s);
					return true;
				}
				break;
			case 'B':
				if (go(MKSTR(s, i, "b"), cnt-1)) {
					sol.push_back(s);
					return true;
				}
				if (go(MKSTR(s, i, "bB"), cnt)) {
					sol.push_back(s);
					return true;
				}
				break;
			default:
				assert(0);
		}
	}
	return false;
}
class DerivationDisplay {
	public:
	vector <string> getDerivation(string input) {
		T = input;
		sol.clear();
		go("S", 1);

		reverse(sol.begin(), sol.end());
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arg0 = "aaabb"; string Arr1[] = {"S", "T", "aTb", "aaTbb", "aaAbb", "aaabb" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getDerivation(Arg0)); }
	void test_case_1() { string Arg0 = "bbba"; string Arr1[] = {"S", "bUa", "bbUa", "bbba" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getDerivation(Arg0)); }
	void test_case_2() { string Arg0 = "baabba"; string Arr1[] = {"S", "bUa", "baUa", "baaUa", "baabUa", "baabba" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getDerivation(Arg0)); }
	void test_case_3() { string Arg0 = "a"; string Arr1[] = {"S", "T", "A", "a" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, getDerivation(Arg0)); }
	void test_case_4() { string Arg0 = "b"; string Arr1[] = {"S", "T", "B", "b" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, getDerivation(Arg0)); }
	void test_case_5() { string Arg0 = "aabbbbbbbb"; string Arr1[] = {"S", "T", "aTb", "aaTbb", "aaBbb", "aabBbb", "aabbBbb", "aabbbBbb", "aabbbbBbb", "aabbbbbBbb", "aabbbbbbbb" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, getDerivation(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    DerivationDisplay ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
