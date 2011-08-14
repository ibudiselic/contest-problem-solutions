#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int C, N;
vector<int> W;
int dp[10][21][1<<13];
int go(int bag, int left, int got) {
    if (bag == N) {
        return 0;
    }
    if (left == 0) {
        return go(bag+1, C, got);
    }

    int &ret = dp[bag][left][got];
    if (ret != -1) {
        return ret;
    }

    ret = go(bag+1, C, got);
    for (int i=0; i<(int)W.size(); ++i) {
        if (got & (1<<i)) {
            continue;
        }
        if (W[i] <= left) {
            ret = max(ret, 1 + go(bag, left-W[i], got | (1<<i)));
        }
    }

    return ret;
}
class CollectingMarbles {
	public:
	int mostMarbles(vector <int> W_, int C_, int N_) {
		W = W_;
        C = C_;
        N = N_;

        memset(dp, 0xff, sizeof dp);
        return go(0, C, 0);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 2, 2, 2, 2, 2 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 2; int Arg3 = 4; verify_case(0, Arg3, mostMarbles(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = { 1, 3, 5, 2, 4 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 2; int Arg3 = 4; verify_case(1, Arg3, mostMarbles(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = { 7, 6, 6, 5 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; int Arg2 = 2; int Arg3 = 4; verify_case(2, Arg3, mostMarbles(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = { 2, 2, 2 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 10; int Arg3 = 0; verify_case(3, Arg3, mostMarbles(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    CollectingMarbles ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
