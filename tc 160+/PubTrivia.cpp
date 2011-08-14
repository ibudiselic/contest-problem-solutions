#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int T;
int N;
int P[500000], B[500000];
long long S[500001];
long long dp[500001][2];
void gen(int *v, int g, vector<int> x) {
    int k = 0;
    int M = x.size();
    for (int i=0; i<N; ++i) {
        v[i] = x[k];
        int s = (k+1) % M;
        x[k] = ((x[k] ^ x[s]) + 13) % g;
        k = s;
    }
}

class PubTrivia {
	public:
	long long maximumScore(int N_, int tokensNeeded, vector <int> p, vector <int> b) {
		N = N_;
        T = tokensNeeded;

        gen(P, 1001, p);
        gen(B, 10001, b);

        S[0] = 0;
        for (int i=0; i<N; ++i) {
            S[i+1] = S[i] + P[i];
        }

        dp[N][0] = dp[N][1] = 0;
        dp[N-1][0] = P[N-1];
        dp[N-1][1] = P[N-1] + (T==1 ? B[N-1] : 0);
        for (int p=N-2; p>=0; --p) {
            dp[p][0] = max(P[p] + dp[p+1][0], -P[p] + dp[p+1][1]);
            dp[p][1] = dp[p][0];
            if (p+T-1 < N) {
                dp[p][1] = max(dp[p][1], S[p+T]-S[p] + B[p+T-1] + dp[p+T][1]);
            }
        }

        return dp[0][1];
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 5; int Arr2[] = {1, 2, 3, 4, 5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0, 0, 0, 2, 5}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 20LL; verify_case(0, Arg4, maximumScore(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 3; int Arr2[] = {1, 2, 3, 4, 5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0, 0, 0, 2, 5}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 16LL; verify_case(1, Arg4, maximumScore(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 3; int Arr2[] = {1, 2, 3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {7, 0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 98LL; verify_case(2, Arg4, maximumScore(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 4; int Arr2[] = {998, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {9998, 1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 1056LL; verify_case(3, Arg4, maximumScore(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    PubTrivia ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
