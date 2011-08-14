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
	int x, y;
	Point(int x_, int y_): x(x_), y(y_) {}
};
Point operator-(const Point &a, const Point &b) {
	return Point(a.x-b.x, a.y-b.y);
}
int cross(const Point &a, const Point &b) {
	return a.x*b.y - a.y*b.x;
}
int sgn(int x) {
	return (x==0 ? 0 : (x>0 ? +1 : -1));
}
int ccw(const Point &a, const Point &b, const Point &c) {
	return sgn(cross(b-a, c-a));
}
struct dPoint {
	double x, y;
	dPoint(double x_=0, double y_=0): x(x_), y(y_) {}
};
struct Circle {
	double r;
	dPoint center;
	Circle(double r_, const dPoint &center_): r(r_), center(center_) {}
};
double sqr(double x) {
	return x*x;
}
double dist(const dPoint &a, const dPoint &b) {
	return sqrt(sqr(a.x-b.x) + sqr(a.y-b.y));
}
bool operator==(const Circle &a, const Circle &b) {
	if (fabs(a.r - b.r) > 1e-5)
		return false;
	return (dist(a.center, b.center) <= 1e-6);
}
bool operator<(const Circle &a, const Circle &b) {
	double eps = 1e-5;
	if (fabs(a.r - b.r) > eps)
		return a.r < b.r;
	else if (fabs(a.center.x - b.center.x) > eps)
		return a.center.x < b.center.x;
	else
		return a.center.y < b.center.y;
}
vector<int> x, y;
bool isVertical(const Point &a) {
	return (a.x == 0);
}
double koef(const Point &a) {
	return double(a.y)/a.x;
}

void testAddCircle(vector<int> ind, vector<Circle> &v) {
#define PT(name, t) Point name(x[(t)], y[(t)])
	PT(aa, ind[0]);
	PT(bb, ind[1]);
	PT(cc, ind[2]);
	if (ccw(aa, bb, cc) == 0)
		return;

	do {
		PT(a, ind[0]);
		PT(b, ind[1]);
		PT(c, ind[2]);
		if (!isVertical(b-a) && !isVertical(c-b))
			break;
	} while (next_permutation(ind.begin(), ind.end()));

	PT(a, ind[0]);
	PT(b, ind[1]);
	PT(c, ind[2]);
#undef PT
	assert(!isVertical(b-a) && !isVertical(c-b));

	double k1 = koef(b-a);
	double k2 = koef(c-b);

	dPoint center;
	center.x = (k1*k2*(a.y-c.y) + k2*(a.x+b.x) - k1*(b.x+c.x))/2/(k2-k1);

	if (fabs(k1) > fabs(k2))
		center.y = -1.0/k1 * (center.x - double(a.x+b.x)/2) + double(a.y+b.y)/2;
	else
		center.y = -1.0/k2 * (center.x - double(c.x+b.x)/2) + double(c.y+b.y)/2;

	Circle circ(dist(center, dPoint(a.x, a.y)), center);
	v.push_back(circ);
}

class CropCircles {
	public:
	int countCircles(vector <int> x_, vector <int> y_) {
		x = x_;
		y = y_;

		vector<Circle> v;
		int n = x.size();
		vector<int> ind;
		for (int i=0; i<n; ++i) {
			ind.push_back(i);
			for (int j=i+1; j<n; ++j) {
				ind.push_back(j);
				for (int k=j+1; k<n; ++k) {
					ind.push_back(k);
					testAddCircle(ind, v);
					ind.pop_back();
				}
				ind.pop_back();
			}
			ind.pop_back();
		}

		sort(v.begin(), v.end());
		return unique(v.begin(), v.end())-v.begin();
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 2, 1, 2, 8}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 1, 8, 9, 9}
; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(0, Arg2, countCircles(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {0, 4, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3, 3, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(1, Arg2, countCircles(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {0, 10, 10, 10, 20}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10, 0, 10, 20, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(2, Arg2, countCircles(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {0, 10, 11, 10, 21}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10, 0, 11, 20, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10; verify_case(3, Arg2, countCircles(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    CropCircles ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
