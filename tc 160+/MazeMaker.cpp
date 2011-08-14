#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <utility>

using namespace std;

int D[50][50];
vector<string> A;
int m, n;
class MazeMaker {
	public:
	int longestPath(vector <string> maze, int startRow, int startCol, vector <int> moveRow, vector <int> moveCol) {
		A = maze;
        m = A.size();
        n = A[0].size();
        
        memset(D, 0xff, sizeof D);
        D[startRow][startCol] = 0;
        queue< pair<int, int> > Q;
        Q.push(make_pair(startRow, startCol));
        
        int t = 0;
        int d = -1;
        while (!Q.empty()) {
            if (t == 0) {
                t = Q.size();
                ++d;
            }
            --t;
            int i = Q.front().first;
            int j = Q.front().second;
            Q.pop();
            
            for (int x=0; x<(int)moveRow.size(); ++x) {
                const int r = i + moveRow[x];
                const int c = j + moveCol[x];
                if (r<0 || c<0 || r>=m || c>=n || A[r][c]=='X') {
                    continue;
                }
                
                if (D[r][c] == -1) {
                    D[r][c] = d + 1;
                    Q.push(make_pair(r, c));
                }
            }
        }
        
        int sol = 0;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (A[i][j] == '.') {
                    sol = max(sol, D[i][j]);
                    if (D[i][j] == -1) {
                        return -1;
                    }
                }
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
	void test_case_0() { string Arr0[] = {"...",
 "...",
 "..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 1; int Arr3[] = {1,0,-1,0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {0,1,0,-1}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 3; verify_case(0, Arg5, longestPath(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { string Arr0[] = {"...",
 "...",
 "..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 1; int Arr3[] = {1, 0, -1, 0, 1, 1, -1, -1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {0, 1, 0, -1, 1, -1, 1, -1}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 2; verify_case(1, Arg5, longestPath(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { string Arr0[] = {"X.X",
 "...",
 "XXX",
 "X.X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 1; int Arr3[] = {1, 0, -1, 0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {0, 1, 0, -1}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = -1; verify_case(2, Arg5, longestPath(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { string Arr0[] = {".......",
 "X.X.X..",
 "XXX...X",
 "....X..",
 "X....X.",
 "......."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 0; int Arr3[] = {1, 0, -1, 0,-2, 1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {0, -1, 0, 1, 3, 0}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 7; verify_case(3, Arg5, longestPath(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { string Arr0[] = {"......."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 0; int Arr3[] = {1, 0, 1, 0, 1, 0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {0, 1, 0, 1, 0, 1}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 6; verify_case(4, Arg5, longestPath(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_5() { string Arr0[] = {"..X.X.X.X.X.X."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 0; int Arr3[] = {2,0,-2,0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {0,2,0,-2}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = -1; verify_case(5, Arg5, longestPath(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    MazeMaker ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
