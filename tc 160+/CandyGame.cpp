#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool G[50][50], A[50][50];
int n;
long long dp[50][51][51];
long long go(int x, int p, int d) {
    long long &ret = dp[x][p][d];
    if (ret != -1) {
        return ret;
    }
    
    ret = 0;
    long long maxinc = 0;
    for (int i=0; i<n; ++i) {
        if (i!=p && G[x][i]) {
            maxinc = max(maxinc, go(i, x, d+1) - go(i, x, 1));
            ret += go(i, x, 1);
        }
    }
    ret += maxinc;
    ret = max(ret, (1LL<<d) - 1);

    return ret;
}
class CandyGame {
	public:
	int maximumCandy(vector <string> G_, int T) {
        n = G_.size();
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                G[i][j] = (G_[i][j]=='Y');
            }
        }
        memcpy(A, G, sizeof A);
		
        for (int i=0; i<n; ++i) {
            A[i][i] = 1;
        }
        for (int k=0; k<n; ++k) {
            for (int i=0; i<n; ++i) {
                for (int j=0; j<n; ++j) {
                    A[i][j] |= A[i][k] && A[k][j];
                }
            }
        }

        for (int i=0; i<n; ++i) {
            if (!A[i][T]) {
                return -1;
            }
        }

        memset(dp, 0xff, sizeof dp);
        long long sol = 0;
        for (int i=0; i<n; ++i) {
            if (G[T][i]) {
                sol += go(i, T, 1);
            }
        }

        return sol>2000000000LL ? -1 : sol;
                
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"NYN", "YNY", "NYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; verify_case(0, Arg2, maximumCandy(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"NYN", "YNY", "NYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 3; verify_case(1, Arg2, maximumCandy(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"NYYY", "YNNN", "YNNN", "YNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 3; verify_case(2, Arg2, maximumCandy(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"NYYY", "YNNN", "YNNN", "YNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 4; verify_case(3, Arg2, maximumCandy(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"NYNNNYN",
 "YNYNYNN",
 "NYNYNNN",
 "NNYNNNN",
 "NYNNNNN",
 "YNNNNNY",
 "NNNNNYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 11; verify_case(4, Arg2, maximumCandy(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"NYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "YNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NYNYNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NNYNYNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NNNYNYNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NNNNYNYNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NNNNNYNYNNNNNNNNNNNNNNNNNNNNNNNN",
 "NNNNNNYNYNNNNNNNNNNNNNNNNNNNNNNN",
 "NNNNNNNYNYNNNNNNNNNNNNNNNNNNNNNN",
 "NNNNNNNNYNYNNNNNNNNNNNNNNNNNNNNN",
 "NNNNNNNNNYNYNNNNNNNNNNNNNNNNNNNN",
 "NNNNNNNNNNYNYNNNNNNNNNNNNNNNNNNN",
 "NNNNNNNNNNNYNYNNNNNNNNNNNNNNNNNN",
 "NNNNNNNNNNNNYNYNNNNNNNNNNNNNNNNN",
 "NNNNNNNNNNNNNYNYNNNNNNNNNNNNNNNN",
 "NNNNNNNNNNNNNNYNYNNNNNNNNNNNNNNN",
 "NNNNNNNNNNNNNNNYNYNNNNNNNNNNNNNN",
 "NNNNNNNNNNNNNNNNYNYNNNNNNNNNNNNN",
 "NNNNNNNNNNNNNNNNNYNYNNNNNNNNNNNN",
 "NNNNNNNNNNNNNNNNNNYNYNNNNNNNNNNN",
 "NNNNNNNNNNNNNNNNNNNYNYNNNNNNNNNN",
 "NNNNNNNNNNNNNNNNNNNNYNYNNNNNNNNN",
 "NNNNNNNNNNNNNNNNNNNNNYNYNNNNNNNN",
 "NNNNNNNNNNNNNNNNNNNNNNYNYNNNNNNN",
 "NNNNNNNNNNNNNNNNNNNNNNNYNYNNNNNN",
 "NNNNNNNNNNNNNNNNNNNNNNNNYNYNNNNN",
 "NNNNNNNNNNNNNNNNNNNNNNNNNYNYNNNN",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNYNYNNN",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNNYNYNN",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNNNYNYN",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNY",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = -1; verify_case(5, Arg2, maximumCandy(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    CandyGame ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
