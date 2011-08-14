#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int bc(int x) {
    int ret = 0;
    while (x > 0) {
        ++ret;
        x &= (x-1);
    }

    return ret;
}

int dp[32][32][32][32][2];
int N;
const int INIT = (1LL<<31) - 1;

int go(int p, int a, int b, int c, bool carry) {
    if (a<0 || b<0 || c<0) {
        return INIT;
    }
    if (p == N) {
        if (a==0 && b==0 && c==0 && !carry) {
            return 0;
        }
        return INIT;
    }

    int &ret = dp[p][a][b][c][carry];
    if (ret != -1) {
        return ret;
    }

    ret = INIT;
    int x, y;
    if (carry) {
        x = min(go(p+1, a-1, b, c, 1), go(p+1, a, b-1, c, 1));
        y = min(go(p+1, a, b, c-1, 0), go(p+1, a-1, b-1, c-1, 1));
    } else {
        x = min(go(p+1, a, b, c, 0), go(p+1, a-1, b-1, c, 1));
        y = min(go(p+1, a-1, b, c-1, 0), go(p+1, a, b-1, c-1, 0));
    }
    if (x != INIT) {
        ret = min(ret, x);
    }

    if (y != INIT) {
        ret = min(ret, (y|(1<<p)));
    }

    return ret;
}

class BinarySum {
	public:
	int rearrange(int a, int b, int c) {
        memset(dp, 0xff, sizeof dp);

        long long t = 1;
        int n = 1;
        while (t <= a) {
            t <<= 1;
            ++n;
        }
        while (t <= b) {
            t <<= 1;
            ++n;
        }
        while (t <= c) {
            t <<= 1;
            ++n;
        }

        N = n-1;
        int sol = go(0, bc(a), bc(b), bc(c), 0);

        return (sol==INIT ? -1 : sol);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 7; int Arg1 = 6; int Arg2 = 9; int Arg3 = 10; verify_case(0, Arg3, rearrange(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 2; int Arg3 = 2; verify_case(1, Arg3, rearrange(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 4; int Arg3 = 2; verify_case(2, Arg3, rearrange(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 9; int Arg3 = 6; verify_case(3, Arg3, rearrange(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1; int Arg3 = -1; verify_case(4, Arg3, rearrange(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 32517565; int Arg1 = 204650420; int Arg2 = 4096; int Arg3 = -1; verify_case(5, Arg3, rearrange(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    BinarySum ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
