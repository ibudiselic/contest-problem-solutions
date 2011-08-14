#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>
#include <set>

using namespace std;

/*(g * k) % n, for k = 0, 1, 2, ..., c-1*/
struct point {
	double x, y;
	point(double x_, double y_): x(x_), y(y_) {}
};
vector<point> v;
double cross(const point &a, const point &b) {
	return a.x*b.y - a.y*b.x;
}
double A(int i, int j, int k) {
	return fabs(cross(point(v[j].x-v[i].x, v[j].y-v[i].y), point(v[k].x-v[i].x, v[k].y-v[i].y)))/2;
}
class QuadrilateralSearch {
	public:
	double findLargest(int d, int n, int c, int g) {
		set<int> ind_;
		for (int i=0; i<c; ++i)
			ind_.insert(((long long)g * i) % n);

		vector<int> ind(ind_.begin(), ind_.end());

		v.clear();
		long double fact = 2*M_PI/n;

		for (int i=0; i<(int)ind.size(); ++i)
			v.push_back(point(d * cos(fact*ind[i])/2, d * sin(fact*ind[i])/2));

		double sol = 0.0;
		for (int i=0; i<(int)ind.size(); ++i)
			for (int j=i+2; j<(int)ind.size() - (i==0); ++j) {
				int l = i+1;
				int r = j-1;

				while (r-l > 10) {
					int mid1 = l + (r-l)/3;
					int mid2 = mid1 + (r-l)/3;

					if (A(i, j, mid1) > A(i, j, mid2))
						r = mid2;
					else
						l = mid1;
				}

				double best1 = 0.0;
				for (int t=l; t<=r; ++t)
					best1 = max(best1, A(i, j, t));

				int offset = (j+1)%ind.size();
				l = 0;
				r = (i-1-offset+2*ind.size())%ind.size();
				while (r-l > 10) {
					int mid1 = l + (r-l)/3;
					int mid2 = mid1 + (r-l)/3;

					if (A(i, j, (mid1+offset)%ind.size()) > A(i, j, (mid2+offset)%ind.size()))
						r = mid2;
					else
						l = mid1;
				}

				double best2 = 0.0;
				for (int t=l; t<=r; ++t)
					best2 = max(best2, A(i, j, (t+offset)%ind.size()));

				sol = max(sol, best1+best2);
			}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arg1 = 13; int Arg2 = 4; int Arg3 = 3; double Arg4 = 48.9142858122447; verify_case(0, Arg4, findLargest(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 20; int Arg1 = 31; int Arg2 = 6; int Arg3 = 5; double Arg4 = 179.10027343916573; verify_case(1, Arg4, findLargest(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 1000; int Arg1 = 80000; int Arg2 = 50; int Arg3 = 3; double Arg4 = 0.028489712517284715; verify_case(2, Arg4, findLargest(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 100; int Arg1 = 1200; int Arg2 = 20; int Arg3 = 139; double Arg4 = 4965.195939678256; verify_case(3, Arg4, findLargest(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    QuadrilateralSearch ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
