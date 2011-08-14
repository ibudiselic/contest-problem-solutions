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

int dist[51][51];
vector<int> S;
int N, K;

int sqr(int x) {
    return x*x;
}
int my_dist(int x, int y, int a, int b) {
    return sqr(x-a) + sqr(y-b);
}
int bet(int c, int a, int b) {
    return a<=c && c<=b;
}
map<int, vector<int> > M;
vector< vector<int> > eps;
vector<int> eps_val;
vector<int> x, y;

int dp[51];
int go(int u) {
    int &ret = dp[u];
    if (ret != -1) {
        return ret;
    }

    ret = 0;
    for (int i=0; i<(int)eps[u].size(); ++i) {
        int v = eps[u][i];
        for (int j=0; j<N; ++j) {
            if (y[j]>y[v] && dist[j][v]<=K) {
                ret = max(ret, go(j));
            }
        }
    }

    return (ret = ret + eps_val[u]);
}

bool G[51][51];
class GetToTheTop {
	public:
	int collectSweets(int K_, vector <int> sweets, vector <int> x_, vector <int> y_, vector <int> L) {
        x = x_;
        y = y_;
        sweets.insert(sweets.begin(), 0);
        x.insert(x.begin(), 0);
        y.insert(y.begin(), 0);
        L.insert(L.begin(), 10001);
		S = sweets;
        N = S.size();
        K = sqr(K_);
        M.clear();

        memset(dist, 0x3f, sizeof dist);
        for (int i=0; i<N; ++i) {
            dist[i][i] = 0;
            for (int j=i+1; j<N; ++j) {
                if (bet(x[i], x[j], x[j]+L[j]) || bet(x[j], x[i], x[i]+L[i])) {
                    dist[i][j] = dist[j][i] = sqr(y[i] - y[j]);
                } else {
                    dist[i][j] = dist[j][i] = min( min(my_dist(x[i], y[i], x[j], y[j]), my_dist(x[i], y[i], x[j]+L[j], y[j])),
                                                   min(my_dist(x[i]+L[i], y[i], x[j], y[j]), my_dist(x[i]+L[i], y[i], x[j]+L[j], y[j])) );
                }
            }
            M[y[i]].push_back(i);
        }

        memset(G, 0, sizeof G);
        for (int i=0; i<N; ++i) {
            G[i][i] = 0;
            const vector<int> &v = M[y[i]];

            for (int j=0; j<(int)v.size(); ++j) {
                if (dist[i][v[j]] <= K) {
                    G[i][v[j]] = 1;
                    G[v[j]][i] = 1;
                }
            }
        }
        for (int k=0; k<N; ++k) {
            for (int i=0; i<N; ++i) {
                if (G[i][k]) {
                    for (int j=0; j<N; ++j) {
                        if (!G[i][j]) {
                            G[i][j] = G[i][k] && G[k][j];
                        }
                    }
                }
            }
        }

        eps.assign(N, vector<int> ());
        eps_val.assign(N, 0);
        for (int i=0; i<N; ++i) {
            for (int j=0; j<N; ++j) {
                if (G[i][j]) {
                    eps[i].push_back(j);
                    eps_val[i] += S[j];
                }
            }
        }

        memset(dp, 0xff, sizeof dp);
        return go(0);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arr1[] = {1, 2, 3, 4, 3, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 1, 1, 4, 5, 5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1, 3, 4, 1, 2, 3}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {2, 1, 1, 2, 1, 1}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 13; verify_case(0, Arg5, collectSweets(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 4; int Arr1[] = {2, 8, 7, 4, 1, 4, 7, 5, 11, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2, 9, 4, 6, 10, 5, 2, 8, 1, 10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1, 1, 3, 3, 3, 5, 6, 6, 8, 9}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {2, 2, 1, 2, 2, 2, 4, 3, 2, 2}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 47; verify_case(1, Arg5, collectSweets(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 10; int Arr1[] = {1, 3, 5, 7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 6, 2, 8}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2, 4, 1, 2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {4, 1, 7, 4}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 16; verify_case(2, Arg5, collectSweets(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 3; int Arr1[] = {80, 20, 15, 13, 10, 7, 8, 9, 1, 4, 3, 15, 14, 19, 22, 12, 6, 15, 10, 30, 1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2, 8, 11, 17, 20, 14, 10, 16, 8, 14, 19, 6, 6, 6, 6, 15, 15, 15, 14, 20, 20, 20}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1, 2, 3, 2, 1, 4, 6, 7, 8, 8, 8, 9, 10, 11, 12, 9, 10, 11, 12, 9, 10, 11}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {2, 2, 2, 2, 2, 2, 3, 2, 3, 2, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 129; verify_case(3, Arg5, collectSweets(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 10; int Arr1[] = {0, 10, 11, 2, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 26, 29, 22, 3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1, 83, 88, 22, 5}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {11, 1, 23, 15, 8}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 0; verify_case(4, Arg5, collectSweets(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_5() { int Arg0 = 5; int Arr1[] = {2, 0, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 8, 9}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {6, 6, 1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {3, 6, 3}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 7; verify_case(5, Arg5, collectSweets(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_6() { int Arg0 = 2; int Arr1[] = {2, 9, 9, 1, 9, 9, 8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10, 8, 6, 6, 8, 7, 3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {6, 7, 5, 4, 5, 2, 5}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {1, 1, 1, 1, 1, 1, 1}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 47; verify_case(6, Arg5, collectSweets(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    GetToTheTop ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
