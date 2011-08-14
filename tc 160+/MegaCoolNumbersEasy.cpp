#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool is(int x) {
    if (x < 10) {
        return true;
    }
    
    int diff = 42;
    int last = 42;
    while (x > 0) {
        int d = x%10;
        x /= 10;
        if (last == 42) {
            last = d;
        } else if (diff == 42) {
            diff = d - last;
            last = d;
        } else {
            if (d-last != diff) {
                return false;
            }
            last = d;
        }
    }
    
    return true;
}
    
class MegaCoolNumbersEasy {
	public:
	int count(int N) {
		int sol = 0;
        for (int i=1; i<=N; ++i) {
            sol += is(i);
        }
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { int Arg0 = 110; int Arg1 = 99; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { int Arg0 = 500; int Arg1 = 119; verify_case(2, Arg1, count(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    MegaCoolNumbersEasy ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
