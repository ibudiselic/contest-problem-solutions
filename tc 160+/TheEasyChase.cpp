#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int di[] = { -1, 0, 1, 0, -2, 0, 2, 0 };
int dj[] = { 0, 1, 0, -1, 0, 2, 0, -2 };
int dp[2][20][20][20][20][2];
const int INF = 1234567890;
int N;
string to_str(int x) {
    ostringstream os;
    os << x;
    return os.str();
}
class TheEasyChase {
	public:
	string winner(int n, int rw, int cw, int rb, int cb) {
        N = n;
        memset(dp, 0xff, sizeof dp);
        int t = 1;
        --rw; --cw; --rb; --cb;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                dp[0][i][j][i][j][0] = dp[0][i][j][i][j][1] = 0;
            }
        }
        
        while (1) {
            for (int r=0; r<n; ++r) {
                for (int c=0; c<n; ++c) {
                    for (int rr=0; rr<n; ++rr) {
                        for (int cc=0; cc<n; ++cc) {
                            for (int b=0; b<2; ++b) {
                                if (dp[!t][r][c][rr][cc][b] != -1) {
                                    dp[t][r][c][rr][cc][b] = dp[!t][r][c][rr][cc][b];
                                    continue;
                                }
                                int min_even = INF;
                                int max_odd = -1;
                                int lim = 4 + b*4;
                                bool have_unknown = false;
                                for (int d=0; d<lim; ++d) {
                                    const int i = r + di[d];
                                    const int j = c + dj[d];
                                    if (i<0 || j<0 || i>=n || j>=n) {
                                        continue;
                                    }
                                    const int next = dp[!t][rr][cc][i][j][!b];
                                    if (next == -1) {
                                        have_unknown = true;
                                        continue;
                                    }
                                    if (next & 1) {
                                        max_odd = max(max_odd, next);
                                    } else {
                                        min_even = min(min_even, next);
                                    }
                                }
                                
                                if (min_even < INF) {
                                    dp[t][r][c][rr][cc][b] = min_even + 1;
                                } else if (max_odd>-1 && !have_unknown) {
                                    dp[t][r][c][rr][cc][b] = max_odd + 1;
                                }
                            }
                        }
                    }
                }
            }
            if (dp[t][rw][cw][rb][cb][0] != -1) {
                const int sol = dp[t][rw][cw][rb][cb][0];
                return (sol&1 ? "WHITE " : "BLACK ") + to_str(sol);
            }
            t = !t;
        }

        return ":/";
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 1; int Arg2 = 1; int Arg3 = 2; int Arg4 = 2; string Arg5 = "BLACK 2"; verify_case(0, Arg5, winner(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 2; int Arg3 = 1; int Arg4 = 2; string Arg5 = "WHITE 1"; verify_case(1, Arg5, winner(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 1; int Arg3 = 3; int Arg4 = 3; string Arg5 = "BLACK 6"; verify_case(2, Arg5, winner(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TheEasyChase ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
