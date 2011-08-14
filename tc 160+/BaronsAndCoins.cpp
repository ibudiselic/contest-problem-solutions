#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <utility>

using namespace std;

vector< pair<int, int> > C;
int dp[52][10001];
int go(int p, int k) {
    int &ret = dp[p][k];
    if (ret != -1) {
        return ret;
    }
    if (p == (int)C.size()) {
        return (ret = 0);
    }
    
    ret = 1;
    for (int i=p+1; i<(int)C.size(); ++i) {
        if (C[i].first > C[p].first) {
            int diffY = C[i].first - C[p].first;
            int diffX = C[i].second - C[p].second;
            int minDiffX = diffY*k + diffY*(diffY+1)/2;
            if (minDiffX > diffX) {
                continue;
            }
            
            ret = max(ret, 1 + go(i, k + diffY + (diffX-minDiffX+diffY-1)/diffY));
        }
    }
    
    return ret;
}
class BaronsAndCoins {
	public:
	int getMaximum(vector <int> x, vector <int> y) {
        C.clear();
        C.push_back(make_pair(0, 0));
        for (int i=0; i<(int)x.size(); ++i) {
            C.push_back(make_pair(y[i], x[i]));
        }
        sort(C.begin(), C.end());
        
        memset(dp, 0xff, sizeof dp);
        return go(0, 0) - 1;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {15, 5, 30}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4, 5, 6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(0, Arg2, getMaximum(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(1, Arg2, getMaximum(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1, 3, 6, 10, 15, 21}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 3, 4, 5, 6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(2, Arg2, getMaximum(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {5, 10, 15, 20, 25, 30, 35, 40, 45}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1, 1, 2, 2, 2, 3, 3, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(3, Arg2, getMaximum(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {1, 3, 6, 10, 22, 35, 50, 66}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 3, 1, 2, 3, 4, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(4, Arg2, getMaximum(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    BaronsAndCoins ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
