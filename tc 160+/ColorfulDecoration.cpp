#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;
pii P[50][2];
int n, N;
int done[50];
int G[100][100];

int my_abs(int x) { return x<0 ? -x : x; }
inline bool intersects(int i, int opt_i, int j, int opt_j, int sz) {
    const pii a = P[i][opt_i];
    const pii b = P[j][opt_j];
    return (my_abs(a.first-b.first)<sz && my_abs(a.second-b.second)<sz);
}

// SSC O(n)
void tarjan(int u, vector<int> &ind, vector<int> &low, int &num, vector<int> &S, vector<int> &in_stack, vector<int> &C) {
    ind[u] = low[u] = num++;
    S.push_back(u);
    in_stack[u] = true;
    for (int v=0; v<N; ++v) {
        if (G[u][v]) {
            if (ind[v] == -1) {
                tarjan(v, ind, low, num, S, in_stack, C);
                low[u] = min(low[u], low[v]);
            } else if (in_stack[v]) {
                low[u] = min(low[u], ind[v]);
            }
        }
    }
    
    if (ind[u] == low[u]) {
        int v;
        do {
            v = S.back();
            S.pop_back();
            in_stack[v] = false;
            C[v] = low[u];
        } while (v != u);
    }
}
// 2sat, clause = (not placed at (x1, y1) or not place at (x2, y2)
bool test(int sz) {
    memset(G, 0, sizeof G);
    for (int i=0; i<n; ++i) {
        for (int opt_i=0; opt_i<2; ++opt_i) {
            for (int j=i+1; j<n; ++j) {
                for (int opt_j=0; opt_j<2; ++opt_j) {
                    if (intersects(i, opt_i, j, opt_j, sz)) {
                        G[2*i+opt_i][2*j+(1-opt_j)] = 1;
                        G[2*j+opt_j][2*i+(1-opt_i)] = 1;
                    }
                }
            }
        }
    }
    
    vector<int> ind(N, -1);
    vector<int> low(N, -1);
    vector<int> in_stack(N, 0);
    vector<int> C(N, -1);
    vector<int> S;
    int num = 0;
    for (int i=0; i<N; ++i) {
        if (ind[i] == -1) {
            tarjan(i, ind, low, num, S, in_stack, C);
        }
    }
    
    for (int i=0; i<n; ++i) {
        if (C[2*i] == C[2*i+1]) {
            return false;
        }
    }
    return true;
}
    
class ColorfulDecoration {
	public:
	int getMaximum(vector <int> xa, vector <int> ya, vector <int> xb, vector <int> yb) {
		n = xa.size();
        N = 2*n;
        for (int i=0; i<n; ++i) {
            P[i][0] = make_pair(xa[i], ya[i]);
            P[i][1] = make_pair(xb[i], yb[i]);
        }
        if (!test(1)) {
            return 0;
        }
        
        int lo = 1;
        int hi = 1000000001;
        while (hi-lo > 1) {
            int mid = lo + (hi-lo)/2;
            if (test(mid)) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
        
        return lo;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 10,  0,  7 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {  0, 19,  6 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 20, 10, 25 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = { 20, 35, 25 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 19; verify_case(0, Arg4, getMaximum(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = { 464, 20 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 464, 10 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 464,  3 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = { 464, 16 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 461; verify_case(1, Arg4, getMaximum(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = { 0, 0, 1, 1 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 0, 0, 1, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 1, 1, 0, 0 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = { 1, 1, 0, 0 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 0; verify_case(2, Arg4, getMaximum(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = { 0, 3, 0, 5, 6 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 1, 6, 0, 8, 5 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 6, 1, 7, 4, 7 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = { 5, 9, 2, 8, 9 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 3; verify_case(3, Arg4, getMaximum(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = { 1000000000, 0 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 0, 1000000000 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 0, 1000000000 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = { 0, 1000000000 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1000000000; verify_case(4, Arg4, getMaximum(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    ColorfulDecoration ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
