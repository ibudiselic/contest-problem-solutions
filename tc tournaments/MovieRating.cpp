#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class MovieRating {
	public:
	double calculate(vector <int> marks, int lowCount, int highCount) {
		sort(marks.begin(), marks.end());
		while (lowCount--)
			marks.erase(marks.begin());
		while (highCount--)
			marks.pop_back();

		int x = 0;
		for (int i=0; i<(int)marks.size(); ++i)
			x += marks[i];

		return double(x)/marks.size();
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {70, 99, 96, 0, 30}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 0; double Arg3 = 59.0; verify_case(0, Arg3, calculate(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {91, 90, 50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 1; double Arg3 = 90.0; verify_case(1, Arg3, calculate(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {23, 23, 23, 23, 23, 23, 23, 23}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 3; double Arg3 = 23.0; verify_case(2, Arg3, calculate(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {31, 52, 20, 86, 47, 76, 82, 27, 42, 29}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 4; double Arg3 = 35.2; verify_case(3, Arg3, calculate(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {1, 1, 0, 0, 1, 1, 0, 1, 0, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 2; double Arg3 = 0.6666666666666666; verify_case(4, Arg3, calculate(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    MovieRating ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
