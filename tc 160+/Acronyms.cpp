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
The words in the sequence must all be within one sentence.
The sequence must not include the first word in a sentence.
At least two words in the sequence must begin with uppercase letters.
The first and last words in the sequence must begin with uppercase letters.
There may not be two adjacent words that do not begin with uppercase letters in the sequence.
*/
string upper(const string &s) {
	string ret;
	for (int i=0; i<(int)s.size(); ++i)
		if (isupper(s[i]))
			ret += s[i];

	return ret;
}
string rest(const string &s) {
	int i = s.size()-1;
	while (i>=0 && !isalpha(s[i]))
		--i;

	return s.substr(i+1);
}
string acronym(const vector<string> &w, int l, int r) {
	string ret;
	for (int i=l; i<=r; ++i)
		if (isupper(w[i][0])) {
			ret += upper(w[i]);
			if (i == r)
				ret += rest(w[i]);
		}
	return ret;
}
class Acronyms {
	public:
	string acronize(vector <string> document) {
		string s;
		for (int i=0; i<(int)document.size(); ++i)
			s += ' ' + document[i];

		s = s.substr(1);

		vector<string> w;
		vector<bool> isSentenceStart;

		int start = 0;
		bool hadSpace = false;
		bool ss = true;
		bool inWord = false;
		for (int i=0; i<(int)s.size(); ++i) {
			if (!inWord) {
				if (s[i] == ' ') {
					if (hadSpace)
						ss = true;
				} else {
					start = i;
					inWord = true;
				}
			} else {
				if (s[i] == ' ') {
					hadSpace = 1;
					w.push_back(s.substr(start, i-start));
					isSentenceStart.push_back(ss);
					ss = 0;
					inWord = false;
				}
			}
		}
		w.push_back(s.substr(start, s.size()-start));
		isSentenceStart.push_back(ss);

		string sol = w[0];
		start = 1;
		int end = 0;
		for (int i=1; i<(int)w.size(); ++i)
			if (isSentenceStart[i]) {
				if (end-start >= 1)
					sol += ' ' + acronym(w, start, end);
				else
					for (int j=start; j<=end; ++j)
						sol += ' ' + w[j];
				for (int j=end+1; j<i; ++j)
					sol += ' ' + w[j];
				start = i+1;
				end = i;
				sol += "  " + w[i];
			} else {
				if (isupper(w[i][0])) {
					if (end < start) {
						start = i;
					}
					end = i;
				} else {
					if (!isupper(w[i-1][0])) {
						if (end-start >= 1)
							sol += ' ' + acronym(w, start, end);
						else
							for (int j=start; j<=end; ++j)
								sol += ' ' + w[j];

						for (int j=end+1; j<=i; ++j)
							sol += ' ' + w[j];
						start = i+1;
						end = i;
					} else if (end < start) {
						sol += ' ' + w[i];
						start = i+1;
						end = i;
					}
				}
			}
		if (end-start >= 1) {
			sol += ' ' + acronym(w, start, end);
			for (int i=end+1; i<(int)w.size(); ++i)
				sol += ' ' + w[i];
		} else {
			for (int j=start; j<(int)w.size(); ++j)
				sol += ' ' + w[j];
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"We the people of the United States of America."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "We the people of the USA."; verify_case(0, Arg1, acronize(Arg0)); }
	void test_case_1() { string Arr0[] = {"Don't","worry.","Be","Happy!"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Don't worry. BH!"; verify_case(1, Arg1, acronize(Arg0)); }
	void test_case_2() { string Arr0[] = {"Entering contests at TopCoder, Inc.", "is a good way to develop your skills."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Entering contests at TCI. is a good way to develop your skills."; verify_case(2, Arg1, acronize(Arg0)); }
	void test_case_3() { string Arr0[] = {"Working at the United States Postal Service",
 "in the United States of America",
 "is a satisfying experience."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Working at the USPS in the USA is a satisfying experience."; verify_case(3, Arg1, acronize(Arg0)); }
	void test_case_4() { string Arr0[] = {"a A & a & a B"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "a A & a & a B"; verify_case(4, Arg1, acronize(Arg0)); }
	void test_case_5() { string Arr0[] = {"The First word can't be included.  In","A sequence, that is."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "The First word can't be included.  In A sequence, that is."; verify_case(5, Arg1, acronize(Arg0)); }
	void test_case_6() { string Arr0[] = {"A Test & Test & & TEst"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "A TT & & TEst"; verify_case(6, Arg1, acronize(Arg0)); }
	void test_case_7() { string Arr0[] = {"This is a TEST tEST Test. ", ".Go Test"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "This is a TESTT.  .Go Test"; verify_case(7, Arg1, acronize(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Acronyms ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
