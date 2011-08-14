#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<int> C;
int dp[51][501];
int calc_cost(int n);
int calc_cost(int p, int n) {
    int &ret = dp[p][n];
    if (ret != -1) {
        return ret;
    }
    if (p == (int)C.size()) {
        return (ret = (n==0 ? 0 : 500001));
    }
    
    ret = calc_cost(p+1, n);
    int lim = n / ((int)C.size()-p); // at most that fraction will start with the most expensive char
    for (int i=1; i<=lim; ++i) {
        ret = min(ret, calc_cost(p+1, n-i) + i*C[p] + calc_cost(i));
    }
    
    return ret;
}
int calc_cost(int n) {
    return (n<=1 ? 0 : calc_cost(0, n));
}
class PrefixFreeCode {
	public:
	int minCost(int N, vector <int> characterCosts) {
        C = characterCosts;
        sort(C.begin(), C.end());
        reverse(C.begin(), C.end());
        
        memset(dp, 0xff, sizeof dp);
        return calc_cost(N);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arr1[] = {1,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 11; verify_case(0, Arg2, minCost(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arr1[] = {1,3,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 9; verify_case(1, Arg2, minCost(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 500; int Arr1[] = { 2, 4, 6, 8,10,12,14,16,18,20,
 22,24,26,28,30,32,34,36,38,40,
 42,44,46,48,50,52,54,56,58,60,
 62,64,66,68,70,72,74,76,78,80,
 82,84,86,88,90,92,94,96,98,100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 9464; verify_case(2, Arg2, minCost(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 500; int Arr1[] = {1,2,3,4,5,6,7,8,9,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4732; verify_case(3, Arg2, minCost(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    PrefixFreeCode ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
