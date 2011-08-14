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

double T, R, S;
vector<int> bx, by, sx, sy;

double sqr(double x) { return x*x; }
double dist(int silo, int base) {
    return sqrt(sqr(sx[silo]-bx[base]) + sqr(sy[silo]-by[base]));
}
double f(int silo, int base) {
    double d = dist(silo, base);
    return T + d/S;
}
double s(int silo, int base) {
    return T + R + f(silo, base);
}
class FeudaliasBattle {
	public:
	double getMinimumTime(vector <int> baseX, vector <int> baseY, vector <int> siloX, vector <int> siloY, int takeOffTime, int rechargeTime, int missileSpeed) {
		T = takeOffTime/60.0;
        R = rechargeTime;
        S = missileSpeed;
        bx = baseX;
        by = baseY;
        sx = siloX;
        sy = siloY;
        
        return min(max(f(0, 0), f(1, 1)), min(max(f(0, 1), f(1, 0)), min(max(f(0, 0), s(0, 1)), min(max(f(0, 1), s(0, 0)), min(max(f(1, 0), s(1, 1)), max(f(1, 1), s(1, 0)))))));
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {100, 500}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {100, 100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {100, 500}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {300, 300}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 6; int Arg5 = 10; int Arg6 = 1; double Arg7 = 200.1; verify_case(0, Arg7, getMinimumTime(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_1() { int Arr0[] = {100, 100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {100, 500}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {100, 500}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {300, 300}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 6; int Arg5 = 10; int Arg6 = 1; double Arg7 = 210.2; verify_case(1, Arg7, getMinimumTime(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_2() { int Arr0[] = {100, 100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {100, 500}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {100, 500}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {300, 300}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 6; int Arg5 = 20; int Arg6 = 20; double Arg7 = 22.4606797749979; verify_case(2, Arg7, getMinimumTime(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_3() { int Arr0[] = {401, 208}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {622, 603}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {51, 387}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {411, 828}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 59; int Arg5 = 518; int Arg6 = 1941; double Arg7 = 1.1111118724871378; verify_case(3, Arg7, getMinimumTime(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    FeudaliasBattle ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
