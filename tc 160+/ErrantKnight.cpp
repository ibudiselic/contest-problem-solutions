#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool done[4001][4001], dp[4001][4001];
int dx[8] = {2,1,-1,-2,-2,-1,1,2};
int dy[8] = {1,2,2,1,-1,-2,-2,-1};
inline int sqr(int x) { return x*x; }
inline int dist2(int x, int y) { return sqr(x) + sqr(y); }

bool go(int x, int y) {
    if (x < 0) {
        x = -x;
    }
    if (y < 0) {
        y = -y;
    }
    if (x < y) {
        swap(x, y);
    }
    if (done[x][y]) {
        return dp[x][y];
    }
    done[x][y] = 1;
    if (x!=y && x!=0 && y!=0) {
        return (dp[x][y] = 1);
    }
    if (x==0 && y==0) {
        return (dp[x][y] = 0);
    }
    for (int d=0; d<8; ++d) {
        int r = x + dx[d];
        int c = y + dy[d];
        while (dist2(r, c) < dist2(r-dx[d], c-dy[d])) {
            if (!go(r, c)) {
                return (dp[x][y] = 1);
            }
            r += dx[d];
            c += dy[d];
        }
    }
    return (dp[x][y] = 0);
}
class ErrantKnight {
	public:
	string whoWins(vector <int> x, vector <int> y) {
	    memset(done, 0, sizeof done);

        string sol;
        for (int i=0; i<(int)x.size(); ++i) {
            sol += (go(x[i], y[i]) ? 'W' : 'B');
        }

        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,1,2,2,9,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1,0,1,5,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "BWWWWB"; verify_case(0, Arg2, whoWins(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,2,3,4,5,6,7,1,2,3,4,5,6,7,1,2,3,4,5,6,7,1,2,3,4,5,6,7,1,2,3,4,5,6,7,1,2,3,4,5,6,7,1,2,3,4,5,6,7,7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0,0,0,0,0,0,1,1,1,1,1,1,1,2,2,2,2,2,2,2,3,3,3,3,3,3,3,4,4,4,4,4,4,4,5,5,5,5,5,5,5,6,6,6,6,6,6,6,7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "BWBBBBBWWWWWWWWWWWWWWWWBWWWWWWWBWWWWWWWBWWWWWWWWWB"; verify_case(1, Arg2, whoWins(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {-10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "B"; verify_case(2, Arg2, whoWins(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    ErrantKnight ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
