#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class ElevatorLimit {
	public:
	vector <int> getRange(vector <int> enter, vector <int> exit, int physicalLimit) {
		int low = 0;
		int high = physicalLimit;
		int diff = 0;

		for (int i=0; i<(int)enter.size(); ++i) {
			int t = low + diff - exit[i];
			if (t < 0)
				low -= t;

			diff += enter[i]-exit[i];

			t = high + diff;
			if (t > physicalLimit)
				high -= t-physicalLimit;
		}

		if (high < low)
			return vector<int> ();

		vector<int> sol(2, 0);
		sol[0] = low;
		sol[1] = high;

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arr3[] = { 0,  0 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(0, Arg3, getRange(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arr3[] = { 0,  1 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(1, Arg3, getRange(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {0,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arr3[] = { 1,  1 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(2, Arg3, getRange(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {0,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arr3[] = { }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(3, Arg3, getRange(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {6, 85, 106, 1, 199, 76, 162, 141} ; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {38, 68, 62, 83, 170, 12, 61, 114} ; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 668; int Arr3[] = { 223,  500 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(4, Arg3, getRange(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arr0[] = {179, 135, 104, 90, 97, 186, 187, 47, 152, 100, 119, 28, 193, 11, 103, 100,
 179, 11, 80, 163, 50, 131, 103, 50, 142, 51, 112, 62, 69, 72, 88, 3, 162,
 93, 190, 85, 79, 86, 146, 71, 65, 131, 179, 119, 66, 111} ; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {134, 81, 178, 168, 86, 128, 1, 165, 62, 46, 188, 70, 104, 111, 3, 47, 144,
 69, 163, 21, 101, 126, 169, 84, 146, 165, 198, 1, 65, 181, 135, 99, 100,
 195, 171, 47, 16, 54, 79, 69, 6, 97, 154, 80, 151, 76} ; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 954; int Arr3[] = { 453,  659 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(5, Arg3, getRange(Arg0, Arg1, Arg2)); }
	void test_case_6() { int Arr0[] = {2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arr3[] = { }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(6, Arg3, getRange(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ElevatorLimit ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
