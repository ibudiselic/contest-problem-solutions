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

class CirclesOfDestruction {
	public:
	void rotate(int &X, int &Y, int &px, int &py, vector<int> &x, vector<int> &y) {
		int t;
		t = px;
		px = Y - py;
		py = t;
		for (int i=0; i<(int)x.size(); ++i) {
			t = x[i]; x[i] = Y - y[i]; y[i] = t;
		}
		t = X; X = Y; Y = t;
	}
	double exitTime(int X, int Y, int px, int py, vector <int> x, vector <int> y) {
		double sol = 1e30;

		for (int direction=0; direction<4; ++direction, rotate(X, Y, px, py, x, y)) {
			for (int i=0; i<(int)x.size(); ++i) {
				double ty;
				if (x[i] < px) {
					ty = py;
				} else if (py==y[i] && x[i]>px) {
					continue;
				} else {
					ty = (X-px)*(X-px) - (X-x[i])*(X-x[i]) - (py-y[i])*(py-y[i]);
					ty /= 2*(py-y[i]);
					ty += py;
				}
				if (ty>=-1e-9 && ty<=Y+1e-9) {
					double cur = (ty-py)*(ty-py) + (X-px)*(X-px);
					for (int j=0; j<(int)x.size(); ++j)
						if ((ty-y[j])*(ty-y[j]) + (X-x[j])*(X-x[j]) < cur-1e-9)
							cur = 1e31;
					sol = min(sol, cur);
				}
			}
		}
		if (sol < 1e20)
			return sqrt(sol);
		else
			return -1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arg1 = 10; int Arg2 = 5; int Arg3 = 5; int Arr4[] = {1, 5, 5}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {5, 1, 9}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); double Arg6 = 5.0; verify_case(0, Arg6, exitTime(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_1() { int Arg0 = 101; int Arg1 = 10; int Arg2 = 5; int Arg3 = 5; int Arr4[] = {1, 5, 5, 9}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {5, 1, 9, 5}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); double Arg6 = -1.0; verify_case(1, Arg6, exitTime(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 3; int Arg2 = 0; int Arg3 = 2; int Arr4[] = {0, 0, 1, 1, 1}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {1, 3, 1, 2, 3}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); double Arg6 = 0.0; verify_case(2, Arg6, exitTime(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_3() { int Arg0 = 5; int Arg1 = 6; int Arg2 = 4; int Arg3 = 2; int Arr4[] = {0, 4, 5}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {6, 0, 2}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); double Arg6 = 4.0; verify_case(3, Arg6, exitTime(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_4() { int Arg0 = 100; int Arg1 = 100; int Arg2 = 50; int Arg3 = 50; int Arr4[] = {10, 30, 70, 90, 10, 30, 70, 90}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {90, 70, 30, 10, 10, 30, 70, 90}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); double Arg6 = -1.0; verify_case(4, Arg6, exitTime(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_5() { int Arg0 = 1000; int Arg1 = 1000; int Arg2 = 800; int Arg3 = 800; int Arr4[] = {1000, 800, 600}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {800, 1000, 750}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); double Arg6 = 805.4744331758768; verify_case(5, Arg6, exitTime(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    CirclesOfDestruction ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
