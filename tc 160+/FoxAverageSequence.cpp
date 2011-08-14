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

int dp[41][1601][41][2];
vector<int> S;
const long long mod = 1000000007LL;
int go(int p, int sum, int last, bool dec) {
    int &ret = dp[p][sum][last][dec];
    if (ret != -1) {
        return ret;
    }
    if (p == (int)S.size()) {
        return (ret = 1);
    }
    
    if (S[p] != -1) {
        if (S[p]>sum/p || dec && S[p]<last) {
            return (ret = 0);
        } else {
            return go(p+1, sum+S[p], S[p], S[p]<last);
        }
    } else {
        long long val = 0;
        int lo = (dec ? last : 0);
        int hi = sum/p;
        for (int i=lo; i<=hi; ++i) {
            val += go(p+1, sum+i, i, (i<last));
        }
        
        ret = int(val%mod);
        return ret;
    }
}
class FoxAverageSequence {
	public:
	int theCount(vector <int> seq) {
		S = seq;
        memset(dp, 0xff, sizeof dp);
        if (S[0] != -1) {
            return go(1, S[0], S[0], 0);
        } else {
            long long sol = 0;
            for (int i=0; i<41; ++i) {
                sol += go(1, i, i, 0);
            }
            return int(sol%mod);
        }
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3, -1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, theCount(Arg0)); }
	void test_case_1() { int Arr0[] = {5, 3, -1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, theCount(Arg0)); }
	void test_case_2() { int Arr0[] = {-1, 0, 40}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, theCount(Arg0)); }
	void test_case_3() { int Arr0[] = {-1, 40, -1, -1, -1, 10, -1, -1, -1, 21, -1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 579347890; verify_case(3, Arg1, theCount(Arg0)); }
	void test_case_4() { int Arr0[] = {-1, 12, 25, 0, 18, -1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 58; verify_case(4, Arg1, theCount(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    FoxAverageSequence ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
