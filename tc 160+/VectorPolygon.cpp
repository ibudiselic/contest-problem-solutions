#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <utility>
#include <cmath>

using namespace std;

typedef pair<int, int> Point;

inline int sgn(int x) {
	return (x==0 ? 0 : (x>0 ? 1 : -1));
}
inline int ccw(const Point &a, const Point &b) {
	return sgn(a.first*b.second - a.second*b.first);
}
inline int ccw(const Point &a, const Point &b, const Point &c) {
	return ccw(Point(a.first-b.first, a.second-b.second), Point(b.first-c.first, b.second-c.second));
}
double area(const vector<Point> &P) {
	int n = P.size();
	if (n == 1)
		return 0.0;

	double A = 0.0;
	for (int i=0; i<n; ++i)
		A += P[i].first*P[i+1].second - P[i].second*P[i+1].first;

	return fabs(A)/2;
}
void update(const vector<int> &dx, const vector<int> &dy, int n, const vector<int> &order, double &sol) {
	vector<Point> P;

	P.push_back(Point(0, 0));
	P.push_back(Point(dx[order[0]], dy[order[0]]));

	for (int i=1; i<n; ++i) {
		Point p(P.back().first + dx[order[i]], P.back().second + dy[order[i]]);
		if (ccw(p, P[i], P[i-1])>=0 && ccw(P[1], p, P[i])>=0) {
			P.push_back(p);
			if (p.first==0 && p.second==0)
				sol = max(sol, area(P));
		} else {
			break;
		}
	}
}
class VectorPolygon {
	public:
	double maxArea(vector <int> dx, vector <int> dy) {
		int n = dx.size();
		vector<int> order(n);
		for (int i=0; i<n; ++i)
			order[i] = i;

		double sol = 0.0;
		do {
			update(dx, dy, n, order, sol);
		} while (next_permutation(order.begin(), order.end()));

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2, 3, -5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, -4, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 7.0; verify_case(0, Arg2, maxArea(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {2, -3, -5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 4, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.0; verify_case(1, Arg2, maxArea(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {0, 0, 1, -1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, -1, 0, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 1.0; verify_case(2, Arg2, maxArea(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {25, 50, 75, 100, -25, -50, -75, -100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {100, 75, 50, 25, -100, -75, -50, -25}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 31250.0; verify_case(3, Arg2, maxArea(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.0; verify_case(4, Arg2, maxArea(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {1, -1, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, -1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.5; verify_case(5, Arg2, maxArea(Arg0, Arg1)); }
	void test_case_6() { int Arr0[] = {0, 1, 1, -2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, -1, -1, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 2.0; verify_case(6, Arg2, maxArea(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    VectorPolygon ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
