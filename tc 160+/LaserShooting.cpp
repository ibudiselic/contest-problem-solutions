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

double calc(int x, int y) {
    return atan(double(y)/x);
}
class LaserShooting {
	public:
	double numberOfHits(vector <int> x, vector <int> y1, vector <int> y2) {
		double t = 0.0;
        int n = x.size();
        for (int i=0; i<n; ++i) {
            if (y1[i] > y2[i]) {
                swap(y1[i], y2[i]);
            }
            if (y1[i]<=0 && y2[i]<=0) {
                t += calc(x[i], -y1[i]) - calc(x[i], -y2[i]);
            } else if (y1[i]<=0 && y2[i]>=0) {
                t += calc(x[i], -y1[i]) + calc(x[i], y2[i]);
            } else {
                t += calc(x[i], y2[i]) - calc(x[i], y1[i]);
            }
        }
        
        return t / acos(-1.0);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 0.5; verify_case(0, Arg3, numberOfHits(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1,-2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 1.0; verify_case(1, Arg3, numberOfHits(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {3,4,7,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {4,3,2,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 0.4623163952488826; verify_case(2, Arg3, numberOfHits(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {134,298,151,942}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-753,-76,19,568}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {440,689,-39,672}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 1.444210260641501; verify_case(3, Arg3, numberOfHits(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    LaserShooting ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
