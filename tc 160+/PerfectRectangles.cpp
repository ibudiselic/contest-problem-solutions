#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool black[2002][2002];
int cntR[2002][2002];
int cntC[2002][2002];
int H[2002], I[2002], cntH[2002], h2j[2002][2002];
bool isPerfect(int r1, int c1, int r2, int c2) {
    return cntR[r1-1][c2] != cntR[r1-1][c1-1] &&
           cntR[r2+1][c2] != cntR[r2+1][c1-1] &&
           cntC[c1-1][r2] != cntC[c1-1][r1-1] &&
           cntC[c2+1][r2] != cntC[c2+1][r1-1];
}
class PerfectRectangles {
	public:
	int numberOfRectangles(int N, int M, int X0, int A, int B, int Y0, int C, int D) {
		memset(black, 0, sizeof black);
        int r = X0 % N;
        int c = Y0 % N;
        for (int i=0; i<M; ++i) {
            black[r+1][c+1] = true;
            r = (r*A + B) % N;
            c = (c*C + D) % N;
        }
        
        for (int i=0; i<N+2; ++i) {
            black[i][0] = black[i][N+1] = true;
            black[0][i] = black[N+1][i] = true;
        }
        memset(cntR, 0, sizeof cntR);
        memset(cntC, 0, sizeof cntC);
        for (int i=0; i<N+2; ++i) {
            cntR[i][0] = 1;
            for (int j=1; j<N+2; ++j) {
                cntR[i][j] = cntR[i][j-1] + black[i][j];
            }
        }
        for (int j=0; j<N+2; ++j) {
            cntC[j][0] = 1;
            for (int i=1; i<N+2; ++i) {
                cntC[j][i] = cntC[j][i-1] + black[i][j];
            }
        }
        
        int sol = 0;
        memset(H, 0, sizeof H);
        for (int i=1; i<N+1; ++i) {
            for (int j=1; j<N+1; ++j) {
                if (!black[i][j]) {
                    ++H[j];
                } else {
                    H[j] = 0;
                }
            }
            memset(cntH, 0, sizeof cntH);
            for (int j=1; j<N+1; ++j) {
                h2j[H[j]][cntH[H[j]]++] = j;
            }
            
            memset(I, 0xff, sizeof I);
            for (int h=N+1; h>0; --h) {
                for (int t=0; t<cntH[h]; ++t) {
                    const int j = h2j[h][t];
                    const int l = (I[j-1]==-1 ? j : I[j-1]);
                    const int r = (I[j+1]==-1 ? j : I[j+1]);
                    I[l] = r; I[r] = l;
                    sol += isPerfect(i+1-h, l, i, r);
                }
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
	void test_case_0() { int Arg0 = 5; int Arg1 = 1; int Arg2 = 2; int Arg3 = 0; int Arg4 = 0; int Arg5 = 2; int Arg6 = 0; int Arg7 = 0; int Arg8 = 4; verify_case(0, Arg8, numberOfRectangles(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 4; int Arg2 = 0; int Arg3 = 1; int Arg4 = 1; int Arg5 = 0; int Arg6 = 1; int Arg7 = 1; int Arg8 = 6; verify_case(1, Arg8, numberOfRectangles(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 1000000; int Arg2 = 1; int Arg3 = 2; int Arg4 = 3; int Arg5 = 1; int Arg6 = 4; int Arg7 = 7; int Arg8 = 0; verify_case(2, Arg8, numberOfRectangles(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 20; int Arg2 = 4; int Arg3 = 76; int Arg4 = 2; int Arg5 = 6; int Arg6 = 2; int Arg7 = 43; int Arg8 = 12; verify_case(3, Arg8, numberOfRectangles(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    PerfectRectangles ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
