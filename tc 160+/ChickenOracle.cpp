#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

const int EGG = 1;
const int CHICKEN = 2;
class ChickenOracle {
	public:
	string theTruth(int n, int eggCount, int lieCount, int liarCount) {
		int state = 0;
        for (int i=0; i+liarCount<=n; ++i) {
            int t;
            if (i+liarCount <= lieCount) {
                t = n-lieCount+liarCount;
            } else if (i < lieCount) {
                t = n-lieCount+(lieCount-i)-(i+liarCount-lieCount);
            } else {
                t = n-lieCount-liarCount;
            }
            if (t == eggCount) {
                state |= EGG;
            }
            if (t == n-eggCount) {
                state |= CHICKEN;
            }
        }
        
        switch (state) {
            case 0: return "The oracle is a lie"; break;
            case EGG: return "The egg"; break;
            case CHICKEN: return "The chicken"; break;
            case EGG|CHICKEN: return "Ambiguous"; break;
            default: assert(0);
        }
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arg1 = 10; int Arg2 = 0; int Arg3 = 0; string Arg4 = "The egg"; verify_case(0, Arg4, theTruth(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 60; int Arg1 = 40; int Arg2 = 0; int Arg3 = 30; string Arg4 = "The oracle is a lie"; verify_case(1, Arg4, theTruth(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 60; int Arg1 = 20; int Arg2 = 5; int Arg3 = 25; string Arg4 = "The chicken"; verify_case(2, Arg4, theTruth(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 1000; int Arg1 = 500; int Arg2 = 250; int Arg3 = 250; string Arg4 = "Ambiguous"; verify_case(3, Arg4, theTruth(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    ChickenOracle ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
