#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <numeric>
#include <iterator>

using namespace std;

long long mod = 1000000007LL;
long long dp[201];
long long C[201][201];
long long fastexp_mod(long long n, long long k) {
    if (n == 0) {
        return 0;
    }
    long long ret = 1;
    while (k > 0) {
        if (k & 1) {
            ret = ret*n%mod;
        }
        n = n*n%mod;
        k >>= 1;
    }
    return ret;
}
class PickAndDelete {
	public:
	int count(vector <string> S) {
		string s = accumulate(S.begin(), S.end(), string());
        istringstream is(s);
        vector<int> V;
        copy(istream_iterator<int>(is), istream_iterator<int>(), back_inserter(V));
        sort(V.begin(), V.end());
        
        int n = V.size();
        for (int i=1; i<=n; ++i) {
            C[i][0] = C[i][i] = 1;
            for (int j=1; j<i; ++j) {
                C[i][j] = C[i-1][j-1] + C[i-1][j];
                if (C[i][j] >= mod) {
                    C[i][j] -= mod;
                }
            }
        }
        
        dp[0] = 1;
        for (int i=1; i<=n; ++i) {
            dp[i] = fastexp_mod(V[i-1], i);
            for (int j=0; j<i-1; ++j) {
                dp[i] -= dp[j]*C[i][j]%mod*fastexp_mod(V[i-1]-V[j], i-j)%mod;
                if (dp[i] < 0) {
                    dp[i] += mod;
                }
            }
        }
        
        return dp[n];
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"1 2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { string Arr0[] = {"2 2 2 2 2 2 2 2 2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 512; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { string Arr0[] = {"5", " 1 ", "2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 34; verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { string Arr0[] = {"3 ", "14159 265", "3589 7", " 932"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 353127147; verify_case(3, Arg1, count(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    PickAndDelete ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
