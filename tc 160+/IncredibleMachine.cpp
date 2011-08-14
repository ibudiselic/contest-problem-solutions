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

vector<int> x, y;
inline double sqr(double x) { return x*x; }
double dist(int i, int j) {
    return sqrt(sqr(x[i]-x[j]) + sqr(y[i]-y[j]));
}
double D[50];
double alpha[50];
double calc(double g) {
    double T = 0.0;
    double v = 0.0;
    for (int i=1; i<(int)x.size(); ++i) {
        double a = g * sin(alpha[i]);
        assert(a > 1e-9);
        
        double disc = v*v + 2*a*D[i];
        assert(disc >= 0.0);
        double t = (sqrt(disc) - v) / a;
        T += t;
        v += t*a;
    }
    
    return T;
}
    
class IncredibleMachine {
	public:
	double gravitationalAcceleration(vector <int> x, vector <int> y, int T) {
		::x = x;
        ::y = y;
        
        for (int i=1; i<(int)x.size(); ++i) {
            D[i] = dist(i-1, i);
            alpha[i] = atan(double(y[i-1]-y[i])/(x[i]-x[i-1]));
        }
        double lo = 0.0;
        double hi = 1e15;
        for (int t=0; t<100; ++t) {
            double mid = (lo+hi)/2.0;
            if (calc(mid) >= T) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
        
        return lo;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {100,22}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; double Arg3 = 9.807692307692307; verify_case(0, Arg3, gravitationalAcceleration(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {0,26,100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {50,26,24}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; double Arg3 = 26.743031720603582; verify_case(1, Arg3, gravitationalAcceleration(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {0,7,8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10,6,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 7; double Arg3 = 1.1076837407708007; verify_case(2, Arg3, gravitationalAcceleration(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    IncredibleMachine ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
