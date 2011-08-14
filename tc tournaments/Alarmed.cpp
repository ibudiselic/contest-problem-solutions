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

vector<int> X, Y, T;
int N;
bool used[50];
bool cutLeft, cutRight;

double sqr(double x) {
	return x*x;
}
void go(int i, const vector<double> &r) {
	used[i] = 1;

	if (X[i]-r[i] < 0)
		cutLeft = 1;
	if (X[i]+r[i] > 100)
		cutRight = 1;
	if (X[i]<50 && (Y[i]+r[i]>100 || Y[i]-r[i]<0))
		cutLeft = 1;
	if (X[i]>50 && (Y[i]+r[i]>100 || Y[i]-r[i]<0))
		cutRight = 1;

	for (int j=0; j<N; ++j)
		if (!used[j] && sqrt(sqr(X[i]-X[j])+sqr(Y[i]-Y[j]))<=r[i]+r[j])
			go(j, r);
}
bool ok(double A) {
	vector<double> r(N);

	for (int i=0; i<N; ++i) {
		r[i] = sqrt(A/T[i]);
		if (sqrt(sqr(X[i]-50) + sqr(Y[i])) <= r[i])
			return false;
		if (sqrt(sqr(X[i]-50) + sqr(Y[i]-100)) <= r[i])
			return false;
	}

	memset(used, 0, sizeof used);

	for (int i=0; i<N; ++i)
		if (!used[i]) {
			cutLeft = cutRight = 0;
			go(i, r);
			if (cutLeft && cutRight)
				return false;
		}
	return true;
}

class Alarmed {
	public:
	double noise(vector <int> x, vector <int> y, vector <int> threshold) {
		N = x.size();
		X = x;
		Y = y;
		T = threshold;

		double lo = 0;
		double hi = 1000.0;

		while (ok(hi))
			hi *= 2;

		for (int i=0; i<1000; ++i) {
			double mid = (lo+hi)/2;

			if (!ok(mid))
				hi = mid;
			else
				lo = mid;
		}

		return (lo+hi)/2;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {87}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 347.99999999999994; verify_case(0, Arg3, noise(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {1,99}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {50,50}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 2400.9999999999995; verify_case(1, Arg3, noise(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {3,11,2,62,91}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {90,10,75,25,50}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5,4,3,2,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 1537.9999999999998; verify_case(2, Arg3, noise(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = { 1,99}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 50,50}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 1, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 3295.5717878751793; verify_case(3, Arg3, noise(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Alarmed ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
