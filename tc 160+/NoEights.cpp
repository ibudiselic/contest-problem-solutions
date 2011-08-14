#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class NoEights {
	public:
	int smallestAmount(int low, int high) {
		ostringstream os;
		os << low;
		string l = os.str();
		ostringstream os2;
		os2 << high;
		string r = os2.str();

		while (l.size() < r.size())
			l = '0' + l;

		int sol = 0;
		for (int i=0; i<(int)l.size(); ++i) {
			if (l[i] != r[i])
				break;
			sol += (l[i]=='8');
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 10; int Arg2 = 0; verify_case(0, Arg2, smallestAmount(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 88; int Arg1 = 88; int Arg2 = 2; verify_case(1, Arg2, smallestAmount(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 800; int Arg1 = 899; int Arg2 = 1; verify_case(2, Arg2, smallestAmount(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 8808; int Arg1 = 8880; int Arg2 = 2; verify_case(3, Arg2, smallestAmount(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    NoEights ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
