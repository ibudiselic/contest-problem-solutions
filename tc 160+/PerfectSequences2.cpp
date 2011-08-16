#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

const int BASE = 100;
const long long inf = 12345678123456123LL;
long long dp[50][2*BASE+1][2*BASE+1];
vector<int> S;
long long go(int at, int sum, int prod) {
    if (at == (int)S.size()) {
        return sum==prod ? 0 : inf;
    }
    long long &ret = dp[at][sum+BASE][prod+BASE];
    if (ret != -1) {
        return ret;
    }
    ret = inf;
    for (int v=0; v<51; ++v) {
        for (int sgn=-1; sgn<2; sgn+=2) {
            int val = sgn*v;
            int nsum = sum + val;
            int nprod = prod * val;
            if (nsum<-BASE || nsum>BASE) {
                continue;
            }
            if (nprod<-BASE || nprod>BASE) {
                continue;
            }
            ret = min(ret, go(at+1, nsum, nprod) + abs(S[at]-val));
        }
    }
    
    return ret;
}

long long myabs(long long x) { return x<0 ? -x : x; }

long long cost(vector<int> a, vector<int> b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    long long ret = 0;
    for (int i=0; i<(int)a.size(); ++i) {
        ret += myabs(a[i]-b[i]);
    }
    return ret;
}
class PerfectSequences2 {
	public:
	long long minimumMoves(vector <int> seq) {
        if (seq.size() == 1) {
            return 0;
        }
		S = seq;
        long long all = accumulate(S.begin(), S.end(), 0LL);
        long long sol = inf;
        int n = S.size();
        for (int i=0; i<n; ++i) {
            sol = min(sol, abs(S[i]) + myabs(all-S[i]));   
        }
        
        if (n%4 == 1) {
            for (int i=0; i<n; ++i) {
                vector<int> a, b;
                for (int j=0; j<n; ++j) {
                    if (j != i) a.push_back(S[j]);
                }
                for (int j=0; j<n/2; ++j) {
                    b.push_back(-1);
                    b.push_back(1);
                }
                sol = min(sol, cost(a, b));
            }
        }

        memset(dp, 0xff, sizeof dp);
        sol = min(sol, go(0, 0, 1));
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {-1000000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 0LL; verify_case(0, Arg1, minimumMoves(Arg0)); }
	void test_case_1() { int Arr0[] = {-1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 2LL; verify_case(1, Arg1, minimumMoves(Arg0)); }
	void test_case_2() { int Arr0[] = {4,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 3LL; verify_case(2, Arg1, minimumMoves(Arg0)); }
	void test_case_3() { int Arr0[] = {17,95,-79}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 33LL; verify_case(3, Arg1, minimumMoves(Arg0)); }
	void test_case_4() { int Arr0[] = {10,9,8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 21LL; verify_case(4, Arg1, minimumMoves(Arg0)); }
	void test_case_5() { int Arr0[] = {-2,-29,-13}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 38LL; verify_case(5, Arg1, minimumMoves(Arg0)); }
	void test_case_6() { int Arr0[] = {-7,-31,2,-14}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 48LL; verify_case(6, Arg1, minimumMoves(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    PerfectSequences2 ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
