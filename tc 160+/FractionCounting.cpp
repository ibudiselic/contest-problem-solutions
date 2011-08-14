#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <utility>

using namespace std;

int gcd(int a, int b) {
	if (a==0) return b;
	else return gcd(b%a, a);
}
typedef pair<int, int> pii;

class FractionCounting {
	public:
	int howMany(int w, int x, int y, int z) {
		set<pii> S;
		for (int i=w; i<=x; ++i)
			for (int j=y; j<=z; ++j) {

				const int d = gcd(i, j);
				pii t = make_pair(i/d, j/d);
				S.insert(t);
			}
		return (int)S.size();
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1; int Arg3 = 1; int Arg4 = 1; verify_case(0, Arg4, howMany(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 10; int Arg2 = 1; int Arg3 = 1; int Arg4 = 10; verify_case(1, Arg4, howMany(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 2; int Arg2 = 1; int Arg3 = 2; int Arg4 = 3; verify_case(2, Arg4, howMany(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 2; int Arg1 = 4; int Arg2 = 2; int Arg3 = 4; int Arg4 = 7; verify_case(3, Arg4, howMany(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 1; int Arg1 = 100; int Arg2 = 1; int Arg3 = 100; int Arg4 = 6087; verify_case(4, Arg4, howMany(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    FractionCounting ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
