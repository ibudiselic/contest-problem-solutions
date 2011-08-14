#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<int> A;
int n;
int D;
int dummy = 51;
const long long INF = 123456789012345678LL;
long long dp2[50][52][11];
bool done[50][52][11], done2[50][52][11];
long long go(int, int, int);
long long go2(int p, int last, int k) { // min
    if (k == 0) {
        return 1;
    }
    if (p==n || last!=dummy && p-last>D) {
        return INF;
    }
    long long &ret = dp2[p][last][k];
    if (done2[p][last][k]) {
        return ret;
    }
    done2[p][last][k] = 1;
    ret = INF;
    long long t = go2(p+1, last, k);
    if (t < INF) {
        ret = t;
    }
    t = (A[p]>=0 ? go2(p+1, p, k-1) : go(p+1, p, k-1));
    if (t<INF && (ret==INF || A[p]*t<ret)) {
        ret = A[p]*t;
    }
    return ret;
}
long long dp[50][52][11];
long long go(int p, int last, int k) { // max
    if (k == 0) {
        return 1;
    }
    if (p==n || last!=dummy && p-last>D) {
        return INF;
    }
    long long &ret = dp[p][last][k];
    if (done[p][last][k]) {
        return ret;
    }
    done[p][last][k] = 1;
    ret = INF;
    long long t = go(p+1, last, k);
    if (t < INF) {
        ret = t;
    }
    t = (A[p]>=0 ? go(p+1, p, k-1) : go2(p+1, p, k-1));
    if (t<INF && (ret==INF || A[p]*t>ret)) {
        ret = A[p]*t;
    }
    return ret;
}
class TheProduct {
	public:
	long long maxProduct(vector <int> numbers, int k, int maxDist) {
		A = numbers;
        n = A.size();
        D = maxDist;
        memset(done, 0, sizeof done);
        memset(done2, 0, sizeof done2);
        
        return go(0, dummy, k);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {7, 4, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 1; long long Arg3 = 28LL; verify_case(0, Arg3, maxProduct(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {7, 4, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 50; long long Arg3 = 49LL; verify_case(1, Arg3, maxProduct(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {-3, -5, -8, -9, -1, -2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 3; long long Arg3 = -10LL; verify_case(2, Arg3, maxProduct(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {3, 0, -2, 10, 0, 0, 3, -8, 0, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 2; long long Arg3 = 0LL; verify_case(3, Arg3, maxProduct(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TheProduct ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
