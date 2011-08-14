#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

struct Point {
	int x, y;
	Point(int x_, int y_): x(x_), y(y_) {}
};
int cross(const Point &a, const Point &b) {
	return a.x*b.y - b.x*a.y;
}
struct Line {
	Point a, b;
	Line(const Point &a_, const Point &b_): a(a_), b(b_) {}
};
int ccw(const Point &a, const Point &b, const Point &c) {
	const int t = cross(Point(b.x-a.x, b.y-a.y), Point(c.x-a.x, c.y-a.y));
	if (t < 0)
		return -1;
	else if (t > 0)
		return 1;
	else
		return 0;
}
bool on_line(const Point &p, const Line &l) {
	return ccw(l.a, l.b, p)==0 && ccw(p, Point(1001, 1001), l.a)*ccw(p, Point(1001, 1001), l.b)<=0;
}
bool intersects(const Line &l1, const Line &l2) {
	return ccw(l1.a, l1.b, l2.a)*ccw(l1.a, l1.b, l2.b) == -1 && ccw(l2.a, l2.b, l1.a)*ccw(l2.a, l2.b, l1.b) == -1;
}
class PointInPolygon {
	public:
	string testPoint(vector <string> vertices, int testPointX, int testPointY) {
		int cnt = 0;
		Point orig(testPointX, testPointY);
		Line test(orig, Point(orig.x+1, 1500));

		vector<Point> v;
		for (int i=0; i<(int)vertices.size(); ++i) {
			istringstream is(vertices[i]);
			int x, y;
			is >> x >> y;
			v.push_back(Point(x, y));
		}

		for (int i=0; i<(int)v.size(); ++i) {
			const Line l(v[i], v[(i+1)%v.size()]);
			if (on_line(orig, l))
				return "BOUNDARY";
			cnt += intersects(l, test);
		}

		return cnt%2==1 ? "INTERIOR":"EXTERIOR";
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"0 0",
 "0 10",
 "10 10",
 "10 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 5; string Arg3 = "INTERIOR"; verify_case(0, Arg3, testPoint(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"0 0",
 "0 10",
 "10 10",
 "10 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 15; string Arg3 = "EXTERIOR"; verify_case(1, Arg3, testPoint(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"0 0",
 "0 10",
 "10 10",
 "10 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 10; string Arg3 = "BOUNDARY"; verify_case(2, Arg3, testPoint(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"-100 -90", "-100 100","100 100", "100 -100",
 "-120 -100","-120 100","-130 100","-130 -110",
 "110 -110", "110 110", "-110 110","-110 -90"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 0; string Arg3 = "EXTERIOR"; verify_case(3, Arg3, testPoint(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"0 0","0 1000","1000 1000","1000 800",
 "200 800","200 600","600 600","600 400",
 "200 400","200 200","1000 200","1000 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; int Arg2 = 500; string Arg3 = "INTERIOR"; verify_case(4, Arg3, testPoint(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arr0[] = {"0 1000","1000 1000","1000 800",
 "200 800","200 600","600 600","600 400",
 "200 400","200 200","1000 200","1000 0","0 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 322; int Arg2 = 333; string Arg3 = "EXTERIOR"; verify_case(5, Arg3, testPoint(Arg0, Arg1, Arg2)); }
	void test_case_6() { string Arr0[] = {"500 0","500 100","400 100","400 200","300 200",
 "300 300","200 300","200 400","100 400","100 500",
 "0 500","0 400","-100 400","-100 300","-200 300",
  "-200 200","-300 200","-300 100","-400 100","-400 0",
  "-500 0","-500 -100","-400 -100","-400 -200","-300 -200",
  "-300 -300","-200 -300","-200 -400","-100 -400","-100 -500",
  "0 -500","0 -400","100 -400","100 -300","200 -300",
  "200 -200","300 -200","300 -100","400 -100","400 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 200; int Arg2 = 200; string Arg3 = "INTERIOR"; verify_case(6, Arg3, testPoint(Arg0, Arg1, Arg2)); }
	void test_case_7() { string Arr0[] = {"1 0","2 0","2 1","3 1","3 0","4 0","4 -1","5 -1","5 0",
 "6 0","6 2","0 2","0 3","-1 3","-1 4","0 4","0 6","1 6",
 "1 7","0 7","0 8","-2 8","-2 2","-8 2","-8 0","-7 0",
 "-7 -1","-6 -1","-6 0","-4 0","-4 1","-3 1","-3 0",
 "-2 0","-2 -6","0 -6","0 -5","1 -5","1 -4","0 -4",
 "0 -3","-1 -3","-1 -2","0 -2","0 -1","1 -1"} ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 0; string Arg3 = "INTERIOR"; verify_case(7, Arg3, testPoint(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    PointInPolygon ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
