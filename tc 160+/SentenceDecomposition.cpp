#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

string S;
vector<string> W;
int dp[51][51];
int inf = 123456789;
int dp2[51][51];
int cnt[50][26];
int cntS[50][50][26];

int match(int p, int w) {
    int &ret = dp2[p][w];
    if (ret != -1) {
        return ret;
    }
    for (int i=0; i<26; ++i) {
        if (cnt[w][i] != cntS[p][p+(int)W[w].size()-1][i]) {
            return (ret = inf);
        }
    }

    ret = 0;
    for (int i=0; i<(int)W[w].size(); ++i) {
        ret += (S[p+i] != W[w][i]);
    }

    return ret;
}
int go(int p, int words) {
    int &ret = dp[p][words];
    if (ret != -1) {
        return ret;
    }
    if (p == (int)S.size()) {
        return (ret = 0);
    }

    ret = inf;
    for (int i=0; i<(int)W.size(); ++i) {
        if (p+W[i].size() <= (int)S.size()) {
            int t = match(p, i) + go(p+W[i].size(), words+1);
            ret = min(ret, t);
        }
    }

    return ret;
}
class SentenceDecomposition {
	public:
	int decompose(string S_, vector <string> W_) {
		S = S_;
        W = W_;

        memset(cnt, 0, sizeof cnt);
        for (int i=0; i<(int)W.size(); ++i) {
            for (int j=0; j<(int)W[i].size(); ++j) {
                ++cnt[i][W[i][j]-'a'];
            }
        }

        memset(cntS, 0, sizeof cntS);
        for (int i=0; i<(int)S.size(); ++i) {
            for (int j=i; j<(int)S.size(); ++j) {
                for (int k=i; k<=j; ++k) {
                    ++cntS[i][j][S[k]-'a'];
                }
            }
        }

        memset(dp, 0xff, sizeof dp);
        memset(dp2, 0xff, sizeof dp2);
        

        int t = go(0, 0);
        return (t < inf ? t : -1);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "neotowheret"; string Arr1[] = {"one", "two", "three", "there"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 8; verify_case(0, Arg2, decompose(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "abba"; string Arr1[] = {"ab", "ac", "ad"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(1, Arg2, decompose(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "thisismeaningless"; string Arr1[] = {"this", "is", "meaningful"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(2, Arg2, decompose(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "ommwreehisymkiml"; string Arr1[] = {"we", "were", "here", "my", "is", "mom", "here", "si", "milk", "where", "si"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10; verify_case(3, Arg2, decompose(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "ogodtsneeencs"; string Arr1[] = {"go", "good", "do", "sentences", "tense", "scen"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 8; verify_case(4, Arg2, decompose(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "sepawaterords"; string Arr1[] = {"separate","words"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(5, Arg2, decompose(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    SentenceDecomposition ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
