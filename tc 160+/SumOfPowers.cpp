#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

long long mod = 1000000007LL;
long long C[51][51];

typedef vector< vector<long long> > vll;

void add(vll &res, const vll &t) {
    for (int i=0; i<(int)res.size(); ++i) {
        for (int j=0; j<(int)res[i].size(); ++j) {
            res[i][j] = (res[i][j] + t[i][j]) % mod;
        }
    }
}

vll matmul(const vll &A, const vll &B) {
    assert(A[0].size() == B.size());
    vll C(A.size(), vector<long long>(B[0].size(), 0));

    for (int i=0; i<(int)C.size(); ++i) {
        for (int j=0; j<(int)C[i].size(); ++j) {
            for (int k=0; k<(int)B.size(); ++k) {
                C[i][j] = (C[i][j] + A[i][k]*B[k][j]) % mod;
            }
        }
    }

    return C;
}

void matexp(vll M, int n, vll &res) {
    res.assign(M.size(), vector<long long>(M[0].size(), 0));
    for (int i=0; i<(int)res.size(); ++i) {
        res[i][i] = 1;
    }

    while (n > 0) {
        if (n & 1) {
            res = matmul(res, M);
        }
        M = matmul(M, M);
        n >>= 1;
    }
}

class SumOfPowers {
	public:
	int value(int n, int k) {
		C[0][0] = 1;
        for (int i=1; i<=k; ++i) {
            C[i][i] = 1;
            C[i][0] = 1;
            for (int j=1; j<i; ++j) {
                C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
            }
        }

        vll M(k+2, vector<long long>(k+2, 0));
        for (int i=0; i<=k; ++i) {
            for (int j=0; j<=k; ++j) {
                M[i][j] = C[k-i][k-j];
            }
        }
        for (int i=0; i<=k+1; ++i) {
            M[i][k+1] = 1;
        }

        vll t;
        matexp(M, n-1, t);

        vll start(k+2, vector<long long>(1, 1));

        return matmul(t, start)[0][0];
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 1; int Arg2 = 15; verify_case(0, Arg2, value(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 2; int Arg2 = 30; verify_case(1, Arg2, value(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 13; int Arg1 = 5; int Arg2 = 1002001; verify_case(2, Arg2, value(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 123456789; int Arg1 = 1; int Arg2 = 383478132; verify_case(3, Arg2, value(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    SumOfPowers ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
