#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

vector<pii> a;
int tlim;
double dp[51][101];

double est(int n, int t) {
	if (t >= tlim)
		return 1e30;
	double &ret = dp[n][t];
	if (ret >= 0)
		return ret;
	ret = 0;
	double mul = 1.0;
	for (int i=0; i<n; ++i) {
		const int r = a[i].first;
		const int w = a[i].second;
		if (w > t) {
			double p = 1.0/(w-t);
			ret += p * mul * min( double(t+r), est(i, t+1) );
			mul *= 1-p;
		}
	}
	ret += mul * est(n, t+1);
	return ret;
}
class TakeBus {
	public:
	double expectedTime(vector <int> tripTime, vector <int> waitTime) {
		a.clear();
		tlim = -1;
		for (int i=0; i<(int)tripTime.size(); ++i) {
			tlim = max(tlim, waitTime[i]);
			a.push_back(make_pair(tripTime[i], waitTime[i]));
		}
		sort(a.begin(), a.end());
		for (int i=0; i<51; ++i)
			for (int j=0; j<101; ++j)
				dp[i][j] = -1.0;
		return est(a.size(), 0);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 5.5; verify_case(0, Arg2, expectedTime(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {100, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 9.5; verify_case(1, Arg2, expectedTime(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {6, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 5.9; verify_case(2, Arg2, expectedTime(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {100, 100, 100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3, 3, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 100.33333333333333; verify_case(3, Arg2, expectedTime(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    TakeBus ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
