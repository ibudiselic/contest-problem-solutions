#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<int> I, R;
int n;
const int MASK = (1<<17)-1;
int dp[51][1<<17];
const int INF = 1234567890;
int go(int p, int mask) {
    int &ret = dp[p][mask];
    if (ret != -1) {
        return ret;
    }
    if (p == n) {
        return ret = 0;
    }
    int need = R[p];
    ret = 0;
    if (mask & (1<<8)) {
        ret = 1;
    }
    int val = 0;
    for (int i=0; i<17; ++i) {
        if (mask & (1<<i)) {
            val += I[p-i+8]/(1<<abs(i-8));
        }
    }
    need -= val;
    if (need > 0) {
        return ret = INF;
    }
    
    int add = go(p+1, (mask<<1)&MASK);
    if (p+9 < n) {
        add = min(add, go(p+1, ((mask<<1)&MASK)|1));
    }
    ret += add;
    return ret;
}
class Bribes {
	public:
	int minBribes(vector <int> influence, vector <int> resistance) {
		I = influence;
        R = resistance;
        n = I.size();
        memset(dp, 0xff, sizeof dp);
        int sol = INF;
        int lim = 1<<min(n, 9);
        for (int mask=0; mask<lim; ++mask) {
            int tmask = mask<<max(0, 9-n);
            sol = min(sol, go(0, tmask));
        }

        return sol<INF ? sol : -1;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 10, 3, 5, 3, 1 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 11, 2, 7, 3, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(0, Arg2, minBribes(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = { 15, 15, 15 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 13, 42, 13 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(1, Arg2, minBribes(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = { 10, 16, 4, 7, 1, 1, 13 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 10, 16, 4, 7, 1, 1, 13 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(2, Arg2, minBribes(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = { 479, 340, 398, 40, 477, 181, 422, 377, 60, 486, 15, 500, 307, 1, 2, 65, 411, 374, 446, 401 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 402, 87, 20, 76, 468, 493, 252, 98, 216, 58, 89, 500, 89, 26, 8, 125, 269, 116, 426, 81 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 7; verify_case(3, Arg2, minBribes(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = { 21, 196, 401, 157, 9, 497, 371, 84, 395, 495, 401, 190, 465, 359, 47, 441, 245, 487, 118, 405 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 127, 313, 376, 94, 66, 37, 237, 142, 315, 495, 257, 153, 437, 339, 483, 356, 16, 132, 231, 342 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 8; verify_case(4, Arg2, minBribes(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    Bribes ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
