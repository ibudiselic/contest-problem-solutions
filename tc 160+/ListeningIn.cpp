#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class ListeningIn {
	public:
	string probableMatch(string typed, string phrase) {
		int i=0, j=0;
		string sol;
		while (i<(int)typed.size() && j<(int)phrase.size()) {
			if (typed[i] != phrase[j]) {
				sol += phrase[j];
				++j;
			} else {
				++j;
				++i;
			}
		}

		if (j < (int)phrase.size())
			sol += phrase.substr(j);

		if (i == (int)typed.size())
			return sol;
		else
			return "UNMATCHED";
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "cptr"; string Arg1 = "capture"; string Arg2 = "aue"; verify_case(0, Arg2, probableMatch(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "port to me"; string Arg1 = "teleport to me"; string Arg2 = "tele"; verify_case(1, Arg2, probableMatch(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "back  to base"; string Arg1 = "back to base"; string Arg2 = "UNMATCHED"; verify_case(2, Arg2, probableMatch(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ListeningIn ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
