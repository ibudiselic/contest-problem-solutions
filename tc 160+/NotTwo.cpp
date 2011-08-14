#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int line(int b) {
    return b/4*2 + (b%4>0) + (b%4>1);
}
int calc(int a, int b) {
    int ret = 0;
    while (a > 0) {
        --a;
        ret += line(b);
        if (a > 0) {
            --a;
            ret += line(b);
        }
        if (a > 0) {
            --a;
            ret += line(b-2);
        }
        if (a > 0) {
            --a;
            ret += line(b-2);
        }
    }
    return ret;
}
class NotTwo {
	public:
	int maxStones(int width, int height) {
		return max(calc(width, height), calc(height, width));
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 4; verify_case(0, Arg2, maxStones(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 5; verify_case(1, Arg2, maxStones(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 8; int Arg1 = 5; int Arg2 = 20; verify_case(2, Arg2, maxStones(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    NotTwo ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
