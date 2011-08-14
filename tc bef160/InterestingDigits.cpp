#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class InterestingDigits {
	public:
	vector <int> digits(int base) {
		vector<int> sol;
		int lim = base*base*base;
		for (int i=2; i<base; ++i) {
			bool ok = true;
			for (int x=i; x<lim; x+=i) {
				int t = x;
				int sum = 0;
				while (t) {
					sum += t%base;
					t /= base;
				}
				if (sum%i != 0) {
					ok = false;
					break;
				}
			}
			if (ok)
				sol.push_back(i);
		}
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 10; int Arr1[] = { 3,  9 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, digits(Arg0)); }
	void test_case_1() { int Arg0 = 3; int Arr1[] = { 2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, digits(Arg0)); }
	void test_case_2() { int Arg0 = 9; int Arr1[] = { 2,  4,  8 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, digits(Arg0)); }
	void test_case_3() { int Arg0 = 26; int Arr1[] = { 5,  25 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, digits(Arg0)); }
	void test_case_4() { int Arg0 = 30; int Arr1[] = { 29 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, digits(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    InterestingDigits ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
