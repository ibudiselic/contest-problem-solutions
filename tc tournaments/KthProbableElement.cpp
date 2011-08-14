#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

double L[101], P[101], H[101], F[101];
class KthProbableElement {
	public:
	double probability(int M, int lowerBound, int upperBound, int N, int K) {
        N -= lowerBound;
        int sz = upperBound - lowerBound + 1;

        F[0] = 1.0;
        L[0] = P[0] = H[0] = 1.0;
        for (int i=1; i<=M; ++i) {
            F[i] = i * F[i-1];
            L[i] = L[i-1] * N / sz;
            P[i] = P[i-1] / sz;
            H[i] = H[i-1] * (sz-N-1) / sz;
        }
        double p = 0.0;
        for (int ns=1; ns<=M; ++ns) {
            for (int lower=0; lower+ns<=M; ++lower) {
                if (lower<K && lower+ns>=K) {
                    p += L[lower]*P[ns]*H[M-lower-ns] / F[lower] / F[ns] / F[M-lower-ns];
                }
            }
        }

        return p * F[M];
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 10; int Arg3 = 3; int Arg4 = 1; double Arg5 = 0.1; verify_case(0, Arg5, probability(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 2; int Arg3 = 2; int Arg4 = 2; double Arg5 = 0.5; verify_case(1, Arg5, probability(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 3; int Arg3 = 2; int Arg4 = 2; double Arg5 = 0.48148148148148145; verify_case(2, Arg5, probability(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 1; int Arg2 = 10; int Arg3 = 1; int Arg4 = 10; double Arg5 = 1.0000000000000003E-10; verify_case(3, Arg5, probability(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 4; int Arg1 = 61; int Arg2 = 65; int Arg3 = 62; int Arg4 = 3; double Arg5 = 0.15200000000000002; verify_case(4, Arg5, probability(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    KthProbableElement ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
