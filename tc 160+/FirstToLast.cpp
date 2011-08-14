#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b) {
	if (a==0) return b;
	else return gcd(b%a, a);
}
enum {
	INF = 2000000001
};
long long pot10[11];
class FirstToLast {
	public:
	int getSmallest(int p, int q) {
		const int d = gcd(p, q);
		p /= d; q /= d;
		if (p >= 10*q) return -1;

		pot10[0] = 1;
		for (int i=1; i<11; ++i)
			pot10[i] = 10 * pot10[i-1];

		int sol = INF;
		for (int d=0; d<10; ++d)
			for (int k=1; k<11; ++k) {
				if (q*d*(pot10[k]-1) % (10*q-p) != 0) continue;
				long long x = q*d*(pot10[k]-1)/(10*q-p);
				if (x>=pot10[k-1] && x<pot10[k] && x/pot10[k-1]==d && x<INF)
					sol = min((long long)sol, x);
			}
		return sol==INF ? -1 : sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1; verify_case(0, Arg2, getSmallest(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 4; int Arg2 = 102564; verify_case(1, Arg2, getSmallest(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 6; int Arg2 = -1; verify_case(2, Arg2, getSmallest(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 1; int Arg1 = 100; int Arg2 = 100; verify_case(3, Arg2, getSmallest(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 92; int Arg1 = 10; int Arg2 = -1; verify_case(4, Arg2, getSmallest(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    FirstToLast ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
