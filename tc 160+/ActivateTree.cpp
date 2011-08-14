#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector< vector<int> > T;
vector< vector< vector<int> > > A;
vector<int> tree_size;
vector<int> C;
const int inf = 987654321;
int FINAL;
int dp[1<<15][17][6];

void match(int mask, int root, int tree, int at, vector<int> &p);
void do_match(int child, int mask, int root, int tree, int at, vector<int> &used, vector<int> &p) {
    if (child >= (int)A[tree][at].size()) {
        p.push_back(0);
    } else {
        for (int i=0; i<(int)used.size(); ++i) {
            if (!used[i]) {
                used[i] = 1;
                const int here = (1<<(T[root][i]-1));
                vector<int> pp;
                match(mask, T[root][i], tree, A[tree][at][child], pp);
                if (pp.size() > 0) {
                    vector<int> ppp;
                    do_match(child+1, mask, root, tree, at, used, ppp);
                    if (ppp.size() > 0) {
                        for (int j=0; j<(int)pp.size(); ++j) {
                            for (int k=0; k<(int)ppp.size(); ++k) {
                                p.push_back(pp[j] | ppp[k] | here);
                            }
                        }
                    }
                }
                used[i] = 0;
            }
        }
        sort(p.begin(), p.end());
        p.resize(unique(p.begin(), p.end()) - p.begin());
    }
}

// match root with at@tree
void match(int mask, int root, int tree, int at, vector<int> &p) {
    if (T[root].size() < A[tree][at].size()) {
        return;
    }
    vector<int> used(T[root].size(), 0);
    do_match(0, mask, root, tree, at, used, p);
}
    
int go(int, int, int);
int match(int mask, int root, int tree) {
    vector<int> possible_masks;
    match(mask, root, tree, 0, possible_masks);
    
    int ret = inf;
    for (int i=0; i<(int)possible_masks.size(); ++i) {
        ret = min(ret, C[tree] + go(mask ^ possible_masks[i], root, tree + 1));
    }
    return ret;
}

int go(int mask, int root, int tree) {
    int &ret = dp[mask][root][tree];
    if (ret != -1) {
        return ret;
    }
    if (mask == FINAL) {
        return (ret = 0);
    }
    if (root >= (int)T.size()) {
        return (ret = inf);
    }
    if (tree >= (int)A.size()) {
        return (ret = go(mask, root+1, 0));
    }
    
    ret = min(go(mask, root, tree+1), match(mask, root, tree));
    return ret;
}
class ActivateTree {
	public:
	int minCost(vector <string> trees, string target, vector <int> costs) {
		T.clear();
        A.clear();
        tree_size.clear();
        C = costs;
        for (int i=0; i<(int)trees.size(); ++i) {
            vector< vector<int> > t;
            istringstream is(trees[i]);
            int p;
            int ind = 0;
            while (is >> p) {
                if (p != -1) {
                    if (t.size() < p+1) {
                        t.resize(p + 1);
                    }
                    t[p].push_back(ind);
                }
                ++ind;
            }
            t.resize(ind);
            A.push_back(t);
            tree_size.push_back(ind);
        }
        
        istringstream is(target);
        int p;
        int ind = 0;
        while (is >> p) {
            if (p != -1) {
                if (T.size() < p+1) {
                    T.resize(p + 1);
                }
                T[p].push_back(ind);
            }
            ++ind;
        }
        T.resize(ind);
        
        FINAL = (1<<(ind-1)) - 1;
        
        memset(dp, 0xff, sizeof dp);
        const int sol = go(0, 0, 0);
        return sol<inf ? sol : -1;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"-1 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "-1 0"; int Arr2[] = {5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 5; verify_case(0, Arg3, minCost(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"-1 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "-1 0 0"; int Arr2[] = {5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -1; verify_case(1, Arg3, minCost(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"-1 0","-1 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "-1 0 0"; int Arr2[] = {1,101}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 102; verify_case(2, Arg3, minCost(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"-1 0","-1 0","-1 0 3 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "-1 0 3 0"; int Arr2[] = {5,10,21}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 20; verify_case(3, Arg3, minCost(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"-1 0 1","-1 0 0","-1 0","-1 0 1 0 2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "-1 0 0 0 2"; int Arr2[] = {3885,13122,31377,21317}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 17007; verify_case(4, Arg3, minCost(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    ActivateTree ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
