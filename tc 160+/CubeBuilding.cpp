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

const int mod = 1000000007;
int row_dp[26][26][26][51];
int dp[26][26][51];
long long C[51][51];
int N;
void add(int &a, int b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}
int row(int pos, int h, int a, int b) {
    int &ret = row_dp[pos][h][a][b];
    if (ret != -1) {
        return ret;
    }
    if (pos == N) {
        return ret = (a+b==0);
    }
    if (a+b == 0) {
        return ret = 1;
    }
    
    ret = 0;
    const int limb = min(h, b);
    for (int aa=0; aa<=a; ++aa) {
        for (int bb=0; bb<=limb; ++bb) {
            const int nh = max(h, aa + bb);
            const int up_a = nh - h;
            add(ret, row(pos+1, nh, a-aa, b-bb) * C[aa-up_a + bb][bb] % mod);
        }
    }
    return ret;
}
int go(int pos, int a, int b) {
    int &ret = dp[pos][a][b];
    if (ret != -1) {
        return ret;
    }
    if (pos == N) {
        return ret = (a+b==0);
    }
    
    ret = 0;
    for (int aa=0; aa<=a; ++aa) {
        for (int bb=0; bb<=b; ++bb) {
            add(ret, (long long)row(0, 0, aa, bb)*go(pos+1, a-aa, b-bb)%mod);
        }
    }
    
    return ret;
}
class CubeBuilding {
	public:
	int getCount(int R, int G, int B, int N) {
		memset(dp, 0xff, sizeof dp);
        memset(row_dp, 0xff, sizeof row_dp);
        C[0][0] = 1;
        for (int i=1; i<51; ++i) {
            C[i][0] = C[i][i] = 1;
            for (int j=1; j<i; ++j) {
                C[i][j] = C[i-1][j-1] + C[i-1][j];
                if (C[i][j] >= mod) {
                    C[i][j] -= mod;
                }
            }
        }
        ::N = N;
        long long sol = go(0, R, G+B)*C[G+B][G] % mod;
        sol += go(0, G, R+B)*C[R+B][R] % mod;
        sol += go(0, B, R+G)*C[R+G][R] % mod;
        return int(sol%mod);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 0; int Arg2 = 1; int Arg3 = 2; int Arg4 = 4; verify_case(0, Arg4, getCount(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 2; int Arg3 = 1; int Arg4 = 0; verify_case(1, Arg4, getCount(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 1; int Arg3 = 3; int Arg4 = 162; verify_case(2, Arg4, getCount(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 10; int Arg3 = 12; int Arg4 = 372185933; verify_case(3, Arg4, getCount(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    CubeBuilding ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
