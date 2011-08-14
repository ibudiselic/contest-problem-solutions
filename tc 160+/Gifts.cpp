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

int bc[1<<18];
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };
vector<string> A;
int m, n;
long long D[18][18];
int G;
long long INF;
long long dp[18][1<<16];

bool done[50][50];
void upd(int i, int j, int orig) {
    memset(done, 0, sizeof done);
    queue< pair<int, int> > Q;
    Q.push(make_pair(i, j));
    done[i][j] = true;
    int d = -1;
    int t = 0;
    while (!Q.empty()) {
        if (t == 0) {
            t = Q.size();
            ++d;
        }
        --t;
        
        i = Q.front().first;
        j = Q.front().second;
        Q.pop();
        if (A[i][j] < G) {
            D[orig][A[i][j]] = D[A[i][j]][orig] = d;
        }
        
        for (int dir=0; dir<4; ++dir) {
            int r = i + di[dir];
            int c = j + dj[dir];
            if (r<0 || c<0 || r>=m || c>=n || A[r][c]=='#' || done[r][c]) {
                continue;
            }
            done[r][c] = 1;
            Q.push(make_pair(r, c));
        }
    }
}

long long go_(int u, int mask, int goal) {
    long long &ret = dp[u][mask];
    if (ret != -1) {
        return ret;
    }
    const int w = bc[mask] + 1;
    if (goal == 0) {
        return (ret = w*D[u][G-1]);
    }
    ret = INF;
    for (int i=0; i<G-2; ++i) {
        if ((mask & (1<<i)) == 0) {
            if (D[u][i] < INF) {
                ret = min(ret, w*D[u][i] + go_(i, mask | (1<<i), goal-1));
            }
        }
    }
    
    return ret;
}
long long go(int goal) {
    memset(dp, 0xff, sizeof dp);
    return go_(G-2, 0, goal);
}
class Gifts {
	public:
	int maxGifts(vector <string> city, int T) {
        A = city;
		m = city.size();
        n = city[0].size();
        INF = T + 1;
        G = 0;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (A[i][j] == 'G') {
                    A[i][j] = G++;
                }
            }
        }
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (A[i][j] == 'K') {
                    A[i][j] = G;
                } else if (A[i][j] == 'Q') {
                    A[i][j] = G+1;
                }
            }
        }
        G += 2;

        bc[0] = 0;
        for (int i=1; i<(1<<G); ++i) {
            bc[i] = bc[i>>1] + (i&1);
        }
        
        for (int i=0; i<G; ++i) {
            for (int j=0; j<G; ++j) {
                D[i][j] = INF;
            }
        }
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (A[i][j] < G) {
                    upd(i, j, A[i][j]);
                }
            }
        }
        
        for (int i=G-2; i>0; --i) {
            if (go(i) <= T) {
                return i;
            }
        }
        return 0;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"#######",
 "#K.G.Q#",
 "#######"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; int Arg2 = 1; verify_case(0, Arg2, maxGifts(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"#######",
 "#K.G.Q#",
 "#######"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 0; verify_case(1, Arg2, maxGifts(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"#######",
 "#K.Q.G#",
 "#######"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; int Arg2 = 0; verify_case(2, Arg2, maxGifts(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"#######",
 "#K.Q.G#",
 "#######"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; int Arg2 = 1; verify_case(3, Arg2, maxGifts(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"#######",
 "#K.QGG#",
 "#######"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; int Arg2 = 2; verify_case(4, Arg2, maxGifts(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"#....G#", 
 "###G###", 
 "#K...Q#", 
 "###.###", 
 "#G..GG#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 50; int Arg2 = 4; verify_case(5, Arg2, maxGifts(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    Gifts ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
