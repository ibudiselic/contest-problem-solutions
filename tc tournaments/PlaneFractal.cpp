#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<string> sol;
long long A[11];
long long a, b;

inline bool between(long long a, long long b, long long c) {
    return b<=a && a<c;
}
char black(int r, int c, int sz) {
    if (sz == 0) {
        return '0';
    }
    if (between(r, a*A[sz-1], b*A[sz-1]) && between(c, a*A[sz-1], b*A[sz-1])) {
        return '1';
    } else {
        return black(r%A[sz-1], c%A[sz-1], sz-1);
    }
}
class PlaneFractal {
	public:
	vector <string> getPattern(int s, int N, int K, int r1, int r2, int c1, int c2) {
	    sol.assign(r2-r1+1, string(c2-c1+1, '0'));
        A[0] = 1;
        for (int i=1; i<=s; ++i) {
            A[i] = A[i-1] * N;
        }

        a = (N-K)/2;
        b = a + K;
        for (int i=r1; i<=r2; ++i) {
            for (int j=c1; j<=c2; ++j) {
                sol[i-r1][j-c1] = black(i, j, s);
            }
        }

        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 5; int Arg2 = 3; int Arg3 = 0; int Arg4 = 4; int Arg5 = 0; int Arg6 = 4; string Arr7[] = {"00000", "01110", "01110", "01110", "00000" }; vector <string> Arg7(Arr7, Arr7 + (sizeof(Arr7) / sizeof(Arr7[0]))); verify_case(0, Arg7, getPattern(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 3; int Arg2 = 1; int Arg3 = 0; int Arg4 = 8; int Arg5 = 0; int Arg6 = 8; string Arr7[] = {"000000000", "010010010", "000000000", "000111000", "010111010", "000111000", "000000000", "010010010", "000000000" }; vector <string> Arg7(Arr7, Arr7 + (sizeof(Arr7) / sizeof(Arr7[0]))); verify_case(1, Arg7, getPattern(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 1; int Arg3 = 4; int Arg4 = 11; int Arg5 = 5; int Arg6 = 10; string Arr7[] = {"101001", "100000", "000000", "001001", "000000", "000011", "001011", "000011" }; vector <string> Arg7(Arr7, Arr7 + (sizeof(Arr7) / sizeof(Arr7[0]))); verify_case(2, Arg7, getPattern(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_3() { int Arg0 = 2; int Arg1 = 8; int Arg2 = 4; int Arg3 = 56; int Arg4 = 61; int Arg5 = 33; int Arg6 = 56; string Arr7[] = {"000000000000000000000000", "000000000000000000000000", "011110000111100001111000", "011110000111100001111000", "011110000111100001111000", "011110000111100001111000" }; vector <string> Arg7(Arr7, Arr7 + (sizeof(Arr7) / sizeof(Arr7[0]))); verify_case(3, Arg7, getPattern(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    PlaneFractal ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
