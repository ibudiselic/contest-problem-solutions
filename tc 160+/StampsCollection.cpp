#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool G[50][50];
int C[50];
int deg[50];
int val[50];
int N;

void dfs(int x, int comp) {
    C[x] = comp;
    for (int i=0; i<N; ++i) {
        if (C[i]==-1 && G[x][i]) {
            dfs(i, comp);
        }
    }
}

vector<int> T;
void dfs(int x, int p, int start) {
    T.push_back(x);
    for (int i=0; i<N; ++i) {
        if (i!=p && i!=start && G[x][i]) {
            dfs(i, x, start);
            return;
        }
    }
}

int dp[50][2];
vector<int> price;
int go(int p, bool took_parent) {
    if (p == (int)T.size()) {
        return 0;
    }
    int &ret = dp[p][took_parent];
    if (ret != -1) {
        return ret;
    }

    ret = go(p+1, 0);
    if (!took_parent) {
        ret = max(ret, price[T[p]] + go(p+1, 1));
    }

    return ret;
}

class StampsCollection {
	public:
	int sell(int n, vector <string> demand, vector <int> price) {
		memset(G, 0, sizeof G);
        ::price = price;
        N = demand.size();
        vector<int> demands(n, -1);

        memset(deg, 0, sizeof deg);
        for (int i=0; i<N; ++i) {
            istringstream is(demand[i]);
            int x;
            while (is >> x) {
                if (demands[x] != -1) {
                    ++deg[i];
                    ++deg[demands[x]];
                    G[demands[x]][i] = G[i][demands[x]] = 1;
                } else {
                    demands[x] = i;
                }
            }
        }

        memset(C, 0xff, sizeof C);
        int cnt = 0;
        for (int i=0; i<N; ++i) {
            if (C[i] == -1) {
                dfs(i, cnt++);
            }
        }

        int sol = 0;
        for (int i=0; i<cnt; ++i) {
            int start = -1; // set to -2 if isolated vertex, deg1 vertex index if path, -1 if cycle
            for (int j=0; j<N; ++j) {
                if (C[j] == i) {
                    if (deg[j] == 0) {
                        start = -2;
                        sol += price[j];
                        break;
                    } else if (deg[j] == 1) {
                        start = j;
                        break;
                    }
                }
            }
            if (start == -2) {
                continue;
            }
            T.clear();
            if (start != -1) {
                dfs(start, -1, -1);
                memset(dp, 0xff, sizeof dp);
                sol += go(0, 0);
            } else {
                for (int j=0; j<N; ++j) {
                    if (C[j] == i) {
                        for (int k=0; k<N; ++k) {
                            if (G[j][k]) {
                                dfs(k, j, j);
                                T.push_back(j);
                                int sz = T.size();
                                int best = 0;
                                for (int l=0; l<sz; ++l) {
                                    memset(dp, 0xff, sizeof dp);
                                    best = max(best, go(1, 0));
                                    T.insert(T.begin(), T.back());
                                    T.pop_back();
                                }
                                sol += best;
                                break;
                            }
                        }
                        break;
                    }
                }
            }
        }

        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; string Arr1[] = {"0 4"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; verify_case(0, Arg3, sell(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 2; string Arr1[] = {"1 0","0"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 5; verify_case(1, Arg3, sell(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 3; string Arr1[] = {"0 1","0 2","1 2"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10,11,12}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 12; verify_case(2, Arg3, sell(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 3; string Arr1[] = {"0","1 0","1 2"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5,9,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 10; verify_case(3, Arg3, sell(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 20; string Arr1[] = {"0 1","1 2","2 3","3 0","4 5","5 6","6 4","8","8","9","9 10","10 11","11 12","12"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3,7,4,1,3,3,1,5,6,5,18,10,1,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 40; verify_case(4, Arg3, sell(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    StampsCollection ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
