#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>

using namespace std;

double best[50][3000];
const double inf = 1e20;
struct state {
    int p, cnt;
    double cost;
    state(int p_, int cnt_, double cost_): p(p_), cnt(cnt_), cost(cost_) {}
};
bool operator<(const state &a, const state &b) {
    if (a.cnt != b.cnt) {
        return a.cnt > b.cnt;
    } else if (a.p != b.p) {
        return a.p < b.p;
    } else {
        return a.cost > b.cost;
    }
}

int M, T;
vector<int> X, Y;
inline int sqr(int x) {
    return x*x;
}
class BuildingCities {
	public:
	int findMinimumCities(int maxDirect, int maxTravel, vector <int> cityX, vector <int> cityY) {
		M = sqr(maxDirect);
        T = maxTravel;
        X = cityX;
        Y = cityY;
        
        if (sqr(X.back()-X[0])+sqr(Y.back()-Y[0]) > sqr(maxTravel)) {
            return -1;
        }
        
        for (int i=0; i<50; ++i) {
            for (int j=0; j<3000; ++j) {
                best[i][j] = inf;
            }
        }
        best[0][0] = 0.0;
        priority_queue<state> Q;
        Q.push(state(0, 0, 0.0));
        while (!Q.empty()) {
            const state s = Q.top();
            Q.pop();
            int p = s.p;
            int added = s.cnt;
            double cost = s.cost;
            
            if (p == (int)X.size()-1) {
                if (cost <= T+1e-9) {
                    return added;
                }
                continue;
            }
            if (best[p][added] < cost-1e-9) {
                continue;
            }
            for (int i=0; i<(int)X.size(); ++i) {
                if (i != p) {
                    int D2 = sqr(X[i]-X[p])+sqr(Y[i]-Y[p]);
                    if (D2 <= M) {
                        double ncost = cost + sqrt(D2);
                        if (ncost < best[i][added]-1e-9) {
                            best[i][added] = ncost;
                            Q.push(state(i, added, ncost));
                        }
                    } else {
                        int add = (int)(sqrt(D2)/maxDirect - 1e-5);
                        assert(add >= 1);
                        double ncost = cost + sqrt(D2);
                        int nadded = added + add;
                        if (ncost < best[i][nadded]-1e-9) {
                            best[i][nadded] = ncost;
                            Q.push(state(i, nadded, ncost));
                        }
                    }
                }
            }
        }
        
        return -1;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 5; int Arr2[] = {0,0,0,1,2,2,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0,1,2,2,2,1,1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1; verify_case(0, Arg4, findMinimumCities(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 15; int Arr2[] = {2,6,10,14}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2,6,2,6}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 3; verify_case(1, Arg4, findMinimumCities(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 15; int Arr2[] = {0,5,2,3,1,8,6,4,7,9,10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0,5,2,3,1,8,6,4,7,9,10}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 0; verify_case(2, Arg4, findMinimumCities(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 2; int Arg1 = 5; int Arr2[] = {0,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0,5}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = -1; verify_case(3, Arg4, findMinimumCities(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 5; int Arg1 = 1500; int Arr2[] = {0,1000}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0,1000}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 282; verify_case(4, Arg4, findMinimumCities(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    BuildingCities ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
