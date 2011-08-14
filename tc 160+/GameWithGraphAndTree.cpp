#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int bc[1<<14];
int n;
int G[14][14], T[14][14], P[14], SZ[14], TT[14][14];
int dfs(int root, int parent) {
    P[root] = parent;
    SZ[root] = 0;
    for (int i=0; i<n; ++i) {
        if (TT[root][i] && i!=parent) {
            T[root][i] = 1;
            SZ[root] += dfs(i, root) + 1;
        }
    }
    return SZ[root];
}
void root_tree_at(int root) {
    memset(T, 0, sizeof T);
    dfs(root, -1);
}
const long long mod = 1000000007;
long long dp[14][14][1<<14];
long long go(int t, int g, int unused) {
    long long &ret = dp[t][g][unused];
    if (ret != -1) {
        return ret;
    }
    
    int p = P[t];
    int next = -1;
    for (int i=0; i<n; ++i) {
        if (T[t][i]) {
            next = i;
            break;
        }
    }
    int sibling = -1;
    for (int i=t+1; i<n; ++i) {
        if (T[p][i]) {
            sibling = i;
            break;
        }
    }
    
    ret = 0;
    if (next == -1) {
        if (sibling == -1) {
            if (bc[unused] == 1) {
                int x = 0;
                while (!(unused & 1)) {
                    ++x;
                    unused >>= 1;
                }
                ret = G[g][x];
            }
        } else {
            for (int i=0; i<n; ++i) {
                if (G[g][i] && (unused & (1<<i))) {
                    ret += go(sibling, g, unused ^ (1<<i));
                }
            }
        }
    } else {
        if (sibling == -1) {
            for (int i=0; i<n; ++i) {
                if (G[g][i] && (unused & (1<<i))) {
                    ret += go(next, i, unused ^ (1<<i));
                }
            }
        } else {
            for (int i=0; i<n; ++i) {
                if (G[g][i] && (unused & (1<<i))) {
                    int rem = unused ^ (1<<i);
                    for (int sub=(rem-1)&rem; sub>0; sub=(sub-1)&rem) {
                        if (bc[sub] == SZ[t]) {
                            ret += go(next, i, sub) * go(sibling, g, rem ^ sub) % mod;
                        }
                    }
                }
            }
        }
    }

    ret %= mod;
    return ret;
}
class GameWithGraphAndTree {
	public:
	int calc(vector <string> graph, vector <string> tree) {
		n = graph.size();
        if (n == 1) {
            return 1;
        }
        bc[0] = 0;
        for (int i=1; i<(1<<n); ++i) {
            bc[i] = bc[i>>1] + (i&1);
        }
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                G[i][j] = (graph[i][j]=='Y');
                TT[i][j] = (tree[i][j]=='Y');
            }
        }
        
        long long sol = 0;
        for (int i=0; i<n; ++i) {
            root_tree_at(i);
            memset(dp, 0xff, sizeof dp);
            for (int j=0; j<n; ++j) {
                if (T[i][j]) {
                    sol += go(j, 0, (1<<n)-2);
                    break;
                }
            }
        }
        
        return int(sol % mod);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"NYN",
 "YNY",
 "NYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NYY",
 "YNN",
 "YNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(0, Arg2, calc(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"NYNNN",
 "YNYYY",
 "NYNYY",
 "NYYNY",
 "NYYYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NYNNN", 
 "YNYNN",
 "NYNYN",
 "NNYNY",
 "NNNYN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 12; verify_case(1, Arg2, calc(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"NYNNNY",
 "YNYNNN",
 "NYNYNN",
 "NNYNYN", 
 "NNNYNY",
 "YNNNYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NYNNYN",
 "YNNYNY",
 "NNNNYN",
 "NYNNNN",
 "YNYNNN",
 "NYNNNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(2, Arg2, calc(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"NYNNYN",
 "YNNYNY",
 "NNNNYN",
 "NYNNNN",
 "YNYNNN",
 "NYNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NNNYYN", 
 "NNYNNN",
 "NYNNYY", 
 "YNNNNN",
 "YNYNNN",
 "NNYNNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(3, Arg2, calc(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"NYNNNYNNY",
 "YNNNNNNYN",
 "NNNNYYNYY",
 "NNNNNYNNY",
 "NNYNNNYNY",
 "YNYYNNNYN",
 "NNNNYNNYN",
 "NYYNNYYNN",
 "YNYYYNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NNYNNNYYN",
 "NNNNYNNNN",
 "YNNNNNNNN",
 "NNNNNNYNN",
 "NYNNNNNYY",
 "NNNNNNNNY",
 "YNNYNNNNN",
 "YNNNYNNNN",
 "NNNNYYNNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 90; verify_case(4, Arg2, calc(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    GameWithGraphAndTree ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
