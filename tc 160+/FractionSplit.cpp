#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int gcd(int m, int n) {
	return n==0 ? m : gcd(n, m%n);
}
string make(int x) {
	ostringstream os;
	os << "1/" << x;
	return os.str();
}
class FractionSplit {
	public:
	vector <string> getSum(int n, int d) {
		int denom = 2;
		vector<string> sol;

		while (n > 0) {
			int x = gcd(n, d);
			n /= x;
			d /= x;
			while (denom*n < d)
				++denom;
			n *= denom;
			n -= d;
			d *= denom;
			sol.push_back(make(denom));
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 5; string Arr2[] = {"1/2", "1/4", "1/20" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, getSum(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 3; string Arr2[] = {"1/2", "1/6" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, getSum(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 2; string Arr2[] = {"1/2" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, getSum(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 15; int Arg1 = 16; string Arr2[] = {"1/2", "1/3", "1/10", "1/240" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, getSum(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 14; int Arg1 = 15; string Arr2[] = {"1/2", "1/3", "1/10" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, getSum(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    FractionSplit ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
