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

int val(char c) {
    if (c == '.') {
        return -1;
    } else if (c <= 'Z') {
        return c - 'A';
    } else {
        return c - 'a' + 26;
    }
}

const int C1 = 52;
const int C2 = C1 + 1;
const int C3 = C2 + 1;

void set(int u, int v, int val, vector< vector<int> > &G) {
    G[u][v] = G[v][u] = val;
}

bool done[64];
void dfs(int at, const vector< vector<int> > &G) {
    done[at] = 1;
    for (int i=0; i<(int)G.size(); ++i) {
        if (!done[i] && G[at][i]!=-1) {
            dfs(i, G);
        }
    }
}
int cnt[64];
bool can(const vector< vector<int> > &G) {
    const int n = G.size();
    memset(done, 0, sizeof done);
    dfs(0, G);
    for (int i=0; i<n; ++i) {
        memset(cnt, 0, sizeof cnt);
        int total = 0;
        for (int j=0; j<n; ++j) {
            if (G[i][j] != -1) {
                ++cnt[G[i][j]];
                ++total;
            }
        }
        if ((total&1) || total>0 && !done[i]) {
            return false;
        }
        for (int c=0; c<=C3; ++c) {
            if (2*cnt[c] > total) {
                return false;
            }
        }
    }
    return true;
}
class LexSmallestTour {
	public:
	vector <int> determineTour(vector <string> roads, vector <int> queries) {
		int n = roads.size();
        vector< vector<int> > G(n+2, vector<int>(n+2, -1));
        int nedges = 0;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                G[i][j] = val(roads[i][j]);
                nedges += (G[i][j] != -1);
            }
        }
        nedges /= 2;
        
        vector< vector<int> > F = G;
        set(0, n, C1, F);
        set(n, n+1, C2, F);
        set(n+1, 0, C3, F);
        if (!can(F)) {
            return vector<int>();
        }
        
        int at = 0;
        int prev_color = C1;
        vector<int> seq;
        seq.push_back(at);
        while (nedges-- > 0) {
            bool ok = false;
            for (int i=0; i<n; ++i) {
                if (G[at][i]!=-1 && G[at][i]!=prev_color) {
                    F = G;
                    set(at, i, -1, F);
                    set(0, n, C1, F);
                    set(n, n+1, C2, F);
                    set(n+1, i, G[at][i], F);
                    if (can(F)) {
                        prev_color = G[at][i];
                        set(at, i, -1, G);
                        seq.push_back(i);
                        at = i;
                        ok = true;
                        break;
                    }
                }
            }
            assert(ok);
        }
        
        for (int i=0; i<(int)queries.size(); ++i) {
            queries[i] = seq[queries[i]];
        }
        return queries;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {".AB"
,"A.C"
,"BC."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, 2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 1, 2, 0 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, determineTour(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {".A..C"
,"A.ABB"
,".A.C."
,".BC.."
,"CB..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, 2, 3, 4, 5, 6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 1, 3, 2, 1, 4, 0 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, determineTour(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {".aa"
,"a.A"
,"aA."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3, 2, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 2, 1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, determineTour(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"..A.A"
,"...A."
,"A...A"
,".A..."
,"A.A.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, determineTour(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    LexSmallestTour ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
