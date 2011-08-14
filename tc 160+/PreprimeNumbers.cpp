#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

const int CNT = 6000000;
char a[CNT];
class PreprimeNumbers {
	public:
	int nthNumber(int n) {
		memset(a, 0, sizeof a);

		int i=0, cnt=0;
		for (i=2; i<CNT && cnt<n; ++i) {
			if (a[i] == 0) { // prime
				for (int j=2*i; j<CNT; j+=i) {
					int t = j;
					while (t%i == 0) {
						t /= i;
						++a[j];
					}
					if (t == 1)
						--a[j];
				}
			}
			if (a[i] == 2)
				++cnt;
		}
		return i-1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 8; verify_case(0, Arg1, nthNumber(Arg0)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 14; verify_case(1, Arg1, nthNumber(Arg0)); }
	void test_case_2() { int Arg0 = 24; int Arg1 = 77; verify_case(2, Arg1, nthNumber(Arg0)); }
	void test_case_3() { int Arg0 = 43765; int Arg1 = 193539; verify_case(3, Arg1, nthNumber(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    PreprimeNumbers ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
