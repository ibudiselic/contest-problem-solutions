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

double pi = acos(-1.0);
class TopCan {
	public:
	double calc(double r, int V) {
		double h = V/(r*r*pi);

		return 2*r*pi*(r+h);
	}
	double minSurface(int volume) {
		double lor = 0.0, hir = 1e20;

		for (int i=0; i<10000; ++i) {
			const double mid1 = lor + (hir-lor)/3;
			const double mid2 = mid1 + (hir-lor)/3;

			if (calc(mid1, volume) < calc(mid2, volume))
				hir = mid2;
			else
				lor = mid1;
		}

		return calc((lor+hir)/2, volume);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; double Arg1 = 25.694955950835347; verify_case(0, Arg1, minSurface(Arg0)); }
	void test_case_1() { int Arg0 = 20; double Arg1 = 40.78820010663257; verify_case(1, Arg1, minSurface(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    TopCan ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
