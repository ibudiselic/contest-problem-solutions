#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;
const char *name[] = { "placeholder", "unu", "du", "tri", "kvar", "kvin", "ses", "sep", "ok", "nau", "dek" };
class EsperantoNumbers {
	public:
	string nameThisNumber(int x) {
		return ((x/10!=0 ? (x/10==1 ? "":string(name[x/10])) + "dek" + (x%10!=0 ? " ":"") : "") + (x%10!=0 ? string(name[x%10]):""));
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; string Arg1 = "unu"; verify_case(0, Arg1, nameThisNumber(Arg0)); }
	void test_case_1() { int Arg0 = 90; string Arg1 = "naudek"; verify_case(1, Arg1, nameThisNumber(Arg0)); }
	void test_case_2() { int Arg0 = 11; string Arg1 = "dek unu"; verify_case(2, Arg1, nameThisNumber(Arg0)); }
	void test_case_3() { int Arg0 = 57; string Arg1 = "kvindek sep"; verify_case(3, Arg1, nameThisNumber(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    EsperantoNumbers ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
