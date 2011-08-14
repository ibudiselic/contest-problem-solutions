#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <numeric>

using namespace std;

int n;
vector<string> G;
int C[50];

void dfs(int x, int c) {
    C[x] = c;
    for (int i=0; i<n; ++i) {
        if (C[i]==-1 && G[x][i]=='1') {
            dfs(i, c);
        }
    }
}

class AddElectricalWires {
	public:
	int maxNewWires(vector <string> G_, vector <int> A) {
		G = G_;
        n = G.size();
        memset(C, 0xff, sizeof C);
        int c = 1;
        for (int i=0; i<(int)A.size(); ++i) {
            dfs(A[i], c++);
        }

        vector<int> sz(c);
        int sol = 0;
        for (int i=1; i<c; ++i) {
            sz[i] = count(C, C+n, i);
            sol += sz[i] * (sz[i] - 1) / 2;
        }

        int t = n - accumulate(sz.begin()+1, sz.end(), 0);
        if (t > 0) {
            int tt = *max_element(sz.begin()+1, sz.end());
            int ttt = tt + t;
            sol += ttt*(ttt-1)/2 - tt*(tt-1)/2;
        }

        int exists = 0;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                exists += (G[i][j]=='1');
            }
        }

        return sol - exists/2;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"000","000","000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(0, Arg2, maxNewWires(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"000","000","000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(1, Arg2, maxNewWires(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"01","10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(2, Arg2, maxNewWires(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"00000","00000","00000","00000","00000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1,2,3,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(3, Arg2, maxNewWires(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"01000","10100","01010","00100","00000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(4, Arg2, maxNewWires(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    AddElectricalWires ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
