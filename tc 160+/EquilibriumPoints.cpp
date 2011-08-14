#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

double eval(long double pos, const vector<int> &x, const vector<int> &m) {
    long double f = 0.0;
    int i = 0;
    while (i<(int)x.size() && x[i]<pos-1e-7) {
        f -= m[i]/((pos-x[i])*(pos-x[i]));
        ++i;
    }
    while (i<(int)x.size() && x[i]>pos+1e-7) {
        f += m[i]/((pos-x[i])*(pos-x[i]));
        ++i;
    }
    return f;
}
class EquilibriumPoints {
	public:
	vector <double> getPoints(vector <int> x, vector <int> m) {
		vector<double> sol(x.size()-1, 0.0);
        for (int i=1; i<(int)x.size(); ++i) {
            double lo = x[i-1];
            double hi = x[i];
            for (int t=0; t<10000; ++t) {
                double mid = (lo+hi)/2;
                if (eval(mid, x, m) >= -1e-15l) {
                    hi = mid;
                } else {
                    lo = mid;
                }
            }
            sol[i-1] = (lo+hi)/2;
        }
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <double> &Expected, const vector <double> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arr2[] = {1.5 }; vector <double> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, getPoints(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arr2[] = {1.0306534300317156 }; vector <double> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, getPoints(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1, 2, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arr2[] = {1.4060952084922507, 2.5939047915077493 }; vector <double> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, getPoints(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {2, 3, 5, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3, 2, 7, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arr2[] = {2.532859446114924, 3.7271944335152813, 6.099953640852538 }; vector <double> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, getPoints(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    EquilibriumPoints ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
