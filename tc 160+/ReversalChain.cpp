#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

string A, B;

int dp[50][50][50][2][2];
int go(int l, int r, int start, int dir, bool canrot) {
    if (l > r) {
       return 0;
    }
    int &ret = dp[l][r][start][dir][canrot];
    if (ret != -1) {
        return ret;
    }

    int end;
    if (dir == 1) {
        end = start + r - l;
    } else {
        end = start - r + l;
    }

    ret = 123456789;
    if (canrot) {
        ret = min(ret, 1 + go(l, r, end, 1-dir, 0));
    }

    if (A[start] == B[l]) {
        ret = min(ret, go(l+1, r, start + (dir==1 ? 1 : -1), dir, 1));
    }

    if (A[end] == B[r]) {
        ret = min(ret, go(l, r-1, start, dir, 1));
    }

    return ret;
}

class ReversalChain {
	public:
	int minReversal(string init, string goal) {
		A = init;
        B = goal;

        memset(dp, 0xff, sizeof dp);
        int sol = go(0, (int)A.size()-1, 0, 1, 1);

        return sol<123456 ? sol : -1;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "1100"; string Arg1 = "0110"; int Arg2 = 1; verify_case(0, Arg2, minReversal(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "111000"; string Arg1 = "101010"; int Arg2 = 2; verify_case(1, Arg2, minReversal(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "0"; string Arg1 = "1"; int Arg2 = -1; verify_case(2, Arg2, minReversal(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "10101"; string Arg1 = "10101"; int Arg2 = 0; verify_case(3, Arg2, minReversal(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "111000111000"; string Arg1 = "001100110011"; int Arg2 = 4; verify_case(4, Arg2, minReversal(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    ReversalChain ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
