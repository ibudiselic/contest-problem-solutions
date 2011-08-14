#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

vector<int> X, Y;
const int SZ = 531441;
bool a_done[SZ], b_done[SZ];
double a_dp[SZ], b_dp[SZ];
int n;
int all;
int encode(int white, int used) {
    int ret = 0;
    for (int i=0; i<n; ++i) {
        if (!(used & (1<<i))) {
            ret = ret*3 + 0;
        } else if (white & (1<<i)) {
            ret = ret*3 + 1;
        } else {
            ret = ret*3 + 2;
        }
    }
    return ret;
}
void decode(int code, int &white, int &used) {
    white = 0;
    used = 0;
    for (int i=n-1; i>=0; --i) {
        int t = code % 3;
        code /= 3;
        if (t != 0) {
            used |= (1<<i);
            if (t == 1) {
                white |= (1<<i);
            }
        }
    }
}

inline double sqr(int x) { return x*x; }
double dist(int a, int b) {
    return sqrt(sqr(X[a]-X[b]) + sqr(Y[a]-Y[b]));
}
double calc(int white) {
    double ret = 0;
    for (int i=0; i<n; ++i) {
        if (white & (1<<i)) {
            for (int j=0; j<n; ++j) {
                if (!(white & (1<<j))) {
                    ret += dist(i, j);
                }
            }
        }
    }

    return ret;
}

double beta(int);

double alpha(int state) {
    if (a_done[state]) {
        return a_dp[state];
    }
    a_done[state] = 1;
    int white, used;
    decode(state, white, used);
    if (used == all) {
        return (a_dp[state] = calc(white));
    }

    double sol = 0.0;
    for (int i=0; i<n; ++i) {
        if (!(used & (1<<i))) {
            sol = max(sol, beta(encode(white | (1<<i), used | (1<<i))));
        }
    }

    return (a_dp[state] = sol);
}

double beta(int state) {
    if (b_done[state]) {
        return b_dp[state];
    }
    b_done[state] = 1;
    int white, used;
    decode(state, white, used);
    if (used == all) {
        return (b_dp[state] = calc(white));
    }

    double sol = 1e32;
    for (int i=0; i<n; ++i) {
        if (!(used & (1<<i))) {
            sol = min(sol, alpha(encode(white, used | (1<<i))));
        }
    }

    return (b_dp[state] = sol);
}

class PointsGame {
	public:
	double gameValue(vector <int> pointsX, vector <int> pointsY) {
	    X = pointsX;
        Y = pointsY;
        n = X.size();

        memset(a_done, 0, sizeof a_done);
        memset(b_done, 0, sizeof b_done);
        all = (1<<n) - 1;
        return alpha(0);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 1.0; verify_case(0, Arg2, gameValue(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {0,0,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,5,0,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 12.198039027185569; verify_case(1, Arg2, gameValue(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {0,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1,5,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 12.0; verify_case(2, Arg2, gameValue(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {0,1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0,0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 6.0; verify_case(3, Arg2, gameValue(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    PointsGame ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
