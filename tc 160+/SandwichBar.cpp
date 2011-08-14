#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool hasAll(const string &a, const vector<string> &b) {
	istringstream is(a);
	string s;

	while (is >> s)
		if (find(b.begin(), b.end(), s) == b.end())
			return false;

	return true;
}
class SandwichBar {
	public:
	int whichOrder(vector <string> available, vector <string> orders) {
		for (int i=0; i<(int)orders.size(); ++i)
			if (hasAll(orders[i], available))
				return i;

		return -1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = { "ham", "cheese", "mustard" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "ham cheese" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(0, Arg2, whichOrder(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = { "cheese", "mustard", "lettuce" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "cheese ham", "cheese mustard lettuce", "ketchup", "beer" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(1, Arg2, whichOrder(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = { "cheese", "cheese", "cheese", "tomato" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "ham ham ham", "water", "pork", "bread", "cheese tomato cheese", "beef" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(2, Arg2, whichOrder(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = { "foo", "bar", "baz", "gazonk", "quux", "bat", "xyzzy",
  "shme", "hukarz", "grault", "waldo", "bleh" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "kalatehas", "spam eggs", "needle haystack", "bleh blarg", "plugh",
  "the best sandwich in the universe" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(3, Arg2, whichOrder(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    SandwichBar ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
