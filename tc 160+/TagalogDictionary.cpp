#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

string alph = "abkdeghilmn oprstuwy";
map<string, int> pos;

struct Wrap {
	Wrap(const string &s) {
		for (int i=0; i<(int)s.size(); ++i)
			if (s[i]!='n' || i==(int)s.size()-1 || s[i+1]!='g') {
				repr.push_back(string(1, s[i]));
			} else {
				++i;
				repr.push_back("ng");
			}
	}
	string str() {
		string ret;
		for (int i=0; i<(int)repr.size(); ++i)
			ret += repr[i];
		return ret;
	}
	vector<string> repr;
};
bool operator<(const Wrap &a, const Wrap &b) {
	int i = 0;

	while (i<(int)a.repr.size() && i<(int)b.repr.size()) {
		if (a.repr[i] != b.repr[i])
			return pos[a.repr[i]] < pos[b.repr[i]];
		++i;
	}
	return a.repr.size() < b.repr.size();
}
class TagalogDictionary {
	public:
	vector <string> sortWords(vector <string> words) {
		for (int i=0; i<(int)alph.size(); ++i)
			if (alph[i] != ' ')
				pos[string(1, alph[i])] = i;

		pos["ng"] = pos["n"] + 1;

		vector<Wrap> v;
		for (int i=0; i<(int)words.size(); ++i)
			v.push_back(Wrap(words[i]));

		sort(v.begin(), v.end());

		for (int i=0; i<(int)v.size(); ++i)
			words[i] = v[i].str();

		return words;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"abakada","alpabet","tagalog","ako"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"abakada", "ako", "alpabet", "tagalog" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, sortWords(Arg0)); }
	void test_case_1() { string Arr0[] = {"ang","ano","anim","alak","alam","alab"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"alab", "alak", "alam", "anim", "ano", "ang" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, sortWords(Arg0)); }
	void test_case_2() { string Arr0[] = {"siya","niya","kaniya","ikaw","ito","iyon"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"kaniya", "ikaw", "ito", "iyon", "niya", "siya" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, sortWords(Arg0)); }
	void test_case_3() { string Arr0[] = {"kaba","baka","naba","ngipin","nipin"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"baka", "kaba", "naba", "nipin", "ngipin" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, sortWords(Arg0)); }
	void test_case_4() { string Arr0[] = {"knilngiggnngginggn","ingkigningg","kingkong","dingdong","dindong","dingdont","ingkblot"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"kingkong", "knilngiggnngginggn", "dindong", "dingdont", "dingdong", "ingkblot", "ingkigningg" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, sortWords(Arg0)); }
	void test_case_5() { string Arr0[] = {"silangang", "baka", "bada", "silang"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"baka", "bada", "silang", "silangang" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, sortWords(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    TagalogDictionary ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
