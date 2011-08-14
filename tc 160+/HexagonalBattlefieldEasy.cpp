#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <utility>
#include <map>

using namespace std;

vector< vector<int> > used;
vector< vector< pair<int, int> > > A;
const int INF = 1234567;
int orig_rowmask[7];
int dp[7][7][256][256];

int lastrow(int r, int c, int here) {
    if (c == (int)A[r].size()) {
        return 1;
    }
    
    int &ret = dp[r][c][here][0];
    if (ret != -1) {
        return ret;
    }
    if ((here>>c) & 1) {
        return (ret = lastrow(r, c+1, here));
    }
    here |= (1<<c);
    if (c+1==(int)A[r].size() || (here & (1<<(c+1)))) {
        return (ret = 0);
    }
    
    return (ret = lastrow(r, c+2, here | (1<<(c+1))));
}
    
int go(int r, int c, int here, int next) {
    if (r+1 == (int)A.size()) {
        assert(c == 0);
        return lastrow(r, 0, here);
    }
    if (c >= (int)A[r].size()) {
        return go(r+1, 0, next, orig_rowmask[r+2]);
    }
    int &ret = dp[r][c][here][next];
    if (ret != -1) {
        return ret;
    }

    if (here & (1<<c)) {
        return (ret = go(r, c+1, here, next));
    }
    
    ret = 0;
    here |= (1<<c);
    if (c+1<(int)A[r].size() && (here & (1<<(c+1)))==0) {
        ret += go(r, c+2, here | (1<<(c+1)), next);
    }
    
    if (A[r].size() > A[r+1].size()) {
        if (c == 0) {
            if ((next & 1) == 0) {
                ret += go(r, c+1, here, next | 1);
            }
        } else if (c+1 == (int)A[r].size()) {
            if ((next & (1<<(c-1))) == 0) {
                ret += go(r, c+1, here, next | (1<<(c-1)));
            }
        } else {
            if ((next & (1<<c)) == 0) {
                ret += go(r, c+1, here, next | (1<<c));
            }
            if ((next & (1<<(c-1))) == 0) {
                ret += go(r, c+1, here, next | (1<<(c-1)));
            }
        }
    } else {
        if ((next & (1<<c)) == 0) {
            ret += go(r, c+1, here, next | (1<<c));
        }
        if ((next & (1<<(c+1))) == 0) {
            ret += go(r, c+1, here, next | (1<<(c+1)));
        }
    }
        
    return ret;
}
class HexagonalBattlefieldEasy {
	public:
	int countArrangements(vector <int> X, vector <int> Y, int N) {
        if (N == 1) {
            return 1;
        }
        
        int moves = N-1;
        int cnt_up = N-1;
        int go_up = N-1;
        A.clear();
        int x = -(N-1);
        int y = -(N-1);
        map< pair<int, int>, pair<int, int> > M;
        while (x != -INF) {
            vector< pair<int, int> > row;
            int r_ind = A.size();
            int c_ind = 0;
            row.push_back(make_pair(x, y));
            M[make_pair(x, y)] = make_pair(r_ind, c_ind);
            int nx, ny;
            if (go_up > 0) {
                nx = x;
                ny = y+1;
            } else if (-go_up < N-1) { // go up-right
                nx = x+1;
                ny = y+1;
            } else {
                nx = ny = -INF;
            }
            --go_up;
            
            int tmoves = moves;
            while (tmoves--) {
                x += 1;
                row.push_back(make_pair(x, y));
                M[make_pair(x, y)] = make_pair(r_ind, ++c_ind);
            }
            if (cnt_up > 0) {
                --cnt_up;
                ++moves;
            } else {
                --moves;
            }
        
            A.push_back(row);
            x = nx;
            y = ny;
        }

        used.clear();
        for (int i=0; i<(int)A.size(); ++i) {
            used.push_back(vector<int> (A[i].size(), 0));
        }
        
        for (int i=0; i<(int)X.size(); ++i) {
            const pair<int, int> &p = M[make_pair(X[i], Y[i])];
            used[p.first][p.second] = 1;
        }
        
        for (int i=0; i<(int)used.size(); ++i) {
            int t = 0;
            for (int j=0; j<(int)used[i].size(); ++j) {
                if (used[i][j]) {
                    t |= (1<<j);
                }
            }
            orig_rowmask[i] = t;
        }

        memset(dp, 0xff, sizeof dp);
        return go(0, 0, orig_rowmask[0], orig_rowmask[1]);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {-2,0,1,1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-2,0,1,0,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 10; verify_case(0, Arg3, countArrangements(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 2; verify_case(1, Arg3, countArrangements(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 104; verify_case(2, Arg3, countArrangements(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {-1,0,0,1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0,1,0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 6; verify_case(3, Arg3, countArrangements(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {0,1,0,0,1,-1,-1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0,-1,1,1,0,-1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 1; verify_case(4, Arg3, countArrangements(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    HexagonalBattlefieldEasy ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
