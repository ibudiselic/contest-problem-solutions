#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

double my_abs(double x) {
    return x<0 ? -x : x;
}
double calc(double t, const vector< vector<int> > &A, const vector< vector<int> > &B, const vector< vector<int> > &C, const vector< vector<int> > &D) {
    int n = A.size();
    double ret = 0.0;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            ret = max(ret, max(my_abs(A[i][j]*t + B[i][j]), my_abs(C[i][j]*t + D[i][j])));
        }
    }
    
    return ret;
}
class CatchTheMice {
	public:
	double largestCage(vector <int> xp, vector <int> yp, vector <int> xv, vector <int> yv) {
		int n = xp.size();

        vector< vector<int> > A(n, vector<int>(n, 0));
        vector< vector<int> > B(n, vector<int>(n, 0));
        vector< vector<int> > C(n, vector<int>(n, 0));
        vector< vector<int> > D(n, vector<int>(n, 0));
        
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                A[i][j] = xv[i] - xv[j];
                B[i][j] = xp[i] - xp[j];
                C[i][j] = yv[i] - yv[j];
                D[i][j] = yp[i] - yp[j];
            }
        }
        
        double lo = 0.0;
        double hi = 10000;
        double sol = 1e32;
        for (int rep=0; rep<1000; ++rep) {
            double m1 = lo + (hi-lo)/3.0;
            double m2 = m1 + (hi-lo)/3.0;
            double v1 = calc(m1, A, B, C, D);
            double v2 = calc(m2, A, B, C, D);
            if (v1 < v2) {
                hi = m2;
                sol = min(sol, v1);
            } else {
                lo = m1;
                sol = min(sol, v2);
            }
        }
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10,-10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0,0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 10.0; verify_case(0, Arg4, largestCage(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {0,10,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,-6,4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {4,5,-4}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 3.0; verify_case(1, Arg4, largestCage(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {50,10,30,15}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-10,30,20,40}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {-5,-10,-15,-5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {40,-10,-1,-50}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 40.526315789473685; verify_case(2, Arg4, largestCage(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {0,10,10,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0,10,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,0,-1,0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0,1,0,-1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 10.0; verify_case(3, Arg4, largestCage(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = {13,50,100,40,-100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {20,20,-150,-40,63}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {4,50,41,-41,-79}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,1,1,3,-1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 212.78688524590163; verify_case(4, Arg4, largestCage(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arr0[] = {0,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {3,3}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 10.0; verify_case(5, Arg4, largestCage(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_6() { int Arr0[] = {-49,-463,-212,-204,-557,-67,-374,-335,-590,-4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {352,491,280,355,129,78,404,597,553,445}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {-82,57,-23,-32,89,-72,27,17,100,-94}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {-9,-58,9,-14,56,75,-32,-98,-81,-43}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 25.467532467532468; verify_case(6, Arg4, largestCage(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    CatchTheMice ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
