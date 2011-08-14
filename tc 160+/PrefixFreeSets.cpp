#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <numeric>

using namespace std;

class PrefixFreeSets {
	public:
	int maxElements(vector <string> words) {
		vector<bool> ok(words.size(), 1);

		for (int i=0; i<(int)words.size(); ++i) {
			bool use = true;
			for (int j=0; j<(int)words.size(); ++j)
				if (i!=j && ok[j] && (words[i].size()<=words[j].size() && words[i]==words[j].substr(0, words[i].size()))) {
					use = false;
					break;
				}
			ok[i] = use;
		}
		return accumulate(ok.begin(), ok.end(), 0);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"hello","hi","h","run","rerun","running"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, maxElements(Arg0)); }
	void test_case_1() { string Arr0[] = {"a","b","cba","cbc","cbb","ccc"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(1, Arg1, maxElements(Arg0)); }
	void test_case_2() { string Arr0[] = {"a","ab","abc","abcd","abcde","abcdef"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, maxElements(Arg0)); }
	void test_case_3() { string Arr0[] = {"topcoder","topcoder","topcoding"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(3, Arg1, maxElements(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    PrefixFreeSets ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
