#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct location {
    int x, y, v;
    location(int x_, int y_, int v_): x(x_), y(y_), v(v_) {}
};
bool operator<(const location &a, const location &b) {
    if (a.x != b.x) {
        return a.x < b.x;
    } else if (a.y != b.y) {
        return a.y < b.y;
    } else {
        return a.v > b.v;
    }
}
const int mod = 1000000009;
void add(int &a, int b) {
    if ((a += b) >= mod) {
        a -= mod;
    }
}
void sub(int &a, int b) {
    add(a, mod - b);
}
int gcd(int m, int n) {
    return m==0 ? n : gcd(n%m, m);
}
int C(int n, int k) {
    if (n < k) {
        return 0;
    }
    if (n == 0) {
        return k==0;
    }
    vector<int> vals;
    vals.reserve(k);
    for (int i=0; i<k; ++i) {
        vals.push_back(n-i);
    }
    for (int i=2; i<=k; ++i) {
        int x = i;
        for (int j=0; x>1 && j<k; ++j) {
            int d = gcd(x, vals[j]);
            x /= d;
            vals[j] /= d;
        }
        assert(x == 1);
    }
    int ret = 1;
    for (int i=0; i<k; ++i) {
        ret = ((long long)ret*vals[i])%mod;
    }
    return ret;
}
vector<location> A;
int empty_board_ways_memo[122][122][11];
int empty_board_ways_(int dx, int dy, int k) {
    if (dx<0 || dy<0 || k==0) {
        return 0;
    }
    if (dx == 0) {
        return C(dy-1, k-1);
    }
    if (dy == 0) {
        return C(dx-1, k-1);
    }
    int ret = 0;
    for (int kk=1; kk<k; ++kk) {
        add(ret, int((long long)C(k, kk) * C(dx-1, kk-1) % mod * C(dy-1, k-kk-1) % mod));
    }
    return ret;
}
int empty_board_ways(int i, int j, int k) {
    int &ret = empty_board_ways_memo[i][j][k];
    if (ret != -1) {
        return ret;
    }

    return ret = empty_board_ways_(A[j].x-A[i].x, A[j].y-A[i].y, k);
}
int from_empty_ways_memo[122][122][11];
int from_empty_ways(int from, int to, int k) {
    int &ret = from_empty_ways_memo[from][to][k];
    if (ret != -1) {
        return ret;
    }
    ret = empty_board_ways(from, to, k);
    int overcount = 0;
    for (int i=from+1; i<to; ++i) {
        if (A[i].v != -1) {
            for (int kk=0; kk<=k; ++kk) {
                add(overcount, int((long long)from_empty_ways(i, to, kk) * empty_board_ways(from, i, k-kk) % mod));
            }
        }
    }
    sub(ret, overcount);
    return ret;
}
int empty_ways_memo[122][122][11];
int empty_ways(int from, int to, int k) {
    int &ret = empty_ways_memo[from][to][k];
    if (ret != -1) {
        return ret;
    }
    if (A[from].v == -1) {
        return ret = from_empty_ways(from, to, k);
    } else {
        ret = 0;
        int i = lower_bound(A.begin(), A.end(), location(A[from].x + A[from].v, A[from].y, 10000000)) - A.begin();
        if (i < (int)A.size()) {
            if (A[i].x==A[from].x+A[from].v && A[i].y==A[from].y) {
                if (i == to) {
                    if (k == 0) {
                        add(ret, 1);
                    }
                } else if (A[i].v == -1) {
                    add(ret, from_empty_ways(i, to, k));
                }
            }
        }
        i = lower_bound(A.begin(), A.end(), location(A[from].x, A[from].y + A[from].v, 10000000)) - A.begin();
        if (i < (int)A.size()) {
            if (A[i].x==A[from].x && A[i].y==A[from].y+A[from].v) {
                if (i == to) {
                    if (k == 0) {
                        add(ret, 1);
                    }
                } else if (A[i].v == -1) {
                    add(ret, from_empty_ways(i, to, k));
                }
            }
        }
        return ret;
    }
}
int ways_memo[122][11];
int ways(int to, int k) {
    int &ret = ways_memo[to][k];
    if (ret != -1) {
        return ret;
    }
    ret = empty_ways(0, to, k);
    for (int i=1; i<to; ++i) {
        if (A[i].v == -1) {
            continue;
        }
        for (int kk=0; kk<=k; ++kk) {
            add(ret, int((long long)ways(i, kk) * empty_ways(i, to, k-kk) % mod));
        }
    }
    return ret;
}
class NumberLabyrinthDiv1 {
	public:
	int getNumberOfPaths(vector <int> X, vector <int> Y, vector <int> val, int fx, int fy, int K) {
        vector<location> AA;
        AA.push_back(location(-1, -1, -1));
        AA.push_back(location(0, 0, -1));
        AA.push_back(location(fx, fy, -1));
        for (int i=0; i<(int)X.size(); ++i) {
            AA.push_back(location(X[i], Y[i], val[i]));
            AA.push_back(location(X[i]+val[i], Y[i], -1));
            AA.push_back(location(X[i], Y[i]+val[i], -1));
        }
        
        sort(AA.begin(), AA.end());
        A.clear();
        for (int i=1; i<(int)AA.size(); ++i) {
            if (AA[i].x>fx || AA[i].y>fy) {
                continue;
            }
            if (AA[i].x!=AA[i-1].x || AA[i].y!=AA[i-1].y) {
                A.push_back(AA[i]);
            }
        }
        
        memset(ways_memo, 0xff, sizeof ways_memo);
        memset(empty_ways_memo, 0xff, sizeof empty_ways_memo);
        memset(from_empty_ways_memo, 0xff, sizeof from_empty_ways_memo);
        memset(empty_board_ways_memo, 0xff, sizeof empty_board_ways_memo);
        int sol = 0;
        for (int k=0; k<=K; ++k) {
            add(sol, ways((int)A.size()-1, k));
        }
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; int Arg4 = 3; int Arg5 = 2; int Arg6 = 2; verify_case(0, Arg6, getNumberOfPaths(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_1() { int Arr0[] = {}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; int Arg4 = 3; int Arg5 = 3; int Arg6 = 14; verify_case(1, Arg6, getNumberOfPaths(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_2() { int Arr0[] = {2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; int Arg4 = 3; int Arg5 = 3; int Arg6 = 18; verify_case(2, Arg6, getNumberOfPaths(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_3() { int Arr0[] = {1, 3, 6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 3, 6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2, 2, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 5; int Arg4 = 5; int Arg5 = 4; int Arg6 = 210; verify_case(3, Arg6, getNumberOfPaths(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_4() { int Arr0[] = {1, 19, 20, 21, 21, 21, 20, 19, 19}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 11, 11, 11, 10, 9, 9, 9, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2, 2, 2, 2, 2, 2, 2, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 20; int Arg4 = 10; int Arg5 = 4; int Arg6 = 1778; verify_case(4, Arg6, getNumberOfPaths(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_5() { int Arr0[] = {13, 224, 77, 509, 1451, 43, 379, 142, 477}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1974, 375, 38, 783, 3, 1974, 1790, 1008, 2710}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {30, 1845, 360, 11, 837, 84, 210, 4, 6704}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 509; int Arg4 = 2011; int Arg5 = 10; int Arg6 = 196052726; verify_case(5, Arg6, getNumberOfPaths(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    NumberLabyrinthDiv1 ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
