#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>
#include <numeric>

using namespace std;

struct Point {
	double x, y;
	Point(double x_, double y_): x(x_), y(y_) {}
};
struct Line {
	double a, b, c;
	Line(const Point &p, const Point &q) {
		a = p.y - q.y;
		b = q.x - p.x;
		c = a*p.x + b*p.y;
	}
	Line(double a_, double b_, double c_): a(a_), b(b_), c(c_) {}
};
Line perpendicular_line(const Line &l, double x, double y) {
	return Line(l.b, -l.a, l.b*x - l.a*y);
}

double dist(double x, double y, double a, double b) {
	return sqrt((a-x)*(a-x) + (b-y)*(b-y));
}
double calc(double a, double b, const vector<int> &x, const vector<int> &y) {
	double ret = 0.0;
	for (int i=0; i<(int)x.size(); ++i)
		ret = max(ret, dist(a, b, x[i], y[i]));

	return ret;
}
class TVTower {
	public:
	double minRadius(vector <int> x, vector <int> y) {
		const int n = x.size();
		if (n == 1)
			return 0.0;

		double sol = 1e32;
		for (int i=0; i<n; ++i)
			for (int j=i+1; j<n; ++j)
				sol = min(sol, calc((x[i]+x[j])/2.0, (y[i]+y[j])/2.0, x, y));

		for (int i=0; i<n; ++i)
			for (int j=i+1; j<n; ++j)
				for (int k=j+1; k<n; ++k) {
					Line l1(Point(x[i], y[i]), Point(x[j], y[j]));
					Line l2(Point(x[j], y[j]), Point(x[k], y[k]));

					Line L1 = perpendicular_line(l1, (x[i]+x[j])/2.0, (y[i]+y[j])/2.0);
					Line L2 = perpendicular_line(l2, (x[j]+x[k])/2.0, (y[j]+y[k])/2.0);

					const double D = L1.a*L2.b - L1.b*L2.a;
					if (D == 0) continue;
					const double X = -(L1.b*L2.c - L1.c*L2.b)/D;
					const double Y = (L1.a*L2.c - L1.c*L2.a)/D;
					sol = min(sol, calc(X, Y, x, y));
				}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 0, -1, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, 0, -1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 1.0; verify_case(0, Arg2, minRadius(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {299}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.0; verify_case(1, Arg2, minRadius(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {5, 3, -4, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 4, 3, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 4.743416490252569; verify_case(2, Arg2, minRadius(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    TVTower ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
