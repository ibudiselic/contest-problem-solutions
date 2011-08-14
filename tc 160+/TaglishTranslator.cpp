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

enum { PRES, FUT, PAST };
bool wCmp(const string &a, const string &b) {
	if (a.size() != b.size())
		return false;
	for (int i=0; i<(int)a.size(); ++i)
		if (tolower(a[i]) != tolower(b[i]))
			return false;

	return true;
}
bool endsWith(const string &a, const string &b) {
	if (a.size() < b.size())
		return false;

	for (int i=0; i<(int)b.size(); ++i)
		if (tolower(a[a.size()-1-i]) != tolower(b[b.size()-1-i]))
			return false;

	return true;
}
const string vowel("aeiouAEIOU");
string doubleSyl(const string &w) {
	for (int i=0; i<(int)w.size(); ++i)
		if (vowel.find(w[i])!=string::npos)
			return w.substr(0, i+1) + w.substr(0, i+1) + (i<(int)w.size()-1 ? w.substr(i+1):"");
	assert(0);
}
class TaglishTranslator {
	public:
	string translate(string sentence) {
		vector<string> subject;
		istringstream is(sentence);
		string w;
		is >> w;

		if (wCmp(w, "the")) {
			subject.push_back(w);
			is >> w;
		}
		subject.push_back(w);

		int tense = PRES;
		vector<string> verb;
		is >> w;
		if (wCmp(w, "will")) {
			tense = FUT;
			verb.push_back(w);
			is >> w;
		}
		verb.push_back(w);
		if (tense==PRES && endsWith(w, "ed"))
			tense = PAST;

		vector<string> object;
		if (is >> w) {
			if (wCmp(w, "to")) {
				object.push_back(w);
				is >> w;
			}
			if (wCmp(w, "the")) {
				object.push_back(w);
				is >> w;
			}
			object.push_back(w);
		}

		/*cerr << sentence << '\n';
		cerr << subject.size() << '\n';
		for (int i=0; i<(int)subject.size(); ++i)
			cerr << subject[i] << ' ';
		cerr << '\n';
		cerr << verb.size() << '\n';
		cerr << tense << '\n';
		for (int i=0; i<(int)verb.size(); ++i)
			cerr << verb[i] << ' ';
		cerr << '\n';
		cerr << object.size() << '\n';
		for (int i=0; i<(int)object.size(); ++i)
			cerr << object[i] << ' ';
		cerr << '\n';*/

		string sol;
		/*Past Tense - Put "nag" at the beginning of the word, and remove the "ed" from the end of it.
		Present Tense - Double the first syllable and put "nag" at the beginning of the word.
		Future Tense - Double the first syllable and put "mag" at the beginning of the word, and remove the word "will" from before the verb.*/
		/*In the present and future tense, the "first syllable" is defined as any consonants at the beginning of the word followed by exactly one vowel
		(where a vowel is a upper- or lower-case a, e, i, o, or u and a consonant is any other letter).*/

		if (tense == PAST) {
			assert(verb.size() == 1);
			assert(endsWith(verb[0], "ed"));
			sol += "nag" + verb[0].substr(0, verb[0].size()-2) + " ";
		} else if (tense == PRES) {
			assert(verb.size() == 1);
			sol += "nag" + doubleSyl(verb[0]) + " ";
		} else if (tense == FUT) {
			assert(verb.size() == 2);
			assert(wCmp(verb[0], "will"));
			sol += "mag" + doubleSyl(verb[1]) + " ";
		}

		/* If the <subject> in the English sentence is a thing, omit the word "the" in the Taglish sentance and prepend the Tagalog article,
		"ang" to the subject to form the Taglish subject. If the <subject> is a name, prepend the Tagalog article "si" to the English name.*/
		if (subject.size() == 2) {
			assert(wCmp(subject[0], "the"));
			sol += "ang " + subject[1];
		} else {
			assert(subject.size() == 1);
			sol += "si " + subject[0];
		}

		/*If the object is a thing and wasn't preceded by the word "to" in the English sentence, it is preceded by the word "ng" in the Taglish sentence (and the word "the" is dropped).
		If the object is a name and wasn't preceded by the word "to", it is preceded by the word "ni".
		If the object is a thing and was preceded by the word "to", it is preceded by the word "sa" (and the words "to" and "the" are dropped).
		If the object is a name and was preceded by the word "to", it is preceded by the word "kay" (and the word "to" is dropped).*/
		if (object.size()) {
			if (object.size()==2 && wCmp(object[0], "the")) {
				sol += " ng " + object[1];
			} else if (object.size() == 1) {
				sol += " ni " + object[0];
			} else if (object.size() == 3) {
				assert(wCmp(object[0], "to"));
				assert(wCmp(object[1], "the"));
				sol += " sa " + object[2];
			} else {
				assert(object.size() == 2);
				assert(wCmp(object[0], "to"));
				sol += " kay " + object[1];
			}
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "The fox jumps to the dog"; string Arg1 = "nagjujumps ang fox sa dog"; verify_case(0, Arg1, translate(Arg0)); }
	void test_case_1() { string Arg0 = "tomek codes"; string Arg1 = "nagcocodes si tomek"; verify_case(1, Arg1, translate(Arg0)); }
	void test_case_2() { string Arg0 = "tHe mAn plAyEd ThE pIAnO"; string Arg1 = "nagplAy ang mAn ng pIAnO"; verify_case(2, Arg1, translate(Arg0)); }
	void test_case_3() { string Arg0 = "Bob will Filed the taxes"; string Arg1 = "magFiFiled si Bob ng taxes"; verify_case(3, Arg1, translate(Arg0)); }
	void test_case_4() { string Arg0 = "Matthew walked to Mathew"; string Arg1 = "nagwalk si Matthew kay Mathew"; verify_case(4, Arg1, translate(Arg0)); }
	void test_case_5() { string Arg0 = "StrongBad kicked TheCheat"; string Arg1 = "nagkick si StrongBad ni TheCheat"; verify_case(5, Arg1, translate(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    TaglishTranslator ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
