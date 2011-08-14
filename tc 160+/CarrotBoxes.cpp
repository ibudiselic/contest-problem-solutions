#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int n;
bool G[50][50];
int C[50];
int comp;
int tar_counter = 0;
void tarjan_(int u, vector<int> &ind, vector<int> &low, vector<int> &S, vector<int> &in_stack) {
    ind[u] = low[u] = tar_counter++;
    S.push_back(u);
    in_stack[u] = 1;
    for (int v=0; v<n; ++v) {
        if (G[u][v]) {
            if (ind[v] == -1) {
                tarjan_(v, ind, low, S, in_stack);
                low[u] = min(low[u], low[v]);
            } else if (in_stack[v]) {
                low[u] = min(low[u], low[v]);
            }
        }
    }
    if (low[u] == ind[u]) {
        int v = -1;
        do {
            v = S.back();
            S.pop_back();
            in_stack[v] = 0;
            C[v] = comp;
        } while (v != u);
        ++comp;
    }
}
void tarjan() {
    vector<int> in_stack(n, 0), ind(n, -1), low(n, 0);
    vector<int> S;
    for (int i=0; i<n; ++i) {
        if (ind[i] == -1) {
            tarjan_(i, ind, low, S, in_stack);
        }
    }
}
bool V[50];
bool can_eliminate(int p, const vector<int> &need_comps) {
    int c = need_comps[p];
    int cnt = 0;
    for (int i=0; i<n; ++i) {
        cnt += (C[i]==c);
    }
    if (cnt > 1) {
        return false;
    }
    vector<int> tmp;
    for (int i=0; i<(int)need_comps.size(); ++i) {
        if (i != p) {
            for (int u=0; u<n; ++u) {
                if (C[u] == need_comps[i]) {
                    tmp.push_back(u);
                }
            }
        }
    }

    memset(V, 0, sizeof V);
    for (int i=0; i<(int)tmp.size(); ++i) {
        for (int j=0; j<n; ++j) {
            if (G[tmp[i]][j]) {
                V[j] = true;
            }
        }
    }

    return count(V, V+n, false) == 1;
}
    
class CarrotBoxes {
	public:
	double theProbability(vector <string> information) {
		n = information.size();
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                G[i][j] = (information[i][j]=='Y');
            }
        }
        for (int k=0; k<n; ++k) {
            for (int i=0; i<n; ++i) {
                for (int j=0; j<n; ++j) {
                    G[i][j] |= G[i][k] && G[k][j];
                }
            }
        }
        comp = 0;
        tarjan();
        
        vector<int> need_comps;
        for (int c=0; c<comp; ++c) {
            for (int i=0; i<n; ++i) {
                if (C[i] == c) {
                    for (int j=0; j<n; ++j) {
                        if (C[j]!=c && G[j][i]) {
                            goto DONT_NEED;
                        }
                    }
                }
            }
            need_comps.push_back(c);
            DONT_NEED: ;
        }

        for (int i=0; i<(int)need_comps.size(); ++i) {
            if (can_eliminate(i, need_comps)) {
                return 1.0 - (need_comps.size()-1.0)/n;
            }
        }
        return 1.0 - 1.0*need_comps.size()/n;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"YYYYY",
 "NYNNN",
 "NNYNN",
 "NNNYN",
 "NNNNY"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.8; verify_case(0, Arg1, theProbability(Arg0)); }
	void test_case_1() { string Arr0[] = {"YNNNN",
 "NYNNN",
 "NNYNN",
 "NNNYN",
 "NNNNY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.2; verify_case(1, Arg1, theProbability(Arg0)); }
	void test_case_2() { string Arr0[] = {"Y"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1.0; verify_case(2, Arg1, theProbability(Arg0)); }
	void test_case_3() { string Arr0[] = {"YNNNN",
 "YYNNN",
 "YNYNN",
 "NNNYY",
 "NNNYY"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.6; verify_case(3, Arg1, theProbability(Arg0)); }
	void test_case_4() { string Arr0[] = {"YYYNNNYN",
 "NYNNNNYN",
 "NNYNNNNN",
 "NYNYNNNN",
 "YNNNYNNY",
 "NNYNNYNN",
 "NNNNYNYN",
 "NNYNNNNY"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.875; verify_case(4, Arg1, theProbability(Arg0)); }
	void test_case_5() { string Arr0[] = {"YNNNNNNNNYNNNNNNNNNN",
 "NYNNNNNNNNNNNNNNNNNN",
 "NNYNNNNNNNYNNNNNYNNN",
 "NNNYNYNNNNNNNNYNNNNN",
 "NNNNYNNNNNNNNNYNNNNY",
 "NNNNNYNNNNNNNNNNNNNY",
 "NNNNYNYNYNNNNNNNNNNN",
 "NNNNNNNYNNNYYNNNNNNN",
 "NNNNNNNNYNNNNNNNNNNN",
 "YNNNNNNNNYNNNNNYNNNN",
 "NNNNNNNNNNYNNNNNNNNN",
 "NYNNNNNNNNNYNNNNNNNN",
 "NNNNNNNYNNNNYNNNNNNN",
 "NNNNNNNNNNNNNYNNNYNN",
 "NNNNNNNNNNNYNNYNNNYN",
 "NYNNNNNNNNNNNNNYNNNN",
 "NNYNNNNNNNNNNNNNYNNN",
 "NNNNNNNNNNNNNYNYNYNN",
 "NNNNNNNNYNYNNNNNNNYY",
 "NNNYNNNNNNNNNNNNNNNY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.75; verify_case(5, Arg1, theProbability(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    CarrotBoxes ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
