#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class FingerCounting {
	public:
	int maxNumber(int a, int b) {
        int f = 1;
        int sol = 0;
        int dir = +1;
        while (1) {
            if (f == a) {
                if (b == 0) {
                    return sol;
                }
                --b;
            }
            ++sol;
            if (f==5 && dir==1) {
                dir = -1;
            } else if (f==1 && dir==-1) {
                dir = 1;
            }
            f += dir;
        }

        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 3; int Arg2 = 15; verify_case(0, Arg2, maxNumber(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 0; int Arg2 = 0; verify_case(1, Arg2, maxNumber(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 0; int Arg2 = 4; verify_case(2, Arg2, maxNumber(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 2; int Arg1 = 48; int Arg2 = 193; verify_case(3, Arg2, maxNumber(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 5; int Arg1 = 973; int Arg2 = 7788; verify_case(4, Arg2, maxNumber(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 3; int Arg1 = 99999; int Arg2 = 399998; verify_case(5, Arg2, maxNumber(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    FingerCounting ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
