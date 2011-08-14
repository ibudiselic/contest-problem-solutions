#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class PaperFold {
	public:
	int numFolds(vector <int> paper, vector <int> box) {
		int pot[9] = {0};
		pot[0] = 1;
		for (int i=1; i<9; ++i)
			pot[i] = pot[i-1]*2;

		int sol = 100;
		for (int f1=0; f1<=8; ++f1)
			for (int f2=0; f2<=f1 && f1+f2<=8; ++f2)
				if (box[0]*pot[f1]>=paper[0] && box[1]*pot[f2]>=paper[1] ||
					  box[0]*pot[f1]>=paper[1] && box[1]*pot[f2]>=paper[0] ||
					 	box[1]*pot[f1]>=paper[0] && box[0]*pot[f2]>=paper[1] ||
					  box[1]*pot[f1]>=paper[1] && box[0]*pot[f2]>=paper[0])
							sol = min(sol, f1+f2);

		return (sol<=8)? sol:-1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {8, 11}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {6, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(0, Arg2, numFolds(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {11, 17}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {6, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(1, Arg2, numFolds(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {11, 17}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(2, Arg2, numFolds(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1000,1000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {62,63}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(3, Arg2, numFolds(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {100,30}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {60,110}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(4, Arg2, numFolds(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {1895, 6416}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {401, 1000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(5, Arg2, numFolds(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    PaperFold ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
