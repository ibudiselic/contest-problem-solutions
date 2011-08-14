#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

const int di[] = { 1, 1, 0, -1, -1, 0 };
const int dj[] = { 0, 1, 1, 0, -1, -1 };
vector<string> B;
int n;
bool used[50][50];
int dfs(int i, int j) {
    if (used[i][j]) {
        return 0;
    }
    used[i][j] = 1;
    int ret = 1;
    for (int d=0; d<6; ++d) {
        const int r = i + di[d];
        const int c = j + dj[d];
        if (r>=0 && r<n && c>=0 && c<=r && B[r][c]=='.') {
            const int dd = (d==5 ? 0 : d+1);
            const int rr = i + di[dd];
            const int cc = j + dj[dd];
            if (rr>=0 && rr<n && cc>=0 && cc<=rr && B[rr][cc]=='.') {
                ret += dfs(r, c) + dfs(rr, cc);
            }
        }
    }
    return ret;
}
class HexagonPuzzle {
	public:
	int theCount(vector <string> board) {
        B = board;
        n = B.size();
        memset(used, 0, sizeof used);
        long long sol = 1;
        const long long mod = 1000000007;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<=i; ++j) {
                if (!used[i][j] && B[i][j]=='.') {
                    int sz = dfs(i, j);
                    if (sz >= 3) {
                        for (int k=3; k<=sz; ++k) {
                            sol = (sol*k)%mod;
                        }
                    }
                }
            }
        }
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".",
 ".X",
 "X..",
 ".X.X"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, theCount(Arg0)); }
	void test_case_1() { string Arr0[] = {"X"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, theCount(Arg0)); }
	void test_case_2() { string Arr0[] = {".",
 "..",
 "...",
 ".X.."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 20160; verify_case(2, Arg1, theCount(Arg0)); }
	void test_case_3() { string Arr0[] = {".",
 "..",
 "XXX",
 "..X.",
 ".X..X",
 "XXXX..",
 "..X.X.X",
 "..X.XX.."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 108; verify_case(3, Arg1, theCount(Arg0)); }
	void test_case_4() { string Arr0[] = {".",
 "..",
 "...",
 "....",
 ".....",
 "......",
 ".......",
 "........"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 261547992; verify_case(4, Arg1, theCount(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    HexagonPuzzle ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
