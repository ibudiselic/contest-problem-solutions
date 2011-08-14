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
int n;
int dp[51][51][51];
int go(int p, int end, int q) {
    int &ret = dp[p][end][q];
    if (ret != -1) {
        return ret;
    }
    if (p == end) {
        ret = n - q;
    } else if (q == n) {
        ret = end - p;
    } else {
        ret = go(p+1, end, q) + 1;
        ret = min(ret, go(p, end, q+1) + 1);
        ret = min(ret, (S[p]!=S[q]) + go(p+1, end, q+1));
    }
    return ret;
}
class MakeSquare {
	public:
	int minChanges(string S) {
		::S = S;
        n = S.size();
        int sol = n;
        memset(dp, 0xff, sizeof dp);
        for (int i=1; i<n; ++i) {
            sol = min(sol, go(0, i, i));
        }
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "abcdabgcd"; int Arg1 = 1; verify_case(0, Arg1, minChanges(Arg0)); }
	void test_case_1() { string Arg0 = "abcdeabce"; int Arg1 = 1; verify_case(1, Arg1, minChanges(Arg0)); }
	void test_case_2() { string Arg0 = "abcdeabxde"; int Arg1 = 1; verify_case(2, Arg1, minChanges(Arg0)); }
	void test_case_3() { string Arg0 = "aabcaabc"; int Arg1 = 0; verify_case(3, Arg1, minChanges(Arg0)); }
	void test_case_4() { string Arg0 = "aaaaabaaaaabaaaaa"; int Arg1 = 2; verify_case(4, Arg1, minChanges(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    MakeSquare ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
