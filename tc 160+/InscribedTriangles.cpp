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

double rad(double deg) {
	deg /= 1000;
	return acos(-1)*deg/180;
}
bool test(double ang, const vector<int> &l, const vector<int> &r) {
	if (ang > 360000)
		ang -= 360000;

	bool ok = false;
	for (int i=0; i<(int)l.size(); ++i)
		if (l[i]<=ang && ang<=r[i]) {
			ok = true;
			break;
		}
	return ok;
}
double calc(double ang1, double ang2, double ang3) {
	if (ang3 > 360000)
		ang3 -= 360000;

	double x1 = 5 * sin(rad(ang1));
	double x2 = 5 * sin(rad(ang2));
	double x3 = 5 * sin(rad(ang3));
	double y1 = 5 * cos(rad(ang1));
	double y2 = 5 * cos(rad(ang2));
	double y3 = 5 * cos(rad(ang3));

	return 0.5 * fabs(x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2));
}
class InscribedTriangles {
	public:
	double findLargest(vector <int> angleFrom, vector <int> angleTo) {
		const int n = angleFrom.size();
		double sol = 0.0;
		for (int i=0; i<n; ++i) {
			int ang1 = angleFrom[i];
			if (test(ang1+120000, angleFrom, angleTo) && test(ang1+240000, angleFrom, angleTo))
				return 3*sqrt(3)/4*25;
			ang1 = angleTo[i];
			if (test(ang1+120000, angleFrom, angleTo) && test(ang1+240000, angleFrom, angleTo))
				return 3*sqrt(3)/4*25;
		}

		for (int i=0; i<n; ++i)
			for (int t=0; t<2; ++t) {
				int ang1 = (t==0 ? angleFrom[i] : angleTo[i]);
				for (int j=i; j<n; ++j)
					for (int v=0; v<2; ++v) {
						int ang2 = (v==0 ? angleFrom[j] : angleTo[j]);
						if (test(double(ang1+ang2)/2, angleFrom, angleTo))
							sol = max(sol, calc(ang1, ang2, double(ang1+ang2)/2));
						if (test(double(ang1+ang2)/2+180000, angleFrom, angleTo))
							sol = max(sol, calc(ang1, ang2, double(ang1+ang2)/2 + 180000));
					}
			}
		for (int i=0; i<n; ++i)
			for (int j=0; j<n; ++j)
				for (int k=0; k<n; ++k) {
					sol = max(sol, calc(angleFrom[i], angleFrom[j], angleFrom[k]));
					sol = max(sol, calc(angleFrom[i], angleFrom[j], angleTo[k]));
					sol = max(sol, calc(angleFrom[i], angleTo[j], angleFrom[k]));
					sol = max(sol, calc(angleFrom[i], angleTo[j], angleTo[k]));
					sol = max(sol, calc(angleTo[i], angleFrom[j], angleFrom[k]));
					sol = max(sol, calc(angleTo[i], angleFrom[j], angleTo[k]));
					sol = max(sol, calc(angleTo[i], angleTo[j], angleFrom[k]));
					sol = max(sol, calc(angleTo[i], angleTo[j], angleTo[k]));
				}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {360000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 32.47595264191645; verify_case(0, Arg2, findLargest(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {15000,25000,100000,265000,330000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {15000,25000,100000,265000,330000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 27.433829549752186; verify_case(1, Arg2, findLargest(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {245900,246500,249900}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {245915,246611,252901}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.002789909594714814; verify_case(2, Arg2, findLargest(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {42}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {42}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.0; verify_case(3, Arg2, findLargest(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    InscribedTriangles ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
