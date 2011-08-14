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

long long mod = 1000000007;
long long C[100060][44];
long long multicombinations(int k, int n) {
    if (k == 0) {
        return (n==0 ? 1 : 0);
    }
    return C[n+k-1][k-1];
}
long long F[64];
vector<int> R;
int n;
int dp[41][43*40][41];
void inc(int &val, long long by) {
    val = (by+val)%mod;
}
int perm_cnt(int p, int len, int groups) {
    if (len <= 0) {
        return 0;
    }
    int &ret = dp[p][len][groups];
    if (ret != -1) {
        return ret;
    }
    if (p == n-1) {
        // floating groups would require 2 items to connect to the edges...
        ret = (len==1 && groups==0);
    } else {
        // choose where the new group will be - (groups+1) ways
        // groups must be seperated so this new group will remove 2*R[p] items
        ret = (groups+1LL) * perm_cnt(p+1, len-2*R[p], groups+1) % mod;
        
        // join pth item with an existing floating group
        if (groups >= 1) {
            // 2 - either left or right
            // extends the group by R[p]
            inc(ret, groups * 2LL * perm_cnt(p+1, len-R[p], groups));
        }
        
        // use pth item to join 2 existing floating groups
        if (groups >= 2) {
            inc(ret, (groups-1LL) * perm_cnt(p+1, len, groups-1));
        }
        
        // edge (left or right => 2);
        inc(ret, 2LL * perm_cnt(p+1, len-R[p], groups));
        
        // join a floating group to the edge
        if (groups >= 1) {
            inc(ret, 2LL * perm_cnt(p+1, len, groups-1));
        }
    }
    
    return ret;
}
class AppleTrees {
	public:
	int theCount(int D, vector <int> r) {
        n = r.size();
        F[0] = 1;
        for (int i=1; i<64; ++i) {
            F[i] = F[i-1]*i%mod;
        }
        C[0][0] = 1;
        for (int n=1; n<100060; ++n) {
            C[n][0] = 1;
            for (int k=1; k<=min(42, n); ++k) {
                C[n][k] = C[n-1][k] + C[n-1][k-1];
                if (C[n][k] >= mod) {
                    C[n][k] -= mod;
                }
            }
        }
        R = r;
        sort(R.rbegin(), R.rend());
        memset(dp, 0xff, sizeof dp);
        long long sol = 0;
        for (int len=n; len<=min(43*n, D); ++len) {
            sol = (sol + perm_cnt(0, len, 0)*multicombinations(n+1, D-len)) % mod;
        }
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arr1[] = {40}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10; verify_case(0, Arg2, theCount(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 4; int Arr1[] = {1, 1, 1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 24; verify_case(1, Arg2, theCount(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 4; int Arr1[] = {1, 1, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(2, Arg2, theCount(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 58; int Arr1[] = {5, 8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2550; verify_case(3, Arg2, theCount(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 47; int Arr1[] = {4, 8, 9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 28830; verify_case(4, Arg2, theCount(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 100000; int Arr1[] = {21, 37, 23, 13, 32, 22, 9, 39}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 923016564; verify_case(5, Arg2, theCount(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    AppleTrees ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
