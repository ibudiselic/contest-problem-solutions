#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int x[400];
int best[300001];
class CannonBalls {
	public:
	int fewestPiles(int n) {
		x[1] = 1;
		for (int i=2; i<400; ++i)
			x[i] = x[i-1]+i;

		for (int i=2; i<=n; ++i)
			best[i] = 1000000000;
		for (int i=2; i<400; ++i) {
			x[i] += x[i-1];
			if (x[i] <= n)
				best[x[i]] = 1;
			else
				break;
		}

		best[1] = 1;
		for (int i=1; i<n; ++i)
			for (int j=1; i+x[j]<=n; ++j)
				best[i+x[j]] = min(best[i+x[j]], best[i]+1);

		return best[n];
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; verify_case(0, Arg1, fewestPiles(Arg0)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 2; verify_case(1, Arg1, fewestPiles(Arg0)); }
	void test_case_2() { int Arg0 = 9; int Arg1 = 3; verify_case(2, Arg1, fewestPiles(Arg0)); }
	void test_case_3() { int Arg0 = 15; int Arg1 = 3; verify_case(3, Arg1, fewestPiles(Arg0)); }
	void test_case_4() { int Arg0 = 91; int Arg1 = 2; verify_case(4, Arg1, fewestPiles(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    CannonBalls ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
