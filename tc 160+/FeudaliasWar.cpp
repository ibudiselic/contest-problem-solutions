#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

double sqr(double x) { return x*x; }
double dist(int x1, int y1, int x2, int y2) {
    return sqrt(sqr(x1-x2) + sqr(y1-y2));
}
struct Edge {
    int to;
    double w;
    Edge(int to_, double w_): to(to_), w(w_) {}
};
bool operator<(const Edge &a, const Edge &b) {
    if (a.to != b.to) {
        return a.to < b.to;
    }
    return a.w < b.w;
}

vector< vector<Edge> > G;
int match[50];
int rmatch[2500];
int N;
int M;

const double eps = 1e-10;

bool v[50];
bool dfs(int at, double t) {
    v[at] = true;
    for (int i=0; i<(int)G[at].size(); ++i) {
        const int to = G[at][i].to;
        const double tt = G[at][i].w;
        if (tt<=t+eps && (rmatch[to]==-1 || !v[rmatch[to]] && dfs(rmatch[to], t))) {
            match[at] = to;
            rmatch[to] = at;
            return true;
        }
    }
    return false;
}
bool can_solve(double t) {
    memset(match, 0xff, sizeof match);
    memset(rmatch, 0xff, sizeof rmatch);
    
    for (int i=0; i<N; ++i) {
        for (int j=0; j<(int)G[i].size(); ++j) {
            const int to = G[i][j].to;
            const double tt = G[i][j].w;
            if (rmatch[to]==-1 && tt <= t+eps) {
                match[i] = to;
                rmatch[to] = i;
                break;
            }
        }
    }
    
    for (int i=0; i<N; ++i) {
        if (match[i] == -1) {
            memset(v, 0, sizeof v);
            if (!dfs(i, t)) {
                return false;
            }
        }
    }
    return true;
}
class FeudaliasWar {
	public:
	double getMinimumTime(vector <int> baseX, vector <int> baseY, vector <int> siloX, vector <int> siloY, int takeOffTime, int rechargeTime, int missileSpeed) {
		N = baseX.size();
        M = siloX.size();
        
        G.assign(N, vector<Edge>());
        vector<double> times;
        for (int i=0; i<M; ++i) {
            for (int j=0; j<N; ++j) {
                double d = dist(siloX[i], siloY[i], baseX[j], baseY[j]);
                for (int slot=0; slot<N; ++slot) {
                    double w = (takeOffTime/60.0 + rechargeTime) * slot + takeOffTime/60.0 + d/missileSpeed;
                    times.push_back(w);
                    G[j].push_back(Edge(i*N + slot, w));
                }
            }
        }
        
        sort(times.begin(), times.end());
        times.erase(unique(times.begin(), times.end()), times.end());
        
        int lo = 0;
        int hi = times.size()-1;
        while (lo < hi) {
            int mid = lo + (hi-lo)/2;
            double t = times[mid];
            if (can_solve(t)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        
        return times[lo];
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,0,50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,50,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {50,0,1000}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {50,1000,0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 30; int Arg5 = 20; int Arg6 = 1; double Arg7 = 91.5; verify_case(0, Arg7, getMinimumTime(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_1() { int Arr0[] = {0,0,50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,50,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {50,0,1000}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {50,1000,0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 30; int Arg5 = 900; int Arg6 = 1; double Arg7 = 950.5; verify_case(1, Arg7, getMinimumTime(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_2() { int Arr0[] = {0,2000,4000,6000,8000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,2000,4000,6000,8000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,2000,4000,6000}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2000,4000,6000,8000}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 60; int Arg5 = 1000; int Arg6 = 50; double Arg7 = 1042.0; verify_case(2, Arg7, getMinimumTime(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_3() { int Arr0[] = {1100,1200,1300,1400,1500,1600,1700,1800,1900}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2100,2300,2500,2700,2900,2700,2500,2300,2100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1400,1400,1500,1600,1600}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {3100,3300,3200,3100,3300}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 20; int Arg5 = 300; int Arg6 = 100; double Arg7 = 306.7494291969649; verify_case(3, Arg7, getMinimumTime(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    FeudaliasWar ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
