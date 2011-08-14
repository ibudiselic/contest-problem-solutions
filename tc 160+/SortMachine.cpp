#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class SortMachine {
	public:
	int countMoves(vector <int> a) {
		vector<int> b = a;
		sort(b.begin(), b.end());

		for (int i=(int)a.size(); i>0; --i) {
			int x = 0;
			for (int j=0; j<(int)a.size(); ++j)
				if (a[j] == b[x]) {
					++x;
					if (x == i)
						return a.size()-x;
				}
		}
		return -1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {19,7,8,25}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, countMoves(Arg0)); }
	void test_case_1() { int Arr0[] = {1,2,3,4,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, countMoves(Arg0)); }
	void test_case_2() { int Arr0[] = {1000,-1000,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, countMoves(Arg0)); }
	void test_case_3() { int Arr0[] = {1,3,4,5,6,7,8,9,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(3, Arg1, countMoves(Arg0)); }
	void test_case_4() { int Arr0[] = {-2, -8, 9, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(4, Arg1, countMoves(Arg0)); }
	void test_case_5() { int Arr0[] = {976, -946, -824, 680, -644, -95, 128, -892, 816, -263,
 -592, -669, 887, 447, -653, -759, 572, 171, 635, 98,
 -904, 78, 143, -416, -40, -846, 784, -702, -738, -858,
 582, 603, -535, 529, 84, -964, 934, 36, 783} ; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 38; verify_case(5, Arg1, countMoves(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    SortMachine ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
