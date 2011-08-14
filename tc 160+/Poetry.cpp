#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
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
bool is_vowel(char c) {
	return c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='-';
}
bool test(const string &s, char pre) {
	if (!is_vowel(s[0]))
		return false;
	int i=0;
	while (i<(int)s.size() && is_vowel(s[i]))
		++i;
	bool good = true;
	for (int j=i; j<(int)s.size(); ++j)
		if (is_vowel(s[j])) {
			good = false;
			break;
		}
	return good & (pre==0 || !is_vowel(pre));
}

class Poetry {
	public:
	string rhymeScheme(vector <string> poem) {
		for (int i=0; i<(int)poem.size(); ++i) {
			vector<string> t = tokenize<string>(poem[i]);
			if (t.size()==0) {
				poem[i] = "";
				continue;
			}
			for (int j=0; j<(int)t[t.size()-1].size(); ++j)
				t[t.size()-1][j] = tolower(t[t.size()-1][j]);
			poem[i] = t[t.size()-1];
		}
		for (int i=0; i<(int)poem.size(); ++i) {
			if (poem[i].size()==0) continue;
			for (int j=1; j<(int)poem[i].size()-1; ++j)
				if (poem[i][j] == 'y')
					poem[i][j] = '-';
		}


		for (int i=0; i<(int)poem.size(); ++i) {
			if (poem[i].size()==0) continue;
			for (int j=0; j<(int)poem[i].size(); ++j)
				if (test(poem[i].substr(j), (j==0)?0:poem[i][j-1])) {
					poem[i] = poem[i].substr(j);
					break;
				}
		}

		for (int i=0; i<(int)poem.size(); ++i)
			for (int j=0; j<(int)poem[i].size(); ++j)
				if (poem[i][j] == '-')
					poem[i][j] = 'y';
		string sol(poem.size(), ' ');
		int cur = 0;
		for (;;) {
			int i=0;
			for (i=0; i<(int)poem.size() && (poem[i].size()==0 || sol[i]!=' '); ++i)
				continue;

			if (i==(int)poem.size())
				break;

			sol[i] = charset[cur];
			for (int j=i+1; j<(int)poem.size(); ++j)
				if (poem[j].size()!=0 && sol[j]==' ' && poem[i]==poem[j])
					sol[j] = charset[cur];

			++cur;
		}
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"I hope this problem",
 "is a whole lot better than",
 "this stupid haiku"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "abc"; verify_case(0, Arg1, rhymeScheme(Arg0)); }
	void test_case_1() { string Arr0[] = {"     ",
 "Measure your height",
 "AND WEIGHT      ",
 "said the doctor",
 "",
 "And make sure to take your pills",
 "   to   cure   your    ills",
 "Every",
 "DAY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = " aab ccde"; verify_case(1, Arg1, rhymeScheme(Arg0)); }
	void test_case_2() { string Arr0[] = {"One bright day in the middle of the night",
 "Two dead boys got up to fight",
 "Back to back they faced each other",
 "Drew their swords and shot each other",
 "",
 "A deaf policeman heard the noise",
 "And came to arrest the two dead boys",
 "And if you dont believe this lie is true",
 "Ask the blind man he saw it too"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "aabb cdef"; verify_case(2, Arg1, rhymeScheme(Arg0)); }
	void test_case_3() { string Arr0[] = {"",
 "",
 "",
 ""}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "    "; verify_case(3, Arg1, rhymeScheme(Arg0)); }
	void test_case_4() { string Arr0[] = {"This poem has uppercase letters",
 "In its rhyme scheme",
 "Alpha", "Blaster", "Cat", "Desert", "Elephant", "Frog", "Gulch",
 "Horse", "Ireland", "Jam", "Krispy Kreme", "Loofah", "Moo", "Narf",
 "Old", "Pink", "Quash", "Rainbow", "Star", "Tour", "Uvula", "Very",
 "Will", "Xmas", "Young", "Zed", "deception", "comic", "grout",
 "oval", "cable", "rob", "steal", "steel", "weak"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "abcdefghibjkblmnopqrstcuvwxyzABCbDEFG"; verify_case(4, Arg1, rhymeScheme(Arg0)); }
	void test_case_5() { string Arr0[] = {" ",
 "     ",
 "This poem",
 "         ",
 " ",
 " ",
 "",
 "Has lots of blank lines",
 " ",
 "      ",
 "                                            ",
 "         ",
 " ",
 "              ",
 "                                                  ",
 "  in      it           "}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "  a    b       c"; verify_case(5, Arg1, rhymeScheme(Arg0)); }
	void test_case_6() { string Arr0[] = {"too bad   your",
 "     solution went   sour"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "aa"; verify_case(6, Arg1, rhymeScheme(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Poetry ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
