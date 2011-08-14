#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class Towers {
	public:
	int attack(int myUnits, int hpT, int attackT, int numT) {
		int damaged = -1;
        int rounds = 0;
        while (myUnits>0 && numT>0) {
            ++rounds;
            int total = myUnits;
            if (damaged != -1) {
                if (total >= damaged) {
                    total -= damaged;
                    damaged = -1;
                    --numT;
                } else {
                    damaged -= total;
                    total = 0;
                }
            }

            if (total > 0) {
                numT -= total/hpT;
                if (total % hpT) {
                    damaged = hpT - total%hpT;
                } else {
                    damaged = -1;
                }
            }

            myUnits -= numT * attackT;
        }

        return (numT<=0 ? rounds : -1);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 13; int Arg1 = 2; int Arg2 = 3; int Arg3 = 8; int Arg4 = 2; verify_case(0, Arg4, attack(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 6; int Arg2 = 8; int Arg3 = 2; int Arg4 = 2; verify_case(1, Arg4, attack(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 6; int Arg2 = 9; int Arg3 = 2; int Arg4 = -1; verify_case(2, Arg4, attack(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1; int Arg3 = 1; int Arg4 = 1; verify_case(3, Arg4, attack(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 10000; int Arg1 = 10; int Arg2 = 2; int Arg3 = 2789; int Arg4 = 10; verify_case(4, Arg4, attack(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arg0 = 2; int Arg1 = 1; int Arg2 = 1; int Arg3 = 3; int Arg4 = 2; verify_case(5, Arg4, attack(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    Towers ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
