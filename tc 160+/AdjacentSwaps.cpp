#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

const long long mod = 1000000007;
bool G[50][2];
int C[51][51];
map<long long, int> memo;
int calc(int n, long long mask) {
    if (n <= 2) {
        return 1;
    }
    {
        const long long tmp = mask | (1ll<<(n-1));
        if (memo.count(tmp)) {
            return memo[tmp];
        }
    }
    int &ret = memo[mask | (1ll<<(n-1))];
    if (mask & 1) {
        ret += calc(n-1, mask>>1);
    }
    if (!(mask & (1ll<<(n-2)))) {
        ret += calc(n-1, mask);
        if (ret >= mod) {
            ret -= mod;
        }
    }
    for (int i=1; i+1<n; ++i) {
        if (((mask>>(i-1))&3) == 2) {
            long long w1 = calc(i, mask&((1ll<<(i-1))-1));
            long long w2 = calc(n-1-i, mask>>(i+1));
            long long val = w1*w2%mod*C[n-1][i]%mod;
            ret += val;
            if (ret >= mod) {
                ret -= mod;
            }
        }
    }
    
    return ret;
}
class AdjacentSwaps {
	public:
	int theCount(vector <int> p) {
        C[0][0] = 1;
        for (int n=1; n<51; ++n) {
            C[n][0] = C[n][n] = 1;
            for (int j=1; j<n; ++j) {
                C[n][j] = C[n-1][j-1] + C[n-1][j];
                if (C[n][j] >= mod) {
                    C[n][j] -= mod;
                }
            }
        }
        memset(G, 0, sizeof G);
        for (int i=0; i<(int)p.size(); ++i) {
            if (p[i] == i) {
                return 0;
            }
            if (p[i] > i) {
                if (i > 0) {
                    assert(i+1 < (int)p.size());
                    G[i][0] = 1;
                }
                for (int j=i; j+1<p[i]; ++j) {
                    G[j][1] = 1;
                }
                if (p[i]+1 < (int)p.size()) {
                    G[p[i]][0] = 1;
                }
            } else {
                if (i+1 < (int)p.size()) {
                    assert(i > 0);
                    G[i-1][1] = 1;
                }
                for (int j=i-1; j>p[i]; --j) {
                    G[j][0] = 1;
                }
                if (p[i] > 0) {
                    G[p[i]-1][1] = 1;
                }
            }
        }
        long long mask = 0;
        for (int i=1; i+1<(int)p.size(); ++i) {
            if (G[i-1][1] && G[i][0]) {
                return 0;
            }
            if (G[i-1][1]) {
                mask |= (1ll<<(i-1));
            }
        }
    
        memo.clear();
        return calc(p.size()-1, mask);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 2, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, theCount(Arg0)); }
	void test_case_1() { int Arr0[] = {0, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, theCount(Arg0)); }
	void test_case_2() { int Arr0[] = {2, 0, 3, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, theCount(Arg0)); }
	void test_case_3() { int Arr0[] = {1, 0, 3, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, theCount(Arg0)); }
	void test_case_4() { int Arr0[] = {1, 3, 0, 5, 2, 7, 4, 8, 10, 6, 12, 9, 14, 11, 16, 13, 18, 15, 19, 17}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 716743312; verify_case(4, Arg1, theCount(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    AdjacentSwaps ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
