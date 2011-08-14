#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

double D;
double dist(double x1, double y1, double x2, double y2) {
    return (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
}
double calc(double x1, double x2, double y2) {
    double lo = y2;
    double hi = 1e5;
    double sol = 0.0;
    for (int t=0; t<100; ++t) {
        double m = (lo+hi)/2.0;
        if (dist(x1, m, x2, y2) <= D+1e-15) {
            sol = max(sol, m);
            lo = m;
        } else {
            hi = m;
        }
    }
    
    return sol;
}
class FallingPoints {
	public:
	vector <double> getHeights(vector <int> X, int R) {
        int n = X.size();
        D = R*R;
		vector<double> sol;
        sol.push_back(0.0);
        
        for (int i=1; i<n; ++i) {
            double y = 0.0;
            for (int j=i-1; j<i; ++j) {
                if (abs(X[i]-X[j]) < R) {
                    y = max(y, calc(X[i], X[j], sol[j]));
                } else if (abs(X[i]-X[j]) == R) {
                    y = max(y, sol[j]);
                }
            }
            sol.push_back(y);
        }
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <double> &Expected, const vector <double> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; double Arr2[] = {0.0 }; vector <double> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, getHeights(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; double Arr2[] = {0.0, 0.0 }; vector <double> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, getHeights(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {0,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; double Arr2[] = {0.0, 4.358898943540674 }; vector <double> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, getHeights(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {0,9,19}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; double Arr2[] = {0.0, 4.358898943540674, 4.358898943540674 }; vector <double> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, getHeights(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    FallingPoints ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
