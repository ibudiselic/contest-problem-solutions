#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int cnt[16][26];
int common_len[1<<16];
vector<string> W;
int n;
int dp[1<<16];
int bc[1<<16];
int go(int mask) {
    int &ret = dp[mask];
    if (ret != -1) {
        return ret;
    }
    if (mask == 0) {
        return (ret = 0);
    }
    if (bc[mask] == 1) {
        for (int i=0; i<n; ++i) {
            if (mask & (1<<i)) {
                return (ret = W[i].size());
            }
        }
    }
    ret = 123456789;
    for (int s=(mask-1)&mask; s>0; s=(s-1)&mask) {
        if (2*bc[s] <= bc[mask]) {
            ret = min(ret, go(s) + go(mask^s) - common_len[mask]);
        }
    }
    
    return ret;
}
class PrefixTree {
	public:
	int getNumNodes(vector <string> words) {
		sort(words.begin(), words.end());
        words.resize(unique(words.begin(), words.end()) - words.begin());
        W = words;
        
        memset(cnt, 0, sizeof cnt);
        for (int i=0; i<(int)W.size(); ++i) {
            for (int j=0; j<(int)W[i].size(); ++j) {
                ++cnt[i][W[i][j]-'a'];
            }
        }
        
        n = W.size();
        bc[0] = 0;
        for (int i=1; i<(1<<n); ++i) {
            bc[i] = bc[i>>1] + (i&1);
        }
        for (int mask=1; mask<(1<<n); ++mask) {
            common_len[mask] = 0;
            for (int c=0; c<26; ++c) {
                int val = 1234;
                for (int i=0; i<n; ++i) {
                    if (mask & (1<<i)) {
                        val = min(val, cnt[i][c]);
                    }
                }
                common_len[mask] += val;
            }
        }
        
        memset(dp, 0xff, sizeof dp);
        return 1 + go((1<<n)-1);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"topcoder"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(0, Arg1, getNumNodes(Arg0)); }
	void test_case_1() { string Arr0[] = {"topcoder","topcoder"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(1, Arg1, getNumNodes(Arg0)); }
	void test_case_2() { string Arr0[] = {"aab","ca"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(2, Arg1, getNumNodes(Arg0)); }
	void test_case_3() { string Arr0[] = {"aab","ca","ba"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(3, Arg1, getNumNodes(Arg0)); }
	void test_case_4() { string Arr0[] = {"ab","cd","ef"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(4, Arg1, getNumNodes(Arg0)); }
	void test_case_5() { string Arr0[] = {"a","aa","aaa"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(5, Arg1, getNumNodes(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    PrefixTree ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
