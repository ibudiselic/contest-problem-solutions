#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class CarrotJumping {
	public:
	int theJump(int init) {
		long long mul = 1;
        long long mod = 1000000007;
        for (int i=0; i<300001; ++i) {
            mul = mul*2%mod;
            long long x = mul*init + mul - 1;
            if (x%mod==0 && i>0) {
                int t = i + 1;
                int sol;
                if (t%3 == 0) {
                    sol = t/3;
                } else {
                    sol = t/3 + 1;
                }
                return sol<=100000 ? sol : -1;
            }
        }
        return -1;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 125000000; int Arg1 = 1; verify_case(0, Arg1, theJump(Arg0)); }
	void test_case_1() { int Arg0 = 281250001; int Arg1 = 2; verify_case(1, Arg1, theJump(Arg0)); }
	void test_case_2() { int Arg0 = 18426114; int Arg1 = 58; verify_case(2, Arg1, theJump(Arg0)); }
	void test_case_3() { int Arg0 = 4530664; int Arg1 = 478; verify_case(3, Arg1, theJump(Arg0)); }
	void test_case_4() { int Arg0 = 705616876; int Arg1 = 100000; verify_case(4, Arg1, theJump(Arg0)); }
	void test_case_5() { int Arg0 = 852808441; int Arg1 = -1; verify_case(5, Arg1, theJump(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    CarrotJumping ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
