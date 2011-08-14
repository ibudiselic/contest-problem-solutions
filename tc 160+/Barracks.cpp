#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

const int LIM = 3000;
int dp[LIM][LIM];
int upr;
const int INF = 1234567890;

int go(int myUnits, int eUnits) {
    if (eUnits <= 0) {
        return 0;
    }
    if (myUnits <= 0) {
        return INF;
    }
    if (myUnits<LIM && eUnits<LIM && dp[myUnits][eUnits]!=-1) {
        return dp[myUnits][eUnits];
    }
    int ret = 1 + go(myUnits-(eUnits-myUnits), eUnits-myUnits);
    if (myUnits<LIM && eUnits<LIM) {
        dp[myUnits][eUnits] = ret;
    }

    return ret;
}

class Barracks {
	public:
	int attack(int myUnits, int barHp, int unitsPerRound) {
		upr = unitsPerRound;
        if (myUnits >= barHp) {
            return 1;
        }
        barHp -= myUnits;
        if (myUnits >= barHp + upr) {
            return 2;
        }

        int sol = INF;
        int eUnits = upr;
        memset(dp, 0xff, sizeof dp);
        for (int r=2; r<=10100; ++r) {
            if (myUnits<=0 || barHp<=0 && eUnits<=0) {
                break;
            }
            if (myUnits >= barHp) {
                int t = max(0, eUnits - (myUnits-barHp));
                sol = min(sol, r + go(myUnits - t, t));
            }
            int t = min(myUnits, eUnits);
            eUnits -= t;
            barHp -= (myUnits-t);
            myUnits -= eUnits;
            eUnits += (barHp>0 ? upr : 0);
        }

        return sol<INF ? sol : -1;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arg1 = 11; int Arg2 = 15; int Arg3 = 4; verify_case(0, Arg3, attack(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 2; int Arg2 = 1; int Arg3 = -1; verify_case(1, Arg3, attack(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1; int Arg3 = 1; verify_case(2, Arg3, attack(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 25; int Arg1 = 200; int Arg2 = 10; int Arg3 = 13; verify_case(3, Arg3, attack(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    Barracks ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
