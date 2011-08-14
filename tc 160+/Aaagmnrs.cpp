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

vector<int> cnts(const string &s) {
	vector<int> ret(26, 0);

	for (int i=0; i<(int)s.size(); ++i)
		if (s[i] != ' ')
			++ret[tolower(s[i])-'a'];

	return ret;
}
bool anagram(const string &a, const string &b) {
	return cnts(a) == cnts(b);
}
class Aaagmnrs {
	public:
	vector <string> anagrams(vector <string> phrases) {
		for (int i=1; i<(int)phrases.size(); ++i)
			for (int j=0; j<i; ++j)
				if (anagram(phrases[i], phrases[j])) {
					phrases.erase(phrases.begin()+i);
					--i;
					break;
				}

		return phrases;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = { "Aaagmnrs", "TopCoder", "anagrams", "Drop Cote" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "Aaagmnrs",  "TopCoder" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, anagrams(Arg0)); }
	void test_case_1() { string Arr0[] = { "SnapDragon vs tomek", "savants groped monk", "Adam vents prongs ok" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "SnapDragon vs tomek" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, anagrams(Arg0)); }
	void test_case_2() { string Arr0[] = { "Radar ghost jilts Kim", "patched hers first",
  "DEPTH FIRST SEARCH", "DIJKSTRAS ALGORITHM" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "Radar ghost jilts Kim",  "patched hers first" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, anagrams(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Aaagmnrs ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
