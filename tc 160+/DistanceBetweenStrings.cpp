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

int sqr(int x) { return x*x; }
void tolow(string &a) {
	for (int i=0; i<(int)a.size(); ++i)
		a[i] = tolower(a[i]);
}
class DistanceBetweenStrings {
	public:
	int getDistance(string a, string b, string letterSet) {
		int sol = 0;

		tolow(a);
		tolow(b);
		tolow(letterSet);
		for (int i=0; i<(int)letterSet.size(); ++i)
			sol += sqr(count(a.begin(), a.end(), letterSet[i]) - count(b.begin(), b.end(), letterSet[i]));

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "topcoder"; string Arg1 = "contest"; string Arg2 = "tcp"; int Arg3 = 2; verify_case(0, Arg3, getDistance(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "abcdef"; string Arg1 = "fedcba"; string Arg2 = "fed"; int Arg3 = 0; verify_case(1, Arg3, getDistance(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "aaaaa"; string Arg1 = "bbbbb"; string Arg2 = "a"; int Arg3 = 25; verify_case(2, Arg3, getDistance(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "aaAaB"; string Arg1 = "BbaAa"; string Arg2 = "ab"; int Arg3 = 2; verify_case(3, Arg3, getDistance(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"; string Arg1 = "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb"; string Arg2 = "ba"; int Arg3 = 5000; verify_case(4, Arg3, getDistance(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arg0 = "ToPcOdEr"; string Arg1 = "tOpCoDeR"; string Arg2 = "wxyz"; int Arg3 = 0; verify_case(5, Arg3, getDistance(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    DistanceBetweenStrings ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
