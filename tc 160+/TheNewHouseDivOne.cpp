#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class TheNewHouseDivOne {
	public:
	double distance(vector <int> x, vector <int> y, int k) {
        for (int i=0; i<(int)x.size(); ++i) {
            x[i] *= 2;
            y[i] *= 2;
        }
        
        int sol = 12345678;
        for (int i=-101; i<102; ++i) {
            for (int j=-101; j<102; ++j) {
                vector<int> d;
                for (int t=0; t<(int)x.size(); ++t) {
                    d.push_back(abs(x[t]-i) + abs(y[t]-j));
                }
                nth_element(d.begin(), d.begin()+k-1, d.end());
                sol = min(sol, d[k-1]);
            }
        }
        return sol/2.0;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {-1, -1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1, 1, -1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; double Arg3 = 2.0; verify_case(0, Arg3, distance(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {-1, -1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1, 1, -1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; double Arg3 = 1.0; verify_case(1, Arg3, distance(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {4, 4, 4, 4, 4, 3, 3, 5, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {7, 7, 7, 4, 4, 5, 6, 5, 6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 9; double Arg3 = 1.5; verify_case(2, Arg3, distance(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {30, -15, 24, -23, 43, -8, -6, -47, 23, -11, 43, 6, -18, 44, -46, 16, 32, 31, 13, 9, 22, 25, 4, -44, 38, -41, -20, 41, -35, 7, 25, 39, -36, -20, -5, -38, -15, -22, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-45, -7, -33, 31, -8, -33, -20, -14, -50, -48, -31, 35, -24, -31, -11, 41, -41, -11, 46, -1, -5, 5, -39, -26, -40, -9, 16, 38, -30, 34, 46, -17, -27, 33, -38, 28, 46, -16, -46}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 13; double Arg3 = 32.0; verify_case(3, Arg3, distance(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TheNewHouseDivOne ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
