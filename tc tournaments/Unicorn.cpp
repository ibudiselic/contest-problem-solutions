#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <utility>

using namespace std;

int ways[301][301];
int sum[301][301];
int ways2[301][301];
char B[301][301];
int R, C;
int mod = 1000000007;

inline void add(int &lhs, int rhs) {
    lhs = (lhs + rhs) % mod;
}
inline void sub(int &lhs, int rhs) {
    lhs = (lhs - rhs + mod) % mod;
}

void make_sum() {
    memset(sum, 0, sizeof sum);
    for (int i=0; i<R; ++i) {
        for (int j=0; j<C; ++j) {
            sum[i][j] = ((i>0 ? sum[i-1][j] : 0) + (j>0 ? sum[i][j-1] : 0)) % mod;
            sum[i][j] = (sum[i][j] - (i>0 && j>0 ? sum[i-1][j-1] : 0) + mod) % mod;
            sum[i][j] = (sum[i][j] + ways[i][j]) % mod;
        }
    }
}

inline void ifsub(int &lhs, int i, int j) {
    if (i<0 || j<0 || i>=R || j>=C) {
        return;
    }
    sub(lhs, ways[i][j]);
}
inline void ifadd(int &lhs, int i, int j) {
    if (i<0 || j<0 || i>=R || j>=C) {
        return;
    }
    add(lhs, ways[i][j]);
}

class Unicorn {
	public:
	int countWays(int R, int C, int L, int seed, string word) {
        ::R = R;
        ::C = C;
        int n = word.size();
        int x = seed;
        int d = 65535/L + 1;
        for (int r=0; r<R; ++r) {
            for (int c=0; c<C; ++c) {
                x = (x * 25173 + 13849) % 65536;
                B[r][c] = char(65 + x/d);
            }
        }

        for (int i=0; i<R; ++i) {
            for (int j=0; j<C; ++j) {
                ways[i][j] = (B[i][j] == word[0]);
            }
        }

        for (int t=1; t<n; ++t) {
            make_sum();
            for (int i=0; i<R; ++i) {
                for (int j=0; j<C; ++j) {
                    if (B[i][j] == word[t]) {
                        int x = sum[R-1][C-1];
                        sub(x, sum[min(R-1, i+1)][C-1]);
                        if (i >= 2) {
                            add(x, sum[i-2][C-1]);
                        }

                        ifsub(x, i-2, j-2);
                        ifsub(x, i-2, j+2);
                        ifsub(x, i+2, j-2);
                        ifsub(x, i+2, j+2);

                        sub(x, sum[R-1][min(C-1, j+1)]);
                        if (j >= 2) {
                            add(x, sum[R-1][j-2]);
                        }

                        for (int di=-1; di<2; ++di) {
                            for (int dj=-1; dj<2; ++dj) {
                                ifadd(x, i+di, j+dj);
                            }
                        }
                        ways2[i][j] = x;
                    } else {
                        ways2[i][j] = 0;
                    }
                }
            }
            memcpy(ways, ways2, sizeof ways);
        }
        make_sum();

        int sol = 0;
        for (int i=0; i<R; ++i) {
            for (int j=0; j<C; ++j) {
                add(sol, ways[i][j]);
            }
        }

        return sol;
    }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 4; int Arg2 = 2; int Arg3 = 47; string Arg4 = "AB"; int Arg5 = 2; verify_case(0, Arg5, countWays(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 5; int Arg2 = 2; int Arg3 = 47; string Arg4 = "CD"; int Arg5 = 0; verify_case(1, Arg5, countWays(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 4; int Arg2 = 1; int Arg3 = 42; string Arg4 = "AA"; int Arg5 = 20; verify_case(2, Arg5, countWays(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 4; int Arg2 = 1; int Arg3 = 42; string Arg4 = "AAAAA"; int Arg5 = 172; verify_case(3, Arg5, countWays(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 5; int Arg3 = 54321; string Arg4 = "ABCDE"; int Arg5 = 0; verify_case(4, Arg5, countWays(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_5() { int Arg0 = 8; int Arg1 = 8; int Arg2 = 26; int Arg3 = 226; string Arg4 = "TOPCODER"; int Arg5 = 1; verify_case(5, Arg5, countWays(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_6() { int Arg0 = 20; int Arg1 = 20; int Arg2 = 2; int Arg3 = 47; string Arg4 = "AAAAA"; int Arg5 = 373977054; verify_case(6, Arg5, countWays(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    Unicorn ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
