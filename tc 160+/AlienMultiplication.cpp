#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int pow10[7];
int sol;
void go(int a, int b, int c, int pos, int cur) {
	if ((long long)a*b % 1000000 == c) {
		sol = min(sol, cur);
		return;
	}
	if (cur>=sol-1 || pos==6)
		return;

	for (int x=0; x<10; ++x)
		for (int y=0; y<10; ++y) {
			const int na = a - (a/pow10[pos]%10 - x) * pow10[pos];
			const int nb = b - (b/pow10[pos]%10 - y) * pow10[pos];
			const int t = int((long long)na*nb % 1000000);
			const int nc = c - (c/pow10[pos]%10 - t/pow10[pos]%10)*pow10[pos];
			int add = (x != a/pow10[pos]%10) + (y != b/pow10[pos]%10) + (nc/pow10[pos]%10 != c/pow10[pos]%10);
			go(na, nb, nc, pos+1, cur+add);
		}
}
class AlienMultiplication {
	public:
	int getCorrections(int a, int b, int c) {
		pow10[0] = 1;
		for (int i=1; i<7; ++i)
			pow10[i] = pow10[i-1]*10;

		sol = 6;
		go(a, b, c, 0, 0);

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 23; int Arg1 = 11; int Arg2 = 2093; int Arg3 = 1; verify_case(0, Arg3, getCorrections(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 1538; int Arg1 = 951234; int Arg2 = 997892; int Arg3 = 0; verify_case(1, Arg3, getCorrections(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 153; int Arg1 = 7; int Arg2 = 71; int Arg3 = 1; verify_case(2, Arg3, getCorrections(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 421368; int Arg1 = 512357; int Arg2 = 862812; int Arg3 = 4; verify_case(3, Arg3, getCorrections(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 987654; int Arg3 = 5; verify_case(4, Arg3, getCorrections(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 999999; int Arg1 = 999999; int Arg2 = 1; int Arg3 = 0; verify_case(5, Arg3, getCorrections(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    AlienMultiplication ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
