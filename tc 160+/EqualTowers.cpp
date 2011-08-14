#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

const int MAXVAL = 500001;
int dp[2][MAXVAL];

class EqualTowers {
	public:
	int height(vector <int> B) {
		memset(dp, 0xff, sizeof dp);
        dp[1][0] = 0;
        for (int i=0; i<(int)B.size(); ++i) {
            for (int h=0; h<MAXVAL; ++h) {
                int &ret = dp[i&1][h];
                ret = -1;
                int t = dp[(i+1)&1][h];
                if (t != -1) {
                    ret = t;
                }
                if (h + B[i] < MAXVAL) {
                    t = dp[(i+1)&1][h+B[i]];
                    if (t!=-1 && (ret==-1 || t>ret)) {
                        ret = t;
                    }
                }
                int x = h - B[i];
                int pre = B[i];
                if (x < 0) {
                    pre = h;
                    x = -x;
                }
                t = dp[(i+1)&1][x];
                if (t!=-1 && (ret==-1 || pre+t>ret)) {
                    ret = pre + t;
                }
            }
        }
        
        int t = ((int)B.size()+1) & 1;
        return dp[t][0] ? dp[t][0] : -1;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 2, 3, 5 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(0, Arg1, height(Arg0)); }
	void test_case_1() { int Arr0[] = { 10, 9, 2 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(1, Arg1, height(Arg0)); }
	void test_case_2() { int Arr0[] = { 11, 11 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 11; verify_case(2, Arg1, height(Arg0)); }
	void test_case_3() { int Arr0[] = { 14, 3, 20, 15, 15, 14, 24, 23, 15 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 64; verify_case(3, Arg1, height(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    EqualTowers ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
