#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class ApproximateDivision {
	public:
	double quotient(int a, int b, int terms) {
	    int p = 1;

        while (p < b) {
            p *= 2;
        }

        double t = p;
        double c = t - b;
        
        double term = 1 / t;
        double f = c / t;

        double sol = 0.0;
        while (terms--) {
            sol += term;
            term *= f;
        }

        return sol*a;    
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 5; int Arg2 = 2; double Arg3 = 0.34375; verify_case(0, Arg3, quotient(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 7; int Arg1 = 8; int Arg2 = 5; double Arg3 = 0.875; verify_case(1, Arg3, quotient(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 3; int Arg2 = 10; double Arg3 = 0.33333301544189453; verify_case(2, Arg3, quotient(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 1; int Arg1 = 10000; int Arg2 = 2; double Arg3 = 8.481740951538086E-5; verify_case(3, Arg3, quotient(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 1; int Arg1 = 7; int Arg2 = 20; double Arg3 = 0.14285714285714285; verify_case(4, Arg3, quotient(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 0; int Arg1 = 4; int Arg2 = 3; double Arg3 = 0.0; verify_case(5, Arg3, quotient(Arg0, Arg1, Arg2)); }
	void test_case_6() { int Arg0 = 50; int Arg1 = 50; int Arg2 = 1; double Arg3 = 0.78125; verify_case(6, Arg3, quotient(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    ApproximateDivision ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
