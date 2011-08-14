#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class SimpleTextProcessor {
	public:
	vector <string> makeColumns(vector <string> words) {
		vector<string> sol;
		int m1=0, m2=0;
		int n = words.size();
		for (int i=0; i<n/2; ++i)
			m1 = max(m1, (int)words[i].size());

		for (int i=n/2; i<n; ++i)
			m2 = max(m2, (int)words[i].size());

		for (int i=0; i<n/2; ++i)
			sol.push_back(words[i] + string(m1-words[i].size(), ' ') + '*' + string(m2-words[n/2+i].size(), ' ') + words[n/2+i]);

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"a", "b", "c", "d"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"a*c", "b*d" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, makeColumns(Arg0)); }
	void test_case_1() { string Arr0[] = {"very", "exciting", "programming", "competition"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"very    *programming", "exciting*competition" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, makeColumns(Arg0)); }
	void test_case_2() { string Arr0[] = {"simple", "test"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"simple*test" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, makeColumns(Arg0)); }
	void test_case_3() { string Arr0[] = {"this", "software", "includes", "a", "number", "of", "subcomponents", "with",
"separate", "copyright", "notices", "and", "license", "terms"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"this         *     with", "software     * separate", "includes     *copyright", "a            *  notices", "number       *      and", "of           *  license", "subcomponents*    terms" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, makeColumns(Arg0)); }
	void test_case_4() { string Arr0[] = {"abcdeabcdeabcdeabcde", "abcdeabcdeabcdeabcde",
"abcdeabcdeabcdeabcde", "abcdeabcdeabcdeabcde",
"abcdeabcdeabcdeabcde", "abcdeabcdeabcdeabcde",
"abcdeabcdeabcdeabcde", "abcdeabcdeabcdeabcde",
"abcdeabcdeabcdeabcde", "abcdeabcdeabcdeabcde",
"abcdeabcdeabcdeabcde", "abcdeabcdeabcdeabcde",
"abcdeabcdeabcdeabcde", "abcdeabcdeabcdeabcde",
"abcdeabcdeabcdeabcde", "abcdeabcdeabcdeabcde",
"abcdeabcdeabcdeabcde", "abcdeabcdeabcdeabcde"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"abcdeabcdeabcdeabcde*abcdeabcdeabcdeabcde", "abcdeabcdeabcdeabcde*abcdeabcdeabcdeabcde", "abcdeabcdeabcdeabcde*abcdeabcdeabcdeabcde", "abcdeabcdeabcdeabcde*abcdeabcdeabcdeabcde", "abcdeabcdeabcdeabcde*abcdeabcdeabcdeabcde", "abcdeabcdeabcdeabcde*abcdeabcdeabcdeabcde", "abcdeabcdeabcdeabcde*abcdeabcdeabcdeabcde", "abcdeabcdeabcdeabcde*abcdeabcdeabcdeabcde", "abcdeabcdeabcdeabcde*abcdeabcdeabcdeabcde" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, makeColumns(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    SimpleTextProcessor ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
