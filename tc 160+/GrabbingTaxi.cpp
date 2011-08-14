#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int dist(int a, int b, int c, int d) {
    return abs(a-c) + abs(b-d);
}
class GrabbingTaxi {
	public:
	int minTime(vector <int> tXs, vector <int> tYs, int gX, int gY, int walkTime, int taxiTime) {
		int sol = dist(0, 0, gX, gY)*walkTime;
        for (int i=0; i<(int)tXs.size(); ++i) {
            sol = min(sol, dist(tXs[i], tYs[i], 0, 0)*walkTime + dist(tXs[i], tYs[i], gX, gY)*taxiTime);
        }

        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 2; int Arg4 = 10; int Arg5 = 2; int Arg6 = 50; verify_case(0, Arg6, minTime(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_1() { int Arr0[] = {-2, -2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, -2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -4; int Arg3 = -2; int Arg4 = 15; int Arg5 = 3; int Arg6 = 42; verify_case(1, Arg6, minTime(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_2() { int Arr0[] = {3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; int Arg3 = 0; int Arg4 = 10; int Arg5 = 20; int Arg6 = 50; verify_case(2, Arg6, minTime(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_3() { int Arr0[] = {34, -12, 1, 0, 21, -43, -98, 11, 86, -31}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {11, 5, -68, 69, -78, -49, -36, -2, 1, 70}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -97; int Arg3 = -39; int Arg4 = 47; int Arg5 = 13; int Arg6 = 2476; verify_case(3, Arg6, minTime(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_4() { int Arr0[] = {82, -60, 57, 98, 30, -67, 84, -42, -100, 62}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-7, 90, 53, -56, -15, -87, 22, -3, -61, -30}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 21; int Arg3 = 15; int Arg4 = 53; int Arg5 = 2; int Arg6 = 1908; verify_case(4, Arg6, minTime(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    GrabbingTaxi ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
