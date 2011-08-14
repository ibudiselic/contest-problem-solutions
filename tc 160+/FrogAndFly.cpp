#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class FrogAndFly {
	public:
	double visibility(int hwall, int dfrog, int dfly, int ylow, int yhigh, vector <int> xwindow, vector <int> ywindow) {
		
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arg1 = 10; int Arg2 = 10; int Arg3 = 5; int Arg4 = 15; int Arr5[] = {5, 5, 15, 15}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arr6[] = {5, 15, 15, 5}; vector <int> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); double Arg7 = 0.5; verify_case(0, Arg7, visibility(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_1() { int Arg0 = 14; int Arg1 = 10; int Arg2 = 10; int Arg3 = 5; int Arg4 = 15; int Arr5[] = {5, 5, 15, 15}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arr6[] = {5, 15, 15, 5}; vector <int> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); double Arg7 = 0.02; verify_case(1, Arg7, visibility(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 5; int Arg2 = 10; int Arg3 = 5; int Arg4 = 15; int Arr5[] = {10, 20, 15}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arr6[] = {5, 5, 15}; vector <int> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); double Arg7 = 0.4166666666666665; verify_case(2, Arg7, visibility(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_3() { int Arg0 = 0; int Arg1 = 1; int Arg2 = 20; int Arg3 = 10; int Arg4 = 100; int Arr5[] = {0, 10, 20, 30, 15}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arr6[] = {20, 10, 10, 20, 40}; vector <int> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); double Arg7 = 1.0; verify_case(3, Arg7, visibility(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_4() { int Arg0 = 100; int Arg1 = 30; int Arg2 = 10; int Arg3 = 20; int Arg4 = 40; int Arr5[] = {10, 20, 30, 20}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arr6[] = {20, 10, 20, 30}; vector <int> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); double Arg7 = 0.0; verify_case(4, Arg7, visibility(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    FrogAndFly ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
