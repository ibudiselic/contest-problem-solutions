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
typedef pair<double, double> Point;

bool cmp(const pair<double, double> &a, const pair<double, double> &b) {
	if (fabs(a.second-b.second)>1e-11)
		return a.second < b.second;
	else
		return a.first < b.first;
}
class ChipArea {
	public:
	double maxArea(int skip, int n) {
		vector<Point> v;
		int R = 1;
		for(int j = 0; j < skip; j++)
			R = 111 * R % 323537;
		for(int pt = 0; pt < n; pt++) {
   			R = 111*R%323537; double x = R/323537.0;
    		R = 111*R%323537; double y = R/323537.0;
    		v.push_back(Point(x, y));
    	}

		sort(v.begin(), v.end());
		double sol = 0.0;

		for (int i=0; i<n; ++i) {
			double yLow = 0;
			double yHigh = 1;
			const double xRight = v[i].first;
			int j;
			for (j=i-1; j>=0; --j) {
				sol = max(sol, (xRight-v[j].first)*(yHigh-yLow));
				if (v[j].second >= v[i].second-1e-11)
					yHigh = min(yHigh, v[j].second);
				if (v[j].second <= v[i].second+1e-11)
					yLow = max(yLow, v[j].second);
				if ((yHigh-yLow)*xRight < sol-1e-11)
					break;
			}
			if (j <= 0)
				sol = max(sol, xRight*(yHigh-yLow));

			yLow = 0;
			yHigh = 1;
			const double xLeft = v[i].first;
			for (j=i+1; j<n; ++j) {
				sol = max(sol, (v[j].first-xLeft)*(yHigh-yLow));
				if (v[j].second >= v[i].second-1e-11)
					yHigh = min(yHigh, v[j].second);
				if (v[j].second <= v[i].second+1e-11)
					yLow = max(yLow, v[j].second);
				if ((yHigh-yLow)*(1-xLeft) < sol-1e-11)
					break;
			}
			if (j >= n)
				sol = max(sol, (1-xLeft)*(yHigh-yLow));
		}

		if (n < 10000) {
		sort(v.begin(), v.end(), cmp);
		for (int i=0; i<n; ++i) {
			double yLow = 0;
			double yHigh = 1;
			const double xRight = v[i].second;
			int j;
			for (j=i-1; j>=0; --j) {
				sol = max(sol, (xRight-v[j].second)*(yHigh-yLow));
				if (v[j].first >= v[i].first-1e-11)
					yHigh = min(yHigh, v[j].first);
				if (v[j].first <= v[i].first+1e-11)
					yLow = max(yLow, v[j].first);
				if ((yHigh-yLow)*xRight < sol-1e-11)
					break;
			}
			if (j <= 0)
				sol = max(sol, xRight*(yHigh-yLow));

			yLow = 0;
			yHigh = 1;
			const double xLeft = v[i].second;
			for (j=i+1; j<n; ++j) {
				sol = max(sol, (v[j].second-xLeft)*(yHigh-yLow));
				if (v[j].first >= v[i].first-1e-11)
					yHigh = min(yHigh, v[j].first);
				if (v[j].first <= v[i].first+1e-11)
					yLow = max(yLow, v[j].first);
				if ((yHigh-yLow)*(1-xLeft) < sol-1e-11)
					break;
			}
			if (j >= n)
				sol = max(sol, (1-xLeft)*(yHigh-yLow));
		}
		}


		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 0; int Arg1 = 3; double Arg2 = 0.6058657896932963; verify_case(0, Arg2, maxArea(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 3; double Arg2 = 0.6885306552897291; verify_case(1, Arg2, maxArea(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 7995; int Arg1 = 25000; double Arg2 = 0.002543062783060902; verify_case(2, Arg2, maxArea(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 0; int Arg1 = 3000; double Arg2 = 0.0053171745173182395; verify_case(3, Arg2, maxArea(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 2657; int Arg1 = 2; double Arg2 = 0.4487007515408176; verify_case(4, Arg2, maxArea(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 12321; int Arg1 = 2; double Arg2 = 0.615729203993725; verify_case(5, Arg2, maxArea(Arg0, Arg1)); }
	void test_case_6() { int Arg0 = 15952; int Arg1 = 2; double Arg2 = 0.8629558001353441; verify_case(6, Arg2, maxArea(Arg0, Arg1)); }
	void test_case_7() { int Arg0 = 2215; int Arg1 = 3; double Arg2 = 0.8157487800137614; verify_case(7, Arg2, maxArea(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ChipArea ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
