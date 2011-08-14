#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct counts {
    int a, b, c, d;
    counts(int a_, int b_, int c_, int d_): a(a_), b(b_), c(c_), d(d_) {}
    bool can_use(int a_, int b_, int c_, int d_) {
        return a<=a_ && b<=b_ && c<=c_ && d<=d_;
    }
};
vector<counts> before, after;
int G[5456][51]; // 5456 = max vertex count (i.e. a,b,c,d s.t. a+b+c+d=30)
counts make_counts(const string &s) {
    int a=0, b=0, c=0, d=0;
    for (int i=0; i<(int)s.size(); ++i) {
        switch (s[i]) {
            case 'A': ++a; break;
            case 'B': ++b; break;
            case 'C': ++c; break;
            case 'D': ++d; break;
        }
    }
    return counts(a, b, c, d);
}
int ind[31][31][31][31];
long long size[5456];
int n;
long long calc_reptfact(long long k, long long a, long long b, long long c, long long d) {
    long long ret = 1;
    long long denom_facts[] = {a, b, c, d};
    long long denom = 1;
    int denom_pos = 0;
    for (long long i=1; i<=k; ++i) {
        while (denom>denom_facts[denom_pos]) {
            ++denom_pos;
            denom = 1;
        }
        ret = ret*i/denom;
        ++denom;
    }
    return ret;
}
int scc_next_ind;
int scc_ind[5456];
int scc_low[5456];
int scc[5456];
bool in_stack[5456];
vector< vector<int> > comps;
void scc_calc(int u, vector<int> &S) {
    scc_ind[u] = scc_low[u] = scc_next_ind++;
    S.push_back(u);
    in_stack[u] = 1;
    int edge = 0;
    while (G[u][edge] != -1) {
        int v = G[u][edge];
        if (scc_ind[v] == -1) {
            scc_calc(v, S);
        }
        if (in_stack[v]) {
            scc_low[u] = min(scc_low[u], scc_low[v]);
        }
        ++edge;
    }
    if (scc_ind[u] == scc_low[u]) {
        comps.push_back(vector<int>());
        int v;
        do {
            v = S.back();
            S.pop_back();
            in_stack[v] = 0;
            scc[v] = (int)comps.size() - 1;
            comps.back().push_back(v);
        } while (v != u);
    }
}
class ImpossibleGame {
	public:
	long long getMinimum(int k, vector <string> before_, vector <string> after_) {
        before.clear();
        after.clear();
        for (int i=0; i<(int)before_.size(); ++i) {
            before.push_back(make_counts(before_[i]));
            after.push_back(make_counts(after_[i]));
        }
        
        n = 0;
        for (int a=0; a<=k; ++a) {
            for (int b=0; b<=k-a; ++b) {
                for (int c=0; c<=k-a-b; ++c) {
                    int d = k-a-b-c;
                    ind[a][b][c][d] = n;
                    size[n] = calc_reptfact(k, a, b, c, d);
                    ++n;
                }
            }
        }
        
        memset(G, 0xff, sizeof G);
        for (int a=0; a<=k; ++a) {
            for (int b=0; b<=k-a; ++b) {
                for (int c=0; c<=k-a-b; ++c) {
                    int d = k-a-b-c;
                    int ind_ = ind[a][b][c][d];
                    int edge = 0;
                    for (int i=0; i<(int)before.size(); ++i) {
                        if (before[i].can_use(a, b, c, d)) {
                            int aa = a - before[i].a + after[i].a;
                            int bb = b - before[i].b + after[i].b;
                            int cc = c - before[i].c + after[i].c;
                            int dd = d - before[i].d + after[i].d;
                            G[ind_][edge++] = ind[aa][bb][cc][dd];
                        }
                    }
                }
            }
        }
        
        scc_next_ind = 0;
        memset(scc, 0xff, sizeof scc);
        memset(scc_ind, 0xff, sizeof scc_ind);
        memset(in_stack, 0, sizeof in_stack);
        comps.clear();
        for (int i=0; i<n; ++i) {
            if (scc[i] == -1) {
                vector<int> S;
                scc_calc(i, S);
            }
        }
        
        n = comps.size();
        vector< vector<int> > G2(n, vector<int>());
        vector< vector<int> > G2_rev(n, vector<int>());
        vector<int> visited(n, 0);
        vector<int> outdeg(n, 0);
        vector<long long> component_size(n, 0);
        queue<int> Q;
        for (int i=0; i<n; ++i) {
            const vector<int> &component = comps[i];
            fill(visited.begin(), visited.end(), 0);
            for (int j=0; j<(int)component.size(); ++j) {
                int u = component[j];
                assert(scc[u] == i);
                component_size[i] += size[u];
                int edge = 0;
                while (G[u][edge] != -1) {
                    int v = G[u][edge];
                    if (scc[v]!=scc[u] && !visited[scc[v]]) {
                        visited[scc[v]] = 1;
                        ++outdeg[i];
                        G2[i].push_back(scc[v]);
                        G2_rev[scc[v]].push_back(i);
                    }
                    ++edge;
                }
            }
            assert(outdeg[i] == G2[i].size());
            if (outdeg[i] == 0) {
                Q.push(i);
            }
        }
        
        vector<long long> total_size(n, 0);
        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            for (int i=0; i<(int)G2[u].size(); ++i) {
                int v = G2[u][i];
                total_size[u] = max(total_size[u], total_size[v]); // choose max path "downward"
            }
            total_size[u] += component_size[u];
            for (int i=0; i<(int)G2_rev[u].size(); ++i) {
                int v = G2_rev[u][i];
                if (--outdeg[v] == 0) {
                    Q.push(v);
                }
                assert(outdeg[v] >= 0);
            }
        }
        
        return *max_element(total_size.begin(), total_size.end());
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; string Arr1[] = { "A" }
; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "B" }
; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 2LL; verify_case(0, Arg3, getMinimum(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 2; string Arr1[] = { "A", "A", "D" }
; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "B", "C", "D" }
; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 5LL; verify_case(1, Arg3, getMinimum(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 2; string Arr1[] = { "B", "C", "D" }
; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "C", "D", "B" }
; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 9LL; verify_case(2, Arg3, getMinimum(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 6; string Arr1[] = { "AABBC", "AAAADA", "AAACA", "CABAA", "AAAAAA", "BAAAA" }
; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "AACCB", "DAAABC", "AAAAD", "ABCBA", "AABAAA", "AACAA" }
; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 499LL; verify_case(3, Arg3, getMinimum(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    ImpossibleGame ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
