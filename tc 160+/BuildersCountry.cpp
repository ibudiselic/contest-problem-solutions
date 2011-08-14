#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

long long road[50][50];
long long help[50][50];
int p_[50];
int root(int x) {
    if (p_[x] != -1) {
        return p_[x] = root(p_[x]);
    } else {
        return x;
    }
}
bool flip() {
    return (int)((rand()/(RAND_MAX+1.0))*2.0);
}
bool join(int x, int y) {
    int a = root(x);
    int b = root(y);
    if (a == b) {
        return false;
    }
    
    if (flip()) {
        p_[a] = b;
    } else {
        p_[b] = a;
    }
    return true;
}

struct Edge {
    int a, b;
    long long t;
    Edge(int a_, int b_): a(a_), b(b_) {
        t = road[a][b] + help[a][b];
    }
};
bool operator<(const Edge &x, const Edge &y) {
    if (x.t != y.t) {
        return x.t < y.t;
    } else if (x.a != y.a) {
        return x.a < y.a;
    } else {
        return x.b < y.b;
    }
}
class BuildersCountry {
	public:
	long long minCost(vector <int> before, vector <int> after, vector <int> houseCost, vector <string> g, int roadCost) {
        long long sol = 0;
        int n = before.size();
        for (int i=0; i<n; ++i) {
            sol += (long long)houseCost[i]*(after[i]-before[i])*(before[i]+after[i]-1)/2;
        }
        
        for (int i=0; i<n; ++i) {
            for (int j=i+1; j<n; ++j) {
                int ii = i;
                int jj = j;
                if (houseCost[ii] < houseCost[jj]) {
                    swap(ii, jj);
                }
                const long long b1 = before[ii];
                const long long a1 = after[ii];
                const long long c1 = houseCost[ii];
                const long long b2 = before[jj];
                const long long a2 = after[jj];
                const long long c2 = houseCost[jj];
                
                road[i][j] = road[j][i] = roadCost * (b1 + b2);
                help[i][j] = help[j][i] = c1*b2*(a1-b1) + c2*a1*(a2-b2);
            }
        }
        
        vector<Edge> v;
        memset(p_, 0xff, sizeof p_);
        for (int i=0; i<n; ++i) {
            for (int j=i+1; j<n; ++j) {
                if (g[i][j] == 'Y') {
                    sol += help[i][j];
                    join(i, j);
                } else {
                    v.push_back(Edge(i, j));
                }
            }
        }
        
        sort(v.begin(), v.end());
        for (int i=0; i<(int)v.size(); ++i) {
            int a = v[i].a;
            int b = v[i].b;
            if (join(a, b)) {
                sol += road[a][b] + help[a][b];
            }
        }
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2, 1, 3, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 1, 3, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {4, 5, 3, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"NNNN", "NNNN", "NNNN", "NNNN"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1000; long long Arg5 = 13000LL; verify_case(0, Arg5, minCost(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arr0[] = {1, 1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 3, 1, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {8, 5, 3, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"NYNN", "YNYN", "NYNY", "NNYN"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 100000; long long Arg5 = 39LL; verify_case(1, Arg5, minCost(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arr0[] = {9, 11}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10, 11}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"NN", "NN"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 15; long long Arg5 = 400LL; verify_case(2, Arg5, minCost(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"N"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 888; long long Arg5 = 999000LL; verify_case(3, Arg5, minCost(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arr0[] = {99, 23, 44, 55, 32}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {99, 23, 44, 55, 32}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {39, 32, 11, 23, 89}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"NYNNN", "YNNNY", "NNNYY", "NNYNY", "NYYYN"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 54; long long Arg5 = 0LL; verify_case(4, Arg5, minCost(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    BuildersCountry ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
