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

double sqr(double x) { return x*x; }
double dist(double x1, double y1, double x2, double y2) {
	return sqrt(sqr(x1-x2) + sqr(y1-y2));
}
class Meteorites {
	public:
	double perimeter(vector <int> x, vector <int> y, vector <int> r) {
		double sol = 0.0;

		for (int i=0; i<(int)x.size(); ++i) {
			vector< pair<double, int> > covered;
			double contrib = 2*M_PI;
			double last = 0.0;
			int cntInt = 0;

			for (int j=0; j<(int)x.size(); ++j)
				if (i != j) {
					const double d = dist(x[i], y[i], x[j], y[j]);
					if (r[i]+r[j] > d) {
						if (r[i] >= d+r[j])
							continue;
						if (r[j] >= d+r[i])
							goto NEXT;

						double ang = atan2(y[j]-y[i], x[j]-x[i]) + 2*M_PI;
						if (ang >= 2*M_PI)
							ang -= 2*M_PI;

						double phi = acos((sqr(r[i]) + sqr(d) - sqr(r[j]))/(2*r[i]*d));
						double alpha = ang-phi;
						if (alpha < 0)
							alpha += 2*M_PI;
						double beta = ang+phi;
						if (beta > 2*M_PI)
							beta -= 2*M_PI;

						if (alpha > beta) {
							covered.push_back(make_pair(0, +1));
							covered.push_back(make_pair(beta, -1));
							covered.push_back(make_pair(alpha, +1));
							covered.push_back(make_pair(2*M_PI, -1));
						} else {
							covered.push_back(make_pair(alpha, +1));
							covered.push_back(make_pair(beta, -1));
						}
					}
				}
			sort(covered.begin(), covered.end());
			for (int j=0; j<(int)covered.size(); ++j) {
				if (cntInt == 0)
					last = covered[j].first;
				cntInt += covered[j].second;
				if (cntInt == 0)
					contrib -= covered[j].first - last;
			}

			sol += contrib * r[i];
			NEXT:;
		}
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {6,7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 63.72326520248748; verify_case(0, Arg3, perimeter(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {-10,-10,-10,0,0,0,10,10,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-10,0,10,-10,0,10,-10,0,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {7,7,7,7,7,7,7,7,7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 135.3757009200326; verify_case(1, Arg3, perimeter(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {-100,100,100,-100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-100,-100,100,100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {110,110,110,110}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 2008.3301227325105; verify_case(2, Arg3, perimeter(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {0,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0,0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,3,100000}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 628318.5307179586; verify_case(3, Arg3, perimeter(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Meteorites ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
