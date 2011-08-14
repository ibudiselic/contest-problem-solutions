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

void reflect(int &x, int &y, const vector<int> &order, int a, int b) {
	for (int i=0; i<4; ++i)
		switch (order[i]) {
			case 0: y = -y; break;
			case 1: x = -x; break;
			case 2: y = 2*b - y; break;
			case 3: x = 2*a - x; break;
		}
}
double sqr(double x) { return x*x; }
double dist(int x0, int y0, int x1, int y1, const vector<int> &order, int a, int b) {
	reflect(x1, y1, order, a, b);

	return sqrt(sqr(x0-x1) + sqr(y0-y1));
}
class Polyline {
	public:
	double length(int a, int b, int x0, int y0, int x1, int y1) {
		vector<int> order;
		for (int i=0; i<4; ++i)
			order.push_back(i);

		double sol = 1e32;
		do {
			sol = min(sol, dist(x0, y0, x1, y1, order, a, b));
		} while (next_permutation(order.begin(), order.end()));

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 3; int Arg2 = 1; int Arg3 = 1; int Arg4 = 3; int Arg5 = 2; double Arg6 = 7.810249675906654; verify_case(0, Arg6, length(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 3; int Arg2 = 1; int Arg3 = 1; int Arg4 = 2; int Arg5 = 2; double Arg6 = 8.602325267042627; verify_case(1, Arg6, length(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 3; int Arg2 = 1; int Arg3 = 1; int Arg4 = 1; int Arg5 = 2; double Arg6 = 9.433981132056603; verify_case(2, Arg6, length(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_3() { int Arg0 = 50; int Arg1 = 70; int Arg2 = 20; int Arg3 = 40; int Arg4 = 20; int Arg5 = 40; double Arg6 = 172.04650534085255; verify_case(3, Arg6, length(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_4() { int Arg0 = 98; int Arg1 = 200; int Arg2 = 78; int Arg3 = 32; int Arg4 = 35; int Arg5 = 174; double Arg6 = 299.9549966244937; verify_case(4, Arg6, length(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Polyline ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
