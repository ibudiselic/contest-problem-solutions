#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class BadExam {
	public:
	double newAverage(vector <int> marks) {
		double sum = 0.0;
		double best = *max_element(marks.begin(), marks.end());

		for (int i=0; i<(int)marks.size(); ++i)
			sum += marks[i]/best * 100;

		return sum/marks.size();
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {40,80,60}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 75.0; verify_case(0, Arg1, newAverage(Arg0)); }
	void test_case_1() { int Arr0[] = {10, 20, 0, 100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 32.5; verify_case(1, Arg1, newAverage(Arg0)); }
	void test_case_2() { int Arr0[] = {50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 100.0; verify_case(2, Arg1, newAverage(Arg0)); }
	void test_case_3() { int Arr0[] = {10, 20, 30, 40, 50, 60, 70, 80, 90}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 55.55555555555556; verify_case(3, Arg1, newAverage(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    BadExam ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
