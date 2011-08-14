#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;

int my_round(double x) {
	int ret = int(x + 1e-11);
	if (int(x*10 + 1e-10)%10 >= 5)
		++ret;
	return ret;
}
class Display {
	public:
	vector <string> transform(vector <int> x, vector <int> y) {
		int mx = *min_element(x.begin(), x.end());
		int my = *min_element(y.begin(), y.end());

		for (int i=0; i<(int)x.size(); ++i) {
			x[i] -= mx;
			y[i] -= my;
		}
		int Mx = *max_element(x.begin(), x.end());
		int My = *max_element(y.begin(), y.end());
		const double fx = 1000.0/Mx;
		const double fy = 1000.0/My;
		for (int i=0; i<(int)x.size(); ++i) {
			x[i] = (int)my_round(x[i]*fx);
			y[i] = (int)my_round(y[i]*fy);
		}

		vector<string> sol;
		for (int i=0; i<(int)x.size(); ++i) {
			ostringstream os;
			os << x[i] << ' ' << y[i];
			sol.push_back(os.str());
		}
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {-100, 0, 50, 100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-100, 0, 50, 100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "0 0",  "500 500",  "750 750",  "1000 1000" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, transform(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {0,2000,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,2001,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "0 0",  "1000 1000",  "1 0" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, transform(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {-1000000000,1000000000,500000,499999}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1000000000,1000000000,500000,499999}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "0 0",  "1000 1000",  "500 500",  "500 500" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, transform(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {-53,652,-6132,673,74,-473,373,736363,234,234,234}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-6464,36464,-43,373,363,-37633,2022,-644,2520,2520,2520}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "8 421",  "9 1000",  "0 507",  "9 513",  "8 513",  "8 0",  "9 535",  "1000 499",  "9 542",  "9 542",  "9 542" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, transform(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {0,1001,2000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,999,2000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "0 0",  "501 500",  "1000 1000" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, transform(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Display ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
