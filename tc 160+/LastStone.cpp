#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <numeric>

using namespace std;

bool bob[100001];
class LastStone {
	public:
	int numWins(vector <int> turns, int m, int n) {
		memset(bob, 0, sizeof bob);
		for (int i=1; i<=n; ++i)
			for (int j=0; j<(int)turns.size(); ++j)
				if (turns[j]<=i) {
					if (!bob[i-turns[j]]) {
						bob[i] = true;
						break;
					}
				} else {
					break;
				}

		return accumulate(bob+m, bob+n+1, 0);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 3, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 5; int Arg3 = 4; verify_case(0, Arg3, numWins(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 100; int Arg3 = 50; verify_case(1, Arg3, numWins(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {1,2,3,4,5,6,7,8,9,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 10; int Arg3 = 10; verify_case(2, Arg3, numWins(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {1, 2, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 8; int Arg3 = 6; verify_case(3, Arg3, numWins(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    LastStone ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
