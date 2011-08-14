#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class Reppity {
	public:
	int longestRep(string s) {
		for (int len=(int)s.size()/2; len>0; --len)
			for (int i=0; i+2*len<=(int)s.size(); ++i)
				if (s.substr(i+len).find(s.substr(i, len)) != string::npos)
					return len;

		return 0;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "ABCDEXXXYYYZZZABCDEZZZYYYXXX"; int Arg1 = 5; verify_case(0, Arg1, longestRep(Arg0)); }
	void test_case_1() { string Arg0 = "abcdabcdabcdabCD"; int Arg1 = 6; verify_case(1, Arg1, longestRep(Arg0)); }
	void test_case_2() { string Arg0 = "abcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxy"; int Arg1 = 25; verify_case(2, Arg1, longestRep(Arg0)); }
	void test_case_3() { string Arg0 = "againANDagainANDagainANDagainANDagainANDagain"; int Arg1 = 21; verify_case(3, Arg1, longestRep(Arg0)); }
	void test_case_4() { string Arg0 = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWX"; int Arg1 = 0; verify_case(4, Arg1, longestRep(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Reppity ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
