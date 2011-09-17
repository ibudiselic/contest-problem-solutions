#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct state {
    int i, j, k;
    state(int i_, int j_, int k_): i(i_), j(j_), k(k_) {}
};
bool done[50][50][51];
class NumberLabyrinthDiv2 {
	public:
	int getMinimumNumberOfMoves(vector <string> board, int r1, int c1, int r2, int c2, int K) {
		int m = board.size();
        int n = board[0].size();
        memset(done, 0, sizeof done);
        
        queue<state> Q;
        Q.push(state(r1, c1, K));
        int sol = 0;
        int sz = 0;
        while (!Q.empty()) {
            if (sz == 0) {
                ++sol;
                sz = Q.size();
            }
            --sz;
            const state t = Q.front();
            Q.pop();
            int i = t.i;
            int j = t.j;
            int k = t.k;
            if (board[i][j] == '.') {
                if (k > 0) {
                    for (int d=1; d<10; ++d) {
                        int r, c;
                        r = i + d;
                        c = j;
                        if (r>=0 && r<m && c>=0 && c<n && !done[r][c][k-1]) {
                            if (r==r2 && c==c2) {
                                return sol;
                            }
                            done[r][c][k-1] = true;
                            Q.push(state(r, c, k-1));
                        }
                        r = i - d;
                        c = j;
                        if (r>=0 && r<m && c>=0 && c<n && !done[r][c][k-1]) {
                            if (r==r2 && c==c2) {
                                return sol;
                            }
                            done[r][c][k-1] = true;
                            Q.push(state(r, c, k-1));
                        }
                        r = i;
                        c = j + d;
                        if (r>=0 && r<m && c>=0 && c<n && !done[r][c][k-1]) {
                            if (r==r2 && c==c2) {
                                return sol;
                            }
                            done[r][c][k-1] = true;
                            Q.push(state(r, c, k-1));
                        }
                        r = i;
                        c = j - d;
                        if (r>=0 && r<m && c>=0 && c<n && !done[r][c][k-1]) {
                            if (r==r2 && c==c2) {
                                return sol;
                            }
                            done[r][c][k-1] = true;
                            Q.push(state(r, c, k-1));
                        }
                    }
                }
            } else if (board[i][j] > '0') {
                int d = board[i][j] - '0';
                int r, c;
                r = i + d;
                c = j;
                if (r>=0 && r<m && c>=0 && c<n && !done[r][c][k]) {
                    if (r==r2 && c==c2) {
                        return sol;
                    }
                    done[r][c][k] = true;
                    Q.push(state(r, c, k));
                }
                r = i - d;
                c = j;
                if (r>=0 && r<m && c>=0 && c<n && !done[r][c][k]) {
                    if (r==r2 && c==c2) {
                        return sol;
                    }
                    done[r][c][k] = true;
                    Q.push(state(r, c, k));
                }
                r = i;
                c = j + d;
                if (r>=0 && r<m && c>=0 && c<n && !done[r][c][k]) {
                    if (r==r2 && c==c2) {
                        return sol;
                    }
                    done[r][c][k] = true;
                    Q.push(state(r, c, k));
                }
                r = i;
                c = j - d;
                if (r>=0 && r<m && c>=0 && c<n && !done[r][c][k]) {
                    if (r==r2 && c==c2) {
                        return sol;
                    }
                    done[r][c][k] = true;
                    Q.push(state(r, c, k));
                }
            }
        }
        
        return -1;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"...2",
 "....",
 "3..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 0; int Arg3 = 2; int Arg4 = 3; int Arg5 = 0; int Arg6 = -1; verify_case(0, Arg6, getMinimumNumberOfMoves(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_1() { string Arr0[] = {"...2",
 "....",
 "3..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 0; int Arg3 = 2; int Arg4 = 3; int Arg5 = 1; int Arg6 = 2; verify_case(1, Arg6, getMinimumNumberOfMoves(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_2() { string Arr0[] = {"...3",
 "....",
 "2..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 0; int Arg3 = 2; int Arg4 = 3; int Arg5 = 3; int Arg6 = 3; verify_case(2, Arg6, getMinimumNumberOfMoves(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_3() { string Arr0[] = {"55255",
 ".0.0.",
 "..9..",
 "..3..",
 "3.9.3",
 "44.44"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 2; int Arg3 = 4; int Arg4 = 2; int Arg5 = 10; int Arg6 = 6; verify_case(3, Arg6, getMinimumNumberOfMoves(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_4() { string Arr0[] = {"920909949",
 "900020000",
 "009019039",
 "190299149",
 "999990319",
 "940229120",
 "000409399",
 "999119320",
 "009939999"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; int Arg2 = 3; int Arg3 = 1; int Arg4 = 1; int Arg5 = 50; int Arg6 = 10; verify_case(4, Arg6, getMinimumNumberOfMoves(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    NumberLabyrinthDiv2 ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
