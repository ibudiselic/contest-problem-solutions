#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int encode(int i, int j) {
    return i*20 + j;
}
void decode(int code, int &i, int &j) {
    j = code % 20;
    i = code / 20;
}
vector<string> B;
int M, N;
bool G[20][20][20][20];

bool done[20][20];
bool valid(int i, int j) {
    if (i<0 || j<0 || i>=M || j>=N || B[i][j]=='#') {
        return false;
    }
    return true;
}
void go(int i, int j) {
    if (B[i][j] == '#') {
        return;
    }
    memset(done, 0, sizeof done);
    done[i][j] = 1;
    queue<int> Q;
    Q.push(encode(i, j));
    int si = i;
    int sj = j;
    while (!Q.empty()) {
        decode(Q.front(), i, j);
        Q.pop();
        G[si][sj][i][j] = 1;

        int r, c;

        r = i;
        c = j + 1;
        if (valid(r, c) && !done[r][c]) {
            Q.push(encode(r, c));
            done[r][c] = 1;
        }

        r = i + 1;
        c = j;
        if (valid(r, c) && !done[r][c]) {
            Q.push(encode(r, c));
            done[r][c] = 1;
        }

        if (B[i][j] == 'U') {
            r = i - 1;
            c = j;
            if (valid(r, c) && !done[r][c]) {
                Q.push(encode(r, c));
                done[r][c] = 1;
            }
        }

        if (B[i][j] == 'L') {
            r = i;
            c = j - 1;
            if (valid(r, c) && !done[r][c]) {
                Q.push(encode(r, c));
                done[r][c] = 1;
            }
        }
    }
}

int dp[20][20];
int calc(int i, int j) {
    int &ret = dp[i][j];
    if (ret != -1) {
        return ret;
    }
    ret = 0;
    vector<string> old = B;
    for (int r=0; r<M; ++r) {
        for (int c=0; c<N; ++c) {
            if (isdigit(B[r][c]) && G[i][j][r][c] && G[r][c][i][j]) {
                ret += B[r][c]-'0';
                B[r][c] = '.';
            }
        }
    }
    int t = 0;
    for (int r=0; r<M; ++r) {
        for (int c=0; c<N; ++c) {
            if (isdigit(B[r][c]) && G[i][j][r][c]) {
                t = max(t, calc(r, c));
            }
        }
    }

    ret += t;

    B = old;
    return ret;
}

class MarbleCollectionGame {
	public:
	int collectMarble(vector <string> board) {
		B = board;
        M = B.size();
        N = B[0].size();
        memset(G, 0, sizeof G);

        for (int i=0; i<M; ++i) {
            for (int j=0; j<N; ++j) {
                go(i, j);
            }
        }

        for (int k1=0; k1<M; ++k1) {
            for (int k2=0; k2<N; ++k2) {
                for (int i=0; i<M; ++i) {
                    for (int j=0; j<N; ++j) {
                        if (G[i][j][k1][k2]) {
                            for (int r=0; r<M; ++r) {
                                for (int c=0; c<N; ++c) {
                                    G[i][j][r][c] |= G[i][j][k1][k2] && G[k1][k2][r][c];
                                }
                            }
                        }
                    }
                }
            }
        }

        memset(dp, 0xff, sizeof dp);
        int sol = calc(0, 0);

        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"7"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(0, Arg1, collectMarble(Arg0)); }
	void test_case_1() { string Arr0[] = {"0",
 "8"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(1, Arg1, collectMarble(Arg0)); }
	void test_case_2() { string Arr0[] = {"264",
 "3LL"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 15; verify_case(2, Arg1, collectMarble(Arg0)); }
	void test_case_3() { string Arr0[] = {"8U4L9",
 "0183U",
 "U8#38",
 "2158#",
 "L65U7"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 44; verify_case(3, Arg1, collectMarble(Arg0)); }
	void test_case_4() { string Arr0[] = {"039LLLU",
 "953348#",
 "0L87#29",
 "718#4#U",
 "594U196"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 55; verify_case(4, Arg1, collectMarble(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    MarbleCollectionGame ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
