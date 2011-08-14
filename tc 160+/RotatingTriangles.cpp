#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;
enum {
    WHITE, BLACK, TRI, DUMMY
};
const int N = 54;
int A[N][N], B[N][N];
inline bool is_a(int x) {
    return x==BLACK || x==TRI;
}
inline bool is_b(int x) {
    return x == TRI;
}
inline bool is_c(int x) { 
    return x==WHITE || x==TRI;
}

class RotatingTriangles {
	public:
	int count(vector <string> grid) {
        memset(A, 0, sizeof A);
        for (int i=0; i<N; ++i) {
            A[i][0] = A[i][N-1] = DUMMY;
            A[0][i] = A[N-1][i] = DUMMY;
        }
        for (int i=0; i<(int)grid.size(); ++i) {
            for (int j=0; j<(int)grid[0].size(); ++j) {
                A[i+2][j+2] = (grid[i][j]=='.' ? WHITE : (grid[i][j]=='#' ? BLACK : TRI));
            }
        }
        
        int sol = 0;
        for (int t=0; t<4; ++t) {
            for (int i=2; i<N-2; ++i) {
                for (int j=2; j<N-2; ++j) {
                    int d = 0;
                    bool failed = false;
                    while (!failed) {
                        if (!is_c(A[i+d][j-1]) || !is_b(A[i+d][j+d])) {
                            break;
                        }
                        bool add = is_c(A[i+d+1][j+d]);
                        for (int k=0; k<d; ++k) {
                            if (!is_a(A[i+d][j+k])) {
                                failed = true;
                                break;
                            }
                            if (!is_c(A[i+d+1][j+k])) {
                                add = false;
                            }
                        }
                        if (!failed) {
                            sol += add;
                        }
                        ++d;
                    }
                    d = 0;
                    failed = false;
                    while (!failed) {
                        if (!is_b(A[i+d][j-d]) || !is_b(A[i+d][j+1+d])) {
                            break;
                        }
                        bool add = is_c(A[i+d+1][j-d]) && is_c(A[i+d+1][j+1+d]);
                        for (int k=0; k<2*d; ++k) {
                            if (!is_a(A[i+d][j-d+1+k])) {
                                failed = true;
                                break;
                            }
                            if (!is_c(A[i+d+1][j-d+1+k])) {
                                add = false;
                            }
                        }
                        if (!failed) {
                            sol += add;
                        }
                        ++d;
                    }
                }
            }
            
            for (int i=0; i<N; ++i) {
                for (int j=0; j<N; ++j) {
                    B[j][N-1-i] = A[i][j];
                }
            }
            memcpy(A, B, sizeof B);
        }
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"//"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { string Arr0[] = {"#//#./#/#",
 "####.#/##",
 "...../#.#",
 ".....####"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { string Arr0[] = {".#.",
 "#/#",
 ".#."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { string Arr0[] = {".../...",
 "..///./",
 ".//#/./"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 46; verify_case(3, Arg1, count(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    RotatingTriangles ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
