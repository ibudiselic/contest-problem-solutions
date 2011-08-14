#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool done[1u<<15];
double dp[1u<<15];
vector<int> V, W;
int n;
double go(unsigned mask) {
	if (mask == 0)
		return 0.0;
	if (done[mask])
		return dp[mask];

	done[mask] = 1;
	double ret = 0.0;
	int w = 0;
	for (int i=0; i<n; ++i)
		if (mask & (1u<<i))
			w += W[i];

	for (int i=0; i<n; ++i)
		if (mask & (1u<<i)) {
			const int curw = w-W[i];
			double p = 1.0;
			double cur = V[i];
			for (int j=0; j<n; ++j)
				if (j!=i && (mask & (1u<<j))) {
					const double disprob = double(W[j])/(curw+100);
					p -= disprob;
					cur += disprob * go(mask ^ (1u<<i) ^ (1u<<j));
				}
			cur += p * go(mask ^ (1u<<i));
			ret = max(ret, cur);
		}

	return dp[mask] = ret;
}
class BagOfDevouring {
	public:
	double expectedYield(vector <int> values, vector <int> weights) {
		V = values;
		W = weights;
		n = V.size();
		memset(done, 0, sizeof done);

		return go((1u<<n)-1);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {100,100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {100,100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 150.0; verify_case(0, Arg2, expectedYield(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {100,200,300}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {100,200,300}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 462.5; verify_case(1, Arg2, expectedYield(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {100,200,300}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {300,200,100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 470.8333333333333; verify_case(2, Arg2, expectedYield(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.0; verify_case(3, Arg2, expectedYield(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {10,100,150,250,500,750,1000,2500,5000,7500,10000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {100,200,300,400,500,1000,2000,1500,3000,6000,4000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 20622.364509064962; verify_case(4, Arg2, expectedYield(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    BagOfDevouring ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
