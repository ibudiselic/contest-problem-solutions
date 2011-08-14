#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

bool W[502][502];
bool done[502][502][5];
struct State {
    int i, j, d;
    State(int i_, int j_ , int d_): i(i_), j(j_), d(d_) {}
};
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };
class DoNotTurn {
	public:
	int minimumTurns(int N, int X0, int A, int B, int Y0, int C, int D, int P, int M) {
        memset(W, 0, sizeof W);
		long long x = X0 % P;
        long long y = Y0 % P;
        if (M > 0) {
            W[x%N + 1][y%N + 1] = 1;
            while (--M) {
                x = (x*A + B) % P;
                y = (y*C + D) % P;
                W[x%N + 1][y%N + 1] = 1;
            }
        }
        for (int i=0; i<N+2; ++i) {
            W[i][0] = 1;
            W[i][N+1] = 1;
            W[0][i] = 1;
            W[N+1][i] = 1;
        }
        W[1][1] = 0;
        W[N][N] = 0;
        
        queue<State> Q;
        Q.push(State(1, 1, 4));
        memset(done, 0, sizeof done);
        done[1][1][4] = 1;
        int t = 0;
        int sol = -1;
        while (!Q.empty()) {
            if (t == 0) {
                t = Q.size();
                ++sol;
            }
            --t;
            int i = Q.front().i;
            int j = Q.front().j;
            int d = Q.front().d;
            Q.pop();
            
            for (int nd=0; nd<4; ++nd) {
                if (nd != d) {
                    int r = i + di[nd];
                    int c = j + dj[nd];
                    while (!W[r][c]) {
                        if (!done[r][c][nd]) {
                            if (r==N && c==N) {
                                return sol;
                            }
                            done[r][c][nd] = true;
                            Q.push(State(r, c, nd));
                        } else {
                            break;
                        }
                        r += di[nd];
                        c += dj[nd];
                    }
                }
            }
        }
        
        return -1;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 0; int Arg2 = 0; int Arg3 = 1; int Arg4 = 0; int Arg5 = 0; int Arg6 = 1; int Arg7 = 10; int Arg8 = 2; int Arg9 = 1; verify_case(0, Arg9, minimumTurns(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 0; int Arg2 = 1; int Arg3 = 1; int Arg4 = 1; int Arg5 = 1; int Arg6 = 0; int Arg7 = 3; int Arg8 = 3; int Arg9 = -1; verify_case(1, Arg9, minimumTurns(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 0; int Arg2 = 1; int Arg3 = 1; int Arg4 = 1; int Arg5 = 1; int Arg6 = 1; int Arg7 = 3; int Arg8 = 3; int Arg9 = 3; verify_case(2, Arg9, minimumTurns(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 911111; int Arg2 = 845499; int Arg3 = 866249; int Arg4 = 688029; int Arg5 = 742197; int Arg6 = 312197; int Arg7 = 384409; int Arg8 = 40; int Arg9 = 12; verify_case(3, Arg9, minimumTurns(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_4() { int Arg0 = 5; int Arg1 = 23; int Arg2 = 2; int Arg3 = 3; int Arg4 = 35; int Arg5 = 5; int Arg6 = 7; int Arg7 = 9; int Arg8 = 3; int Arg9 = 2; verify_case(4, Arg9, minimumTurns(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_5() { int Arg0 = 2; int Arg1 = 0; int Arg2 = 0; int Arg3 = 0; int Arg4 = 0; int Arg5 = 0; int Arg6 = 0; int Arg7 = 1; int Arg8 = 0; int Arg9 = 1; verify_case(5, Arg9, minimumTurns(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    DoNotTurn ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
