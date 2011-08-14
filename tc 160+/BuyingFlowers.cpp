#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

const int inf = 1234567890;
int my_abs(int x) {
    return x<0 ? -x : x;
}
int get_d(int x) {
    int ret = 1;
    for (int d=2; d*d<=x; ++d) {
        if (x%d == 0) {
            ret = d;
        }
    }
    return ret;
}
class BuyingFlowers {
	public:
	int buy(vector <int> roses, vector <int> lilies) {
	    int n = roses.size();
        int sol = inf;
        for (int i=1; i<(1<<n); ++i) {
            int r = 0;
            int l = 0;
            for (int j=0; j<n; ++j) {
                if (i & (1<<j)) {
                    r += roses[j];
                    l += lilies[j];
                }
            }
            if (my_abs(l-r) > 1) {
                continue;
            }
            int t = r + l;
            int d = get_d(t);
            sol = min(sol, t/d - d);
        }
        
        return sol==inf ? -1 : sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(0, Arg2, buy(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {2, 7, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3, 4, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(1, Arg2, buy(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {4, 5, 2, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {6, 10, 5, 9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(2, Arg2, buy(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1, 208, 19, 0, 3, 234, 1, 106, 99, 17}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {58, 30, 3, 5, 0, 997, 9, 615, 77, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 36; verify_case(3, Arg2, buy(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    BuyingFlowers ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
