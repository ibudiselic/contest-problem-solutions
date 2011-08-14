#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class DigitHoles {
	public:
	int numHoles(int number) {
		int sol = 0;
        while (number > 0) {
            int d = number%10;
            number /= 10;
            switch (d) {
                case 1: case 2: case 3: case 5: case 7: break;
                case 0: case 4: case 6: case 9: sol += 1; break;
                case 8: sol += 2; break;
            }
        }
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 42; int Arg1 = 1; verify_case(0, Arg1, numHoles(Arg0)); }
	void test_case_1() { int Arg0 = 669; int Arg1 = 3; verify_case(1, Arg1, numHoles(Arg0)); }
	void test_case_2() { int Arg0 = 688; int Arg1 = 5; verify_case(2, Arg1, numHoles(Arg0)); }
	void test_case_3() { int Arg0 = 123; int Arg1 = 0; verify_case(3, Arg1, numHoles(Arg0)); }
	void test_case_4() { int Arg0 = 456; int Arg1 = 2; verify_case(4, Arg1, numHoles(Arg0)); }
	void test_case_5() { int Arg0 = 789; int Arg1 = 3; verify_case(5, Arg1, numHoles(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    DigitHoles ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
