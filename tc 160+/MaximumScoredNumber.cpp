#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool is_sqr[10001];
class MaximumScoredNumber {
	public:
	int getNumber(int l, int u) {
        int sol = -1;
        int val = -1;

        for (int i=0; i*i<=10001; ++i) {
            is_sqr[i*i] = 1;
        }

        for (int i=l; i<=u; ++i) {
            int t = 0;
            for (int d=0; d*d*2<=i; ++d) {
                t += is_sqr[i-d*d];
            }
            if (t >= val) {
                val = t;
                sol = i;
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
	void test_case_0() { int Arg0 = 0; int Arg1 = 2; int Arg2 = 2; verify_case(0, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 0; int Arg1 = 30; int Arg2 = 25; verify_case(1, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 0; verify_case(2, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 5; int Arg1 = 99; int Arg2 = 85; verify_case(3, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 0; int Arg1 = 10000; int Arg2 = 9425; verify_case(4, Arg2, getNumber(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    MaximumScoredNumber ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
