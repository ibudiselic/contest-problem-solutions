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

double f(int x, int l, int r) {
    double mid = (l + r) / 2.0;
    if (x <= mid) {
        return x/(mid-l) - l/(mid-l);
    } else {
        return x/(mid-r) - r/(mid-r);
    }
}
double A(int l, int r, int a, int b) {
    double mid = (a + b) / 2.0;

    double fl = f(l, a, b);
    double fr = f(r, a, b);
    if (r <= mid) {
        return (r - l)*fl + (fr-fl)*(r - l)/2.0;
    } else if (l >= mid) {
        return (r - l)*fr + (fl-fr)*(r - l)/2.0;
    } else {
        return (mid-l)*fl + (r-mid)*fr + (mid-l)*(1-fl)/2.0 + (r-mid)*(1-fr)/2.0;
    }
}
class TripleJump {
	public:
	vector <double> getProbabilities(int lower, int upper, int first, vector <int> opponents) {
        sort(opponents.begin(), opponents.end());
        reverse(opponents.begin(), opponents.end());
        vector<double> sol(opponents.size()+1, 0.0);
        lower *= 2;
        upper *= 2;
        upper += first;
        lower += first;
        if (lower == upper) {
            for (int i=0; i<(int)opponents.size(); ++i) {
                if (lower >= opponents[i]) {
                    sol[i] = 1.0;
                    return sol;
                }
            }
            sol.back() = 1.0;
            return sol;
        }
        double range = upper - lower;
        double area = range / 2.0;

        int left = max(lower, opponents[0]);
        int right = upper;
        if (right > left) {
            sol[0] = A(left, right, lower, upper)/area;
        }

        for (int i=0; i<(int)opponents.size()-1; ++i) {
            if (lower >= opponents[i]) {
                break;
            }
            if (upper <= opponents[i+1]) {
                continue;
            }
            left = max(lower, opponents[i+1]);
            right = min(upper, opponents[i]);

            sol[i+1] = A(left, right, lower, upper)/area;
        }

        sol.back() = 1.0 - accumulate(sol.begin(), sol.end(), 0.0);

        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <double> &Expected, const vector <double> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 2; int Arg2 = 1; int Arr3[] = {1,2,3,4}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arr4[] = {0.5, 0.5, 0.0, 0.0, 0.0 }; vector <double> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(0, Arg4, getProbabilities(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 7; int Arg2 = 5; int Arr3[] = {9,9,19,19,19}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arr4[] = {0.0, 0.0, 0.0, 1.0, 0.0, 0.0 }; vector <double> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(1, Arg4, getProbabilities(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 10; int Arg2 = 1; int Arr3[] = {5}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arr4[] = {0.9753086419753086, 0.024691358024691357 }; vector <double> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(2, Arg4, getProbabilities(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 1; int Arg1 = 10; int Arg2 = 5; int Arr3[] = {1,2,3,5,10,11,12,19}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arr4[] = {0.22222222222222227, 0.6234567901234567, 0.05555555555555558, 0.043209876543209846, 0.05555555555555558, 0.0, 0.0, 0.0, 0.0 }; vector <double> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(3, Arg4, getProbabilities(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TripleJump ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
