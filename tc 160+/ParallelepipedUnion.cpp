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
	double x, y, z;
	Point(int x_, int y_, int z_, bool shift=true): x(x_+shift*0.5), y(y_+shift*0.5), z(z_+shift*0.5) {}
};
vector<Point> parse(const string &s) {
	istringstream is(s);
	int x1, y1, z1, x2, y2, z2;
	is >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
	vector<Point> ret;
	ret.push_back(Point(x1, y1, z1));
	ret.push_back(Point(x2, y2, z2));

	return ret;
}
bool inside(const Point &p, const vector<Point> &v) {
	return v[0].x<=p.x && p.x<=v[1].x && v[0].y<=p.y && p.y<=v[1].y && v[0].z<=p.z && p.z<=v[1].z;
}
class ParallelepipedUnion {
	public:
	int getVolume(vector <string> parallelepipeds) {
		vector<Point> a, b;
		a = parse(parallelepipeds[0]);
		b = parse(parallelepipeds[1]);

		int sol = 0;
		for (int x=1; x<=100; ++x)
			for (int y=1; y<=100; ++y)
				for (int z=1; z<=100; ++z)
					sol += (inside(Point(x, y, z, false), a) || inside(Point(x, y, z, false), b));

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"1 1 1 4 4 2", "3 2 1 5 3 3"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(0, Arg1, getVolume(Arg0)); }
	void test_case_1() { string Arr0[] = {"1 1 1 2 2 2", "3 3 3 4 4 4"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, getVolume(Arg0)); }
	void test_case_2() { string Arr0[] = {"1 10 20 5 15 23", "2 12 22 3 14 23"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 60; verify_case(2, Arg1, getVolume(Arg0)); }
	void test_case_3() { string Arr0[] = {"28 31 21 67 60 81","60 1 21 67 50 81"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 80460; verify_case(3, Arg1, getVolume(Arg0)); }
	void test_case_4() { string Arr0[] = {"34 3 50 37 6 53","36 1 51 38 4 55"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 49; verify_case(4, Arg1, getVolume(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ParallelepipedUnion ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
