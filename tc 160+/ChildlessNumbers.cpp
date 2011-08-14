#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int f(long long x) {
    for (int mul=1; mul<200; ++mul) {
        long long xx = x*mul;
        int sum = 0;
        long long y = xx;
        while (y > 0) {
            sum += y%10;
            y /= 10;
        }
        if (sum == mul) {
            return 0;
        }
    }
    return 1;
}
class ChildlessNumbers {
	public:
	int howMany(int A, int B) {
		int sol = 0;
        for (int i=A; i<=B; ++i) {
            sol += f(i);
        }
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 7; int Arg2 = 0; verify_case(0, Arg2, howMany(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 37; int Arg1 = 37; int Arg2 = 0; verify_case(1, Arg2, howMany(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 61; int Arg1 = 65; int Arg2 = 3; verify_case(2, Arg2, howMany(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 275; int Arg1 = 300; int Arg2 = 1; verify_case(3, Arg2, howMany(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    ChildlessNumbers ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
