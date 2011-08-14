#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int C[9];
vector<string> M;
int dfs(int u, int comp) {
    C[u] = comp;
    int ret = 1;
    for (int i=0; i<(int)M.size(); ++i) {
        if (M[u][i]=='Y' && C[i]==-1) {
            ret += dfs(i, comp);
        }
    }
    
    return ret;
}
vector<long long> T;

int dp[9][1<<9][9];
int go(int u, int in_subtree, int start) {
    assert(in_subtree & (1<<u));
    int &ret = dp[u][in_subtree][start];
    if (ret != -1) {
        return ret;
    }
    if (in_subtree == (1<<u)) {
        return (ret = 1);
    }
    
    const int others = in_subtree ^ (1<<u);
    ret = 0;
    for (int v=start; v<(int)T.size(); ++v) {
        if ((others>>v) & 1) {
            ret += T[u]*T[v]*go(u, in_subtree ^ (1<<v), v+1); // v is a leaf
            int s = others ^ (1<<v);
            for (int rem=s; rem; rem=(rem-1)&s) { // v is the root of a subtree
                ret += T[u]*T[v]*go(v, rem|(1<<v), 0)*go(u, (s^rem)|(1<<u), v+1);
            }
        }
    }
    
    return ret;
}
class TheCitiesAndRoadsDivTwo {
	public:
	int find(vector <string> map) {
		memset(C, 0xff, sizeof C);
        int cmp = 0;
        M = map;
        vector<long long> t;
        for (int i=0; i<(int)map.size(); ++i) {
            if (C[i] == -1) {
                t.push_back(dfs(i, cmp++));
            }
        }
        T = t;
        
        if (cmp == 1) {
            return 1;
        }
        memset(dp, 0xff, sizeof dp);
        return go(0, (1<<t.size())-1, 1);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"NN",
 "NN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, find(Arg0)); }
	void test_case_1() { string Arr0[] = {"NY",
 "YN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, find(Arg0)); }
	void test_case_2() { string Arr0[] = {"NNY",
 "NNN",
 "YNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, find(Arg0)); }
	void test_case_3() { string Arr0[] = {"NYNN",
 "YNNN",
 "NNNY",
 "NNYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(3, Arg1, find(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TheCitiesAndRoadsDivTwo ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
