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

double calc(double ang, const vector<int> &w, const vector<int> &s, double target) {
	double pos = 0.0;

	for (int i=0; i+1<(int)w.size(); ++i) {
		pos += w[i]*tan(ang);
		ang = asin(sin(ang)*s[i+1]/s[i]);
	}

	return fabs(target - (pos + w.back()*tan(ang)));
}
class RemoteRover {
	public:
	double optimalTravel(vector <int> width, vector <int> speed, int offset) {
		double lo = 0.0;
		double hi = atan(double(offset)/width[0]);

		for (int i=0; i<1000; ++i) {
			double m1 = lo + (hi-lo)/3;
			double m2 = m1 + (hi-lo)/3;

			double l = calc(m1, width, speed, offset);
			double r = calc(m2, width, speed, offset);

			if (isnan(r) || l<r)
				hi = m2;
			else
				lo = m1;
		}

		double ang = (lo+hi)/2;
		double sol = 0.0;
		for (int i=0; i+1<(int)width.size(); ++i) {
			sol += width[i]/cos(ang)/speed[i];

			ang = asin(sin(ang)*speed[i+1]/speed[i]);
		}

		return sol + width.back()/cos(ang)/speed.back();
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {100, 300, 200}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {100, 50, 75}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1000; double Arg3 = 17.042083785318038; verify_case(0, Arg3, optimalTravel(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {1155, 6184, 2783, 7540, 8156}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {570, 810, 875, 172, 642}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; double Arg3 = 69.38271426584203; verify_case(1, Arg3, optimalTravel(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {5000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {50}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10000; double Arg3 = 223.60679774997894; verify_case(2, Arg3, optimalTravel(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {9033, 8232, 8842, 6518, 2358, 1115, 941, 928, 220, 8460}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {50, 50, 50, 50, 50, 50, 50, 50, 50, 50}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10000; double Arg3 = 954.1368054948935; verify_case(3, Arg3, optimalTravel(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {9236, 7065, 2283, 506, 6432, 9812, 3133, 1397, 7052, 3729,
2556, 9954, 1367, 6440, 5141, 3091, 2879, 1346, 7080, 1036,
7503, 7775, 433, 7579, 6520, 2287, 1971, 3879, 1725, 8200,
1830, 2774, 3850, 7509, 8531, 7493, 1511, 9399, 9679, 2124,
791, 3432}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {956, 799, 481, 194, 993, 444, 571, 986, 815, 910,
98, 847, 650, 487, 419, 434, 410, 812, 374, 751,
307, 134, 134, 955, 758, 73, 932, 360, 135, 588,
218, 936, 674, 494, 157, 556, 881, 292, 851, 890,
886, 912}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 9756; double Arg3 = 501.6129192127166; verify_case(4, Arg3, optimalTravel(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    RemoteRover ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
