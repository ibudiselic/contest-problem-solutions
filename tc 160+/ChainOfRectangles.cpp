#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class ChainOfRectangles {
	public:
	int getMaximalArea(vector <int> width, vector <int> height, string color) {
		int rgb[4] = {0};
		string C = "RGB";
		int last = 3;
		for (int i=0; i<(int)width.size(); ++i) {
			int a = width[i]*height[i];
			rgb[last] -= a;
			last = C.find(color[i]);
			rgb[last] += a;
		}

		return *max_element(rgb, rgb+3);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {10000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "R"; int Arg3 = 100000000; verify_case(0, Arg3, getMaximalArea(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {10, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "GB"; int Arg3 = 75; verify_case(1, Arg3, getMaximalArea(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {10, 9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {8, 7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "GB"; int Arg3 = 63; verify_case(2, Arg3, getMaximalArea(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {10, 8, 6, 4, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {9, 7, 5, 3, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "GBRRG"; int Arg3 = 36; verify_case(3, Arg3, getMaximalArea(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ChainOfRectangles ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
