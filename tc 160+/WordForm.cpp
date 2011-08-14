#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

class WordForm {
	public:
	bool is_vowel(const string &s, int i) {
		if (s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || (i>0 && s[i]=='y' && !is_vowel(s, i-1)))
			return true;
		else return false;
	}
	string getSequence(string word) {
		string sol;

		for (int i=0; i<(int)word.size(); ++i)
			word[i] = tolower(word[i]);

		int i=0;
		while (i<(int)word.size()) {
			if (is_vowel(word, i)) {
				sol += 'V';
				while (i<(int)word.size() && is_vowel(word, i))
					++i;
			} else {
				sol += 'C';
				while (i<(int)word.size() && !is_vowel(word, i))
					++i;
			}
		}
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "WHEREABOUTS"; string Arg1 = "CVCVCVC"; verify_case(0, Arg1, getSequence(Arg0)); }
	void test_case_1() { string Arg0 = "yoghurt"; string Arg1 = "CVCVC"; verify_case(1, Arg1, getSequence(Arg0)); }
	void test_case_2() { string Arg0 = "YipPy"; string Arg1 = "CVCV"; verify_case(2, Arg1, getSequence(Arg0)); }
	void test_case_3() { string Arg0 = "AyYyEYye"; string Arg1 = "VCVCVCV"; verify_case(3, Arg1, getSequence(Arg0)); }
	void test_case_4() { string Arg0 = "yC"; string Arg1 = "C"; verify_case(4, Arg1, getSequence(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    WordForm ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
