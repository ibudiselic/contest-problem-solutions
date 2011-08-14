#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

// ne kuzim bas...

int dx[] = { 0, -1, -2, -2, -1, 1, 2, 1 };
int dy[] = { 0, 2, 1, -1, -2, -2, -1, 2 };
int mark[160][160][500];
int equ[500][500];
bool valid(int r, int c, int R, int C) {
    return r>=0 && r<R && c>=0 && c<C;
}
bool used[500];
class KnightsOut {
	public:
	int count(int M, int N) {
        if (M < N) {
            swap(M, N);
        }
		if (N == 1) {
            return 1;
        }
        
        memset(mark, 0, sizeof mark);
        memset(equ, 0, sizeof equ);
        int n = N*2 + M - 2;
        for (int i=0; i<N; ++i) {
            mark[0][i][i] = 1;
            mark[1][i][N+i] = 1;
        }
        for (int i=2; i<M; ++i) {
            mark[i][0][2*N+i-2] = 1;
        }
        
        int cnt = 0;
        for (int i=0; i<M; ++i) {
            for (int j=0; j<N; ++j) {
                if (valid(i+2, j+1, M, N)) {
                    for (int k=0; k<8; ++k) {
                        if (valid(i+dx[k], j+dy[k], M, N)) {
                            for (int l=0; l<n; ++l) {
                                mark[i+2][j+1][l] ^= mark[i+dx[k]][j+dy[k]][l];
                            }
                        }
                    }
                } else {
                    for (int k=0; k<8; ++k) {
                        if (valid(i+dx[k], j+dy[k], M, N)) {
                            for (int l=0; l<n; ++l) {
                                equ[cnt][l] ^= mark[i + dx[k]][j + dy[k]][l];
                            }
                        }
                    }
                    ++cnt;
                }
            }
        }
        
/*        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                cerr << equ[i][j];
            }
            cerr << '\n';
        }*/
        
        memset(used, 0, sizeof used);
        int rank = 0;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                if (!used[j] && equ[j][i]) {
                    used[j] = 1;
                    for (int k=0; k<n; ++k) {
                        if (!used[k] && equ[k][i]) {
                            for (int l=0; l<n; ++l) {
                                equ[k][l] ^= equ[j][l];
                            }
                        }
                    }
                    ++rank;
                    break;
                }
            }
        }
        
        long long ret = 1;
        for (int i=rank; i<n; ++i) {
            ret = 2*ret%123456789;
        }
        return ret;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 3; int Arg2 = 4; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 1; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 7; int Arg1 = 5; int Arg2 = 16; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1; verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 69; int Arg1 = 142; int Arg2 = 77502052; verify_case(4, Arg2, count(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    KnightsOut ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
