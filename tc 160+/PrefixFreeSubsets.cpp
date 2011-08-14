#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

struct Trie;
long long calc(const Trie &);
// '@' je dummy (tj. predstavlja zajednicki prefiks svih nizova)
struct Trie {
	char c;
	bool word;
	vector<Trie> v;
	Trie(char c_='@'): c(c_), word(false) {}

	void insert(const string &s) {
		if (s.size() == 0) {
			word = true;
			return;
		}
		for (int i=0; i<(int)v.size(); ++i)
			if (v[i].c == s[0]) {
				v[i].insert(s.substr(1));
				return;
			}
		v.push_back(Trie(s[0]));
		v.back().insert(s.substr(1));
	}
	void print(const string &tab="") {
		cerr << tab << c;
		if (word)
			cerr << '|';
		cerr << calc(*this);
		cerr << '\n';
		for (int i=0; i<(int)v.size(); ++i)
			v[i].print(tab+"  ");
	}
};
long long calc(const Trie &T) {
	if (T.v.size() == 0)
		return 1+T.word;
	long long ret = 1;
	for (int i=0; i<(int)T.v.size(); ++i)
		ret *= calc(T.v[i]);

	return ret + T.word;
}
class PrefixFreeSubsets {
	public:
	long long cantPrefFreeSubsets(vector <string> words) {
		Trie T;

		for (int i=0; i<(int)words.size(); ++i)
			T.insert(words[i]);

		return calc(T);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"hello","hell","hi"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 6LL; verify_case(0, Arg1, cantPrefFreeSubsets(Arg0)); }
	void test_case_1() { string Arr0[] = {"a","b","c","d"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 16LL; verify_case(1, Arg1, cantPrefFreeSubsets(Arg0)); }
	void test_case_2() { string Arr0[] = {"a","ab","abc","abcd","abcde","abcdef"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 7LL; verify_case(2, Arg1, cantPrefFreeSubsets(Arg0)); }
	void test_case_3() { string Arr0[] = {"a","b","aa","ab","ba","bb"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 25LL; verify_case(3, Arg1, cantPrefFreeSubsets(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    PrefixFreeSubsets ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
