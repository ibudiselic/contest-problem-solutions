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

/* ne radi... */

struct Point {
	double x, y;
	Point(double x_, double y_): x(x_), y(y_) {}
};
struct Line {
	Point a, b;
	Line(const Point &a_, const Point &b_): a(a_), b(b_) {}
};
Point operator-(const Point &a, const Point &b) {
	return Point(a.x-b.x, a.y-b.y);
}
int ccw(const Point &a, const Point &b) {
	double cross = a.x*b.y - a.y*b.x;
	if (fabs(cross) <= 1e-9)
		return 0;
	else
		return (cross > 0 ? 1 : -1);
}
int ccw(const Point &a, const Point &b, const Point &c) {
	return ccw(a-c, b-c);
}
bool intersects(const Line &l1, const Line &l2) {
	int ccw1 = ccw(l1.b, l2.a, l1.a);
	int ccw2 = ccw(l1.b, l2.b, l1.a);

	if (ccw1*ccw2 == 1)
		return false;

	ccw1 = ccw(l2.b, l1.a, l2.a);
	ccw2 = ccw(l2.b, l1.b, l2.a);

	if (ccw1*ccw2 == 1)
		return false;

	return true;
}
Point intersectionPoint(const Line &l1, const Line &l2) {
	assert(intersects(l1, l2));

	double A1 = l1.a.y-l1.b.y;
	double B1 = l1.b.x-l1.a.x;
	double C1 = l1.b.x*l1.a.y - l1.a.x*l1.b.y;

	double A2 = l2.a.y-l2.b.y;
	double B2 = l2.b.x-l2.a.x;
	double C2 = l2.b.x*l2.a.y - l2.a.x*l2.b.y;

	double det = A1*B2 - A2*B1;

	return Point((C1*B2 - C2*B1)/det, (A1*C2 - A2*C1)/det);
}
void parse(const vector<string> &poly, vector<Point> &p) {
	for (int i=0; i<(int)poly.size(); ++i) {
		double x, y;
		sscanf(poly[i].c_str(), "%lf %lf", &x, &y);
		p.push_back(Point(x, y));
	}
}
bool insidePoly(const Point &p, const vector<Point> &poly) {
	const Point q(p.x+20001, p.y+1);
	Line testLine(p, q);

	int cntIntersect = 0;
	for (int i=0; i+1<(int)poly.size(); ++i)
		cntIntersect += intersects(testLine, Line(poly[i], poly[i+1]));

	return cntIntersect%2 == 1;
}
double sqr(double x) { return x*x; }
double dist(const Point &a, const Point &b) {
	return sqrt(sqr(a.x-b.x) + sqr(a.y-b.y));
}
class ConvexPolygons {
	public:
	double overlap(vector <string> polygon1, vector <string> polygon2) {
		vector<Point> p1, p2;
		parse(polygon1, p1);
		parse(polygon2, p2);

		p1.push_back(p1[0]);
		p2.push_back(p2[0]);

		vector<Point> intersectPoly;
		for (int i=0; i+1<(int)p1.size(); ++i)
			for (int j=0; j+1<(int)p2.size(); ++j)
				if (intersects(Line(p1[i], p1[i+1]), Line(p2[j], p2[j+1])))
					intersectPoly.push_back(intersectionPoint(Line(p1[i], p1[i+1]), Line(p2[j], p2[j+1])));

		for (int i=0; i+1<(int)p1.size(); ++i)
			if (insidePoly(p1[i], p2))
				intersectPoly.push_back(p1[i]);

		for (int i=0; i+1<(int)p2.size(); ++i)
			if (insidePoly(p2[i], p1))
				intersectPoly.push_back(p2[i]);

		if (intersectPoly.size() == 0)
			return 0.0;

		double minx = 1e32;
		int p = -1;
		for (int i=0; i<(int)intersectPoly.size(); ++i)
			if (intersectPoly[i].x < minx-1e-9) {
				p = i;
				minx = intersectPoly[i].x;
			}

		vector<int> convexHull;
		convexHull.push_back(p);
		int q = p;
		int t = 0;
		do {
			int next = -1;
			for (int cand=0; cand<(int)intersectPoly.size(); ++cand)
				if (cand != q)
					if (next==-1 || ((t = ccw(intersectPoly[next], intersectPoly[cand], intersectPoly[q]))<0 || t==0 && dist(intersectPoly[next], intersectPoly[q])<dist(intersectPoly[cand], intersectPoly[q])))
						next = cand;

			convexHull.push_back(q = next);
		} while (q != p);

		double area = 0.0;
		for (int i=0; i+1<(int)convexHull.size(); ++i)
			area += intersectPoly[convexHull[i]].x*intersectPoly[convexHull[i+1]].y - intersectPoly[convexHull[i]].y*intersectPoly[convexHull[i+1]].x;

		return fabs(area/2);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"00 00","02 00","00 03"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1 1","3 1","3 3", "1 3"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.08333333333333326; verify_case(0, Arg2, overlap(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"-1 -1","1 -1","1 1","-1 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"-2 -2","0 -2","2 -2","2 0","2 2","0 2","-2 2","-2 0"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 4.0; verify_case(1, Arg2, overlap(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"-1 -1","-2 -1","-1 -2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1 1","2 1","1 2"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.0; verify_case(2, Arg2, overlap(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"-2 0","-1 -2","1 -2","2 0","1 2","-1 2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0 -3","1 -1","2 2","-1 0"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 5.233333333333333; verify_case(3, Arg2, overlap(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ConvexPolygons ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
