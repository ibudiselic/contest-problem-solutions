#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<string> G;
int m, n;
int K;

int dp[11][1<<10][11];
int go(int a, int mask, int k) {
    int &ret = dp[a][mask][k];
    if (ret != -1) {
        return ret;
    }

    if (a == m) {
        return (ret = (k==0));
    } else {
        ret = go(a+1, mask, k);
        if (k > 0) {
            for (int i=0; i<n; ++i) {
                if (G[a][i]=='Y' && !(mask & (1<<i))) {
                    ret += go(a+1, mask | (1<<i), k-1);
                }
            }
        }

        return ret;
    }
}
    
class DancingCouples {
	public:
	int countPairs(vector <string> canDance, int K) {
        ::K = K;
        G = canDance;
        m = canDance.size();
        n = canDance[0].size();

        memset(dp, 0xff, sizeof dp);
        return go(0, 0, K);
	}








   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"YYYY", 
 "YYYY",
 "YYYY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 24; verify_case(0, Arg2, countPairs(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"YYNN", 
 "NYYN", 
 "NNYY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 4; verify_case(1, Arg2, countPairs(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"YY", 
 "YY", 
 "YY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 0; verify_case(2, Arg2, countPairs(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"YYNNNN",
 "NYYNNN",
 "NNYYNN",
 "NNNYYN",
 "NNNNYY",
 "YNNNNY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 112; verify_case(3, Arg2, countPairs(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    DancingCouples ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
