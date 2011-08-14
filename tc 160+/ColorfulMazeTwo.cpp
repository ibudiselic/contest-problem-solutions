#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>

using namespace std;

double A[50][50], B[50][50];
int m, n;
int si, sj, ei, ej;
double P[50][50];
vector<string> M;
vector<int> T;
double trap_prob(int i, int j) {
    const char c = M[i][j];
    if (c == '.') {
        return 0.0;
    } else if (c == '#') {
        return 1.0;
    } else {
        return T[c-'A']/100.0;
    }
}
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };

struct state {
    int i, j;
    double p_dead;
    int ok;
    state(int i_, int j_, double p_dead_, int ok_):
        i(i_), j(j_), p_dead(p_dead_), ok(ok_) {}
};
const double EPS = 1e-11;
bool operator<(const state &a, const state &b) {
    if (fabs(a.p_dead - b.p_dead) > EPS) {
        return a.p_dead > b.p_dead;
    } else if (a.i != b.i) {
        return a.i < b.i;
    } else if (a.j != b.j) {
        return a.j < b.j;
    } else {
        return a.ok < b.ok;
    }
}
    
double best[50][50][1<<7];
class ColorfulMazeTwo {
	public:
	double getProbability(vector <string> maze, vector <int> trap) {
        M = maze;
        T = trap;
        m = maze.size();
        n = maze[0].size();
        
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
                P[i][j] = 1.0 - trap_prob(i, j);
            }
        }
        
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                for (int k=0; k<(1<<7); ++k) {
                    best[i][j][k] = 1.0;
                }
            }
        }
        
        priority_queue<state> Q;
        Q.push(state(si, sj, 0.0, 0));
        best[si][sj][0] = 0.0;
        while (!Q.empty()) {
            const state s = Q.top();
            Q.pop();
            
            if (s.p_dead > best[s.i][s.j][s.ok]) {
                continue;
            }

            if (s.i==ei && s.j==ej) {
                return 1.0 - s.p_dead;
            }
            
            for (int d=0; d<4; ++d) {
                const int r = s.i + di[d];
                const int c = s.j + dj[d];
                if (r<0 || c<0 || r>=m || c>=n) {
                    continue;
                }
                const int C = maze[r][c];
                if (C == '#') {
                    continue;
                }
                double p_surv = 0.0;
                int nok = s.ok;
                if (C == '.') {
                    p_surv = 1.0;
                } else {
                    const int ind = C - 'A';
                    if (s.ok & (1<<ind)) {
                        p_surv = 1.0;
                    } else {
                        p_surv = P[r][c];
                        nok |= (1<<ind);
                    }
                }
                const double np_dead = 1.0 - (1.0-s.p_dead)*p_surv;
                if (np_dead < best[r][c][nok]) {
                    best[r][c][nok] = np_dead;
                    Q.push(state(r, c, np_dead, nok));
                }
            }
        }
        
        return 0.0;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = { ".$.",
  "A#B",
  "A#B",
  ".!." }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 50, 50, 0, 0, 0, 0, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.5; verify_case(0, Arg2, getProbability(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = { ".$.",
  "A#B",
  "A#B",
  ".!." }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 50, 40, 0, 0, 0, 0, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.6; verify_case(1, Arg2, getProbability(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = { "$A#",
  ".#.",
  "#B!" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 10, 10, 10, 10, 10, 10, 10 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.0; verify_case(2, Arg2, getProbability(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = { "$A..",
  "##.A",
  "..B!" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 50, 50, 0, 0, 0, 0, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.5; verify_case(3, Arg2, getProbability(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = { "$C..",
  "##.A",
  "..B!" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 50, 50, 100, 0, 0, 0, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.0; verify_case(4, Arg2, getProbability(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = { ".$.D.E.F.G.!." }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 10, 20, 30, 40, 50, 60, 70 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.036000000000000004; verify_case(5, Arg2, getProbability(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    ColorfulMazeTwo ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
