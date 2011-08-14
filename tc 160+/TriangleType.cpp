#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

/*
For a triangle with side-lengths x, y, and z and x <= y <= z. * The triangle is right if x*x + y*y = z*z. *
The triangle is obtuse if x*x + y*y < z*z. *
The triangle is acute if x*x + y*y > z*z. *
It is impossible to have x + y <= z.
*/
class TriangleType {
	public:
	string type(int a, int b, int c) {
		if (a > b)
			swap(a, b);
		if (a > c)
			swap(a, c);
		if (b > c)
			swap(b, c);

		if (a+b <= c)
			return "IMPOSSIBLE";
		int x = a*a + b*b;
		if (x < c*c)
			return "OBTUSE";
		else if (x == c*c)
			return "RIGHT";
		else
			return "ACUTE";
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 4; int Arg2 = 5; string Arg3 = "RIGHT"; verify_case(0, Arg3, type(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 4; int Arg2 = 4; string Arg3 = "ACUTE"; verify_case(1, Arg3, type(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 4; int Arg2 = 6; string Arg3 = "OBTUSE"; verify_case(2, Arg3, type(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 7; int Arg1 = 4; int Arg2 = 3; string Arg3 = "IMPOSSIBLE"; verify_case(3, Arg3, type(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    TriangleType ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
