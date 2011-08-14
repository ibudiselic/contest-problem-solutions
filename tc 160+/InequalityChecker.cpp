#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

/*s = 13 + 23 + ... + (n-1)3 < n4/4 < 13 + 23 + ... + n3 = S
Given n return (S+s)/2 - n4/4*/
int third(int x) { return x*x*x; }
class InequalityChecker {
	public:
	vector <int> getDifferences(int n) {
		int s = 0;
		for (int i=1; i<n; ++i)
			s += third(i);

		int S = s + third(n);

		int t = 2*(s+S) - n*third(n);

		int sign = 1;
		if (t < 0) {
			t = -t;
			sign = -1;
		}

		int denom = 4;
		for (int i=0; i<2; ++i)
			if (t % 2 == 0) {
				t /= 2;
				denom /= 2;
			}

		vector<int> v(2, 0);
		v[0] = sign*t;
		v[1] = denom;

		return v;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 2; int Arr1[] = { 1,  1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getDifferences(Arg0)); }
	void test_case_1() { int Arg0 = 3; int Arr1[] = { 9,  4 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getDifferences(Arg0)); }
	void test_case_2() { int Arg0 = 100; int Arr1[] = { 2500,  1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getDifferences(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    InequalityChecker ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
