#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <set>

using namespace std;

set<int> factorize(int n) {
	set<int> ret;
	for (int d=2; d<=n; ++d)
		if (n%d == 0) {
			ret.insert(d);
			while (n%d == 0)
				n /= d;
		}
	if (n != 1)
		ret.insert(n);
	return ret;
}
class RSABreaker {
	public:
	int decrypt(int e, int n, int b) {
		set<int> FN = factorize(n);

		int m = 0;
		for (int i=1; i<n; ++i) {
			set<int> F = factorize(i);
			bool ok = true;
			for (set<int>::const_iterator it=F.begin(); it!=F.end(); ++it)
				if (FN.count(*it) != 0) {
					ok = false;
					break;
				}
			m += ok;
		}

		int x = m+1;
		while (x%e != 0)
			x += m;

		int d = x/e;
		int sol = 1;
		while (d--)
			sol = sol*b % n;

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 10; int Arg2 = 3; int Arg3 = 7; verify_case(0, Arg3, decrypt(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 17; int Arg1 = 33; int Arg2 = 4; int Arg3 = 31; verify_case(1, Arg3, decrypt(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 42; int Arg2 = 17; int Arg3 = 17; verify_case(2, Arg3, decrypt(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 5; int Arg1 = 997; int Arg2 = 7; int Arg3 = 523; verify_case(3, Arg3, decrypt(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    RSABreaker ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
