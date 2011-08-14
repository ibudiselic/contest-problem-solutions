#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

double dp[1<<16];
vector<int> F;

inline double area(int a, int b, int c) {
	double s = (a+b+c)/2.0;
	return sqrt(s*(s-a)*(s-b)*(s-c));
}
double go(unsigned mask) {
	if (dp[mask] > -0.5)
		return dp[mask];
	if (mask == 0)
		return dp[mask] = 0.0;

	double ret = 0.0;
	for (int i=0; i<(int)F.size(); ++i)
		if (mask & (1<<i)) {
			const unsigned m1 = (1<<i);
			for (int j=i+1; j<(int)F.size(); ++j)
				if (mask & (1<<j)) {
					const unsigned m2 = (1<<j);
					for (int k=j+1; k<(int)F.size(); ++k)
						if (mask & (1<<k)) {
							const unsigned m3 = (1<<k);
							if (F[i]+F[j] > F[k])
								ret = max(ret, area(F[i], F[j], F[k])+go(mask^m1^m2^m3));
						}
				}
		}
	return dp[mask] = ret;
}
class GrasslandFencer {
	public:
	double maximalFencedArea(vector <int> fences) {
		F = fences;
		for (int i=0; i<(1<<fences.size()); ++i)
			dp[i] = -1.0;

		sort(F.begin(), F.end());
		return go((1u<<fences.size())-1);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3,4,5,6,7,8,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 36.754383146489694; verify_case(0, Arg1, maximalFencedArea(Arg0)); }
	void test_case_1() { int Arr0[] = {1,2,4,8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.0; verify_case(1, Arg1, maximalFencedArea(Arg0)); }
	void test_case_2() { int Arr0[] = {7,4,4,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 6.928203230275509; verify_case(2, Arg1, maximalFencedArea(Arg0)); }
	void test_case_3() { int Arr0[] = {21,72,15,55,16,44,54,63,69,35,75,69,76,70,50,81}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 7512.322360676162; verify_case(3, Arg1, maximalFencedArea(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    GrasslandFencer ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
