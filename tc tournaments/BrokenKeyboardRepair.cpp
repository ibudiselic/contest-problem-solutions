#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <set>

using namespace std;

class BrokenKeyboardRepair {
	public:
	int minimalNumberOfKeys(string word) {
		set<char> S(word.begin(), word.end());

		return S.size();
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "coder"; int Arg1 = 5; verify_case(0, Arg1, minimalNumberOfKeys(Arg0)); }
	void test_case_1() { string Arg0 = "hello"; int Arg1 = 4; verify_case(1, Arg1, minimalNumberOfKeys(Arg0)); }
	void test_case_2() { string Arg0 = "abracadabra"; int Arg1 = 5; verify_case(2, Arg1, minimalNumberOfKeys(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    BrokenKeyboardRepair ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
