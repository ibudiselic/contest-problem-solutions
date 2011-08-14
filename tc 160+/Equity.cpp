#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Equity {
	public:
	int minPieces(int n, int k) {
		vector<int> a(n, 0);
		k *= 6;

		for (int i=0; i<n; ++i) {
			a[i] += 2;
			k -= 2;
			if (0 == k)
				return i+1;
		}

		int t = k/n;
		for (int i=0; i<n; ++i) {
			a[i] += t;
			k -= t;
		}
		for (int i=0; k>0 && i<n; ++i) {
			++a[i];
			--k;
		}

		int sol = 0;
		for (int i=0; i<n; ++i) {
			int halfs = a[i]/3;
			if (a[i]%3 == 1)
				--halfs;
			a[i] -= halfs*3;
			int thirds = a[i]/2;
			assert(a[i] - thirds*2 == 0);
			sol += halfs/2 + halfs%2 + thirds;
		}
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 12; int Arg1 = 11; int Arg2 = 18; verify_case(0, Arg2, minPieces(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 12; int Arg1 = 4; int Arg2 = 12; verify_case(1, Arg2, minPieces(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 12; int Arg1 = 1; int Arg2 = 3; verify_case(2, Arg2, minPieces(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Equity ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
