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

long long dp[18][2][2][2];
int digs[] = {0, 1, 2, 3, 5, 6, 8, 9};
string S;
long long go(int pos, bool any, bool have_one, bool zero) {
    long long &ret = dp[pos][any][have_one][zero];
    if (ret != -1) {
        return ret;
    }
    if (pos == (int)S.size()) {
        return ret = 1;
    }
    ret = 0;
    if (any || S[pos]-'0'>=4) {
        ret += go(pos+1, any || 4<S[pos]-'0', have_one, false);
    }
    if (any || S[pos]-'0'>=7) {
        ret += go(pos+1, any || 7<S[pos]-'0', have_one, false);
    }
    if (!have_one) {
        for (int i=0; i<8; ++i) {
            int d = digs[i];
            if (any || S[pos]-'0'>=d) {
                ret += go(pos+1, any || d<S[pos]-'0', !(zero&&d==0), zero && d==0);
            }
        }
    }
    return ret;
}
long long calc(long long n) {
    ostringstream os;
    os << n;
    S = os.str();
    memset(dp, 0xff, sizeof dp);
    return go(0, 0, 0, true);
}
class TheAlmostLuckyNumbersDivOne {
	public:
	long long find(long long a, long long b) {
		return calc(b) - calc(a-1);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 4LL; long long Arg1 = 7LL; long long Arg2 = 4LL; verify_case(0, Arg2, find(Arg0, Arg1)); }
	void test_case_1() { long long Arg0 = 8LL; long long Arg1 = 19LL; long long Arg2 = 4LL; verify_case(1, Arg2, find(Arg0, Arg1)); }
	void test_case_2() { long long Arg0 = 28LL; long long Arg1 = 33LL; long long Arg2 = 0LL; verify_case(2, Arg2, find(Arg0, Arg1)); }
	void test_case_3() { long long Arg0 = 12345678900LL; long long Arg1 = 98765432100LL; long long Arg2 = 91136LL; verify_case(3, Arg2, find(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TheAlmostLuckyNumbersDivOne ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
