#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class ExploringEuropa {
	public:
	int travelTime(string surface, int d) {
		surface += string(200, '-');

		int v0 = surface.find('V');

		int sol = v0 + 5*d;

		for (int i=v0+d; i>v0; --i)
			if (surface[i] == 'V') {
				sol = min(sol, v0 + 5*d - (i-v0));
				break;
			}

		for (int x=1; x<d; ++x)
			if (surface[v0+d+x] == 'V') {
				sol = min(sol, v0 + 4*d + 3*x);
				break;
			}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "S----V-----V----"; int Arg1 = 5; int Arg2 = 28; verify_case(0, Arg2, travelTime(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "S----VV---------"; int Arg1 = 5; int Arg2 = 29; verify_case(1, Arg2, travelTime(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "S---V"; int Arg1 = 10; int Arg2 = 54; verify_case(2, Arg2, travelTime(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "SVVVVV"; int Arg1 = 1; int Arg2 = 5; verify_case(3, Arg2, travelTime(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "S------------------------------V-----------V"; int Arg1 = 22; int Arg2 = 129; verify_case(4, Arg2, travelTime(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ExploringEuropa ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
