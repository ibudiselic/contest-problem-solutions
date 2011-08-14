#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

#undef PI
#define PI 3.14159265358979323846

class Archimedes {
	public:
	double approximatePi(int n) {
		return n*sin(PI/n);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; double Arg1 = 2.598076211353316; verify_case(0, Arg1, approximatePi(Arg0)); }
	void test_case_1() { int Arg0 = 8; double Arg1 = 3.0614674589207183; verify_case(1, Arg1, approximatePi(Arg0)); }
	void test_case_2() { int Arg0 = 17280; double Arg1 = 3.1415926362832276; verify_case(2, Arg1, approximatePi(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Archimedes ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
