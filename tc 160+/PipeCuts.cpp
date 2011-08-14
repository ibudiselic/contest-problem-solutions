#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class PipeCuts {
	public:
	double probability(vector <int> x, int L) {
		int n = (int)x.size();
		int cnt = n*(n-1)/2;
		sort(x.begin(), x.end());
		int ok = 0;
		for (int i=0; i<n-1; ++i)
			for (int j=i+1; j<n; ++j)
				ok += (x[i]>L || (x[j]-x[i] > L) || (100-x[j] > L));

		return double(ok)/cnt;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {25, 50, 75}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 25; double Arg2 = 1.0; verify_case(0, Arg2, probability(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {25, 50, 75}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 50; double Arg2 = 0.0; verify_case(1, Arg2, probability(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {25, 50, 75}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 24; double Arg2 = 1.0; verify_case(2, Arg2, probability(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {99, 88, 77, 66, 55, 44, 33, 22, 11}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 50; double Arg2 = 0.7222222222222222; verify_case(3, Arg2, probability(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    PipeCuts ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
