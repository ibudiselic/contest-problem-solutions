#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <utility>

using namespace std;

typedef pair<int, int> point;

int x1, y1, x2, y2;
vector<point> v;
int n, W, H;

void upd(int xl, int yl, int xr, int yr) {

	int a1 = (x2-x1)*(y2-y1);
	int a2 = (xr-xl)*(yr-yl);

	if (a2>a1 || (a2==a1 && yl<y1) || (a2==a1 && yl==y1 && xl<x1) || (a2==a1 && yl==y1 && xl==x1 && (xr-xl)>(x2-x1))) {
		x1 = xl;
		x2 = xr;
		y1 = yl;
		y2 = yr;
	}
}
void update(int xl, int xr) {
	if (xl >= xr)
		return;

	vector<int> y;
	y.push_back(-1);
	y.push_back(H);

	for (int i=0; i<n; ++i)
		if (xl<=v[i].first && v[i].first<xr)
			y.push_back(v[i].second);

	sort(y.begin(), y.end());
	y.erase(unique(y.begin(), y.end()), y.end());
	for (int i=1; i<(int)y.size(); ++i)
		upd(xl, y[i-1]+1, xr, y[i]);
}
class SensorGrid {
	public:
	vector <int> largestRectangle(int width, int height, vector <int> x, vector <int> y) {
		v.clear();
		n = x.size();
		W = width;
		H = height;
		for (int i=0; i<n; ++i)
			v.push_back(point(x[i], y[i]));

		sort(v.begin(), v.end());

		x1 = y1 = x2 = y2 = 0;

		update(0, W);
		for (int i=0; i<n; ++i) {
			update(0, v[i].first);
			update(v[i].first+1, W);
		}
		for (int i=0; i<n-1; ++i)
			for (int j=i+1; j<n; ++j)
				update(v[i].first+1, v[j].first);

		vector<int> sol;
		sol.push_back(x1);
		sol.push_back(y1);
		sol.push_back(x2-x1);
		sol.push_back(y2-y1);

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 9; int Arg1 = 7; int Arr2[] = { 1, 5, 1, 5, 3, 7, 3, 7 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = { 0, 0, 2, 2, 4, 4, 6, 6 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = { 2,  0,  3,  4 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(0, Arg4, largestRectangle(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 6; int Arg1 = 5; int Arr2[] = { 5, 4 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = { 2, 4 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = { 0,  0,  5,  4 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(1, Arg4, largestRectangle(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 17; int Arg1 = 16; int Arr2[] = { 1, 3, 5, 7, 11, 13, 15,
  1, 3, 5, 7, 11, 13, 15,
  1, 3, 5, 7, 11, 13, 15,
  1, 3, 5, 7, 11, 13, 15,
  1, 3, 5, 7, 11, 13, 15,
  1, 3, 5, 7, 11, 13, 15,
  1, 3, 5, 7, 11, 13, 15 }
; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = { 1, 1, 1, 1, 1, 1, 1,
  3, 3, 3, 3, 3, 3, 3,
  5, 5, 5, 5, 5, 5, 5,
  7, 7, 7, 7, 7, 7, 7,
  10, 10, 10, 10, 10, 10, 10,
  12, 12, 12, 12, 12, 12, 12,
  14, 14, 14, 14, 14, 14, 14 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = { 8,  0,  3,  16 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(2, Arg4, largestRectangle(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    SensorGrid ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
