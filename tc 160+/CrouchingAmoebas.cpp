#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<int> X, Y;
int A, T;
int n;
long long x0, y0;
inline long long my_abs(long long x) {
    return x<0 ? -x : x;
}
inline long long man_dist(long long x1, long long y1, long long x2, long long y2) {
    return my_abs(x2-x1) + my_abs(y2-y1);
}
long long get_dist(long long x, long long y) {
    if (x <= x0) {
        if (y <= y0) {
            return man_dist(x, y, x0, y0);
        } else if (y <= y0+A) {
            return x0 - x;
        } else {
            return man_dist(x, y, x0, y0+A);
        }
    } else if (x <= x0+A) { 
        if (y <= y0) {
            return y0 - y;
        } else if (y <= y0+A) {
            return 0; // inside
        } else {
            return y - y0 - A;
        }
    } else {
        if (y <= y0) {
            return man_dist(x, y, x0+A, y0);
        } else if (y <= y0+A) {
            return x - x0 - A;
        } else {
            return man_dist(x, y, x0+A, y0+A);
        }
    }
}
int calc(int x0, int y0) {
    ::x0 = x0;
    ::y0 = y0;
    vector<long long> need;
    for (int i=0; i<n; ++i) {
        need.push_back(get_dist(X[i], Y[i]));
    }
    sort(need.begin(), need.end());
    int t = T;
    int ret = 0;
    for (int i=0; i<n; ++i) {
        if (need[i] <= t) {
            t -= need[i];
            ++ret;
        }
    }
    return ret;
}
class CrouchingAmoebas {
	public:
	int count(vector <int> x, vector <int> y, int a, int t) {
        A = a;
        T = t;
        X = x;
        Y = y;
        n = X.size();
        
        int sol = 0;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                for (int dx=-10; dx<=10; ++dx) {
                    for (int dy=-10; dy<=10; ++dy) {
                        sol = max(sol, calc(x[i]+dx, y[j]+dy));
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
	void test_case_0() { int Arr0[] = {0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 1; int Arg4 = 2; verify_case(0, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {0,1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 1; int Arg4 = 2; verify_case(1, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {0,1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 2; int Arg4 = 3; verify_case(2, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {0,0,3,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,3,0,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 4; int Arg4 = 4; verify_case(3, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = {-1000000000,1000000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1000000000,1000000000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 15; int Arg4 = 1; verify_case(4, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    CrouchingAmoebas ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
