#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class ColorfulBoxesAndBalls {
	public:
	int getMaximum(int numRed, int numBlue, int onlyRed, int onlyBlue, int bothColors) {
        if (numRed > numBlue) {
            return getMaximum(numBlue, numRed, onlyBlue, onlyRed, bothColors);
        } else if (numRed == numBlue) {
            if (onlyRed + onlyBlue >= 2*bothColors) {
                return onlyRed*numRed + onlyBlue*numBlue;
            } else {
                return bothColors*(numRed + numBlue);
            }
        } else {
            return getMaximum(numRed, numRed, onlyRed, onlyBlue, bothColors) + onlyBlue*(numBlue-numRed);
        }
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 3; int Arg2 = 100; int Arg3 = 400; int Arg4 = 200; int Arg5 = 1400; verify_case(0, Arg5, getMaximum(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 3; int Arg2 = 100; int Arg3 = 400; int Arg4 = 300; int Arg5 = 1600; verify_case(1, Arg5, getMaximum(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 5; int Arg2 = 464; int Arg3 = 464; int Arg4 = 464; int Arg5 = 4640; verify_case(2, Arg5, getMaximum(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 1; int Arg1 = 4; int Arg2 = 20; int Arg3 = -30; int Arg4 = -10; int Arg5 = -100; verify_case(3, Arg5, getMaximum(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 9; int Arg1 = 1; int Arg2 = -1; int Arg3 = -10; int Arg4 = 4; int Arg5 = 0; verify_case(4, Arg5, getMaximum(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    ColorfulBoxesAndBalls ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
