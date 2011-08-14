#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<int> P, B;
int T;
int dp[50][50];
bool done[50][50];
int add(int x, int t) {
    return P[x] + (t+1>=T ? B[x] : 0);
}
int tok(int x, int t) {
    return t+1<T ? t+1 : 0;
}
int go(int x, int t) {
    if (x == (int)P.size()) {
        return 0;
    }
    int &ret = dp[x][t];
    if (done[x][t]) {
        return ret;
    }
    done[x][t] = 1;

    ret = max(go(x+1, t) - P[x], add(x, t) + go(x+1, tok(x, t)));

    return ret;
}
class TriviaGame {
	public:
	int maximumScore(vector <int> points, int tokensNeeded, vector <int> bonuses) {
		P = points;
        T = tokensNeeded;
        B = bonuses;

        memset(done, 0, sizeof done);
        return go(0, 0);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 2, 3, 4, 5, 6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arr2[] = {4, 4, 4, 4, 4, 4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 29; verify_case(0, Arg3, maximumScore(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {1, 2, 3, 4, 5, 6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arr2[] = {1, 1, 1, 20, 1, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 39; verify_case(1, Arg3, maximumScore(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {150, 20, 30, 40, 50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arr2[] = {0, 0, 0, 250, 0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 500; verify_case(2, Arg3, maximumScore(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {500, 500, 500, 0, 500}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arr2[] = {0, 0, 0, 500, 0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2000; verify_case(3, Arg3, maximumScore(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TriviaGame ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
