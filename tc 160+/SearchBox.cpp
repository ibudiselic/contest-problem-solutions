#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool sw(const string &s, const string &t) {
	if (s.size() < t.size())
		return false;
	for (int i=0; i<(int)t.size(); ++i)
		if (s[i] != t[i])
			return false;
	return true;
}
class SearchBox {
	public:
	int find(string text, string search, string wholeWord, int start) {
		for (int i=start; i<(int)text.size(); ++i)
			if (sw(text.substr(i), search) && (wholeWord=="N" || ((i==0 || text[i-1]==' ') && (i+search.size()==text.size() || text[i+search.size()]==' '))))
				return i;

		return -1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "We dont need no education"; string Arg1 = "ed"; string Arg2 = "N"; int Arg3 = 13; int Arg4 = 16; verify_case(0, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { string Arg0 = "We dont need no thought control"; string Arg1 = "We"; string Arg2 = "Y"; int Arg3 = 0; int Arg4 = 0; verify_case(1, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { string Arg0 = "No dark sarcasm in the classroom"; string Arg1 = "The"; string Arg2 = "Y"; int Arg3 = 5; int Arg4 = -1; verify_case(2, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { string Arg0 = "Teachers leave them kids alone"; string Arg1 = "kid"; string Arg2 = "Y"; int Arg3 = 1; int Arg4 = -1; verify_case(3, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { string Arg0 = "All in all its just another brick in the wall"; string Arg1 = "all"; string Arg2 = "Y"; int Arg3 = 9; int Arg4 = -1; verify_case(4, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { string Arg0 = "All in all youre just another brick in the wall"; string Arg1 = "just"; string Arg2 = "Y"; int Arg3 = 17; int Arg4 = 17; verify_case(5, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    SearchBox ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
