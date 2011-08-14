#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

/*
If the player with the ball has already received the ball M times, the game is over.
Otherwise, if the player has received the ball p times, he'll pass the ball directly to the person L places to his left if p is even, or L places to his right if p is odd
*/
class ThrowTheBall {
	public:
	int timesThrown(int N, int M, int L) {
		int sol = 0;
		int p = 0;
		vector<int> cnt(N, 0);

		while (++cnt[p] < M) {
			++sol;
			if (cnt[p] & 1)
				p = (p+N-L)%N;
			else
				p = (p+L)%N;
		}
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 3; int Arg2 = 2; int Arg3 = 10; verify_case(0, Arg3, timesThrown(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 1; int Arg2 = 3; int Arg3 = 0; verify_case(1, Arg3, timesThrown(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 3; int Arg2 = 5; int Arg3 = 4; verify_case(2, Arg3, timesThrown(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 15; int Arg1 = 4; int Arg2 = 9; int Arg3 = 15; verify_case(3, Arg3, timesThrown(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ThrowTheBall ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
