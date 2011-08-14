#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int calc2(int r, int c, const vector<string> &B, int m, int n, char ch) {
    int sol = 0;
    bool eq = true;
    for (int i=r-8; i<r; ++i) {
        for (int j=c-8; j<c; ++j) {
            if ((B[i][j]==ch) != eq) {
                ++sol;
            }
            eq = !eq;
        }
        eq = !eq;
    }

    return sol;
}

int calc(int r, int c, const vector<string> &B, int m, int n) {
    return min(calc2(r, c, B, m, n, 'W'), calc2(r, c, B, m, n, 'B'));
}
class RepaintTheChessboard {
	public:
	int minimumChanges(vector <string> board) {
	    int m = board.size();
        int n = board[0].size();

        int sol = 1234567890;
        for (int i=8; i<=m; ++i) {
            for (int j=8; j<=n; ++j) {
                sol = min(sol, calc(i, j, board, m, n));
            }
        }

        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"BWBWBWBW",
 "WBWBWBWB",
 "BWBWBWBW",
 "WBWBWBWB",
 "BWBWBWBW",
 "WBWBWBWB",
 "BWBWBWBW",
 "WBWBWBWB"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(0, Arg1, minimumChanges(Arg0)); }
	void test_case_1() { string Arr0[] = {"WBWBWBWB",
 "BWBWBWBW",
 "WBWBWBWB",
 "BWBBBWBW",
 "WBWBWBWB",
 "BWBWBWBW",
 "WBWBWBWB",
 "BWBWBWBW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, minimumChanges(Arg0)); }
	void test_case_2() { string Arr0[] = {"BBBBBBBBBBBBBBBBBBBBBBB",
 "BBBBBBBBBBBBBBBBBBBBBBB",
 "BBBBBBBBBBBBBBBBBBBBBBB",
 "BBBBBBBBBBBBBBBBBBBBBBB",
 "BBBBBBBBBBBBBBBBBBBBBBB",
 "BBBBBBBBBBBBBBBBBBBBBBB",
 "BBBBBBBBBBBBBBBBBBBBBBB",
 "BBBBBBBBBBBBBBBBBBBBBBB",
 "BBBBBBBBBBBBBBBBBBBBBBW"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 31; verify_case(2, Arg1, minimumChanges(Arg0)); }
	void test_case_3() { string Arr0[] = {"BBBBBBBBBB",
 "BBWBWBWBWB",
 "BWBWBWBWBB",
 "BBWBWBWBWB",
 "BWBWBWBWBB",
 "BBWBWBWBWB",
 "BWBWBWBWBB",
 "BBWBWBWBWB",
 "BWBWBWBWBB",
 "BBBBBBBBBB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, minimumChanges(Arg0)); }
	void test_case_4() { string Arr0[] = {"WBWBWBWB",
 "BWBWBWBW",
 "WBWBWBWB",
 "BWBBBWBW",
 "WBWBWBWB",
 "BWBWBWBW",
 "WBWBWWWB",
 "BWBWBWBW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(4, Arg1, minimumChanges(Arg0)); }
	void test_case_5() { string Arr0[] = {"BWWBWWBWWBWW",
 "BWWBWBBWWBWW",
 "WBWWBWBBWWBW",
 "BWWBWBBWWBWW",
 "WBWWBWBBWWBW",
 "BWWBWBBWWBWW",
 "WBWWBWBBWWBW",
 "BWWBWBWWWBWW",
 "WBWWBWBBWWBW",
 "BWWBWBBWWBWW",
 "WBWWBWBBWWBW"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 15; verify_case(5, Arg1, minimumChanges(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    RepaintTheChessboard ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
