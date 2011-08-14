#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int dp[51][51][251];
int upr;

int go(int myUnits, int barHp, int eUnits) {
    if (barHp<=0 && eUnits<=0) {
        return 0;
    }
    if (myUnits <= 0) {
        return 12345678;
    }
    int &ret = dp[myUnits][barHp][eUnits];
    if (ret != -1) {
        return ret;
    }

    ret = 12345678;
    for (int i=0; i<=myUnits && i<=barHp; ++i) {
        ret = min(ret, 1 + go(myUnits - max(0, eUnits-(myUnits-i)), barHp-i, max(0, eUnits-(myUnits-i)) + (i<barHp ? upr : 0)));
    }

    return ret;
}

class BarracksEasy {
	public:
	int attack(int myUnits, int barHp, int unitsPerRound) {
		upr = unitsPerRound;

        memset(dp, 0xff, sizeof dp);
        return (go(myUnits, barHp, 0) < 12345678 ? go(myUnits, barHp, 0) : -1);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arg1 = 11; int Arg2 = 15; int Arg3 = 4; verify_case(0, Arg3, attack(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 10; int Arg2 = 4; int Arg3 = -1; verify_case(1, Arg3, attack(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 10; int Arg2 = 1; int Arg3 = 9; verify_case(2, Arg3, attack(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 11; int Arg1 = 12; int Arg2 = 9; int Arg3 = 2; verify_case(3, Arg3, attack(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    BarracksEasy ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
