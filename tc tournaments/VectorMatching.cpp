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

int N;
vector<int> x, y;
double sol;
double len(double x, double y) {
	return sqrt(x*x + y*y);
}
void go(int pos, int X, int Y, int cntP, int cntM) {
	if (pos == N) {
		sol = min(sol, len(X, Y));
		return;
	}
	if (cntP < N/2)
		go(pos+1, X+x[pos], Y+y[pos], cntP+1, cntM);
	if (cntM < N/2)
		go(pos+1, X-x[pos], Y-y[pos], cntP, cntM+1);
}
class VectorMatching {
	public:
	double minimumLength(vector <int> x_, vector <int> y_) {
		x = x_;
		y = y_;
		N = x.size();

		sol = 1e32;
		go(0, 0, 0, 0, 0);

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {-5, -5, 5, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-5, 5, 5, -5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.0; verify_case(0, Arg2, minimumLength(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {-100000, 100000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-100000, 100000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 282842.71247461904; verify_case(1, Arg2, minimumLength(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {26, 65, 78, 92, -60, -27, 42, -86, 92, -41}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-76, -83, 38, 22, -42, 85, 46, 98, -47, 38}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 13.341664064126334; verify_case(2, Arg2, minimumLength(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    VectorMatching ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
