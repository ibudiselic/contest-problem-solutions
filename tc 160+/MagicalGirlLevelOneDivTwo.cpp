#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

class MagicalGirlLevelOneDivTwo {
	public:
	double theMinDistance(int d, int x, int y) {
		x = x<0 ? -x : x;
        y = y<0 ? -y : y;
        int dx = max(0, x-d);
        int dy = max(0, y-d);
        return sqrt(dx*dx + dy*dy);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 10; int Arg2 = 10; double Arg3 = 7.0710678118654755; verify_case(0, Arg3, theMinDistance(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 10; int Arg2 = 3; double Arg3 = 5.0; verify_case(1, Arg3, theMinDistance(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = -8; int Arg2 = -6; double Arg3 = 3.1622776601683795; verify_case(2, Arg3, theMinDistance(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 5; int Arg1 = 3; int Arg2 = 2; double Arg3 = 0.0; verify_case(3, Arg3, theMinDistance(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 24; int Arg1 = 24; int Arg2 = -24; double Arg3 = 0.0; verify_case(4, Arg3, theMinDistance(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 345; int Arg1 = -471; int Arg2 = 333; double Arg3 = 126.0; verify_case(5, Arg3, theMinDistance(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    MagicalGirlLevelOneDivTwo ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
