#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

double a1[1000], a2[1000];
class RandomSwaps {
	public:
	double getProbability(int arrayLength, int swapCount, int a, int b) {
		double *staro=a1, *novo=a2;
		double sum = 1.0;
		const double c1 = arrayLength*(arrayLength-1)/2;
		const double c2 = double(arrayLength-2)/arrayLength;

		for (int i=0; i<1000; ++i)
			staro[i] = 0.0;

		staro[a] = 1;
		while (swapCount--) {
			double ns = 0;
			for (int i=0; i<arrayLength; ++i) {
				novo[i] = (sum-staro[i])/c1 + staro[i]*c2;
				ns += novo[i];
			}
			sum = ns;
			swap(staro, novo);
		}

		return staro[b];
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 1; int Arg2 = 0; int Arg3 = 0; double Arg4 = 0.6; verify_case(0, Arg4, getProbability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 1; int Arg2 = 0; int Arg3 = 3; double Arg4 = 0.1; verify_case(1, Arg4, getProbability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 2; int Arg2 = 0; int Arg3 = 0; double Arg4 = 0.4; verify_case(2, Arg4, getProbability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 100; int Arg1 = 500; int Arg2 = 3; int Arg3 = 3; double Arg4 = 0.010036635745123007; verify_case(3, Arg4, getProbability(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    RandomSwaps ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
