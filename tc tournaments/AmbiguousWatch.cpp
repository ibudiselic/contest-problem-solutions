#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class AmbiguousWatch {
	public:
	int howMany(string startTime, string finishTime) {
		int sh, sm, eh, em;
		sscanf(startTime.c_str(), "%d:%d", &sh, &sm);
		sscanf(finishTime.c_str(), "%d:%d", &eh, &em);

		return (143*(eh*60+em))/720 - (143*(sh*60+sm)-1)/720 - (11*(eh*60+em))/720 + (11*(sh*60+sm)-1)/720;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "00:00"; string Arg1 = "00:00"; int Arg2 = 0; verify_case(0, Arg2, howMany(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "00:05"; string Arg1 = "00:06"; int Arg2 = 1; verify_case(1, Arg2, howMany(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "00:00"; string Arg1 = "01:00"; int Arg2 = 11; verify_case(2, Arg2, howMany(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    AmbiguousWatch ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
