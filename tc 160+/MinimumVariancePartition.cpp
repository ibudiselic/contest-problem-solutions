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

vector<int> V;
double dp[50][51];
bool done[50][51];

double sqr(double x) {
	return x*x;
}
double var(int start, int cnt) {
	int sum = accumulate(V.begin()+start, V.begin()+start+cnt, 0);
	double mean = double(sum)/cnt;

	double ret = 0.0;
	for (int i=start; i<start+cnt; ++i)
		ret += sqr(V[i]-mean);

	return ret/cnt;
}
double go(int start, int k) {
	if (start == (int)V.size())
		return k ? 1e32 : 0.0;
	if (k == 0)
		return 1e32;
	if (done[start][k])
		return dp[start][k];

	done[start][k] = 1;
	dp[start][k] = 1e32;
	for (int cnt=1; start+cnt<=(int)V.size(); ++cnt)
		dp[start][k] = min(dp[start][k], var(start, cnt) + go(start+cnt, k-1));

	return dp[start][k];
}
class MinimumVariancePartition {
	public:
	double minDev(vector <int> mixedSamples, int k) {
		memset(done, 0, sizeof done);
		V = mixedSamples;
		sort(V.begin(), V.end());

		return go(0, k);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3,4,7,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; double Arg2 = 7.5; verify_case(0, Arg2, minDev(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1000,500,1,500}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; double Arg2 = 0.0; verify_case(1, Arg2, minDev(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {54,653,876,2,75}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; double Arg2 = 0.0; verify_case(2, Arg2, minDev(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {42,234,10,1,123,545,436,453,74,85,34,999}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; double Arg2 = 1700.7397959183672; verify_case(3, Arg2, minDev(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {923,456,12,12,542,234,11,12,10,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; double Arg2 = 1850.3333333333333; verify_case(4, Arg2, minDev(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    MinimumVariancePartition ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
