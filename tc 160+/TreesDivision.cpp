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

struct point {
    int x, y;
    point(int x_, int y_): x(x_), y(y_) {}
};
bool operator<(const point &a, const point &b) {
    if (a.x != b.x) {
        return a.x < b.x;
    } else {
        return a.y < b.y;
    }
}
const point operator-(const point &a, const point &b) {
    return point(a.x-b.x, a.y-b.y);
}
int ccw(const point &a, const point &b) {
    return a.x*b.y - a.y*b.x;
}
int ccw(const point &c, const point &a, const point &b) {
    return ccw(c-a, b-a);
}
vector<point> p;
struct Cmp {
    bool operator()(int i, int j) {
        return p[i] < p[j];
    }
};
class TreesDivision {
	public:
	int minDifference(vector <int> x, vector <int> y, vector <int> income) {
	    int sol = accumulate(income.begin(), income.end(), 0);
        
        p.clear();
        int n = x.size();
        for (int i=0; i<n; ++i) {
            p.push_back(point(x[i], y[i]));   
        }
        for (int i=0; i<n; ++i) {
            for (int j=i+1; j<n; ++j) {
                vector<int> on;
                int pos = 0;
                int neg = 0;
                int z = 0;
                for (int k=0; k<n; ++k) {
                    int t = ccw(p[k], p[i], p[j]);
                    if (t == 0) {
                        on.push_back(k);
                        z += income[k];
                    } else {
                        (t>0 ? pos : neg) += income[k];
                    }
                }
                sol = min(sol, abs(pos+z-neg));
                sol = min(sol, abs(pos-z-neg));
                sort(on.begin(), on.end(), Cmp());
                int l = 0;
                for (int k=0; k<(int)on.size(); ++k) {
                    l += income[on[k]];
                    sol = min(sol, abs(pos+l - (neg + (z-l))));
                    sol = min(sol, abs(pos+(z-l) - (neg+l)));
                }
            }
        }
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10,20}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 10; verify_case(0, Arg3, minDifference(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {0,1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,1,1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,1,1,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(1, Arg3, minDifference(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {0,0,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,3,4,1000}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 990; verify_case(2, Arg3, minDifference(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {0,0,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1,1,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,4,8}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(3, Arg3, minDifference(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {4,2,4,2,3,6,3,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,4,3,3,2,4,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {4,5,2,6,7,4,2,4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(4, Arg3, minDifference(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arr0[] = {1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3,2,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,1000000,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1000000; verify_case(5, Arg3, minDifference(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TreesDivision ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
