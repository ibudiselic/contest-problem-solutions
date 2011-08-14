#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

double calc(double pos, const vector<int> &x, const vector<int> &h) {
	double ret = 0.0;
	for (int i=1; i<(int)x.size(); ++i)
		ret = max(ret, h[i-1] + (pos-x[i-1]) * (h[i]-h[i-1])/(x[i]-x[i-1]));

	return ret;
}
class WatchTower {
	public:
	double minHeight(vector <int> positions, vector <int> heights) {
		double sol = 1e32;

		for (int i=1; i<(int)positions.size(); ++i) {
			double lo = positions[i-1];
			double hi = positions[i];

			for (int iter=0; iter<1000; ++iter) {
				double m1 = lo + (hi-lo)/3;
				double m2 = m1 + (hi-lo)/3;

				if (calc(m1, positions, heights) - (heights[i-1] + (m1-positions[i-1]) * (heights[i]-heights[i-1])/(positions[i]-positions[i-1]))
					<
					calc(m2, positions, heights) - (heights[i-1] + (m2-positions[i-1]) * (heights[i]-heights[i-1])/(positions[i]-positions[i-1])))
					hi = m2;
				else
					lo = m1;
			}
			sol = min(sol, calc((lo+hi)/2, positions, heights) - (heights[i-1] + ((lo+hi)/2-positions[i-1]) * (heights[i]-heights[i-1])/(positions[i]-positions[i-1])));
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 1,2,4,5,6,7 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 1,2,2,4,2,1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 1.0; verify_case(0, Arg2, minHeight(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = { 10,20,49,59 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 0,10,10,0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 14.5; verify_case(1, Arg2, minHeight(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = { 0,2,4,6,8,10 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 0,1,3,6,10,11 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.0; verify_case(2, Arg2, minHeight(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    WatchTower ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
