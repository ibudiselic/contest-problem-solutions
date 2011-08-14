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

inline int sqrDist(int x1, int y1, int x2, int y2) {
	return (x1-x2)*(x1-x2) + (y2-y1)*(y2-y1);
}
inline bool inside(int i, int j, const vector<int> &x, const vector<int> &y, const vector<int> &r) {
	return sqrDist(x[i], y[i], x[j], y[j]) <= r[j]*r[j];
}

class BlackWhitePlane {
	public:
	double area(vector <string> circles) {
		int n = circles.size();
		vector<int> x(n), y(n), r(n);
		for (int i=0; i<n; ++i)
			sscanf(circles[i].c_str(), "%d %d %d", &x[i], &y[i], &r[i]);
		for (int i=0; i<n; ++i)
			for (int j=i+1; j<n; ++j)
				if (r[i] < r[j]) {
					swap(r[i], r[j]);
					swap(x[i], x[j]);
					swap(y[i], y[j]);
				}

		vector<bool> isWhite(n, false);

		double sol = 0;
		for (int i=0; i<n; ++i) {
			for (int j=i-1; j>=0; --j)
				if (inside(i, j, x, y, r)) {
					if (isWhite[j]) {
						isWhite[i] = false;
						sol -= r[i]*r[i] * M_PI;
					} else {
						isWhite[i] = true;
						sol += r[i]*r[i] * M_PI;
					}
					goto SKIP;
				}
			isWhite[i] = true;
			sol += r[i]*r[i] * M_PI;
			SKIP: ;
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"1 1 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 3.141592653589793; verify_case(0, Arg1, area(Arg0)); }
	void test_case_1() { string Arr0[] = {"4 3 1", "3 2 3", "8 1 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 28.274333882308138; verify_case(1, Arg1, area(Arg0)); }
	void test_case_2() { string Arr0[] = {"15 15 4", "15 25 4", "25 25 4", "25 15 4", "25 25 100"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 31214.86460606818; verify_case(2, Arg1, area(Arg0)); }
	void test_case_3() { string Arr0[] = {"2549 8482 11", "9175 5927 35", "2747 6177 93", "5512 8791 81", "4487 8456 60",
 "6899 610 77", "9716 2202 3", "9312 5625 79", "4020 9851 85", "1640 7179 54",
 "5761 4348 51","5917 3436 88","6547 386 33","182 7676 1","6329 4496 89"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 194250.95695676407; verify_case(3, Arg1, area(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    BlackWhitePlane ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
