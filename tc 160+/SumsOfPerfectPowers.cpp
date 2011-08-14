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

bool isSPP[5000001];
class SumsOfPerfectPowers {
	public:
	int howMany(int lowerBound, int upperBound) {
		memset(isSPP, 0, sizeof isSPP);
		isSPP[0] = 1;
		isSPP[1] = 1;

		for (int a=0; a<=2500; ++a) {
			long long y = a*a;
			while (y <= 5000000) {
				for (int b=a; b<=2500; ++b) {
					long long w = b*b;
					if (w + y > 5000000)
						break;
					while (w + y <= 5000000) {
						isSPP[w+y] = 1;

						w *= b;
						if (b<=1 || w>5000000-y)
							break;
					}
				}

				y *= a;
				if (a <= 1)
					break;
			}
		}

		return accumulate(isSPP+lowerBound, isSPP+upperBound+1, 0);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 0; int Arg1 = 1; int Arg2 = 2; verify_case(0, Arg2, howMany(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 6; int Arg2 = 1; verify_case(1, Arg2, howMany(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 25; int Arg1 = 30; int Arg2 = 5; verify_case(2, Arg2, howMany(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 103; int Arg1 = 103; int Arg2 = 0; verify_case(3, Arg2, howMany(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 1; int Arg1 = 100000; int Arg2 = 33604; verify_case(4, Arg2, howMany(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    SumsOfPerfectPowers ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
