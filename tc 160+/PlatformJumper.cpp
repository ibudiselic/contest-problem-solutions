#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int dp[50];
int X[50], Y[50], C[50];
int N;
long long V, G;
long long sqr(long long x) { return x*x; }
int go(int pos) {
	if (dp[pos] != -1)
		return dp[pos];

	int ret = C[pos];
	for (int i=0; i<N; ++i)
		if (Y[i]<Y[pos] && 2*sqr(V)*(Y[pos]-Y[i])>=G*sqr(X[i]-X[pos]))
			ret = max(ret, C[pos]+go(i));

	return dp[pos] = ret;
}
class PlatformJumper {
	public:
	int maxCoins(vector <string> platforms, int v, int g) {
		N = platforms.size();
		V = v;
		G = g;
		for (int i=0; i<N; ++i)
			sscanf(platforms[i].c_str(), "%d %d %d", &X[i], &Y[i], &C[i]);

		memset(dp, 0xff, sizeof dp);

		int sol = 0;
		for (int i=0; i<N; ++i)
			sol = max(sol, go(i));

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"3 10 7", "5 15 7", "8 9 12" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 10; int Arg3 = 14; verify_case(0, Arg3, maxCoins(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"0 0 1", "2 4 1", "4 0 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; int Arg3 = 2; verify_case(1, Arg3, maxCoins(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"0 0 1", "5000 5000 10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; int Arg2 = 87; int Arg3 = 10; verify_case(2, Arg3, maxCoins(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    PlatformJumper ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
