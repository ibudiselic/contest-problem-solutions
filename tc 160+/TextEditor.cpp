#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
template<class T> vector<T> tokenize(string s, const string &delim=" ") {
  vector<T> ret;
  string::size_type i=0;
  string::size_type len = delim.length();
  if (delim != " ")
    while ((i=s.find(delim)) != string::npos)
      s.replace(i, len, " ");

  istringstream is(s);
  T val;
  while (is >> val)
    ret.push_back(val);
  return ret;
}
class TextEditor {
	public:
	vector <string> twoColumn(vector <string> text, int width) {
		vector<string> t;
		for (int i=0; i<(int)text.size(); ++i) {
			vector<string> tt = tokenize<string>(text[i]);
			for (int j=0; j<(int)tt.size(); ++j)
				t.push_back(tt[j]);
		}
		int nlines = 0;
		int k = 0;
		for (nlines=0, k=0; k<(int)t.size(); ++nlines) {
			int cur = t[k++].size();
			while (k<(int)t.size() && cur+1+(int)t[k].size()<=width)
				cur += 1+t[k++].size();
		}

		vector<string> sol(nlines);
		k = 0;
		for (int line=0; line<nlines/2 + (nlines%2); ++line) {
			sol[line*2] = t[k++];
			while (k<(int)t.size() && (int)sol[line*2].size()+1+(int)t[k].size()<=width)
				sol[line*2] += ' '+t[k++];
		}
		for (int line=0; line<nlines/2; ++line) {
			sol[line*2+1] = t[k++];
			while (k<(int)t.size() && (int)sol[line*2+1].size()+1+(int)t[k].size()<=width)
				sol[line*2+1] += ' '+t[k++];
		}
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"The quick brown fox jumps over the lazy dog. "}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; string Arr2[] = { "The",  "over",  "quick",  "the",  "brown",  "lazy",  "fox",  "dog.",  "jumps" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, twoColumn(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"Such a preposterous use of !punctuation! !!!","Who would write ... something like this ???"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 17; string Arr2[] = { "Such a",  "write ...",  "preposterous use",  "something like",  "of !punctuation!",  "this ???",  "!!! Who would" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, twoColumn(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {" Forsaking monastic tradition,    twelve jovial",
"  friars gave up their vocation for a questionable",
"     existence on the flying trapeze.    "}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 25; string Arr2[] = { "Forsaking monastic",  "vocation for a",  "tradition, twelve jovial",  "questionable existence on",  "friars gave up their",  "the flying trapeze." }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, twoColumn(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {" "," "," "," "," "," "}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; string Arr2[] = { }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, twoColumn(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {" I WONDER by my troth, what thou,",
"and I Did, till we lovd? were we",
"not weand till then? But suckd on",
"countrey pleasures, childishly? Or",
"snorted we in the seaven sleepers",
"den? Twas so; But this, all",
"pleasures fancies bee. If ever any",
"beauty I did see, Which I desird,",
"and got, twas but a dreame of",
"thee. And now good morrow to our",
"waking soules, Which watch not one",
"another out of feare; For love, all",
"love of other sights controules,",
"And makes one little roome, an",
"every where. Let seadiscoverers to",
"new worlds have gone, Let Maps to",
"other, worlds on worlds have",
"showne, Let us possesse one world,",
"each hath one, and is one. My face",
"in thine eye, thine in mine",
"appeares, And true plaine hearts",
"doe in the faces rest, Where can we",
"finde two better hemispheares",
"Without sharpe North, without",
"declining West? What ever dyes, was",
"not mixt equally; If our two loves",
"be one, or, thou and I Love so",
"alike, that none doe slacken, none",
"can die.",
"John Donne"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 45; string Arr2[] = { "I WONDER by my troth, what thou, and I Did,",  "seadiscoverers to new worlds have gone, Let",  "till we lovd? were we not weand till then?",  "Maps to other, worlds on worlds have showne,",  "But suckd on countrey pleasures, childishly?",  "Let us possesse one world, each hath one, and",  "Or snorted we in the seaven sleepers den?",  "is one. My face in thine eye, thine in mine",  "Twas so; But this, all pleasures fancies bee.",  "appeares, And true plaine hearts doe in the",  "If ever any beauty I did see, Which I desird,",  "faces rest, Where can we finde two better",  "and got, twas but a dreame of thee. And now",  "hemispheares Without sharpe North, without",  "good morrow to our waking soules, Which watch",  "declining West? What ever dyes, was not mixt",  "not one another out of feare; For love, all",  "equally; If our two loves be one, or, thou",  "love of other sights controules, And makes",  "and I Love so alike, that none doe slacken,",  "one little roome, an every where. Let",  "none can die. John Donne" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, twoColumn(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    TextEditor ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
