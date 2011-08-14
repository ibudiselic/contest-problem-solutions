#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int num[10];
int start[20];
int cur[20];
int change_to[10][10];
int add[10][10];
int sub[10][10];
vector<string> digs;
int f(int x) {
    int ret = 0;
    for (int i=0; i<5; ++i) {
        for (int j=0; j<3; ++j) {
            ret += (digs[x][i*3+j] == '#');
        }
    }
    return ret;
}
int calc(int x, int y) {
    if (x == y) {
        add[x][y] = 0;
        sub[x][y] = 0;
        return 0;
    }
    int diff = 0;
    for (int i=0; i<5; ++i) {
        for (int j=0; j<3; ++j) {
            diff += (digs[x][i*3+j]=='#' && digs[y][i*3+j]=='.');
        }
    }
    int rmv = max(0, num[x] - num[y]);
    add[x][y] = max(0, num[y] - num[x]);
    sub[x][y] = rmv;
    return max(0, diff - rmv);
}

const int ZERO = 140;
long long dp[20][127][2*ZERO];
int cnt;
void prnt() {
    for (int i=0; i<cnt; ++i) {
        cerr << cur[cnt-1-i];
    }
}
long long go(int p, int k, int extra) {
    if (k < 0) {
        return 0;
    }
    if (p < 0) {
        return (extra==ZERO);
    }
    long long &ret = dp[p][k][extra];
    if (ret != -1) {
        return ret;
    }
    ret = 0;
    for (int i=0; i<10; ++i) {
        int moves = sub[start[p]][i] + change_to[start[p]][i];
        cur[p] = i;
        ret += go(p-1, k-moves, extra+add[start[p]][i]-sub[start[p]][i]);
    }
    return ret;
}
class NumbersAndMatches {
	public:
	long long differentNumbers(long long N, int K) {
        cnt = 0;
        while (N > 0) {
            start[cnt++] = N%10;
            N /= 10;
        }

        digs.clear();
        digs.push_back(string(".#.") +
                              "#.#" +
                              "..." +
                              "#.#" +
                              ".#.");

        digs.push_back(string("...") +
                              "..#" +
                              "..." +
                              "..#" +
                              ".#.");

        digs.push_back(string(".#.") +
                              "..#" +
                              ".#." +
                              "#.." +
                              ".#.");
        
        digs.push_back(string(".#.") +
                              "..#" +
                              ".#." +
                              "..#" +
                              ".#.");

        digs.push_back(string("...") +
                              "#.#" +
                              ".#." +
                              "..#" +
                              "...");
        
        digs.push_back(string(".#.") +
                              "#.." +
                              ".#." +
                              "..#" +
                              ".#.");
        
        digs.push_back(string(".#.") +
                              "#.." +
                              ".#." +
                              "#.#" +
                              ".#.");

        digs.push_back(string(".#.") +
                              "..#" +
                              "..." +
                              "..#" +
                              "...");

        digs.push_back(string(".#.") +
                              "#.#" +
                              ".#." +
                              "#.#" +
                              ".#.");

        digs.push_back(string(".#.") +
                              "#.#" +
                              ".#." +
                              "..#" +
                              ".#.");
        
        for (int i=0; i<10; ++i) {
            num[i] = f(i);
        }
        
        for (int i=0; i<10; ++i) {
            for (int j=0; j<10; ++j) {
                change_to[i][j] = calc(i, j);
            }
        }
        
        memset(dp, 0xff, sizeof dp);
        return go(cnt-1, K, ZERO);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 10LL; int Arg1 = 1; long long Arg2 = 4LL; verify_case(0, Arg2, differentNumbers(Arg0, Arg1)); }
	void test_case_1() { long long Arg0 = 23LL; int Arg1 = 1; long long Arg2 = 4LL; verify_case(1, Arg2, differentNumbers(Arg0, Arg1)); }
	void test_case_2() { long long Arg0 = 66LL; int Arg1 = 2; long long Arg2 = 15LL; verify_case(2, Arg2, differentNumbers(Arg0, Arg1)); }
	void test_case_3() { long long Arg0 = 888888888LL; int Arg1 = 100; long long Arg2 = 1LL; verify_case(3, Arg2, differentNumbers(Arg0, Arg1)); }
	void test_case_4() { long long Arg0 = 444444444444444444LL; int Arg1 = 2; long long Arg2 = 1LL; verify_case(4, Arg2, differentNumbers(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    NumbersAndMatches ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
