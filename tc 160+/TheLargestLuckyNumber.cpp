#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool test(int x) {
    while (x > 0) {
        int d = x%10;
        if (d!=4 && d!=7) {
            return false;
        }
        x /= 10;
    }

    return true;
}
class TheLargestLuckyNumber {
	public:
	int find(int n) {
		while (1) {
            if (test(n)) {
                return n;
            }
            --n;
        }

        return -1;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 100; int Arg1 = 77; verify_case(0, Arg1, find(Arg0)); }
	void test_case_1() { int Arg0 = 75; int Arg1 = 74; verify_case(1, Arg1, find(Arg0)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 4; verify_case(2, Arg1, find(Arg0)); }
	void test_case_3() { int Arg0 = 474747; int Arg1 = 474747; verify_case(3, Arg1, find(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TheLargestLuckyNumber ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
