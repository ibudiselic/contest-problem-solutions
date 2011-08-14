#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int G[50][50];
int my_abs(int x) {
    return x<0 ? -x : x;
}
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };

struct S {
    int a, b, c, d, v;
    S(int a_, int b_, int c_, int d_): a(a_), b(b_), c(c_), d(d_) {
        v = my_abs(G[a][b] - G[c][d]);
    }
};
bool operator<(const S &x, const S &y) {
    if (x.v != y.v) {
        return x.v > y.v;
    } else if (x.a != y.a) {
        return x.a < y.a;
    } else if (x.b != y.b) {
        return x.b < y.b;
    } else if (x.c != y.c) {
        return x.c < y.c;
    } else {
        return x.d < y.d;
    }
}

bool A[50][50];
class ActivateGame {
	public:
	int findMaxScore(vector <string> grid) {
		int m = grid.size();
        int n = grid[0].size();
        
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                const char c = grid[i][j];
                if (c <= '9') {
                    G[i][j] = c-'0';
                } else if (c <= 'Z') {
                    G[i][j] = c-'A' + 36;
                } else {
                    G[i][j] = c-'a' + 10;
                }
            }
        }
        
        vector<S> v;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                for (int d=0; d<4; ++d) {
                    const int r = i + di[d];
                    const int c = j + dj[d];
                    if (r<0 || c<0 || r>=m || c>=n) {
                        continue;
                    }
                    v.push_back(S(i, j, r, c));
                }
            }
        }
        sort(v.begin(), v.end());
        memset(A, 0, sizeof A);
        A[0][0] = true;
        int cnt = m*n - 1;
        int sol = 0;
        while (cnt--) {
            for (int i=0; i<(int)v.size(); ++i) {
                const S &t = v[i];
                if (A[t.a][t.b] ^ A[t.c][t.d]) {
                    sol += t.v;
                    A[t.a][t.b] = A[t.c][t.d] = true;
                    break;
                }
            }
        }
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"05",
 "aB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 69; verify_case(0, Arg1, findMaxScore(Arg0)); }
	void test_case_1() { string Arr0[] = {"03",
 "21"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(1, Arg1, findMaxScore(Arg0)); }
	void test_case_2() { string Arr0[] = {"John",
 "Brus",
 "Gogo"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 118; verify_case(2, Arg1, findMaxScore(Arg0)); }
	void test_case_3() { string Arr0[] = {"AAA",
 "AAA",
 "AAA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, findMaxScore(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    ActivateGame ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
