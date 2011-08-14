#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int K;
int dp[1024];
int f(const vector<int> &P, int i) {
    int &ret = dp[i];
    if (ret != -1) {
        return ret;
    }
    if (i+K+1 >= (int)P.size()) {
        return (ret=0);
    }
    ret = max(f(P, i+K+1),
              f(P, i+2*K+2) + P[i] + P[i+K+1]);
    return ret;
}
class BunnyComputer {
	public:
	int getMaximum(vector <int> preference, int k) {
		int sol = 0;
        memset(dp, 0xff, sizeof dp);
        K = k;
        for (int i=0; i<=k; ++i) {
            sol += f(preference, i);
        }
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 3, 1, 4, 1, 5, 9, 2, 6 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 28; verify_case(0, Arg2, getMaximum(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = { 3, 1, 4, 1, 5, 9, 2, 6 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 31; verify_case(1, Arg2, getMaximum(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = { 1, 2, 3, 4, 5, 6 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 14; verify_case(2, Arg2, getMaximum(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = { 487, 2010 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 0; verify_case(3, Arg2, getMaximum(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    BunnyComputer ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
