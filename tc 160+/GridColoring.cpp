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

double f(int r, int c, int R, int C) {
    return (2.0 * (r+1) *  (R-r) - 1) * (2.0 * (c+1) * (C-c) - 1) / R / R / C / C;
}

class GridColoring {
	public:
	double area(int K, int rows, int cols) {
		double sol = 0.0;
        for (int r=0; r<rows; ++r) {
            for (int c=0; c<cols; ++c) {
                double p = f(r, c, rows, cols);
                double pp = pow(1-p, K);
                sol += 1.0 - pp;
            }
        }

        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 2; int Arg2 = 1; double Arg3 = 1.5; verify_case(0, Arg3, area(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 1; double Arg3 = 1.875; verify_case(1, Arg3, area(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 2; int Arg2 = 2; double Arg3 = 2.25; verify_case(2, Arg3, area(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 3; int Arg1 = 5; int Arg2 = 7; double Arg3 = 19.11917924647044; verify_case(3, Arg3, area(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    GridColoring ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
