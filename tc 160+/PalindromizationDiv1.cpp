#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int add[26];
int del[26];
int change[26][26];
int dp[50][51];
const int inf = 987654321;
void upd(int &a, int b) {
    if (a > b) {
        a = b;
    }
}
class PalindromizationDiv1 {
	public:
	int getMinimumCost(string W, vector <string> ops) {
		int n = W.size();
        memset(add, 0xff, sizeof add);
        memset(del, 0xff, sizeof del);
        memset(change, 0xff, sizeof change);
        
        for (int i=0; i<(int)ops.size(); ++i) {
            istringstream is(ops[i]);
            string op;
            is >> op;
            char a, b;
            int x;
            if (op[0] == 'a') {
                is >> a >> x;
                add[a-'a'] = x;
            } else if (op[0] == 'e') {
                is >> a >> x;
                del[a-'a'] = x;
            } else {
                is >> a >> b >> x;
                change[a-'a'][b-'a'] = x;
            }
        }

        for (int i=0; i<26; ++i) {
            change[i][i] = 0;
        }
        for (int k=0; k<26; ++k) {
            for (int i=0; i<26; ++i) {
                if (change[i][k] == -1) {
                    continue;
                }
                for (int j=0; j<26; ++j) {
                    if (change[k][j] == -1) {
                        continue;
                    }
                    if (change[i][j]==-1 || change[i][j]>change[i][k]+change[k][j]) {
                        change[i][j] = change[i][k] + change[k][j];
                    }
                }
            }
        }
        
        for (int i=0; i<26; ++i) {
            for (int j=0; j<26; ++j) {
                if (change[i][j] != -1) {
                    if (del[j] != -1) {
                        if (del[i]==-1 || del[i]>change[i][j]+del[j]) {
                            del[i] = change[i][j] + del[j];
                        }
                    }
                    if (add[i] != -1) {
                        if (add[j]==-1 || add[j]>add[i]+change[i][j]) {
                            add[j] = add[i] + change[i][j];
                        }
                    }
                }
            }
        }
        
        for (int i=0; i<n; ++i) {
            dp[i][i+1] = dp[i][i] = 0;
        }
        for (int len=2; len<=n; ++len) {
            for (int i=0; i+len<=n; ++i) {
                dp[i][i+len] = inf;
                for (int c=0; c<26; ++c) {
                    if (change[W[i]-'a'][c] != -1) {
                        if (add[c] != -1) {
                            upd(dp[i][i+len], dp[i+1][i+len] + change[W[i]-'a'][c] + add[c]);
                        }
                        if (del[c] != -1) {
                            upd(dp[i][i+len], dp[i+1][i+len] + change[W[i]-'a'][c] + del[c]);
                        }
                    }
                    if (change[W[i+len-1]-'a'][c] != -1) {
                        if (add[c] != -1) {
                            upd(dp[i][i+len], dp[i][i+len-1] + change[W[i+len-1]-'a'][c] + add[c]);
                        }
                        if (del[c] != -1) {
                            upd(dp[i][i+len], dp[i][i+len-1] + change[W[i+len-1]-'a'][c] + del[c]);
                        }
                    }
                    if (change[W[i]-'a'][c]!=-1 && change[W[i+len-1]-'a'][c]!=-1) {
                        upd(dp[i][i+len], dp[i+1][i+len-1] + change[W[i]-'a'][c] + change[W[i+len-1]-'a'][c]);
                    }
                }
            }
        }

        return dp[0][n]==inf ? -1 : dp[0][n];
    }







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if (Case==-1 || Case==5) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "racecar"; string Arr1[] = {}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(0, Arg2, getMinimumCost(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "topcoder"; string Arr1[] = {"erase t 1", "erase o 1", "erase p 1", "erase c 1", "erase d 1", "erase e 1", "erase r 1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(1, Arg2, getMinimumCost(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "topcoder"; string Arr1[] = {"erase t 10", "erase o 1", "erase p 1", "erase c 1", "erase d 1", "erase e 1", "erase r 1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 7; verify_case(2, Arg2, getMinimumCost(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "caaaaaab"; string Arr1[] = {"change b a 100000", "change c a 100000", "change c d 50000", "change b e 50000", "erase d 50000", "erase e 49999"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 199999; verify_case(3, Arg2, getMinimumCost(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "moon"; string Arr1[] = {"erase o 5", "add u 7", "change d p 3", "change m s 12", "change n d 6", "change s l 1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(4, Arg2, getMinimumCost(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "ltbgpjcsaknlzctionkqffrpevmybpptydvizassekdoznkln"; string Arr1[] = {"change g n 47673", "erase r 77264", "change l t 42081", "add r 4800", "add b 96464", "erase k 51662", "change b n 39898", "erase d 22461", "erase g 27854", "change p u 14295", "add d 51496", "add e 75369", "add o 87389", "change t z 27185", "change c z 71695", "change b l 54216", "add i 19003", "add f 27638", "add u 85866", "change j u 67802", "erase t 57582", "erase i 22054", "add k 10000", "change q b 34740", "add q 72938", "change x m 44234", "erase s 36666", "erase b 14907", "add h 69181", "erase f 99058", "change p b 90898", "erase l 21277", "add x 32316", "change c m 85633", "change v o 96383", "change y u 61797", "change h v 19755", "change p r 8901", "change n h 99960"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1629924; verify_case(5, Arg2, getMinimumCost(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    PalindromizationDiv1 ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
