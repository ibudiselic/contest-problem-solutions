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

const double sqrt2 = sqrt(2.0);
const double pi = acos(-1.0);
class RecursiveFigures {
	public:
	double getArea(double sideLength, int K) {
        return sideLength*sideLength*pi/4.0 + (K==1 ? 0.0 : -sideLength*sideLength/2.0 + getArea(sideLength/sqrt2, K-1));
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arg1 = 1; double Arg2 = 78.53981633974483; verify_case(0, Arg2, getArea(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 2; double Arg2 = 67.80972450961724; verify_case(1, Arg2, getArea(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 3; double Arg2 = 62.444678594553444; verify_case(2, Arg2, getArea(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    RecursiveFigures ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
