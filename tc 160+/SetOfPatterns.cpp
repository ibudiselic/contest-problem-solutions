#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

int mod = 1000003;
int dp[50];
int len;
bool join(string &a, const string &b) {
    for (int i=0; i<(int)b.size(); ++i) {
        if (b[i] != '?') {
            if (a[i]!='?' && a[i]!=b[i]) {
                return false;
            }
            a[i] = b[i];
        }
    }

    return true;
}
int bc[1<<15];
int val[1<<15];
string S;
int M;

int go(int x) {
    if (x == len) {
        return 1;
    }

    int &ret = dp[x];
    if (ret != -1) {
        return ret;
    }

    ret = 0;
    if (S[x] != '?') {
        ret = go(x + 1);
    } else {
        ret = 26LL*go(x + 1) % mod;
    }

    return ret;
}

class SetOfPatterns {
	public:
	int howMany(vector <string> patterns, int k) {
		len = patterns[0].size();
        int N = patterns.size();

        bc[0] = 0;
        for (int m=1; m<(1<<N); ++m) {
            bc[m] = bc[m>>1] + (m&1);
        }

        memset(val, 0, sizeof val);
        for (M=1; M<(1<<N); ++M) {
            if (bc[M] >= k) {
                S = string(len, '?');
                for (int i=0; i<N; ++i) {
                    if ((M & (1<<i)) && !join(S, patterns[i])) {
                        goto SKIP;
                    }
                }

                memset(dp, 0xff, sizeof dp);
                val[M] = go(0);
                SKIP: ;
            }
        }

        int sol = 0;
        for (M=(1<<N)-1; M>=0; --M) {
            int t = bc[M];
            if (t < k) {
                continue;
            }
            for (int m=(M+1) & ~M; m<(1<<N); m = (M + m + 1) & ~M) {
                val[M] = (val[M] - val[M|m] + mod) % mod;
            }
            if (t == k) {
                sol = (sol + val[M]) % mod;
            }
        }

        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"?"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 26; verify_case(0, Arg2, howMany(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"a","b","c"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 3; verify_case(1, Arg2, howMany(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"a?","?b"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 1; verify_case(2, Arg2, howMany(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"?????"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 881343; verify_case(3, Arg2, howMany(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    SetOfPatterns ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
