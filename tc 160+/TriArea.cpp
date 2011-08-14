#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

enum {
	WHOLE=1, LEFT=2, RIGHT=4
};
unsigned char A[405][405];
class TriArea {
	public:
	double area(vector <int> xCenter, vector <int> yCenter, vector <int> height) {
		memset(A, 0, sizeof A);

		for (int i=0; i<(int)xCenter.size(); ++i) {
			int lx = xCenter[i]-height[i] + 200;
			int rx = xCenter[i]+height[i]-1 + 200;
			for (int y=yCenter[i]+1 + 100; y<yCenter[i]+1+height[i] + 100; ++y) {
				for (int x=lx+1; x<rx; ++x)
					A[y][x] |= WHOLE;
				A[y][lx] |= LEFT;
				++lx;
				A[y][rx] |= RIGHT;
				--rx;
			}
		}

		int cnt = 0;
		for (int i=0; i<405; ++i)
			for (int j=0; j<405; ++j)
				if (A[i][j] & WHOLE)
					cnt += 4;
				else if ((A[i][j] & LEFT) && (A[i][j] & RIGHT))
					cnt += 3;
				else if (A[i][j] & (LEFT | RIGHT))
					cnt += 2;

		return double(cnt)/4;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1}

; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 49.0; verify_case(0, Arg3, area(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3,3,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {7,7,8}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 64.0; verify_case(1, Arg3, area(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {7,7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 55.75; verify_case(2, Arg3, area(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {3, 6, 10, 12}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4, 11, -1, -7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2, 4, 6, 8}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 116.0; verify_case(3, Arg3, area(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    TriArea ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
