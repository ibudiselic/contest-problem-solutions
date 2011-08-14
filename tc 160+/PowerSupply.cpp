#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class PowerSupply {
	public:
	int calc(const vector<int> &a, long long D) {
		int ret = 0;
		int i, j;
		for (i=0; i<(int)a.size(); ++i) {
			for (j=i+1; j<(int)a.size(); ++j)
				if ((long long)(a[i]-a[j])*(a[i]-a[j]) > D) break;
			ret = max(ret, j-i);
		}
		return ret;
	}
	int maxProfit(vector <int> x, vector <int> y, int D) {
		long long hvD = (long long)D * D * 4; /* 2D */
		long long diagD = hvD * 2; /* 2sqrt(2)D */

		vector<int> s(x.size());
		for (int i=0; i<(int)x.size(); ++i) s[i] = x[i]+y[i];
		vector<int> bs(x.size());
		for (int i=0; i<(int)x.size(); ++i) bs[i] = x[i]-y[i];
		sort(x.begin(), x.end());
		sort(y.begin(), y.end());
		sort(s.begin(), s.end());
		sort(bs.begin(), bs.end());

		int sol = 0;
		sol = max(sol, calc( x,   hvD));
		sol = max(sol, calc( y,   hvD));
		sol = max(sol, calc( s, diagD));
		sol = max(sol, calc(bs, diagD));

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,3,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,6,-4,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 4; verify_case(0, Arg3, maxProfit(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {-1000000,13,1000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; int Arg3 = 3; verify_case(1, Arg3, maxProfit(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {-5,-2,2,8,-1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,1,2,8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 4; verify_case(2, Arg3, maxProfit(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {-5,-5,-2,-2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-2,-3,4,6,9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 4; verify_case(3, Arg3, maxProfit(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {511590, -60297, 337900, -322958, -806739, 358447, 685932, 663609, 276080, -213586}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-500859, -840607, -792296, -379621, -890856, 362559, -98535, 617148, -128203, 802475}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 31194; int Arg3 = 4; verify_case(4, Arg3, maxProfit(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    PowerSupply ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
