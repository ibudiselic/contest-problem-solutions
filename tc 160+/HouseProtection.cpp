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

vector<int> xb, yb, xr, yr;
int n1, n2;

inline int sqr(int x) {
    return x*x;
}
inline int dist2(int i, int j) {
    return sqr(xb[i]-xr[j]) + sqr(yb[i]-yr[j]);
}

const double pi = acos(-1.0);

int G[50][50];
int match[50], rmatch[50];
bool tried[50];

bool can_match(int x) {
    tried[x] = 1;
    for (int i=0; i<n2; ++i) {
        if (G[x][i]) {
            if (rmatch[i]==-1 || !tried[rmatch[i]] && can_match(rmatch[i])) {
                rmatch[i] = x;
                match[x] = i;
                return true;
            }
        }
    }

    return false;
}
int bipartite_match() {
    memset(match, 0xff, sizeof match);
    memset(rmatch, 0xff, sizeof rmatch);

    int ret = 0;
    for (int i=0; i<n1; ++i) {
        if (match[i] == -1) {
            memset(tried, 0, sizeof tried);
            ret += can_match(i);
        }
    }

    return ret;
}

class HouseProtection {
	public:
	double safetyFactor(vector <int> xb_, vector <int> yb_, vector <int> xr_, vector <int> yr_, int R) {
		xb = xb_;
        yb = yb_;
        xr = xr_;
        yr = yr_;

        n1 = xb.size();
        n2 = xr.size();

        vector<int> dist;
        for (int i=0; i<n1; ++i) {
            for (int j=0; j<n2; ++j) {
                int t = dist2(i, j);
                if (t < 4*R*R) {
                    dist.push_back(t);
                }
            }
        }
        dist.push_back(4*R*R);
        sort(dist.begin(), dist.end());

        memset(G, 0, sizeof G);
        double sol = 0.0;

        for (int i=0; i<(int)dist.size(); ++i) {
            int d = dist[i];
            for (int a=0; a<n1; ++a) {
                for (int b=0; b<n2; ++b) {
                    if (dist2(a, b) < d) {
                        G[a][b] = 1;
                    }
                }
            }

            int t = n1 + n2 - bipartite_match();
            sol = max(sol, t*d*pi/4);
        }

        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 0, 4 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 0, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 2, 1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = { 2, -1 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1; double Arg5 = 9.42477796076938; verify_case(0, Arg5, safetyFactor(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arr0[] = { 1 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = { 1 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 5; double Arg5 = 78.53981633974483; verify_case(1, Arg5, safetyFactor(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arr0[] = { 0 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 100 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = { 0 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 51; double Arg5 = 15707.963267948966; verify_case(2, Arg5, safetyFactor(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arr0[] = { 23, 29, 29, 35 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 77, 79, 75, 77 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 26, 26, 32 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = { 78, 76, 76 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 3; double Arg5 = 113.09733552923255; verify_case(3, Arg5, safetyFactor(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    HouseProtection ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
