#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <utility>

using namespace std;

vector<int> L, S;
int n;
int can_watch(int i, int cur) {
    cur -= S[i];
    if (cur < 0) {
        return -1;
    }
    cur -= L[i]-S[i]-47;
    if (cur < 0) {
        return -1;
    } else {
        return cur;
    }
}
int bc[1<<20];
int final;
int dp[1<<20];
int next[1<<20];
int go(int mask, int val) {
    int &ret = dp[mask];
    if (ret != -1) {
        return ret;
    }
    next[mask] = -1;
    ret = bc[mask];
    for (int i=0; i<n; ++i) {
        if (mask & (1<<i)) {
            continue;
        }
        const int after = can_watch(i, val);
        if (after == -1) {
            continue;
        }
        const int t = go(mask | (1<<i), after);
        if (t > ret) {
            ret = t;
            next[mask] = i;
        }
    }
    return ret;
}
class TheMoviesLevelTwoDivOne {
	public:
	vector <int> find(vector <int> length, vector <int> scary) {
		L = length;
        S = scary;
        n = L.size();
        bc[0] = 0;
        for (int i=1; i<(1<<n); ++i) {
            bc[i] = bc[i>>1] + (i&1);
        }
        
        vector<int> sol;
        memset(dp, 0xff, sizeof dp);
        go(0, 74);
        int used = 0;
        while (next[used] != -1) {
            const int t = next[used];
            sol.push_back(t);
            used |= (1<<t);
        }
        for (int i=0; i<n; ++i) {
            if (!(used & (1<<i))) {
                sol.push_back(i);
            }
        }
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {100, 50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, find(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {100, 50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 49}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 0 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, find(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {100, 100, 100, 100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {77, 76, 75, 74}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3, 0, 1, 2 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, find(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {99}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, find(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TheMoviesLevelTwoDivOne ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
