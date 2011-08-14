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

int K;
double X[10], Y[10];
int C[10][10];
double my_pow(double x, int n) {
    double ret = 1.0;
    while (n > 0) {
        if (n & 1) {
            ret *= x;
        }
        x *= x;
        n >>= 1;
    }
    return ret;
}
double w1(double x, double y) {
    double ret = 0.0;
    
    for (int i=0; i<=K; ++i) {
        X[i] = my_pow(x, i) * my_pow(1-x, K-i) * C[K][i];
        Y[i] = my_pow(y, i) * my_pow(1-y, K-i) * C[K][i];
    }

    for (int a=1; a<=K; ++a) {
        for (int b=0; b<a; ++b) {
            ret += X[a] * Y[b];
        }
    }

    return ret;
}
double w2(double x, double y) {
    double ret = 0.0;
    
    for (int i=0; i<=K; ++i) {
        X[i] = my_pow(x, i) * my_pow(1-x, K-i) * C[K][i];
        Y[i] = my_pow(y, i) * my_pow(1-y, K-i) * C[K][i];
    }

    for (int a=0; a<K; ++a) {
        for (int b=a+1; b<=K; ++b) {
            ret += X[a] * Y[b];
        }
    }

    return ret;
}
double draw(double x, double y) {
    double ret = 0.0;
    for (int i=0; i<=K; ++i) {
        ret += my_pow(x, i) * my_pow(1-x, K-i) * C[K][i]
                *
               my_pow(y, i) * my_pow(1-y, K-i) * C[K][i];
    }

    return ret;
}

double EPS = 1e-6;
bool eq(double a, double b) {
    return fabs(a-b) <= EPS;
}

class ReasonableOdds {
	public:
	string check(int p1, int pDraw, int p2, int k) {
	    K = k;	

        for (int i=0; i<=K; ++i) {
            C[i][0] = C[i][i] = 1;
            for (int j=1; j<i; ++j) {
                C[i][j] = C[i-1][j] + C[i-1][j-1];
            }
        }

        double x = 0;
        double y = 0;

        const int cnt_rep = 400;
        int global_rep;
        switch (K) {
            case 1: global_rep = 18*cnt_rep; break;
            case 2: global_rep = 9*cnt_rep; break;
            case 3: global_rep = 6*cnt_rep; break;
            case 4: global_rep = 5*cnt_rep; break;
            case 5: global_rep = 4*cnt_rep; break;
            default: assert(0); break;
        }
        for (int t=0; t<global_rep; ++t) {
            double lo = x;
            double hi = 1.0;
            for (int tt=0; tt<cnt_rep; ++tt) {
                double mid = (lo+hi) / 2;
                double val = w1(mid, y);
                if (100*val < p1) {
                    lo = mid;
                } else {
                    hi = mid;
                }
            }
            x = hi;

            lo = y;
            hi = 1.0;
            for (int tt=0; tt<cnt_rep; ++tt) {
                double mid = (lo+hi) / 2;
                double val = w2(x, mid);
                if (100*val < p2) {
                    lo = mid;
                } else {
                    hi = mid;
                }
            }
            y = hi;
        }

        return (eq(100*w1(x, y), p1) && eq(100*w2(x, y), p2) && eq(100*draw(x, y), pDraw) ? "YES" : "NO");
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 0; int Arg1 = 100; int Arg2 = 0; int Arg3 = 1; string Arg4 = "YES"; verify_case(0, Arg4, check(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 50; int Arg1 = 0; int Arg2 = 50; int Arg3 = 1; string Arg4 = "NO"; verify_case(1, Arg4, check(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 30; int Arg1 = 0; int Arg2 = 70; int Arg3 = 5; string Arg4 = "NO"; verify_case(2, Arg4, check(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 30; int Arg1 = 10; int Arg2 = 60; int Arg3 = 2; string Arg4 = "NO"; verify_case(3, Arg4, check(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 30; int Arg1 = 40; int Arg2 = 30; int Arg3 = 2; string Arg4 = "YES"; verify_case(4, Arg4, check(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    ReasonableOdds ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
