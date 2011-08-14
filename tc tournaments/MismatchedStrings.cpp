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

int n;
long long dp[55][55];
long long calc(int b, int rem) {
    if (b < 0) {
        return (1LL<<rem);
    }
    if (rem == 0) {
        return (b!=0);
    }

    long long &ret = dp[b][rem];
    if (ret != -1) {
        return ret;
    }

    return (ret = calc(b+1, rem-1) + calc(b-1, rem-1));
}

long long cnt(const string &s) {
    int b = 0;
    for (int i=0; i<(int)s.size(); ++i) {
        if (s[i] == '(') {
            ++b;
        } else if (--b < 0) {
            return (1LL << (n-s.size()));
        }
    }

    return calc(b, n-s.size());
}
class MismatchedStrings {
	public:
	string getString(int N, long long K) {
        n = N;
        memset(dp, 0xff, sizeof dp);
        string sol;
        if (cnt(sol) <= K) {
            return "";
        }

        for (int i=0; i<n; ++i) {
            sol += '(';
            long long t = cnt(sol);
            if (t <= K) {
                K -= t;
                sol[i] = ')';
            }
        }

        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; long long Arg1 = 0LL; string Arg2 = "(((("; verify_case(0, Arg2, getString(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 4; long long Arg1 = 4LL; string Arg2 = "())("; verify_case(1, Arg2, getString(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 6; long long Arg1 = 63LL; string Arg2 = ""; verify_case(2, Arg2, getString(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 7; long long Arg1 = 13LL; string Arg2 = "((())()"; verify_case(3, Arg2, getString(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    MismatchedStrings ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
