#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class MagicSquare {
	public:
	int missing(vector <int> square) {
		vector<int> v(3, 0), h(3, 0);

		for (int i=0; i<3; ++i)
			for (int j=0; j<3; ++j) {
				h[i] += square[i*3 + j];
				v[j] += square[i*3 + j];
			}

		int sum = h[0];
		if (h[1] != sum)
			sum = h[2];

		int i=0, j=0;
		for (i=0; i<3; ++i)
			if (h[i] != sum)
				break;
		for (j=0; j<3; ++j)
			if (v[j] != sum)
				break;

		return sum - (h[i]+1);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 8, 1, 6, 3, 5, -1, 4, 9, 2 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(0, Arg1, missing(Arg0)); }
	void test_case_1() { int Arr0[] = { -1, 1, 6, 3, 5, 7, 4, 9, 2 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(1, Arg1, missing(Arg0)); }
	void test_case_2() { int Arr0[] = { 5, 15, 13, 19, 11, 3, 9, 7, -1 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 17; verify_case(2, Arg1, missing(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    MagicSquare ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
