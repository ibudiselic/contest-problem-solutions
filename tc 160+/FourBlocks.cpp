#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int m, n;
vector<string> G;
int dp[26][11][1<<10];
int go(int j, int p, int mask) {
    int &ret = dp[j][p][mask];
    if (ret != -1) {
        return ret;
    }
    if (j == n) {
        ret = 0;
        for (int i=0; i<m; ++i) {
            if (((mask>>i) & 1) == 0) {
                ++ret;
            }
        }
        return ret;
    }
    if (p == m) {
        return (ret = go(j+1, 0, mask));
    }
    
    ret = 0;
    int add = 1 - ((mask>>p)&1);
    if (G[p][j] == '1') {
        ret = max(ret, add + 1 + go(j, p+1, mask | (1<<p)));
    } else {
        ret = max(add + go(j, p+1, mask & ~(1<<p)), add + 1 + go(j, p+1, mask | (1<<p)));
        if (add && p+1<m && G[p+1][j]=='.') {
            int add2 = 1 - ((mask>>(p+1))&1);
            if (add2) {
                ret = max(ret, 16 + go(j, p+2, mask | (1<<p) | (1<<(p+1))));
            }
        }
    }
    
    return ret;
}
class FourBlocks {
	public:
	int maxScore(vector <string> grid) {
		G = grid;
        m = G.size();
        n = G[0].size();
        
        memset(dp, 0xff, sizeof dp);
        return go(0, 0, (1<<m)-1);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".....1..1..",
 "..1.....1.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 70; verify_case(0, Arg1, maxScore(Arg0)); }
	void test_case_1() { string Arr0[] = {"...1.",
 ".....",
 ".1..1",
 ".....",
 "1...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 73; verify_case(1, Arg1, maxScore(Arg0)); }
	void test_case_2() { string Arr0[] = {"...1.",
 ".1...",
 "..1.1",
 "1...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 20; verify_case(2, Arg1, maxScore(Arg0)); }
	void test_case_3() { string Arr0[] = {".....1...",
 ".....1...",
 "111111111",
 ".....1...",
 ".....1..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 117; verify_case(3, Arg1, maxScore(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    FourBlocks ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
