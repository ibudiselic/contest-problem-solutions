#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class EggCartons {
	public:
	int minCartons(int n) {
	    int sol = 1234567;
        for (int i=0; i<1000; ++i) {
            for (int j=0; j<1000; ++j) {
                if (i*8 + j*6 == n) {
                    sol = min(sol, i+j);
                }
            }
        }
        return sol==1234567 ? -1 : sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 20; int Arg1 = 3; verify_case(0, Arg1, minCartons(Arg0)); }
	void test_case_1() { int Arg0 = 24; int Arg1 = 3; verify_case(1, Arg1, minCartons(Arg0)); }
	void test_case_2() { int Arg0 = 15; int Arg1 = -1; verify_case(2, Arg1, minCartons(Arg0)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = -1; verify_case(3, Arg1, minCartons(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    EggCartons ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
