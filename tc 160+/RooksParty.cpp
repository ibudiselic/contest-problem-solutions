#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <numeric>

using namespace std;

/* inclusion - exclusion */

const long long mod = 1000000009;
long long dp[2][31][31];
long long C[901][901];

long long col_ways_dp[31][31][901];
long long col_ways(int r, int c, int n) { // n rooks into r*c such that all cs have at least one rook in them
    long long &ret = col_ways_dp[r][c][n];
    if (ret != -1) {
        return ret;
    }
    if (r*c < n) {
        return (ret = 0);
    }
    
    long long retval = 0;
    // incl-excl Ai = {all arangements in which column i doesn't contain any rooks}
    // cnt = #all_arangements - U{Ai}
    long long sgn = 1;
    for (int i=0; i<=c; ++i) {
        retval += sgn*C[c][i]*C[r*(c-i)][n];
        if (retval < 0) {
            long long cnt = (-retval+mod-1)/mod;
            retval += cnt * mod;
        } else {
            retval %= mod;
        }
        sgn *= -1;
    }
    
    //cerr << r << ' ' << c << ' ' << n << " col_ways " << retval << '\n';
    return (ret = retval);
}
long long ways_dp[31][31][901];
/*long long ways(int r, int c, int n) { // n rooks into r rows and c cols such that all rs and cs have at least one rook in them
    long long &ret = ways_dp[r][c][n];
    if (ret != -1) {
        return ret;
    }
    if (r*c < n) {
        return (ret = 0);
    }
    
    long long retval = 0;
    // incl-excl Ai = {all arrangements in which row i doesn't contain any rooks (and all cols contain rooks!)}
    // cnt = #all_arrangements_with_filled_columns - U{Ai}
    long long sgn = 1;
    for (int i=0; i<=r; ++i) {
        retval += sgn*C[r][i]*col_ways(r-i, c, n);
        if (retval < 0) {
            long long cnt = (-retval+mod-1)/mod;
            retval += cnt * mod;
        } else {
            retval %= mod;
        }
        sgn *= -1;
    }
    
    //cerr << r << ' ' << c << ' ' << n << " ways " << retval << '\n';
    return (ret = retval);
}*/
/* alternatively, ways can be calculated using dp 
 but since n<=900, it must be done bottom up (not like done here...) 
   
 every arrangement is counted prod(counts[i]!) times with this dp method! 
 */
/*long long ways(int r, int c, int n) {
    long long &ret = ways_dp[r][c][n];
    if (ret != -1) {
        return ret;
    }
    if (r*c < n) {
        return (ret = 0);
    }
    ret = ways(r, c, n-1) * (r*c - n + 1) % mod; // same number of rows and cols
    if (r > 1) { // nth was added in a new row
        ret = (ret + ways(r-1, c, n-1) * c) % mod;
    }
    if (c > 1) { // nth was added in a new col
        ret = (ret + ways(r, c-1, n-1) * r) % mod;
    }
    if (r>1 && c>1) { // nth was added on the intersection cell of a new row and new col
        ret = (ret + ways(r-1, c-1, n-1)) % mod;
    }
    return ret;
}*/
class RooksParty {
	public:
	int countArrangements(int rows, int columns, vector <int> counts) {
        int n = accumulate(counts.begin(), counts.end(), 0);
        int lim = max(n, rows*columns);
        C[0][0] = 1;
        for (int i=1; i<=lim; ++i) {
            C[i][0] = C[i][i] = 1;
            for (int j=1; j<i; ++j) {
                C[i][j] = C[i-1][j] + C[i-1][j-1];
                if (C[i][j] >= mod) {
                    C[i][j] -= mod;
                }
            }
        }
		memset(dp, 0, sizeof dp);
        memset(ways_dp, 0xff, sizeof ways_dp);
        memset(col_ways_dp, 0xff, sizeof col_ways_dp);
        dp[0][rows][columns] = 1;
        for (int i=0; i<(int)counts.size(); ++i) {
            for (int r=1; r<=rows; ++r) {
                for (int c=1; c<=columns; ++c) {
                    if (dp[i&1][r][c] > 0) {
                        //cerr << i << ' ' << r << ' ' << c << ' ' << dp[i&1][r][c] << '\n';
                        for (int dr=1; dr<=r; ++dr) {
                            for (int dc=1; dc<=c; ++dc) {
                                long long add = dp[i&1][r][c] * C[r][dr] % mod * C[c][dc] % mod;
                                dp[(i+1)&1][r-dr][c-dc] = (dp[(i+1)&1][r-dr][c-dc] + add*ways(dr, dc, counts[i])) % mod;
                            }
                        }
                    }
                }
            }
            memset(dp[i&1], 0, sizeof dp[i&1]);
        }
        
        long long sol = 0;
        for (int r=0; r<rows; ++r) {
            for (int c=0; c<columns; ++c) {
                sol += dp[counts.size() & 1][r][c];
            }
        }
        return int(sol % mod);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 3; int Arr2[] = {1,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 12; verify_case(0, Arg3, countArrangements(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 2; int Arr2[] = {3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 120; verify_case(1, Arg3, countArrangements(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 2; int Arr2[] = {1,1,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(2, Arg3, countArrangements(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 8; int Arg1 = 8; int Arr2[] = {1,1,1,1,1,1,1,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 625702391; verify_case(3, Arg3, countArrangements(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 4; int Arg1 = 2; int Arr2[] = {3,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 8; verify_case(4, Arg3, countArrangements(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    RooksParty ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
