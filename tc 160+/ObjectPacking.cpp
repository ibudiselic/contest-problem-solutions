#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class ObjectPacking {
	public:
	int smallBox(int objWidth, int objLength, vector <int> boxWidth, vector <int> boxLength) {
		int sol = 1234567890;
		for (int i=0; i<(int)boxWidth.size(); ++i)
			if (objWidth<=boxWidth[i] && objLength<=boxLength[i] || objWidth<=boxLength[i] && objLength<=boxWidth[i])
				sol = min(sol, boxWidth[i]*boxLength[i]);
		return sol==1234567890 ? -1 : sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 7; int Arg1 = 3; int Arr2[] = {3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {7}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 21; verify_case(0, Arg4, smallBox(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 8; int Arr2[] = {6,9,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {7,4,5}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = -1; verify_case(1, Arg4, smallBox(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 17; int Arg1 = 5; int Arr2[] = {19,10,12,40}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {12,20,15,5}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 200; verify_case(2, Arg4, smallBox(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 20; int Arg1 = 44; int Arr2[] = {36,42,18,37,33,5,30,10,29,9,11,16,48,50,34,44,33,12,31,41}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {42,45,46,24,23,21,21,8,26,25,48,12,10,45,18,6,12,22,42,45}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1845; verify_case(3, Arg4, smallBox(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 1; int Arg1 = 10; int Arr2[] = {9,1,10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {10,6,4}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 40; verify_case(4, Arg4, smallBox(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arg0 = 5; int Arg1 = 4; int Arr2[] = {2,3,3,3,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2,7,7,4,2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = -1; verify_case(5, Arg4, smallBox(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_6() { int Arg0 = 3; int Arg1 = 3; int Arr2[] = {2,3,3,3,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {3,1,3,3,2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 9; verify_case(6, Arg4, smallBox(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ObjectPacking ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
