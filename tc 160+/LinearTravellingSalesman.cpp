#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int my_abs(int x) {
    return x<0 ? -x : x;
}
class LinearTravellingSalesman {
	public:
	int findMinimumDistance(vector <int> x, vector <int> y) {
        int mi = 0;
        for (int i=1; i<(int)x.size(); ++i) {
            if (x[i]<x[mi] || x[i]==x[mi] && y[i]<y[mi]) {
                mi = i;
            }
        }
        
        int sol = 0;
        for (int i=0; i<(int)x.size(); ++i) {
            if (i != mi) {
                int t = my_abs(x[i]-x[mi]) + my_abs(y[i]-y[mi]);
                sol = max(sol, t);
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
	void test_case_0() { int Arr0[] = {1,3,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,2,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(0, Arg2, findMinimumDistance(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {3,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3,2,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(1, Arg2, findMinimumDistance(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {0,100,1000,10000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,10,100,1000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 11000; verify_case(2, Arg2, findMinimumDistance(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {80,60,70,50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {50,70,60,80}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 60; verify_case(3, Arg2, findMinimumDistance(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {7,7,7,7,7,7,7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {105,1231,5663,295,3062,380,7777}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 7672; verify_case(4, Arg2, findMinimumDistance(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    LinearTravellingSalesman ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
