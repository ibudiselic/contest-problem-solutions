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

class DrawingMarbles {
	public:
	double sameColor(vector <int> colors, int n) {
		double sol = 0;
		int total = accumulate(colors.begin(), colors.end(), 0);
		for (int i=0; i<(int)colors.size(); ++i) {
			if (colors[i] >= n) {
				double t = 1.0;
				for (int j=0; j<n; ++j) {
					t *= double(colors[i]-j)/(total-j);
				}
				sol += t;
			}
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 13 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; double Arg2 = 1.0; verify_case(0, Arg2, sameColor(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = { 5, 7 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; double Arg2 = 1.0; verify_case(1, Arg2, sameColor(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = { 5, 6, 7 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; double Arg2 = 0.3006535947712418; verify_case(2, Arg2, sameColor(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = { 12, 2, 34, 13, 17 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; double Arg2 = 0.035028830818304504; verify_case(3, Arg2, sameColor(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    DrawingMarbles ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
