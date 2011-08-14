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

double sqr(double x) { return x*x; }
class LanguageRecognition {
	public:
	int whichLanguage(vector <string> languages, string text) {
		vector<double> textFreq(26, 0);
		int cntChar = 0;
		for (int i=0; i<(int)text.size(); ++i)
			if (isalpha(text[i])) {
				++cntChar;
				textFreq[toupper(text[i])-'A'] += 1;
			}
		for (int i=0; i<26; ++i)
			textFreq[i] /= cntChar;

		double bestDist = 1e32;
		int best = -1;
		for (int i=0; i<(int)languages.size(); ++i) {
			vector<double> langFreq(26, 0);
			int cnt = 0;
			for (int j=0; j<(int)languages[i].size(); ++j)
			if (isalpha(languages[i][j])) {
				++cnt;
				langFreq[toupper(languages[i][j])-'A'] += 1;
			}
			double dist = 0.0;
			for (int j=0; j<26; ++j) {
				langFreq[j] /= cnt;
				dist += sqr(textFreq[j]-langFreq[j]);
			}

			if (dist < bestDist-1e-9) {
				bestDist = dist;
				best = i;
			}
		}

		return best;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"This is an English sentence.",
 "Dieser ist ein Deutscher Satz.",
 "C'est une phrase Francaise.",
 "Dit is een Nederlandse zin."
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "In welke taal is deze zin geschreven?"; int Arg2 = 3; verify_case(0, Arg2, whichLanguage(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"aaaaa","bbbb","ccc","dd","e"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "xxx"; int Arg2 = 0; verify_case(1, Arg2, whichLanguage(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"AABB","AaBb","A? B!","ab!@#$%"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "ab"; int Arg2 = 0; verify_case(2, Arg2, whichLanguage(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    LanguageRecognition ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
