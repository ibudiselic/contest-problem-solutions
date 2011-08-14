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

bool ok(int x1, int y1, int x2, int y2, const vector<int> &x, const vector<int> &y, const vector<int> &w, const vector<int> &h) {
	for (int i=0; i<(int)x.size(); ++i)
		if (x[i]<=x1 && x1<=x[i]+w[i] && y[i]<=y1 && y1<=y[i]+h[i]
			&&
			x[i]<=x2 && x2<=x[i]+w[i] && y[i]<=y2 && y2<=y[i]+h[i])
		return false;
	return true;
}
class PerforatedSheet {
	public:
	vector <double> getCenterOfMass(int sheetWidth, int sheetHeight, vector <int> x, vector <int> y, vector <int> width, vector <int> height) {
		set<int> X_, Y_;

		X_.insert(0);
		X_.insert(sheetWidth);
		Y_.insert(0);
		Y_.insert(sheetHeight);
		for (int i=0; i<(int)x.size(); ++i) {
			X_.insert(x[i]);
			X_.insert(x[i]+width[i]);
			Y_.insert(y[i]);
			Y_.insert(y[i]+height[i]);
		}

		vector<int> X(X_.begin(), X_.end());
		vector<int> Y(Y_.begin(), Y_.end());

		double nomX = 0, nomY = 0;
		double denom = 0;

		for (int i=0; i+1<(int)X.size(); ++i)
			for (int j=0; j+1<(int)Y.size(); ++j)
				if (ok(X[i], Y[j], X[i+1], Y[j+1], x, y, width, height)) {
					double area = double(X[i+1]-X[i])*(Y[j+1]-Y[j]);
					nomX += area*((X[i]+X[i+1])/2.0);
					nomY += area*((Y[j]+Y[j+1])/2.0);
					denom += area;
				}

		if (denom <= 1e-9)
			return vector<double>();

		vector<double> sol(2, 0.0);
		sol[0] = nomX/denom;
		sol[1] = nomY/denom;

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <double> &Expected, const vector <double> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 10; int Arr2[] = {}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); double Arr6[] = {2.5, 5.0 }; vector <double> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); verify_case(0, Arg6, getCenterOfMass(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 5; int Arr2[] = {0, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0, 0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {1, 9}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {5, 1}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); double Arr6[] = {5.5, 3.0 }; vector <double> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); verify_case(1, Arg6, getCenterOfMass(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 5; int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {1}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {1}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); double Arr6[] = {2.5416666666666665, 2.5416666666666665 }; vector <double> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); verify_case(2, Arg6, getCenterOfMass(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_3() { int Arg0 = 822741; int Arg1 = 110524; int Arr2[] = {335076, 665632, 210102, 714135, 229942, 149776, 675634, 502085, 393066, 115215,
80993, 272343, 434287, 593760, 589713, 485801, 395389, 755380, 417327, 477023}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {104509, 23182, 103471, 62180, 5040, 10186, 45286, 107985, 36936, 87885,
63846, 58794, 89480, 85195, 64703, 96341, 89224, 7727, 71438, 39128}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {24578, 20552, 3332, 254, 21489, 21158, 35061, 37453, 21881, 216,
32930, 31555, 5121, 36687, 6949, 3512, 8049, 30019, 37252, 8001}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {2240, 3152, 4625, 3508, 4206, 5262, 1750, 627, 3983, 3192,
3609, 3361, 1135, 2580, 4158, 1356, 583, 5408, 5521, 2742}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); double Arr6[] = {411084.49564976187, 55331.97175632337 }; vector <double> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); verify_case(3, Arg6, getCenterOfMass(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_4() { int Arg0 = 1234567; int Arg1 = 314159; int Arr2[] = {0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {1234567}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {314159}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); double Arr6[] = { }; vector <double> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); verify_case(4, Arg6, getCenterOfMass(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_5() { int Arg0 = 2000000; int Arg1 = 2000000; int Arr2[] = {1, 0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0, 1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {1999999, 1}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {2000000, 1999999}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); double Arr6[] = {0.5, 0.5 }; vector <double> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); verify_case(5, Arg6, getCenterOfMass(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    PerforatedSheet ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
