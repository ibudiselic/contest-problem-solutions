#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class CompletingBrackets {
	public:
	string complete(string text) {
		string sol;

		int bc = 0;
		for (int i=0; i<(int)text.size(); ++i) {
			bc += (text[i]=='[') - (text[i]==']');
			if (bc == -1) {
				bc = 0;
				sol += '[';
			}
		}

		sol += text + string(bc, ']');

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "[["; string Arg1 = "[[]]"; verify_case(0, Arg1, complete(Arg0)); }
	void test_case_1() { string Arg0 = "]["; string Arg1 = "[][]"; verify_case(1, Arg1, complete(Arg0)); }
	void test_case_2() { string Arg0 = "[[[[]]]]"; string Arg1 = "[[[[]]]]"; verify_case(2, Arg1, complete(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    CompletingBrackets ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
