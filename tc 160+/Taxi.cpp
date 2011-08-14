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

class Taxi {
	public:
	double dist(double x, double y) {
		return sqrt(x*x + y*y);
	}
	double maxDis(int maxX, int maxY, int taxiDis) {
		double best = -1.0;
		for (int x=0; x<=maxX; ++x) {
			int y = taxiDis - x;
			if (y>=0 && y<=maxY)
				best = max(best, dist(x, y));
		}
		return best;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arg1 = 3; int Arg2 = 3; double Arg3 = 3.0; verify_case(0, Arg3, maxDis(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 3; int Arg2 = 24; double Arg3 = -1.0; verify_case(1, Arg3, maxDis(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 7; int Arg1 = 10; int Arg2 = 13; double Arg3 = 10.44030650891055; verify_case(2, Arg3, maxDis(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 4; int Arg2 = 7; double Arg3 = 5.0; verify_case(3, Arg3, maxDis(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 976421; int Arg1 = 976421; int Arg2 = 1000000; double Arg3 = 976705.6560100387; verify_case(4, Arg3, maxDis(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Taxi ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
