#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <numeric>

using namespace std;

long long mod = 1234567891LL;

typedef vector< vector<long long> > vll;

vll matmul(const vll &A, const vll &B) {
    int m = A.size();
    int n = B[0].size();
    int x = B.size();
    vll C(m, vector<long long>(n, 0));
    
    for (int i=0; i<m; ++i) {
        for (int j=0; j<n; ++j) {
            for (int k=0; k<x; ++k) {
                C[i][j] = (C[i][j] + A[i][k]*B[k][j]) % mod;
            }
        }
    }
    
    return C;
}
vll matadd(const vll &A, const vll &B) {
    int m = A.size();
    int n = A[0].size();
    vll C(m, vector<long long>(n, 0));
    for (int i=0; i<m; ++i) {
        for (int j=0; j<n; ++j) {
            C[i][j] = A[i][j] + B[i][j];
            if (C[i][j] >= mod) {
                C[i][j] -= mod;
            }
        }
    }
    
    return C;
}

vll matunit(int n) {
    vll ret(n, vector<long long>(n, 0));
    for (int i=0; i<n; ++i) {
        ret[i][i] = 1;
    }
    
    return ret;
}
vll matexp(vll A, int n) {
    int m = A.size();
    vll ret = matunit(m);

    while (n > 0) {
        if (n & 1) {
            ret = matmul(ret, A);
        }
        A = matmul(A, A);
        n >>= 1;
    }

    return ret;
}
    
int K;
vll T;

vll SA(int n) {
    assert(n > 0);
    if (n == 1) {
        return T;
    } else if (n & 1) {
        return matadd(matmul(SA(n-1), T), T);
    } else {
        return matmul(matadd(matexp(T, n/2), matunit(27)), SA(n/2));
    }
}
    
long long S(int n) {
    vll t = SA(n);
    return accumulate(t[0].begin(), t[0].begin()+K+1, 0LL) % mod;
}

class TheLongPalindrome {
	public:
	int count(int n, int k) {
        K = k;
        T.assign(27, vector<long long>(27, 0));
        int start_row = 0;
        for (int j=1; j<27; ++j) {
            T[start_row][j] = 27-j;
            T[++start_row][j] = j;
        }
        if (n & 1) {
            return ((n>1 ? S((n-1)/2) : 0) + S((n+1)/2)) % mod;
        } else {
            return 2*S(n/2) % mod;
        }
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 26; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 10; int Arg2 = 52; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 728; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 44; int Arg1 = 7; int Arg2 = 240249781; verify_case(3, Arg2, count(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TheLongPalindrome ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
