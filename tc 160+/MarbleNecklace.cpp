#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class MarbleNecklace {
	public:
	string normalize(string necklace) {
		string sol = necklace;
		for (int i=1; i<(int)necklace.size(); ++i)
			sol = min(sol, necklace.substr(i) + necklace.substr(0, i));
		reverse(necklace.begin(), necklace.end());
		sol = min(sol, necklace);
		for (int i=1; i<(int)necklace.size(); ++i)
			sol = min(sol, necklace.substr(i) + necklace.substr(0, i));
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "CDAB"; string Arg1 = "ABCD"; verify_case(0, Arg1, normalize(Arg0)); }
	void test_case_1() { string Arg0 = "RGB"; string Arg1 = "BGR"; verify_case(1, Arg1, normalize(Arg0)); }
	void test_case_2() { string Arg0 = "TOPCODER"; string Arg1 = "CODERTOP"; verify_case(2, Arg1, normalize(Arg0)); }
	void test_case_3() { string Arg0 = "SONBZELGFEQMSULZCNPJODOWPEWLHJFOEW"; string Arg1 = "BNOSWEOFJHLWEPWODOJPNCZLUSMQEFGLEZ"; verify_case(3, Arg1, normalize(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    MarbleNecklace ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
