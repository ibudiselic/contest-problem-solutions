#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int firstN(int n) {
	return n*(n+1)/2;
}
class TriangleCount {
	public:
	int count(int N) {
		int sol = 0;

		for (int side=1; side<=N; ++side)
			sol += firstN(N-side+1) + (N-side>=side ? firstN(N-2*side+1) : 0);

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 5; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 27; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { int Arg0 = 100; int Arg1 = 256275; verify_case(2, Arg1, count(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    TriangleCount ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
