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

const double sqrt2 = 1/sqrt(2);
double di[] = { -1, -sqrt2, 0, sqrt2, 1, sqrt2, 0, -sqrt2 };
double dj[] = { 0, sqrt2, 1, sqrt2, 0, -sqrt2, -1, -sqrt2 };
string D[] = { "NORTH", "NORTHEAST", "EAST", "SOUTHEAST", "SOUTH", "SOUTHWEST", "WEST", "NORTHWEST" };
class PirateTreasure {
	public:
	double getDistance(vector <int> steps, vector <string> directions) {
		double x = 0;
		double y = 0;

		for (int i=0; i<(int)steps.size(); ++i) {
			int d = find(D, D+8, directions[i]) - D;
			x += steps[i]*di[d];
			y += steps[i]*dj[d];
		}

		return sqrt(x*x + y*y);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NORTH"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 1.0; verify_case(0, Arg2, getDistance(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NORTHWEST"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 2.0; verify_case(1, Arg2, getDistance(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {3,10,7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"EAST","WEST","EAST"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.0; verify_case(2, Arg2, getDistance(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {34,48,34}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NORTH","SOUTHWEST","EAST"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.08326112068522587; verify_case(3, Arg2, getDistance(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {2,2,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NORTH","NORTH","NORTH","NORTHWEST"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 6.744277676240694; verify_case(4, Arg2, getDistance(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    PirateTreasure ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
