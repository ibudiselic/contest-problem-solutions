#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class Packhorses {
	public:
	int horses(int p, int x, int y) {
		int sol = 1000000000;
		for (int i=0; i<=p; ++i) {
			const int xx = max(0, x - 2*i);
			const int yy = max(0, y - (p-i));
			sol = min(sol, p + (xx+2)/3 + (yy+1)/2);
		}
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 5; int Arg2 = 0; int Arg3 = 2; verify_case(0, Arg3, horses(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 6; int Arg2 = 0; int Arg3 = 3; verify_case(1, Arg3, horses(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 20; int Arg1 = 15; int Arg2 = 7; int Arg3 = 20; verify_case(2, Arg3, horses(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 1; int Arg1 = 3; int Arg2 = 1; int Arg3 = 2; verify_case(3, Arg3, horses(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Packhorses ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
