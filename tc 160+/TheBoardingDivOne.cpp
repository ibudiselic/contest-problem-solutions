#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<int> P;
int T;
int n;
long long dp[1<<18][19];
long long go(int y, int mask, int upper_bound) {
    long long &ret = dp[mask][upper_bound];
    if (ret != -1) {
        return ret;
    }
    if (mask == (1<<n)-1) {
        return 1;
    }
    ret = 0;
    bool can_pick_over_ub = true; // only the first one though... (he will only block once on the smallest number to his right)
    for (int w=n-1; w>=0; --w) {
        if (mask & (1<<w)) {
            continue;
        }
        if (P[y]==-1 || P[y]==w+1) {
            int time_to_sit = (n+w-y) + 74 + (w>upper_bound)*74;
            if (time_to_sit<=T && (w<upper_bound || can_pick_over_ub)) {
                ret += go(y-1, mask | (1<<w), min(w, max(0, upper_bound-1)));
            }
        }
        can_pick_over_ub = false;
    }
    return ret;
}
class TheBoardingDivOne {
	public:
	long long find(vector <int> pattern, int boardingTime) {
		P = pattern;
        T = boardingTime;
        n = P.size();
        memset(dp, 0xff, sizeof dp);
        return go(n-1, 0, n);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {-1, -1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; long long Arg2 = 1LL; verify_case(0, Arg2, find(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {-1, 2, -1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 222; long long Arg2 = 1LL; verify_case(1, Arg2, find(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {2, 1, 3, 5, 4, 6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 155; long long Arg2 = 1LL; verify_case(2, Arg2, find(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {-1, -1, -1, -1, -1, -1, -1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 198; long long Arg2 = 233LL; verify_case(3, Arg2, find(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TheBoardingDivOne ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
