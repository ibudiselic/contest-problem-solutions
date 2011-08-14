#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int max_rounds;
int U;
int get_rounds(int soliders, int hpT, int numT, int attackT) {
    int healthT = hpT * numT;
    int rounds = 0;
    cerr << soliders << ' ' << healthT << '\n';
    while (soliders>0 && healthT>0) {
        healthT -= soliders;
        if (healthT > 0) {
            soliders -= (healthT+hpT-1)/hpT * attackT;
        }
        ++rounds;
    }

    return (soliders<=0 ? 2*U + 1 : rounds);
}
int min_soliders(int rounds, int hpT, int numT, int attackT) {
    if (get_rounds(U-1, hpT, numT, attackT) > rounds) {
        return U;
    }
    int lo = 1;
    int hi = U - 1;
    while (lo < hi) {
        int m = lo + (hi-lo)/2;
        if (get_rounds(m, hpT, numT, attackT) <= rounds) {
            hi = m;
        } else {
            lo = m + 1;
        }
    }
    
    return lo;
}
bool can_do(int rounds, int hpT, int attackT, int numWodT, int numStoT) {
    int W = min_soliders(rounds, hpT, numWodT, attackT);
    
    return (W<U && get_rounds(U-W, hpT, numStoT, attackT)<=rounds);
}

class EnemyTowers {
	public:
	int attack(int myUnits, int hpT, int attackT, int numWodT, int numStoT) {
        U = myUnits;
        if (U == 1) {
            return -1;
        }

		int lo = 1;
        int hi = 2;
        while (!can_do(hi, hpT, attackT, numWodT, numStoT)) {
            lo = hi;
            if (hi > myUnits) {
                return -1;
            }
            hi *= 2;
        }
        
        while (lo < hi) {
            int m = lo + (hi-lo)/2;
            if (can_do(m, hpT, attackT, numWodT, numStoT)) {
                hi = m;
            } else {
                lo = m + 1;
            }
        }
        
        return lo;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 7; int Arg1 = 2; int Arg2 = 1; int Arg3 = 2; int Arg4 = 3; int Arg5 = 2; verify_case(0, Arg5, attack(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 120; int Arg1 = 10; int Arg2 = 40000; int Arg3 = 6; int Arg4 = 6; int Arg5 = 1; verify_case(1, Arg5, attack(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 119; int Arg1 = 10; int Arg2 = 40000; int Arg3 = 6; int Arg4 = 6; int Arg5 = -1; verify_case(2, Arg5, attack(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 200; int Arg1 = 50; int Arg2 = 3; int Arg3 = 10; int Arg4 = 5; int Arg5 = 6; verify_case(3, Arg5, attack(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    EnemyTowers ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
