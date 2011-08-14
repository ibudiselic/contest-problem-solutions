#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int factors[100001];
bool is_prime[100001];
class Underprimes {
	public:
	int howMany(int A, int B) {
		factors[2] = 1;
        is_prime[2] = 1;
        for (int i=3; i<=B; ++i) {
            factors[i] = 1;
            is_prime[i] = 1;
            for (int d=2; d*d<=i; ++d) {
                if (i%d == 0) {
                    factors[i] = factors[i/d] + 1;
                    is_prime[i] = 0;
                    break;
                }
            }
        }
        
        int sol = 0;
        for (int i=A; i<=B; ++i) {
            sol += is_prime[factors[i]];
        }
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 10; int Arg2 = 5; verify_case(0, Arg2, howMany(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 100; int Arg1 = 105; int Arg2 = 2; verify_case(1, Arg2, howMany(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 17; int Arg1 = 17; int Arg2 = 0; verify_case(2, Arg2, howMany(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 123; int Arg1 = 456; int Arg2 = 217; verify_case(3, Arg2, howMany(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    Underprimes ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
