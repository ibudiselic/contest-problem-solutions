#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int mod = 1000000007;
vector<string> S;
int dp[50][1001];
int go(int last, int left) {
    int &ret = dp[last][left];
    if (ret != -1) {
        return ret;
    }
    if (left == 0) {
        return (ret = 1);
    }
    
    ret = 0;
    for (int i=0; i<(int)S.size(); ++i) {
        if (S[last].substr(S[last].size()-3) == S[i].substr(0, 3)) {
            ret = (ret + go(i, left-1)) % mod;
        }
    }
    return ret;
}
class EllysPlaylists {
	public:
	int countPlaylists(vector <string> songs, int K) {
        S = songs;
		memset(dp, 0xff, sizeof dp);
        int sol = 0;
        for (int i=0; i<(int)S.size(); ++i) {
            sol = (sol + go(i, K-1)) % mod;
        }
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = { "abcxxx", "xxxabc", "entersandman", "toxicity", "maneater", "heavensalie",
  "liebe", "citylights", "fadetoblack", "breakingthehabit", "yyydefg", "defgyyy" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 5; verify_case(0, Arg2, countPlaylists(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = { "aaaaaa", "aaabcd", "bcdaaa" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 13; verify_case(1, Arg2, countPlaylists(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = { "aaa", "aaaa", "aaaaa" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 27; verify_case(2, Arg2, countPlaylists(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = { "elly", "looks", "lovely" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 3; verify_case(3, Arg2, countPlaylists(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = { "life", "universe", "everything" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 42; int Arg2 = 0; verify_case(4, Arg2, countPlaylists(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = { "aaaaaaaaa", "aaabbbaaa", "aaacccaaa", "aaadddaaa", "aaaeeeaaa", "aaafffaaa" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; int Arg2 = 176782322; verify_case(5, Arg2, countPlaylists(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    EllysPlaylists ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
