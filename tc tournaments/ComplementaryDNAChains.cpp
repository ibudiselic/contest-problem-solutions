#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool isComplementary(char a, char b) {
	return a=='A' && b=='T' || a=='T' && b=='A' || a=='G' && b=='C' || a=='C' && b=='G';
}
class ComplementaryDNAChains {
	public:
	int minReplaces(string first, string second) {
		int sol = 0;
		for (int i=0; i<(int)first.size(); ++i)
			sol += !isComplementary(first[i], second[i]);

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "ACGT"; string Arg1 = "TGCA"; int Arg2 = 0; verify_case(0, Arg2, minReplaces(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "ACGT"; string Arg1 = "ACGT"; int Arg2 = 4; verify_case(1, Arg2, minReplaces(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "ATAGTACCAC"; string Arg1 = "CTTATTGGGT"; int Arg2 = 6; verify_case(2, Arg2, minReplaces(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ComplementaryDNAChains ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
