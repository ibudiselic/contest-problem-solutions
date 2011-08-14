#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

/*double dp[2][100001]; 
int my_abs(int x) {
    return x<0 ? -x : x;
}*/

double disjoint(int l1, int h1, int l2, int h2) {
    assert(l1 <= h1);
    assert(l2 <= h2);
    assert(h1 < l2);
    const double cnt1 = h1-l1+1.0;
    const double cnt2 = h2-l2+1.0;
    return cnt1*cnt2/2.0*(l2+h2-l1-h1);
}
double same_set(int l, int h) {
    assert(l <= h);
    double n = h-l+1.0;
    return n*(n+1)*(2*n+1)/6.0 - n*(n+1)/2.0;
}
// sum of |a-b| for a in [l1, h1] and b in [l2, h2]
double calc(int l1, int h1, int l2, int h2) {
    if (l1 > l2) {
        swap(l1, l2);
        swap(h1, h2);
    }
    double ret = 0.0;
    if (l1 < l2) { // i.e. if they are not equal
        ret += disjoint(l1, min(h1, l2-1), l2, h2);
    }
    if (l2 <= h1) { // i.e. if there is overlap
        ret += same_set(l2, min(h1, h2));
        if (h1 < h2) { // overlapping part with the "right" remainder
            ret += disjoint(l2, h1, h1+1, h2);
        } else if (h1 > h2) {
            ret += disjoint(l2, h2, h2+1, h1);
        }
    }
    return ret;
}
class AlternatingLane {
	public:
	double expectedBeauty(vector <int> low, vector <int> high) {
        /*int n = low.size();
        memset(dp, 0, sizeof dp);
        double ways = 1.0;
        double sum = 0.0;
        for (int i=0; i<n-1; ++i) {
            for (int h=low[i+1]; h<=high[i+1]; ++h) {
                dp[i&1][h] = 0;
                if (h < low[i]) {
                    double w = high[i] - low[i] + 1.0;
                    dp[i&1][h] = sum + ways*w*((low[i]-h) + (w-1)/2);
                } else if (h <= high[i]) {
                    double lt = h - low[i];
                    double gte = high[i] - h + 1.0;
                    dp[i&1][h] = sum + ways*(lt*(lt+1)/2 + gte*(gte-1)/2);
                } else {
                    double w = high[i] - low[i] + 1.0;
                    dp[i&1][h] = sum + ways*w*((h-high[i]) + (w-1)/2);
                }
            }
            ways *= high[i]-low[i]+1.0;
            sum = 0.0;
            for (int j=low[i+1]; j<=high[i+1]; ++j) {
                sum += dp[i&1][j];
            }
        }
        
        double sol = 0.0;
        for (int h=low.back(); h<=high.back(); ++h) {
            sol += dp[n&1][h];
        }
        for (int i=0; i<n; ++i) {
            sol /= high[i]-low[i]+1.0;
        }
        return sol;*/
        
        // or, using linearity of expectation
        int n = low.size();
        double sol = 0.0;
        for (int i=0; i<n-1; ++i) {
            sol += calc(low[i], high[i], low[i+1], high[i+1])/(high[i]-low[i]+1.0)/(high[i+1]-low[i+1]+1.0);
        }
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.0; verify_case(0, Arg2, expectedBeauty(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 2, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 1.0; verify_case(1, Arg2, expectedBeauty(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1, 3, 5, 7, 9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 4, 6, 8, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 8.0; verify_case(2, Arg2, expectedBeauty(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {4, 3, 3, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10, 7, 7, 7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 6.171428571428572; verify_case(3, Arg2, expectedBeauty(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    AlternatingLane ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
