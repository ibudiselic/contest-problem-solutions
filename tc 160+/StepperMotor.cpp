#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

long long my_abs(long long x) {
	return (x>=0 ? x : -x);
}
long long norm(long long x, long long n) {
	if (x >= 0)
		return x%n;
	else
		return (x + (my_abs(x)+n-1)/n*n) % n;
}
class StepperMotor {
	public:
	int rotateToNearest(int n, int current, vector <int> target) {
		long long pos = norm(current, n);

		int sign = 0;
		long long absVal = 1LL<<33;

		for (int i=0; i<(int)target.size(); ++i) {
			long long x = norm(target[i], n);

			if (x >= pos) {
				long long t = x-pos;
				if (t<absVal || (t==absVal && sign!=1)) {
					absVal = t;
					sign = 1;
				}
			} else {
				long long t = n-(pos-x);
				if (t<absVal || (t==absVal && sign!=1)) {
					absVal = t;
					sign = 1;
				}
			}

			if (x >= pos) {
				long long t = n - (x-pos);
				if (t < absVal) {
					absVal = t;
					sign = -1;
				}
			} else {
				long long t = pos - x;
				if (t < absVal) {
					absVal = t;
					sign = -1;
				}
			}
		}

		return sign*absVal;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arg1 = 0; int Arr2[] = {-2, -3, 4, 5, 6, 9999999}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -1; verify_case(0, Arg3, rotateToNearest(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 314159; int Arr2[] = {10, 8, 6, 4, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(1, Arg3, rotateToNearest(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = -2147483648; int Arr2[] = {-2147483648, -2147483648, 2147483647, 2147483647}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(2, Arg3, rotateToNearest(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 23; int Arg1 = 10; int Arr2[] = {64077, -567273, 105845, -279980, 35557,
-286190, -652879, -431665, -634870, -454044}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -11; verify_case(3, Arg3, rotateToNearest(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 1000000000; int Arg1 = 1403466951; int Arr2[] = {1233321992, 11423750, 1356595134, 1130863021, 1183514764,
1943494859, 1714480374, 1529875954, 1738756510, 1190153525}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -46871817; verify_case(4, Arg3, rotateToNearest(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    StepperMotor ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
