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

struct Point {
	long long x, y;
	Point(int x_, int y_): x(x_), y(y_) {}
};
Point operator-(const Point &a, const Point &b) {
	return Point(a.x-b.x, a.y-b.y);
}

int sgn(long long x) {
	assert(x != 0);
	return x>0 ? 1 : -1;
}
int ccw(const Point &a, const Point &b) {
	long long val = a.x*b.y - a.y*b.x;

	if (val == 0)
		return 0;
	else
		return sgn(val);
}

class CultureGrowth {
	public:
	double finalTray(vector <int> xs, vector <int> ys) {
		vector<int> convexHull;

		vector<Point> v;
		int n = xs.size();
		long long minx = 1234567;
		for (int i=0; i<n; ++i) {
			v.push_back(Point(xs[i], ys[i]));
			minx = min(minx, (long long)xs[i]);
		}

		int p;
		for (p=0; v[p].x != minx; ++p)
			;

		convexHull.push_back(p);
		int q = p;
		do {
			int next = -1;
			for (int cand=0; cand<n; ++cand)
				if (cand != q)
					if (next==-1 || ccw(v[next]-v[q], v[cand]-v[q])==-1)
						next = cand;
			convexHull.push_back(q = next);
		} while (q != p);

		double area = 0.0;
		for (int i=0; i+1<(int)convexHull.size(); ++i)
			area += v[convexHull[i]].x*v[convexHull[i+1]].y - v[convexHull[i+1]].x*v[convexHull[i]].y;

		return fabs(area/2);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0, 3, 6, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 3, 6, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.0; verify_case(0, Arg2, finalTray(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {240}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.0; verify_case(1, Arg2, finalTray(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {10,15,3,37}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {49,49,12,8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 745.5; verify_case(2, Arg2, finalTray(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    CultureGrowth ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
