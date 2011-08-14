#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<int> X, Y, R;
inline int dist_sqr(int x, int y, int xc, int yc) {
    return (x-xc)*(x-xc) + (y-yc)*(y-yc);
}
inline bool inside(int x, int y, int xc, int yc, int r) {
    return dist_sqr(x, y, xc, yc) < r*r;
}
inline bool inside(int i, int j) {
    return inside(X[i], Y[i], X[j], Y[j], R[j]);
}
int n;
bool v[50];
int P[50];
int get_circ(int x, int y) {
    for (int i=0; i<n; ++i) {
        if (inside(x, y, X[i], Y[i], R[i])) {
            return i;
        }
    }
    return n;
}

int dfs(int c) {
    if (c==n || v[c]) {
        return c;
    } else {
        v[c] = true;
        return dfs(P[c]);
    }
}
int depth(int c, int p) {
    return (c==p ? 0 : 1 + depth(P[c], p));
}
class CirclesCountry {
	public:
	int leastBorders(vector <int> X_, vector <int> Y_, vector <int> R_, int x1, int y1, int x2, int y2) {
        X = X_;
        Y = Y_;
        R = R_;
		n = X.size();
        for (int i=0; i<n; ++i) {
            for (int j=i+1; j<n; ++j) {
                if (R[i] > R[j]) {
                    swap(R[i], R[j]);
                    swap(X[i], X[j]);
                    swap(Y[i], Y[j]);
                }
            }
        }
        for (int i=0; i<n; ++i) {
            P[i] = n;
            for (int j=i+1; j<n; ++j) {
                if (inside(i, j)) {
                    P[i] = j;
                    break;
                }
            }
        }
        int c1 = get_circ(x1, y1);
        int c2 = get_circ(x2, y2);
        
        memset(v, 0, sizeof v);
        dfs(c1);
        int p = dfs(c2);
        
        return depth(c1, p) + depth(c2, p);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -5; int Arg4 = 1; int Arg5 = 5; int Arg6 = 1; int Arg7 = 0; verify_case(0, Arg7, leastBorders(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_1() { int Arr0[] = {0,-6,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,2,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -5; int Arg4 = 1; int Arg5 = 5; int Arg6 = 1; int Arg7 = 2; verify_case(1, Arg7, leastBorders(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_2() { int Arr0[] = {1,-3,2,5,-4,12,12}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,-1,2,5,5,1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {8,1,2,1,1,1,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -5; int Arg4 = 1; int Arg5 = 12; int Arg6 = 1; int Arg7 = 3; verify_case(2, Arg7, leastBorders(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_3() { int Arr0[] = {-3,2,2,0,-4,12,12,12}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1,2,3,1,5,1,1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,3,1,7,1,1,2,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; int Arg4 = 3; int Arg5 = 13; int Arg6 = 2; int Arg7 = 5; verify_case(3, Arg7, leastBorders(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_4() { int Arr0[] = {-107,-38,140,148,-198,172,-179,148,176,153,-56,-187}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {175,-115,23,-2,-49,-151,-52,42,0,68,109,-174}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {135,42,70,39,89,39,43,150,10,120,16,8}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 102; int Arg4 = 16; int Arg5 = 19; int Arg6 = -108; int Arg7 = 3; verify_case(4, Arg7, leastBorders(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    CirclesCountry ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
