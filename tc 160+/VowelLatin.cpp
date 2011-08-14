#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class VowelLatin {
	public:
	string translate(string word) {
		string a, b;
		string v("aeiouAEIOU");

		for (int i=0; i<(int)word.size(); ++i)
			if (v.find(word[i]) != string::npos)
				b += word[i];
			else
				a += word[i];

		return a+b;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "XYz"; string Arg1 = "XYz"; verify_case(0, Arg1, translate(Arg0)); }
	void test_case_1() { string Arg0 = "application"; string Arg1 = "pplctnaiaio"; verify_case(1, Arg1, translate(Arg0)); }
	void test_case_2() { string Arg0 = "qwcvb"; string Arg1 = "qwcvb"; verify_case(2, Arg1, translate(Arg0)); }
	void test_case_3() { string Arg0 = "aeioOa"; string Arg1 = "aeioOa"; verify_case(3, Arg1, translate(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    VowelLatin ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
