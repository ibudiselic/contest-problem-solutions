#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool A[100][100];
int m, n;
const long long mod = 1000000007;
/*int last_fail[100][100];
inline bool is_ok(int row, int l, int r) {
    return last_fail[row][r] < l;
}

int dp[100][100][100][2][2];
int go(int row, int l, int r, bool canL, bool canR) { // way too slow
    if (row == m) {
        return 1;
    }
    int &ret = dp[row][l][r][canL][canR];
    if (ret != -1) {
        return ret;
    }
    
    long long retval = 1;
    const int lim_i = canL ? 0 : l;
    const int lim_j = canR ? n-1 : r;
    for (int i=r; i>=lim_i; --i) {
        for (int j=max(i, l); j<=lim_j; ++j) {
            if (is_ok(row, i, j)) {
                retval += go(row+1, i, j, canL&&(i<=l), canR&&(j>=r));
                if (retval >= mod) {
                    retval -= mod;
                }
            }
        }
    }
    
    return (ret = int(retval));
}*/

long long dp[2][2][101][101], partial_sum[2][2][101][101]; // upper left corner sum...
void inc(long long &val, long long by) {
    val += by;
    if (val >= mod) {
        val -= mod;
    }
}
long long get_rect(int canL, int canR, int l1, int l2, int r1, int r2) {
    l1 = max(l1, 1);
    l2 = min(l2, n);
    r1 = max(r1, 1);
    r2 = min(r2, n);
    return (partial_sum[canL][canR][l2][r2] - partial_sum[canL][canR][l1-1][r2] - partial_sum[canL][canR][l2][r1-1] + partial_sum[canL][canR][l1-1][r1-1] + 2*mod) % mod;
}
class AmoebaDivOne {
	public:
	int count(vector <string> table) {
	    m = table.size()*2;
        n = table[0].size()*2;
        for (int i=0; i<(int)table.size(); ++i) {
            for (int j=0; j<(int)table[i].size(); ++j) {
                int v = (table[i][j]<='9' ? (int)table[i][j]-'0' : table[i][j]-'a'+10);
                for (int k=0; k<4; ++k) {
                    A[2*i + (k>1)][2*j + (k&1)] = 1 - ((v>>k) & 1);
                }
            }
        }
        
        /*for (int i=0; i<m; ++i) {
            last_fail[i][0] = (A[i][0] ? -1 : 0);
            for (int j=1; j<n; ++j) {
                last_fail[i][j] = (A[i][j] ? last_fail[i][j-1] : j);
            }
        }
        
        memset(dp, 0xff, sizeof dp);
        long long sol = 0;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (A[i][j]) {
                    int k = j;
                    while (k<n && A[i][k]) {
                        sol += go(i+1, j, k, 1, 1);
                        if (sol >= mod) {
                            sol -= mod;
                        }
                        ++k;
                    }
                }
            }
        }*/
            
        memset(dp, 0, sizeof dp);
        
        long long sol = 0;
        for (int row=0; row<m; ++row) {
            // use old row data to calc partial sums...
            memset(partial_sum, 0, sizeof partial_sum);
            for (int canL=0; canL<2; ++canL) {
                for (int canR=0; canR<2; ++canR) {
                    for (int l=1; l<=n; ++l) {
                        for (int r=1; r<=n; ++r) {
                            partial_sum[canL][canR][l][r] = (partial_sum[canL][canR][l-1][r] + partial_sum[canL][canR][l][r-1] - partial_sum[canL][canR][l-1][r-1] + dp[canL][canR][l][r] + mod) % mod;
                        }
                    }
                }
            }
            
            memset(dp, 0, sizeof dp);
            for (int l=1; l<=n; ++l) {
                int r = l;
                while (r<=n && A[row][r-1]) {
                    dp[1][1][l][r] = 1; // this amoeba starts in this row (can expand both ways in the next row)
                    ++r;
                }
            }
            
            for (int l=1; l<=n; ++l) {
                for (int r=l; r<=n; ++r) {
                    if (dp[1][1][l][r] == 0) {
                        continue;
                    }
                    
                    // can't expand further in either direction:
                    //  1) either it couldn't expand neither dimension from the previous row
                    inc(dp[0][0][l][r], get_rect(0, 0, 1, l, r, n));
                    //  2) or it could have expanded r from the previous row (but shrunk it instead)
                    inc(dp[0][0][l][r], get_rect(0, 1, 1, l, r+1, n));
                    //  3) or it could have expanded l from the previous row (but shrunk it instead)
                    inc(dp[0][0][l][r], get_rect(1, 0, 1, l-1, r, n));
                    //  4) or it could have expanded both ways from the previous row (but shrunk both)
                    inc(dp[0][0][l][r], get_rect(1, 1, 1, l-1, r+1, n));
                    
                    // can expand only r
                    //  1) either it couldn't expand l from the previous row
                    inc(dp[0][1][l][r], get_rect(0, 1, 1, l, l, r));
                    //  2) or it could have expanded l but actually shrunk it
                    inc(dp[0][1][l][r], get_rect(1, 1, 1, l-1, l, r));
                    
                    // can expand only l
                    //  1) either it couldn't expand r from the previous row
                    inc(dp[1][0][l][r], get_rect(1, 0, l, r, r, n));
                    //  2) or it could have expanded r but shrunk it
                    inc(dp[1][0][l][r], get_rect(1, 1, l, r, r+1, n));
                    
                    // to be able to expand both ways in the following rows
                    // an amoeba had to be able to expand both ways previously
                    // and no larger (i.e. smaller or equal) in both dimensions than
                    // the dimensions chosen for this row (l and r)
                    inc(dp[1][1][l][r], get_rect(1, 1, l, r, l, r));

                    for (int canL=0; canL<2; ++canL) {
                        for (int canR=0; canR<2; ++canR) {
                            inc(sol, dp[canL][canR][l][r]);
                        }
                    }
                }
            }
        }

        return int(sol);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { string Arr0[] = {"84","21"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 72; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { string Arr0[] = {"e","e"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { string Arr0[] = {"00"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 90; verify_case(3, Arg1, count(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    AmoebaDivOne ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
