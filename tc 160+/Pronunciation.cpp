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

string vowels = "aeiouAEIOU";
bool isVowel(char c) {
	return vowels.find(c) != string::npos;
}
bool isConsonant(char c) {
	return !isVowel(c);
}
bool twoDiffVowels(const string &s) {
	for (int i=1; i<(int)s.size(); ++i)
		if (tolower(s[i])!=tolower(s[i-1]) && isVowel(s[i]) && isVowel(s[i-1]))
			return true;
	return false;
}
bool threeConsonants(const string &s) {
	for (int i=2; i<(int)s.size(); ++i)
		if (isConsonant(s[i]) && isConsonant(s[i-1]) && isConsonant(s[i-2]))
			return true;
	return false;
}
bool invalid(const string &s) {
	return twoDiffVowels(s) || threeConsonants(s);
}
class Pronunciation {
	public:
	string canPronounce(vector <string> words) {
		for (int i=0; i<(int)words.size(); ++i)
			if (invalid(words[i]))
				return words[i];

		return string();
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"All","of","these","are","not","difficult"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = ""; verify_case(0, Arg1, canPronounce(Arg0)); }
	void test_case_1() { string Arr0[] = {"The","word","REALLY","is","really","hard"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "REALLY"; verify_case(1, Arg1, canPronounce(Arg0)); }
	void test_case_2() { string Arr0[] = {"TRiCKy"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "TRiCKy"; verify_case(2, Arg1, canPronounce(Arg0)); }
	void test_case_3() { string Arr0[] = {"irresistable","prerogative","uttermost","importance"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = ""; verify_case(3, Arg1, canPronounce(Arg0)); }
	void test_case_4() { string Arr0[] = {"Aa"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = ""; verify_case(4, Arg1, canPronounce(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Pronunciation ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
