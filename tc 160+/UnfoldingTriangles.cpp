#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

const int N = 54;
int A[N][N];
enum {
    WHITE, BLACK, TRI, DUMMY
};
bool is_c(int x) {
    return x==WHITE || x==TRI;
}
bool is_a(int x) {
    return x==BLACK || x==TRI;
}
class UnfoldingTriangles {
	public:
	int solve(vector <string> grid, int unfoldLimit) {
		memset(A, 0, sizeof A);
        for (int i=0; i<N; ++i) {
            A[i][0] = A[i][N-1] = DUMMY;
            A[0][i] = A[N-1][i] = DUMMY;
        }
        for (int i=0; i<(int)grid.size(); ++i) {
            for (int j=0; j<(int)grid[0].size(); ++j) {
                A[i+2][j+2] = (grid[i][j]=='.' ? WHITE : (grid[i][j]=='/' ? TRI : BLACK));
            }
        }
        
        int sol = -1;
        for (int i=2; i<N-2; ++i) {
            for (int j=2; j<N-2; ++j) {
                int cnt = 0;
                for (int d=0; ; ++d) {
                    if (A[i+d][j-d]!=TRI || !is_c(A[i+d][j+1])) {
                        break;
                    }
                    bool add = is_c(A[i+d+1][j-d]);
                    bool good = true;
                    for (int k=0; k<d; ++k) {
                        if (!is_a(A[i+d][j-k])) {
                            good = false;
                            break;
                        } else if (A[i+d][j-k] == TRI) {
                            ++cnt;
                        }
                        if (!is_c(A[i+d+1][j-k])) {
                            add = false;
                        }
                    }
                    if (!good || cnt>unfoldLimit) {
                        break;
                    }
                    if (add) {
                        sol = max(sol, d*(d+1)/2 + d+1);
                    }
                }
            }
        }
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".../",
 "../#",
 "./#/",
 "/#//"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 10; verify_case(0, Arg2, solve(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {".../",
 "../#",
 "./#/",
 "/#//"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 3; verify_case(1, Arg2, solve(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"////",
 "////",
 "////",
 "////"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 6; verify_case(2, Arg2, solve(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {".....#...",
 "....###.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = -1; verify_case(3, Arg2, solve(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"#//#",
 "#//#",
 "####",
 "///#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 1; verify_case(4, Arg2, solve(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {".../.../",
 "../#..//",
 "./.#.///",
 "/###...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 6; verify_case(5, Arg2, solve(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    UnfoldingTriangles ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
