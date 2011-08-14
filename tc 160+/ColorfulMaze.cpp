#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <cctype>

using namespace std;

int si, sj;
int ei, ej;
int m, n;
vector<string> M;
double P[7];
double dp[50][50][1<<7][8];
int T[50][50];
int token;
typedef pair<int, int> pii;
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };
double go(int i, int j, int safe, int deadly) {
    if (dp[i][j][safe][deadly] > -0.5) {
        return dp[i][j][safe][deadly];
    }
    
    if (M[i][j] == 'A' + deadly) { // can't calculate the flat zone because M[i][j] can't be passed through again!
        double ret = 0.0;
        for (int d=0; d<4; ++d) {
            const int r = i + di[d];
            const int c = j + dj[d];
            if (r<0 || c<0 || r>=m || c>=n || M[r][c]=='#' || M[r][c]=='A'+deadly) {
                continue;
            }
            if (r==ei && c==ej) {
                return 1.0;
            }
            if (isalpha(M[r][c]) && !(safe & (1<<(M[r][c]-'A')))) {
                int col = M[r][c] - 'A';
                ret = max(ret, (1.0 - P[col]) * go(r, c, safe | (1<<col), deadly));
            } else {
                ret = max(ret, go(r, c, safe, deadly));
            }
        }
        return ret;
    }
    vector<pii> flat;
    vector<pii> change;
    flat.push_back(make_pair(i, j));
    T[i][j] = ++token;
    bool flat_exit = false;
    for (int k=0; k<(int)flat.size(); ++k) {
        const int r = flat[k].first;
        const int c = flat[k].second;
        for (int d=0; d<4; ++d) {
            const int rr = r + di[d];
            const int cc = c + dj[d];
            
            if (rr<0 || cc<0 || rr>=m || cc>=n || M[rr][cc]=='A'+deadly || M[rr][cc]=='#' || T[rr][cc]==token) {
                continue;
            }
            T[rr][cc] = token;
            if (isalpha(M[rr][cc]) && !(safe & (1<<(M[rr][cc]-'A')))) {
                change.push_back(make_pair(rr, cc));
            } else {
                flat_exit |= (rr==ei && cc==ej);
                flat.push_back(make_pair(rr, cc));
            }
        }
    }
    
    double ret = 0.0;
    if (flat_exit) {
        ret = 1.0;
    } else {
        for (int k=0; k<(int)change.size(); ++k) {
            const int r = change[k].first;
            const int c = change[k].second;
            const int col = M[r][c]-'A';
            ret = max(ret,
                    (1.0-P[col]) * go(r, c, safe | (1<<col), deadly) +
                    (deadly<7 ? 0.0 : P[col] * go(r, c, safe, col)));
        }
    }
    
    for (int k=0; k<(int)flat.size(); ++k) {
        dp[flat[k].first][flat[k].second][safe][deadly] = ret;
    }
    
    return ret;
}
class ColorfulMaze {
	public:
	double getProbability(vector <string> maze, vector <int> trap) {
		M = maze;
        m = M.size();
        n = M[0].size();
        for (int i=0; i<7; ++i) {
            P[i] = trap[i]/100.0;
        }
        
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (maze[i][j] == '$') {
                    si = i;
                    sj = j;
                    maze[i][j] = '.';
                } else if (maze[i][j] == '!') {
                    ei = i;
                    ej = j;
                    maze[i][j] = '.';
                }
            }
        }
        
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                for (int k=0; k<(1<<7); ++k) {
                    for (int l=0; l<8; ++l) {
                        dp[i][j][k][l] = -2.0;
                    }
                }
            }
        }
        
        memset(T, 0, sizeof T);
        token = 0;
        return go(si, sj, 0, 7);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = { ".$.",
  "A#B",
  "A#B",
  ".!." }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 50, 40, 0, 0, 0, 0, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.8; verify_case(0, Arg2, getProbability(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = { ".$.",
  "A#B",
  "A#C",
  ".!." }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 20, 70, 40, 0, 0, 0, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.86; verify_case(1, Arg2, getProbability(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = { "$A#",
  ".#.",
  "#B!" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 10, 10, 10, 10, 10, 10, 10 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.0; verify_case(2, Arg2, getProbability(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = { "$A..",
  "##.A",
  "..B!" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 50, 50, 0, 0, 0, 0, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.75; verify_case(3, Arg2, getProbability(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = { "$C..",
  "##.A",
  "..B!" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 50, 50, 100, 0, 0, 0, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.5; verify_case(4, Arg2, getProbability(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = { ".$.D.E.F.G.!." }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 10, 20, 30, 40, 50, 60, 70 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.23400000000000004; verify_case(5, Arg2, getProbability(Arg0, Arg1)); }
	void test_case_6() { string Arr0[] = { "CC...AA",
  "C##.##A",
  "!.E.E.$",
  "D##.##B",
  "DD...BB" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 90, 90, 25, 50, 75, 0, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.8125; verify_case(6, Arg2, getProbability(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    ColorfulMaze ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
