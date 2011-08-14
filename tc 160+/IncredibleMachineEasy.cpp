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

double calc(double g, const vector<int> &H) {
    double t = 0;
    for (int i=0; i<(int)H.size(); ++i) {
        t += sqrt(2*H[i]/g);
    }
    return t;
}
class IncredibleMachineEasy {
	public:
	double gravitationalAcceleration(vector <int> height, int T) {
		double lo = 0.0;
        double hi = 1e20;
        
        for (int t=0; t<10000; ++t) {
            double mid = (lo + hi)/2.0;
            if (calc(mid, height) < T) {
                hi = mid;
            } else {
                lo = mid;
            }
        }
        
        return lo;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {16,23,85,3,35,72,96,88,2,14,63}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 30; double Arg2 = 9.803799620759717; verify_case(0, Arg2, gravitationalAcceleration(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; double Arg2 = 26.73924541044107; verify_case(1, Arg2, gravitationalAcceleration(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {8,8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; double Arg2 = 7.111111111111111; verify_case(2, Arg2, gravitationalAcceleration(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {3,1,3,1,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; double Arg2 = 0.7192306901503684; verify_case(3, Arg2, gravitationalAcceleration(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    IncredibleMachineEasy ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
