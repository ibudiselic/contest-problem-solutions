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
string to_str(int x) {
    ostringstream os;
    os << x;
    return os.str();
}
int dp[10][2][2];
int go(int p, bool can_over, bool can_under) {
    if (p == (int)A.size()) {
        return 1;
    }
    int &ret = dp[p][can_over][can_under];
    if (ret != -1) {
        return ret;
    }

    if (can_over) {
        if (can_under) {
            ret = 2*go(p+1, 1, 1);
        } else {
            if (A[p] > '7') {
                ret = 0;
            } else if (A[p] == '7') {
                ret = go(p+1, 1, 0);
            } else if (A[p] > '4') {
                ret = go(p+1, 1, 1);
            } else if (A[p] == '4') {
                ret = go(p+1, 1, 1) + go(p+1, 1, 0);
            } else {
                ret = 2*go(p+1, 1, 1);
            }
        }
    } else {
        if (can_under) {
            if (B[p] > '7') {
                ret = 2*go(p+1, 1, 1);
            } else if (B[p] == '7') {
                ret = go(p+1, 0, 1) + go(p+1, 1, 1);
            } else if (B[p] > '4') {
                ret = go(p+1, 1, 1);
            } else if (B[p] == '4') {
                ret = go(p+1, 0, 1);
            } else {
                ret = 0;
            }
        } else {
            ret = 0;
            if (B[p]>='7' && A[p]<='7') {
                ret += go(p+1, B[p]>'7', A[p]<'7');
            }
            if (B[p]>='4' && A[p]<='4') {
                ret += go(p+1, B[p]>'4', A[p]<'4');
            }
        }
    }

    return ret;
}

class TheLuckyNumbers {
	public:
	int count(int a, int b) {
		A = to_str(a);
        B = to_str(b);
        A = string(B.size()-A.size(), '0') + A;

        memset(dp, 0xff, sizeof dp);
        int sol = 0;
        for (int start=0; start<(int)A.size(); ++start) {
            if (A[start] != '0') {
                return sol + go(start, (start>0), 0);
            } else {
                sol += go(start, (start>0), 0);
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
	void test_case_0() { int Arg0 = 1; int Arg1 = 10; int Arg2 = 2; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 11; int Arg1 = 20; int Arg2 = 0; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 74; int Arg1 = 77; int Arg2 = 2; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 1000000; int Arg1 = 5000000; int Arg2 = 64; verify_case(3, Arg2, count(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TheLuckyNumbers ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
