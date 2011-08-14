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

vector<int> x, y;
double dist(int i, int j) {
	return sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
}
double dp[52];
int init;
double calc(int start) {
	if (start==(int)x.size()-2 && init==1)
		return dist(start, 1);
	if (start+2 >= (int)x.size())
		return 0.0;
	if (dp[start] > -0.5)
		return dp[start];

	double ret = dist(start, start+2);

	ret += max(calc(start+2), calc(start+3));
	return dp[start] = max(ret, calc(start+1));
}
class PolyMove {
	public:
	double addedArea(vector <int> x_, vector <int> y_) {
		x = x_;
		y = y_;
		x.push_back(x[0]);
		y.push_back(y[0]);
		for (int i=0; i<52; ++i)
			dp[i] = -1.0;
		double a = calc(init = 0);
		for (int i=0; i<52; ++i)
			dp[i] = -1.0;
		double b = calc(init = 1);
		return max(a, b)/2;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 1.0; verify_case(0, Arg2, addedArea(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {0,1,1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,1,0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 1.4142135623730951; verify_case(1, Arg2, addedArea(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    PolyMove ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
