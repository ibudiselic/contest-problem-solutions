#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int f(int x) {
    int ret = 0;
    while (x > 0) {
        ret += x % 10;
        x /= 10;
    }
    return ret;
}
class MinimalDifference {
	public:
	int findNumber(int A, int B, int C) {
		int sold = 123245678;
        int sol = -1;
        C = f(C);
        for (int i=A; i<=B; ++i) {
            int x = f(i);
            if (abs(x-C) < sold) {
                sold = abs(x-C);
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
	void test_case_0() { int Arg0 = 1; int Arg1 = 9; int Arg2 = 10; int Arg3 = 1; verify_case(0, Arg3, findNumber(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 11; int Arg1 = 20; int Arg2 = 20; int Arg3 = 11; verify_case(1, Arg3, findNumber(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 999; int Arg3 = 1; verify_case(2, Arg3, findNumber(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 100; int Arg1 = 1000; int Arg2 = 99; int Arg3 = 189; verify_case(3, Arg3, findNumber(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 1987; int Arg1 = 9123; int Arg2 = 1; int Arg3 = 2000; verify_case(4, Arg3, findNumber(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    MinimalDifference ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
