#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int L[120000];

vector<int> karatsuba(const vector<int> &x, const vector<int> &y) {
    int n = x.size();
    vector<int> ret(2*n, 0);
    if (n <= 64) {
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                ret[i+j] += x[i]*y[j];
            }
        }
        return ret;
    }
    int m = n/2;
    // x = x1*B^m + x0
    // y = y1*B^m + y0
    vector<int> x1(x.begin(), x.begin()+m);
    vector<int> x0(x.begin()+m, x.end());
    vector<int> y1(y.begin(), y.begin()+m);
    vector<int> y0(y.begin()+m, y.end());
    
    // x*y = z2*B^2m + z1*B^m + z0
    // z2 = x1*y1
    // z0 = x0*y0
    // z1 = x0*y1 + x1*y0 = (x0+x1)*(y0+y1) - z2 - z0
    vector<int> z2 = karatsuba(x1, y1);
    vector<int> z0 = karatsuba(x0, y0);
    
    vector<int> addx = x0;
    for (int i=0; i<m; ++i) {
        addx[i] += x1[i];
    }
    vector<int> addy = y0;
    for (int i=0; i<m; ++i) {
        addy[i] += y1[i];
    }
    vector<int> z1 = karatsuba(addx, addy);
    for (int i=0; i<n; ++i) {
        z1[i] -= z2[i] + z0[i];
    }
    for (int i=0; i<n; ++i) {
        ret[i] += z2[i];
        ret[i+m] += z1[i];
        ret[i+n] += z0[i];
    }
    
    return ret;
}
    
class CircularShifts {
	public:
	int maxScore(int N, int Z0, int A, int B, int M) {
		L[0] = Z0 % M;
        for (int i=1; i<2*N; ++i) {
            L[i] = ((long long)L[i-1]*A + B) % M;
        }
        
        vector<int> x, y;
        x.reserve(N);
        y.reserve(N);
        for (int i=0; i<N; ++i) {
            x.push_back(L[i] % 100);
            y.push_back(L[i+N] % 100);
        }
        reverse(x.begin(), x.end());
        while (x.size() & (x.size()-1)) { // zeros to front till 2^k
            x.push_back(0);
            y.push_back(0);
        }
        reverse(x.begin(), x.end());
        reverse(y.begin(), y.end());
        
        vector<int> muls = karatsuba(x, y);
        for (int i=N; i<muls.size(); ++i) {
            muls[i%N] += muls[i];
        }
        int sol = 0;
        for (int i=0; i<N; ++i) {
            sol = max(sol, muls[i]);
        }
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 1; int Arg2 = 1; int Arg3 = 0; int Arg4 = 13; int Arg5 = 5; verify_case(0, Arg5, maxScore(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 1; int Arg2 = 1; int Arg3 = 1; int Arg4 = 20; int Arg5 = 70; verify_case(1, Arg5, maxScore(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 23; int Arg2 = 11; int Arg3 = 51; int Arg4 = 4322; int Arg5 = 28886; verify_case(2, Arg5, maxScore(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 1000; int Arg1 = 3252; int Arg2 = 3458736; int Arg3 = 233421; int Arg4 = 111111111; int Arg5 = 2585408; verify_case(3, Arg5, maxScore(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 141; int Arg1 = 96478; int Arg2 = 24834; int Arg3 = 74860; int Arg4 = 92112; int Arg5 = 419992; verify_case(4, Arg5, maxScore(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    CircularShifts ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
