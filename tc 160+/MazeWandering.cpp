#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <utility>

using namespace std;

int m, n;
vector<string> A;
bool done[50][50];
double dp[50][50];

double go(int i, int j, int pi, int pj) {
    if (done[i][j]) {
        return dp[i][j];
    }
    done[i][j] = 1;
    int cnt = 0;
    double &ret = dp[i][j];
    if (pi == -1) {
        ret = 0;
    } else {
        ret = 1;
    }
    for (int di=-1; di<2; ++di) {
        for (int dj=-1; dj<2; ++dj) {
            if (abs(di) + abs(dj) == 1) {
                const int r = i + di;
                const int c = j + dj;
                if ((r==pi && c==pj) || r<0 || c<0 || r>=m || c>=n || A[r][c]=='X') {
                    continue;
                }
                ++cnt;
                if (pi == -1) {
                    ret += go(r, c, i, j);
                } else {
                    ret += 1 + go(r, c, i, j);
                }
            }
        }
    }
    if (pi == -1) {
        return (ret = 0);
    }
    ret *= 1.0/(cnt+1);
    ret /= (1 - 1.0*cnt/(cnt+1));
    return ret;
}

double sum(int i, int j, int pi, int pj, double p_exp = 0.0) {
    double e = dp[i][j] + p_exp;
    double ret = e;
    for (int di=-1; di<2; ++di) {
        for (int dj=-1; dj<2; ++dj) {
            if (abs(di) + abs(dj) == 1) {
                const int r = i + di;
                const int c = j + dj;
                if ((r==pi && c==pj) || r<0 || c<0 || r>=m || c>=n || A[r][c]=='X') {
                    continue;
                }
                ret += sum(r, c, i, j, e);
            }
        }
    }
    
    return ret;
}
    
class MazeWandering {
	public:
	double expectedTime(vector <string> maze) {
        A = maze;
        m = A.size();
        n = A[0].size();
        
        int cnt = 0;
        memset(done, 0, sizeof done);
        int si = -1;
        int sj = -1;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (A[i][j] == '*') {
                    si = i;
                    sj = j;
                    go(i, j, -1, -1);
                }   
                if (A[i][j] != 'X') {
                    ++cnt;
                }
            }
        }
        return sum(si, sj, -1, -1)/cnt;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"*",
 "."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.5; verify_case(0, Arg1, expectedTime(Arg0)); }
	void test_case_1() { string Arr0[] = {"*.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 2.3333333333333335; verify_case(1, Arg1, expectedTime(Arg0)); }
	void test_case_2() { string Arr0[] = {"...",
 "X*X",
 "..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 4.857142857142857; verify_case(2, Arg1, expectedTime(Arg0)); }
	void test_case_3() { string Arr0[] = {".*.",
 ".XX",
 "..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 13.714285714285714; verify_case(3, Arg1, expectedTime(Arg0)); }
	void test_case_4() { string Arr0[] = {"*........",
 "XXX.XXXX.",
 ".XX.X....",
 ".....XX.X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 167.2608695652174; verify_case(4, Arg1, expectedTime(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    MazeWandering ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
