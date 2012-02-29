#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

const int inf = 1234;
int calc(int m, int n, const vector<string> &A) {
    int ret = inf;
    for (int col=0; col<n; ++col) { // this column is not colored
        vector<string> B = A;
        for (int i=0; i<m; ++i) { // i.e. all the rows must be colored
            char rowclr = A[i][col]; // row i with this color
            for (int j=0; j<n; ++j) {
                if (B[i][j] == rowclr) {
                    B[i][j] = '?';
                }
            }
        }
        
        int cur = m; // all the rows
        bool G[100][100] = {{0}}; // order of rows (0..m-1) and columns (m..m+n-1)
        for (int j=0; j<n; ++j) { // should we color column j?
            if (j == col) {
                continue;
            }
            char colclr = ' '; // no color
            for (int i=0; i<m; ++i) {
                if (B[i][j] != '?') { // this cell not done by the row coloring
                    if (colclr == ' ') { // this is then the color we must use for column
                        colclr = B[i][j];
                        ++cur;
                    } else if (colclr != B[i][j]) { // can't get both colors on this column
                        cur = inf;
                        break;
                    }
                }
            }
            if (cur >= ret) {
                break;
            }
            if (colclr == ' ') {
                continue;
            }
            for (int i=0; i<m; ++i) {
                if (A[i][col] == colclr) { // they use the same color so no order imposed
                    continue;
                }
                if (B[i][j] == '?') { // column j first
                    G[m+j][i] = 1;
                } else { // row i first
                    G[i][m+j] = 1;
                }
            }
        }
        if (cur >= ret) {
            continue;
        }
        // is it a DAG, i.e. possible?
        for (int k=0; k<m+n; ++k) { // floyd-warshall
            for (int i=0; i<m+n; ++i) {
                if (G[i][k])
                for (int j=0; j<m+n; ++j) {
                    G[i][j] |= G[k][j];
                }
            }
        }
        bool dag = true;
        for (int i=0; i<m+n; ++i) {
            if (G[i][i]) { // there's a cycle :/
                dag = false;
                break;
            }
        }
        if (dag) {
            ret = cur;
        }
    }
    return ret;
}
class ColorfulBoard {
	public:
	int theMin(vector <string> board) {
		int m = board.size();
        int n = board[0].size();
        int sol = inf;
        for (int iter=0; iter<2; ++iter) {
            sol = min(sol, calc(m, n, board));
            vector<string> tmp(n, string(m, 0));
            for (int i=0; i<m; ++i) {
                for (int j=0; j<n; ++j) {
                    tmp[j][i] = board[i][j];
                }
            }
            board.swap(tmp);
            swap(m, n);
        }
        return sol==inf ? -1 : sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"SSS",
 "SRR",
 "SMM"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, theMin(Arg0)); }
	void test_case_1() { string Arr0[] = {"BBBBBBBB",
 "BBBBBBBB",
 "BBBBBBBB",
 "BBBBBBBB",
 "BBBBBBBB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(1, Arg1, theMin(Arg0)); }
	void test_case_2() { string Arr0[] = {"Ab",
 "bA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(2, Arg1, theMin(Arg0)); }
	void test_case_3() { string Arr0[] = {"iiiii",
 "iwiwi"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(3, Arg1, theMin(Arg0)); }
	void test_case_4() { string Arr0[] = {"ffffffffff",
 "xfxxoofoxo",
 "ffffffffff",
 "xfxxoofoxo",
 "ffffffffff",
 "ooxxoofoxo",
 "xfxxoofoxo",
 "xfxxoxfxxo",
 "ffxxofffxo",
 "xfxxoxfxxo"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 17; verify_case(4, Arg1, theMin(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    ColorfulBoard ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
