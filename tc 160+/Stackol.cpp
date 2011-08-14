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

using namespace std;

string S;
const long long mod = 1000000007LL;
int one[2501][2501];
int cntA[2501], cntB[2501];
int n;
int get_count(int *cnt, int l, int r) {
    return cnt[r] - cnt[l];
}

int can_make(int i, int j, int k) {
    if (i>=j || j>k) {
        return 0;
    }
    int s1B = get_count(cntB, i, j);
    int s2A = get_count(cntA, j, k);
    bool s1topA = (S[i]=='A');
    bool s2topB = (j<k && S[j]=='B');
    
    if (s1B == s2A) {
        return !s2topB;
    } else if (s1B == s2A + 1) {
        return !s1topA;
    } else {
        return false;
    }
}

void add(long long &a, long long b) {
    a = (a+b)%mod;
}
long long ways[2][2501];
class Stackol {
	public:
	int countPrograms(vector <string> outputFragments, int K) {
		S = accumulate(outputFragments.begin(), outputFragments.end(), string());
        n = S.size();
        
        memset(cntA, 0, sizeof cntA);
        memset(cntB, 0, sizeof cntB);
        for (int i=1; i<=n; ++i) {
            cntA[i] = cntA[i-1] + (S[i-1]=='A');
            cntB[i] = cntB[i-1] + (S[i-1]=='B');
        }

        memset(one, 0, sizeof one);
        for (int i=0; i<n; ++i) {
            one[i][i] = 1;
            for (int j=i+1; j<=n; ++j) {
                int cA = get_count(cntA, i, j);
                one[i][j] = can_make(i, i+cA, j) + can_make(i, i+cA+1, j);
            }
        }
        one[n][n] = 1;
        
        long long sol = one[0][n];
        for (int i=0; i<=n; ++i) {
            ways[1][i] = one[i][n];
        }
        for (int i=2; i<=K; ++i) {
            for (int j=0; j<=n; ++j) {
                long long v = 0;
                for (int k=j; k<=n; ++k) {
                    add(v, one[j][k]*ways[(i+1)&1][k]%mod);
                }
                ways[i&1][j] = v;
            }
            add(sol, ways[i&1][0]);
        }
        
        return int(sol);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"A"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 3; verify_case(0, Arg2, countPrograms(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"AAAA","BABA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 0; verify_case(1, Arg2, countPrograms(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"AB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 1; verify_case(2, Arg2, countPrograms(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"AAABABABAABA", "AA", "BBAB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 94; verify_case(3, Arg2, countPrograms(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"AAAAAAAAAAAA","B"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 120; verify_case(4, Arg2, countPrograms(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    Stackol ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
