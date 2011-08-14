#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int m, n;
int cP[50], cB[50];
int sqr(int x) { return x*x; }
int G[102][102];
const int INF = 12345678;
int P[102];
const int source = 101;
const int sink = 100;
void augment() {
    queue<int> Q;
    Q.push(source);
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (int i=0; i<source; ++i) {
            if (G[u][i]>0 && P[i]==-1) {
                P[i] = u;
                if (i == sink) {
                    return;
                }
                Q.push(i);
            }
        }
    }
}
class GreenWarfare {
	public:
	int minimumEnergyCost(vector <int> canonX, vector <int> canonY, vector <int> baseX, vector <int> baseY, vector <int> plantX, vector <int> plantY, int energySupplyRadius) {
	    m = baseX.size();
        n = plantX.size();
        
        memset(cP, 0x3f, sizeof cP);
        memset(cB, 0x3f, sizeof cB);
        for (int i=0; i<(int)canonX.size(); ++i) {
            for (int j=0; j<(int)baseX.size(); ++j) {
                cB[j] = min(cB[j], sqr(canonX[i]-baseX[j]) + sqr(canonY[i]-baseY[j]));
            }
            for (int j=0; j<(int)plantX.size(); ++j) {
                cP[j] = min(cP[j], sqr(canonX[i]-plantX[j]) + sqr(canonY[i]-plantY[j]));
            }
        }
        
        memset(G, 0, sizeof G);
        for (int i=0; i<(int)baseX.size(); ++i) {
            G[source][i] = cB[i];
        }
        for (int i=0; i<(int)plantX.size(); ++i) {
            G[m+i][sink] = cP[i];
        }
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (sqr(baseX[i]-plantX[j]) + sqr(baseY[i]-plantY[j]) <= energySupplyRadius*energySupplyRadius) {
                    G[i][m+j] = INF;
                }
            }
        }
        
        int sol = 0;
        while (1) {
            memset(P, 0xff, sizeof P);
            augment();
            if (P[sink] == -1) {
                break;
            }
            int add = INF;
            for (int i=sink; i!=source; i=P[i]) {
                add = min(add, G[P[i]][i]);
            }
            sol += add;
            for (int i=sink; i!=source; i=P[i]) {
                G[P[i]][i] -= add;
                G[i][P[i]] += add;
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
	void test_case_0() { int Arr0[] = { 0 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0,0,0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {3}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {3}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arg6 = 4; int Arg7 = 14; verify_case(0, Arg7, minimumEnergyCost(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_1() { int Arr0[] = { 0 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0,0,0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {2}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {2}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arg6 = 4; int Arg7 = 8; verify_case(1, Arg7, minimumEnergyCost(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_2() { int Arr0[] = {3,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,3,4,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {5,4,2,3,1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {1,2,5}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {1,2,5}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arg6 = 5; int Arg7 = 12; verify_case(2, Arg7, minimumEnergyCost(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_3() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {-10,-10,10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {10,-10,0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {10,10,-10}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {10,-10,0}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arg6 = 10; int Arg7 = 200; verify_case(3, Arg7, minimumEnergyCost(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_4() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {3}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {1,2,3}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {0,0,0}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arg6 = 4; int Arg7 = 14; verify_case(4, Arg7, minimumEnergyCost(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    GreenWarfare ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
