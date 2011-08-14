#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };
int M, N;
vector<string> A, B;
bool pos[50][50], t[50][50];
class MazeOnFire {
	public:
	int maximumTurns(vector <string> maze) {
        A = maze;
        M = A.size();
        N = A[0].size();
        int si=-1, sj=-1;
		int cnt = 0;
        for (int i=0; i<M; ++i) {
            for (int j=0; j<N; ++j) {
                cnt += (A[i][j] == 'F');
                if (A[i][j] == '$') {
                    si = i;
                    sj = j;
                    A[i][j] = '.';
                }
            }
        }
        
        if (cnt == 0) {
            return -1;
        }

        memset(pos, 0, sizeof pos);
        pos[si][sj] = 1;
        int sol = 0;
        while (1) {
            memcpy(t, pos, sizeof t);
            for (int i=0; i<M; ++i) {
                for (int j=0; j<N; ++j) {
                    if (pos[i][j]) {
                        for (int d=0; d<4; ++d) {
                            const int r = i + di[d];
                            const int c = j + dj[d];
                            if (r<0 || c<0 || r>=M || c>=N || A[r][c]!='.') {
                                continue;
                            }
                            t[r][c] = 1;
                        }
                    }
                }
            }
            memcpy(pos, t, sizeof pos);
            B = A;
            for (int i=0; i<M; ++i) {
                for (int j=0; j<N; ++j) {
                    if (A[i][j] == 'F') {
                        for (int d=0; d<4; ++d) {
                            const int r = i + di[d];
                            const int c = j + dj[d];
                            if (r<0 || c<0 || r>=M || c>=N || A[r][c]!='.') {
                                continue;
                            }
                            B[r][c] = 'F';
                        }
                    }
                }
            }
            A = B;
            for (int i=0; i<M; ++i) {
                for (int j=0; j<N; ++j) {
                    if (A[i][j] == 'F') {
                        pos[i][j] = 0;
                    }
                }
            }
            cnt = 0;
            for (int i=0; i<M; ++i) {
                for (int j=0; j<N; ++j) {
                    cnt += pos[i][j];
                }
            }
            if (cnt == 0) {
                return sol + 1;
            }
            if (sol > 2500) {
                return -1;
            }
            ++sol;
        }
        return 42;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"F..",
 ".$.",
 "..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, maximumTurns(Arg0)); }
	void test_case_1() { string Arr0[] = {".F#...",
 "F....#",
 ".F###.",
 "F.#.$.",
 "F.#..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(1, Arg1, maximumTurns(Arg0)); }
	void test_case_2() { string Arr0[] = {"....#.",
 "$##.#.",
 ".#..#F",
 ".F#.#.",
 "..#..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(2, Arg1, maximumTurns(Arg0)); }
	void test_case_3() { string Arr0[] = {"...$..",
 "..#...",
 "..###.",
 "..#...",
 "F.#.F."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(3, Arg1, maximumTurns(Arg0)); }
	void test_case_4() { string Arr0[] = {".F....F.",
 ".#.##.#.",
 ".#....#.",
 "F.$##..F",
 ".#....#.",
 ".###.##.",
 ".F....F."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(4, Arg1, maximumTurns(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    MazeOnFire ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
