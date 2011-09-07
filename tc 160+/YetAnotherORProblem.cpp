#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<long long> R;
const int mod = 1000000009;
int dp[63][1<<10];
int go(int bit, int any) {
    if (bit < 0) {
        return 1;
    }
    int &ret = dp[bit][any];
    if (ret != -1) {
        return ret;
    }
    int nany = any;
    for (int i=0; i<(int)R.size(); ++i) {
        if ((R[i]>>bit)&1) {
            nany |= 1<<i;
        }
    }
    ret = go(bit-1, nany);
    for (int i=0; i<(int)R.size(); ++i) {
        if ((1LL<<bit)>R[i] || !(any&(1<<i)) && ((R[i]>>bit)&1)==0) {
            continue;
        }
        int nnany = nany;
        if (!(any&(1<<i)) && (nnany&(1<<i))) {
            nnany ^= 1<<i;
        }
        ret += go(bit-1, nnany);
        if (ret >= mod) {
            ret -= mod;
        }
    }
    return ret;
}
class YetAnotherORProblem {
	public:
	int countSequences(vector<long long> R) {
		::R = R;
        memset(dp, 0xff, sizeof dp);
        return go(62, 0);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long Arr0[] = {3,5}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 15; verify_case(0, Arg1, countSequences(Arg0)); }
	void test_case_1() { long Arr0[] = {3,3,3}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 16; verify_case(1, Arg1, countSequences(Arg0)); }
	void test_case_2() { long Arr0[] = {1,128}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 194; verify_case(2, Arg1, countSequences(Arg0)); }
	void test_case_3() { long Arr0[] = {26,74,25,30}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8409; verify_case(3, Arg1, countSequences(Arg0)); }
	void test_case_4() { long Arr0[] = {1000000000,1000000000}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 420352509; verify_case(4, Arg1, countSequences(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    YetAnotherORProblem ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
