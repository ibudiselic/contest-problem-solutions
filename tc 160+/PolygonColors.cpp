#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int n;
vector<int> C;
long long mod = 100000007;
long long dp[50][50][2];
long long go(int a, int b, bool join) {
    long long &ret = dp[a][b][join];
    if (ret != -1) {
        return ret;
    }
    if (b-a <= 1) {
        return 1;
    }

    ret = go(a+1, b, 1);
    for (int i=a+2; i<b+join; ++i) {
        if (C[a] != C[i]) {
            ret = (ret + go(a, i, 0)*go(i, b, 1)%mod) % mod;
        }
    }

    return ret;
}

class PolygonColors {
	public:
	int getWays(int N, vector <int> colors) {
		n = N;
        C = colors;
        for (int i=0; i<n; ++i) {
            if (C[i] == C[(i+1)%n]) {
                return 0;
            }
        }

        memset(dp, 0xff, sizeof dp);

        return int(go(0, n-1, 0));
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arr1[] = {1, 2, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(0, Arg2, getWays(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 4; int Arr1[] = {1, 2, 3, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(1, Arg2, getWays(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 5; int Arr1[] = {0, 1, 1, 1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(2, Arg2, getWays(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 16; int Arr1[] = {0,1,2,6,4,5,6,7,1,9,10,11,12,13,14,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 96791474; verify_case(3, Arg2, getWays(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    PolygonColors ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
