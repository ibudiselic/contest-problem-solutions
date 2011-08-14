#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<int> S, W, P;
int n;

int dp[1001][1001];
int go(int str, int wis) {
    if (str>1000 || wis>1000) {
        return 0;
    }
    int &ret = dp[str][wis];
    if (ret != -1) {
        return ret;
    }
    
    int pts = 0;
    int done = 0;
    for (int i=0; i<n; ++i) {
        if (str>=S[i] || wis>=W[i]) {
            pts += P[i];
            ++done;
        }
    }
    
    pts -= str+wis - 2;
    assert(pts >= 0);
    ret = done;
    if (pts > 0) {
        ret = max(ret, go(str+1, wis));
        ret = max(ret, go(str, wis+1));
    }
    
    return ret;
}
class StrengthOrIntellect {
	public:
	int numberOfMissions(vector <int> strength, vector <int> intellect, vector <int> points) {
		S = strength;
        W = intellect;
        P = points;
        n = S.size();
        
        memset(dp, 0xff, sizeof dp);
        return go(1, 1);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(0, Arg3, numberOfMissions(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(1, Arg3, numberOfMissions(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {1, 3, 1, 10, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1, 3, 20, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2, 1, 1, 5, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 4; verify_case(2, Arg3, numberOfMissions(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {1, 2, 100, 5, 100, 10, 100, 17, 100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 100, 3, 100, 7, 100, 13, 100, 21}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 9; verify_case(3, Arg3, numberOfMissions(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {1, 10, 1, 2, 16, 12, 13, 19, 12, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 5, 1, 8, 3, 5, 3, 16, 19, 20}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 1, 1, 2, 1, 1, 2, 3, 5, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 7; verify_case(4, Arg3, numberOfMissions(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    StrengthOrIntellect ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
