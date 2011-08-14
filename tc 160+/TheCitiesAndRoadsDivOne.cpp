#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

vector<string> M;
int C[20];
const long long mod = 1234567891;
vector<long long> T;
pair<int, bool> dfs(int u, int comp, int p=-1) {
    C[u] = comp;
    int cnt = 1;
    bool cyc = false;
    for (int v=0; v<(int)M.size(); ++v) {
        if (v!=p && M[u][v]=='Y') {
            if (C[v] == -1) {
                const pair<int, bool> t = dfs(v, comp, u);
                cyc |= t.second;
                cnt += t.first;
            } else {
                cyc = true;
            }
        }
    }
    
    return make_pair(cnt, cyc);
}

map< vector<long long>, long long > seen_at;
int canon[1<<20];
long long size[1<<20];
long long dp[1<<20][2];
long long go(unsigned in_subtree, bool make_cycle) {
    in_subtree = canon[in_subtree];
    long long &ret = dp[in_subtree][make_cycle];
    if (ret != -1) {
        return ret;
    }
    
    ret = 0;
    assert(in_subtree != 0);
    int u = 0;
    while (!((in_subtree>>u) & 1)) {
        ++u;
    }
    if (in_subtree == (1<<u)) {
        if (make_cycle) {
            int pos_edges = T[u]*(T[u]-1)/2;
            int have_edges = T[u] - 1;
            return (ret = pos_edges - have_edges);
        } else {
            return (ret = 1);
        }
    } else {
        int v = u+1;
        while (!((in_subtree>>v) & 1u)) {
            ++v;
        }
        unsigned others = in_subtree ^ (1u<<u) ^ (1u<<v);
        unsigned s = 0;
        do {
            assert((s|others) == others);
            assert((s & others) == s);
            const unsigned A = s | (1<<u);
            const unsigned B = (others^s) | (1<<v);
            const long long cnt = T[u] * size[B];
            if (make_cycle) {
                const long long A1 = go(A, 1);
                const long long A0 = go(A, 0);
                const long long B1 = go(B, 1);
                const long long B0 = go(B, 0);
                const long long left = cnt*A1*B0;
                const long long right = cnt*A0*B1;
                const long long span = cnt*(cnt-1)/2*A0*B0;
                ret = (ret + left + right + span) % mod;
            } else {
                ret = (ret + cnt*go(A, 0)*go(B, 0)) % mod;
            }
            s = ((s|~others)+1u) & others;
        } while (s != 0);
    }
    
    return ret;
}
class TheCitiesAndRoadsDivOne {
	public:
	int find(vector <string> map_) {
		M = map_;
        memset(C, 0xff, sizeof C);
        bool have_cycle = false;
        T.clear();
        for (int i=0; i<(int)M.size(); ++i) {
            if (C[i] == -1) {
                const pair<int, bool> t = dfs(i, T.size());
                have_cycle |= t.second;
                T.push_back(t.first);
            }
        }
        sort(T.begin(), T.end());
        
        seen_at.clear();
        size[0] = 0;
        canon[0] = 0;
        for (int i=1; i<(1<<T.size()); ++i) {
            vector<long long> repr;
            size[i] = 0;
            for (int j=0; j<(int)T.size(); ++j) {
                if ((i>>j) & 1u) {
                    size[i] += T[j];
                    repr.push_back(T[j]);
                }
            }
            if (seen_at.count(repr)) {
                canon[i] = seen_at[repr];
            } else {
                seen_at[repr] = i;
                canon[i] = i;
            }
        }
        
        memset(dp, 0xff, sizeof dp);
        long long sol = go((1u<<T.size())-1u, 0);
        if (!have_cycle) {
            sol += go((1u<<T.size())-1u, 1);
            if (sol >= mod) {
                sol -= mod;
            }
        }
        return sol;
	}








   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"NN",
 "NN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, find(Arg0)); }
	void test_case_1() { string Arr0[] = {"NNY",
 "NNN",
 "YNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(1, Arg1, find(Arg0)); }
	void test_case_2() { string Arr0[] = {"NY",
 "YN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, find(Arg0)); }
	void test_case_3() { string Arr0[] = {"NYNN",
 "YNNN",
 "NNNY",
 "NNYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(3, Arg1, find(Arg0)); }
	void test_case_4() { string Arr0[] = {"NNNNNNNNNNNN",
 "NNNNNNNNNNNN",
 "NNNNNNNNNNNN",
 "NNNNNNNNNNNN",
 "NNNNNNNNNNNN",
 "NNNNNNNNNNNN",
 "NNNNNNNNNNNN",
 "NNNNNNNNNNNN",
 "NNNNNNNNNNNN",
 "NNNNNNNNNNNN",
 "NNNNNNNNNNNN",
 "NNNNNNNNNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1137797187; verify_case(4, Arg1, find(Arg0)); }
	void test_case_5() { string Arr0[] = {"N"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(5, Arg1, find(Arg0)); }
	void test_case_6() { string Arr0[] = {"NYYNN",
 "YNYNN",
 "YYNNN",
 "NNNNY",
 "NNNYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(6, Arg1, find(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TheCitiesAndRoadsDivOne ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
