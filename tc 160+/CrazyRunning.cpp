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
double zero, avg;
int N;
double go(int n) {
	if (n == 0)
		return -avg;

	const double t = go(n-1);
	const double p1 = double(n)/(N-1);
	const double p2 = p1/(N-1);
	const double p3 = double(N-n-2)/(N-1);
	const double p4 = double(N-n-1)/(N-1)/(N-1);

	return (p1*(2*avg + t) + p2*(2*zero + 2*avg + t) + p3*2*avg + p4*2*(zero + avg))/(1-p3-p4);
}
class CrazyRunning {
	public:
	double expectedTime(vector <int> corridors) {
		zero = corridors[0];
		N = corridors.size();
		avg = accumulate(corridors.begin()+1, corridors.end(), 0.0)/(N-1);

		return zero + 2*avg + go(N-2);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {10,20}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 30.0; verify_case(0, Arg1, expectedTime(Arg0)); }
	void test_case_1() { int Arr0[] = {150,150,150}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 900.0; verify_case(1, Arg1, expectedTime(Arg0)); }
	void test_case_2() { int Arr0[] = {100,150,200}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 875.0; verify_case(2, Arg1, expectedTime(Arg0)); }
	void test_case_3() { int Arr0[] = {1000,1000,900,1000,555,1000,2562}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 33550.32857142857; verify_case(3, Arg1, expectedTime(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    CrazyRunning ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
