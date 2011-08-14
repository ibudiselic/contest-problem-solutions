#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class LevelUp {
	public:
	int toNextLevel(vector <int> expNeeded, int received) {
		int i=0;

		while (i<(int)expNeeded.size() && expNeeded[i]<=received)
			++i;

		return expNeeded[i] - received;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {150,450,900,1800}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 133; int Arg2 = 17; verify_case(0, Arg2, toNextLevel(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {150,450,900,1800}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 312; int Arg2 = 138; verify_case(1, Arg2, toNextLevel(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {150,450,900,1800}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 612; int Arg2 = 288; verify_case(2, Arg2, toNextLevel(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {150,450,900,1800}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 450; int Arg2 = 450; verify_case(3, Arg2, toNextLevel(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    LevelUp ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
