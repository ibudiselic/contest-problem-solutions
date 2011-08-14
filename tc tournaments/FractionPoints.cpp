#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int num, denom;
int gcd(int m, int n) {
	return m ? gcd(n%m, m) : n;
}
vector<int> D;
class FractionPoints {
	public:
	double median(int l, int r) {
		const int sz = r-l;

		if (sz & 1)
			return D[l + sz/2];
		else
			return (D[l+sz/2-1] + D[l+sz/2])/2.0;
	}
	double rec(int l, int r, int n, int d) {
		if (n==num && d==denom)
			return median(l, r);

		n *= 2;
		d *= 2;
		const int sz = r-l;
		const int med = l + sz/2;

		if (num*d < n*denom)
			return rec(l, med, n-1, d);
		else
			return rec(med+(sz&1), r, n+1, d);
	}
	double findPoint(vector <int> data, int numerator, int denominator) {
		sort(data.begin(), data.end());
		D = data;
		const int div = gcd(numerator, denominator);
		num = numerator/div;
		denom = denominator/div;

		return rec(0, data.size(), 1, 2);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 2, 3, 5, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; double Arg3 = 3.0; verify_case(0, Arg3, findPoint(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {1, 2, 3, 6, 7, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 4; double Arg3 = 7.0; verify_case(1, Arg3, findPoint(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {7, 3, 1, 5, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 4; double Arg3 = 1.5; verify_case(2, Arg3, findPoint(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; double Arg3 = 7.0; verify_case(3, Arg3, findPoint(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {983, 126, 1078, -512, 1, 9876, -1234, 2387}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 8; double Arg3 = 63.5; verify_case(4, Arg3, findPoint(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    FractionPoints ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
