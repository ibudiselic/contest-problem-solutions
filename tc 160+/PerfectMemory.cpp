#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

double dp[1251][1251];
bool done[1251][1251];

double go(int not_seen, int seen_one) {
    double &ret = dp[not_seen][seen_one];
    if (done[not_seen][seen_one]) {
        return ret;
    }
    done[not_seen][seen_one] = 1;
    ret = 0.0;
    if (not_seen+seen_one > 0) {
        const int total = 2*not_seen + seen_one;
        if (not_seen > 0) {
            // not_seen + same not_seen
            ret += (go(not_seen-1, seen_one) + 1) * 2 * not_seen / total / (total - 1);
            // not_seen + seen_one (+2 because we take the seen_one pair in the next move)
            // seen_one+1-1 because we add one in this move and then remove the seen_one in the next move
            if (seen_one > 0) ret += (go(not_seen-1, seen_one+1-1) + 2) * 2 * not_seen / total * seen_one / (total - 1);
        }
        // not_seen + another not_seen
        if (not_seen > 1) ret += (go(not_seen-2, seen_one+2) + 1) * 2*not_seen/total * 2*(not_seen-1)/(total-1);
        // seen_one + the same seen_one from before (prob 100% thanks to perfect memory)
        if (seen_one > 0) ret += (go(not_seen, seen_one-1) + 1) * seen_one / total;
    }
    
    return ret;
}
class PerfectMemory {
	public:
	double getExpectation(int N, int M) {
        memset(done, 0, sizeof done);
        return go(N*M/2, 0);
    }






   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 2; double Arg2 = 1.0; verify_case(0, Arg2, getExpectation(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; double Arg2 = 2.6666666666666665; verify_case(1, Arg2, getExpectation(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 3; double Arg2 = 4.333333333333334; verify_case(2, Arg2, getExpectation(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 4; double Arg2 = 12.392984792984793; verify_case(3, Arg2, getExpectation(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    PerfectMemory ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
