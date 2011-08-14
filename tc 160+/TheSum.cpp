#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

string to_str(int x) {
    ostringstream os;
    os << x;
    return os.str();
}
string S[3];
int tot;
int I, D, R;
const int inf = 1234567890;
int dp[3][11][11][11][20][8][8];

int go(int p, int a, int b, int c, int sum, int nz, int ins) {
    if (p == 3) {
        p = 0;
        sum *= 10;
    }
    if (sum>=20 || sum<0) {
        return inf;
    }
    int &ret = dp[p][a][b][c][sum][nz][ins];
    if (ret != -1) {
        return ret;
    }
    
    ret=p==0&&sum==0&&nz==7?(tot-a-b-c)*D:inf;
    
    if (ins) {
        for (int i=0; i<10; ++i) {
            ret = min(ret, go(p+1, b, c, a, sum + (p==0 ? 1:-1)*i, nz | ((i!=0)<<p), ins-1) + (((~nz >> p)&1) && i==0 ? 0 : I));
        }
    }
    if (a == (int)S[p].size()) {
        return ret;
    }
    
    ret = min(ret, go(p, a+1, b, c, sum, nz, 7) + D);
    
    for (int i=0; i<10; ++i) {
        if (i>0 || (nz>>p)&1) {
            ret = min(ret, go(p+1, b, c, a+1, sum + (p==0 ? 1:-1)*i, nz | ((i!=0)<<p), 7) + (S[p][a]-'0'!=i)*R);
        }
    }
    
    return ret;
}

class TheSum {
	public:
	int minCost(int a, int b, int c, int insCost, int delCost, int repCost) {
		string A = to_str(a);
        string B = to_str(b);
        string C = to_str(c);
        /*reverse(A.begin(), A.end());
        reverse(B.begin(), B.end());
        reverse(C.begin(), C.end());*/
        S[1] = A;
        S[2] = B;
        S[0] = C;
        tot = 0;
        for (int i=0; i<3; ++i) {
            tot += S[i].size();
        }
        I = insCost;
        D = delCost;
        R = repCost;
        memset(dp, 0xff, sizeof dp);

        return go(0, 0, 0, 0, 0, 0, 7);
    }







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 44; int Arg1 = 77; int Arg2 = 11; int Arg3 = 1; int Arg4 = 1; int Arg5 = 1; int Arg6 = 1; verify_case(0, Arg6, minCost(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_1() { int Arg0 = 44; int Arg1 = 77; int Arg2 = 11; int Arg3 = 4; int Arg4 = 4; int Arg5 = 1; int Arg6 = 2; verify_case(1, Arg6, minCost(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_2() { int Arg0 = 100; int Arg1 = 100; int Arg2 = 10000; int Arg3 = 1000000; int Arg4 = 1000000; int Arg5 = 0; int Arg6 = 1000000; verify_case(2, Arg6, minCost(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_3() { int Arg0 = 23456765; int Arg1 = 19876; int Arg2 = 927547301; int Arg3 = 7744; int Arg4 = 9876; int Arg5 = 9977; int Arg6 = 48697; verify_case(3, Arg6, minCost(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TheSum ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
