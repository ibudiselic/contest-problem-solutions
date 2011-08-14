#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <set>

using namespace std;

struct Point {
	int x, y, z;
	Point(int x_, int y_, int z_): x(x_), y(y_), z(z_) {}
};
bool operator<(const Point &a, const Point &b) {
	if (a.x != b.x)
		return a.x < b.x;
	else if (a.y != b.y)
		return a.y < b.y;
	else
		return a.z < b.z;
}

int minSqrDist;

int nextPoint(int &seed, int range) {
	const int ret = (seed * 16807LL) % ((1LL<<31)-1);
	seed = ret;

	return ret%(2*range) - range;
}

long long sqr(long long x) {
	return x * x;
}
long long distSqr(const Point &a, const Point &b) {
	return sqr(a.x-b.x) + sqr(a.y-b.y) + sqr(a.z-b.z);
}
vector<int> go(const vector<Point> &);
vector<int> goX(const vector<Point> &points) {
	int minx=1234567890, maxx=-1234567890;

	for (int i=0; i<(int)points.size(); ++i) {
		minx = min(minx, points[i].x);
		maxx = max(maxx, points[i].x);
	}

	int mid = minx + (maxx-minx)/2;

	vector<Point> p1, p2;
	for (int i=0; i<(int)points.size(); ++i)
		if (points[i].x <= mid)
			p1.push_back(points[i]);
		else
			p2.push_back(points[i]);

	vector<int> r1, r2;

	r1 = go(p1);
	r2 = go(p2);

	int d = min(r1[0], r2[0]);
	minSqrDist = min(minSqrDist, d);

	d = minSqrDist;
	int cnt = 0;
	if (d == r1[0])
		cnt += r1[1];
	if (d == r2[0])
		cnt += r2[1];

	vector<Point> a1, a2;
	for (int i=0; i<(int)p1.size(); ++i)
		if (sqr(mid-p1[i].x) <= d)
			a1.push_back(p1[i]);

	for (int i=0; i<(int)p2.size(); ++i)
		if (sqr(p2[i].x-mid) <= d)
			a2.push_back(p2[i]);

	for (int i=0; i<(int)a1.size(); ++i)
		for (int j=0; j<(int)a2.size(); ++j) {
			long long cur = distSqr(a1[i], a2[j]);

			if (cur < d) {
				d = cur;
				cnt = 0;
			}
			cnt += (cur == d);
		}

	minSqrDist = d;

	vector<int> ret(2, 0);
	ret[0] = d;
	ret[1] = cnt;

	return ret;
}

vector<int> goZ(vector<Point> points) {
	for (int i=0; i<(int)points.size(); ++i)
		swap(points[i].x, points[i].z);

	return goX(points);
}
vector<int> goY(vector<Point> points) {
	for (int i=0; i<(int)points.size(); ++i)
		swap(points[i].x, points[i].y);

	return goX(points);
}
vector<int> go(const vector<Point> &points) {
	if (points.size() < 500) {
		int d = 1234567890;
		int cnt = 0;

		for (int i=0; i<(int)points.size(); ++i)
			for (int j=i+1; j<(int)points.size(); ++j) {
				long long cur = distSqr(points[i], points[j]);

				if (cur < d) {
					d = cur;
					cnt = 0;
				}
				cnt += (d == cur);
			}

		vector<int> ret(2, 0);
		ret[0] = d;
		ret[1] = cnt;

		return ret;
	} else {
		int maxx, maxy, maxz, minx, miny, minz;

		maxx = maxy = maxz = -1234567890;
		minx = miny = minz = 1234567890;

		for (int i=0; i<(int)points.size(); ++i) {
			maxx = max(maxx, points[i].x);
			maxy = max(maxy, points[i].y);
			maxz = max(maxz, points[i].z);

			minx = min(minx, points[i].x);
			miny = min(miny, points[i].y);
			minz = min(minz, points[i].z);
		}

		const int dx = maxx-minx;
		const int dy = maxy-miny;
		const int dz = maxz-minz;

		if (dx>=dy && dx>=dz)
			return goX(points);
		else if (dy >= dz)
			return goY(points);
		else
			return goZ(points);
	}
}
class ClosestPoints {
	public:
	vector <int> distance(int N, int range, int seed) {
		set<Point> uniquePoints;

		for (int i=0; i<N; ++i) {
			int x, y, z;
			x = nextPoint(seed, range);
			y = nextPoint(seed, range);
			z = nextPoint(seed, range);
			uniquePoints.insert(Point(x, y, z));
		}


		vector<Point> points(uniquePoints.begin(), uniquePoints.end());
		minSqrDist = 1234567890;

		return go(points);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 100; int Arg2 = 1; int Arr3[] = { 9163,  1 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(0, Arg3, distance(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 10000; int Arg1 = 1; int Arg2 = 7; int Arr3[] = { 1,  12 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(1, Arg3, distance(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 25; int Arg1 = 1; int Arg2 = 12; int Arr3[] = { 1,  9 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(2, Arg3, distance(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 15; int Arg1 = 5; int Arg2 = 504; int Arr3[] = { 5,  2 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(3, Arg3, distance(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 50000; int Arg1 = 1000000; int Arg2 = 75; int Arr3[] = { 1252249,  1 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(4, Arg3, distance(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ClosestPoints ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
