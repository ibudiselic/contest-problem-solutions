#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int dp[51][51][51][51];
vector<string> A;
int m, n;

int go(int r1, int c1, int r2, int c2) {
    int &ret = dp[r1][c1][r2][c2];
    if (ret != -1) {
        return ret;
    }
    if (r2-r1<3 || c2-c1<3) {
        return (ret = 0);
    }
    bool is_donut = true;
    for (int i=r1; i<r2; ++i) {
        if (A[i][c1]!='0' || A[i][c2-1]!='0') {
            is_donut = false;
            break;
        }
    }
    if (is_donut) {
        for (int j=c1; j<c2; ++j) {
            if (A[r1][j]!='0' || A[r2-1][j]!='0') {
                is_donut = false;
                break;
            }
        }
    }
    
    if (is_donut) {
        ret = 1 + go(r1+1, c1+1, r2-1, c2-1);
    } else {
        ret = max(go(r1+1, c1, r2, c2),
              max(go(r1, c1+1, r2, c2),
              max(go(r1, c1, r2-1, c2),
                  go(r1, c1, r2, c2-1))));
    }
    
    return ret;
}
class DonutsOnTheGridEasy {
	public:
	int calc(vector <string> grid) {
		memset(dp, 0xff, sizeof dp);
        A = grid;
        m = A.size();
        n = A[0].size();
        
        return go(0, 0, m, n);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"0000000"
,"0.....0"
,"0.00000"
,"0.0..00"
,"0.00000"
,"0.....0"
,"0000000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, calc(Arg0)); }
	void test_case_1() { string Arr0[] = {"000"
,"0.0"
,"000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, calc(Arg0)); }
	void test_case_2() { string Arr0[] = {"..."
,"..."
,"..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, calc(Arg0)); }
	void test_case_3() { string Arr0[] = {"00.000"
,"00.000"
,"0.00.0"
,"000.00"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, calc(Arg0)); }
	void test_case_4() { string Arr0[] = {"0000000....",
 "0000000....",
 "0000000.000",
 "0000000.0.0",
 "0000000.000",
 "0000000....",
 "0000000...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(4, Arg1, calc(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    DonutsOnTheGridEasy ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
