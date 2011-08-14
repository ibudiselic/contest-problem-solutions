#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <numeric>
using namespace std;

class PassingGrade {
	public:
	int pointsNeeded(vector <int> pointsEarned, vector <int> pointsPossible, int finalExam) {
		int e = accumulate(pointsEarned.begin(), pointsEarned.end(), 0);
		int p = accumulate(pointsPossible.begin(), pointsPossible.end(), 0);

		if ((e+finalExam)*100 < 65*(p+finalExam))
			return -1;

		return max(0, (65*(p+finalExam)+99)/100 - e);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {55,77,82,60}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {100,100,100,100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 300; int Arg3 = 181; verify_case(0, Arg3, pointsNeeded(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = { 1, 2, 3, 4 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 2, 3, 4, 5 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 7; int Arg3 = 4; verify_case(1, Arg3, pointsNeeded(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = { 1, 2, 2, 1 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 9, 9, 9, 9 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 9; int Arg3 = -1; verify_case(2, Arg3, pointsNeeded(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = { 7, 8, 7, 6 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 8, 8, 8, 8 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 9; int Arg3 = 0; verify_case(3, Arg3, pointsNeeded(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = { 17, 23, 50, 200, 19, 56, 83, 91, 77, 9, 0 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 20, 30, 50, 250, 20, 70, 100, 100, 100, 10, 10 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 400; int Arg3 = 129; verify_case(4, Arg3, pointsNeeded(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arr0[] = {600,600,600,600,600,600,600,600,600,600,
 600,600,600,600,600,600,600,600,600,600}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1000,1000,1000,1000,1000,1000,1000,1000,
 1000,1000,1000,1000,1000,1000,1000,1000,
 1000,1000,1000,901}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3000; int Arg3 = 2886; verify_case(5, Arg3, pointsNeeded(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    PassingGrade ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
