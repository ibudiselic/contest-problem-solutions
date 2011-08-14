#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class VariableSpeedLimit {
	public:
	double journeyTime(int L, vector <int> S) {
		double ret = 0.0;

        while (L > 0) {
            for (int i=0; i<(int)S.size(); ++i) {
                int x = S[i];
                if (L >= x) {
                    L -= x;
                    ret += 1;
                } else {
                    return ret + double(L)/S[i];
                }
            }
        }

        return ret;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 100; int Arr1[] = {50}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 2.0; verify_case(0, Arg2, journeyTime(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 100; int Arr1[] = {50,25}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 2.5; verify_case(1, Arg2, journeyTime(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1000; int Arr1[] = {50,40,30,40,50}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 24.0; verify_case(2, Arg2, journeyTime(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 2058; int Arr1[] = {80,43,57,23,28,45,60,75,73,80}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 37.4; verify_case(3, Arg2, journeyTime(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 17216; int Arr1[] = {26,30,62,55,51,56,58,4,60,23,31}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 415.03333333333336; verify_case(4, Arg2, journeyTime(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 9839; int Arr1[] = {45,90,13,4,81,50,81,10,64,86,69}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 182.8395061728395; verify_case(5, Arg2, journeyTime(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    VariableSpeedLimit ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
