#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool is_prime(int x) {
    if (x < 2) {
        return false;
    }
    if (x == 2) {
        return true;
    }
    if (x%2 == 0) {
        return false;
    }
    for (int d=3; d*d<=x; d+=2) {
        if (x%d == 0) {
            return false;
        }
    }
    return true;
}
class PrimeContainers {
	public:
	int containerSize(int N) {
		int d = 1;
        int sol = 0;
        while (d < N) {
            sol += is_prime(N/d);
            d *= 2;
        }
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arg1 = 2; verify_case(0, Arg1, containerSize(Arg0)); }
	void test_case_1() { int Arg0 = 42; int Arg1 = 2; verify_case(1, Arg1, containerSize(Arg0)); }
	void test_case_2() { int Arg0 = 47; int Arg1 = 5; verify_case(2, Arg1, containerSize(Arg0)); }
	void test_case_3() { int Arg0 = 959; int Arg1 = 6; verify_case(3, Arg1, containerSize(Arg0)); }
	void test_case_4() { int Arg0 = 421337; int Arg1 = 2; verify_case(4, Arg1, containerSize(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    PrimeContainers ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
