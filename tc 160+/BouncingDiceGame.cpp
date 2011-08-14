#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

double p1[5001], p2[5001], t[5001];
double ONE;
void advance(double *p, int n, int d) {
    memset(t, 0, sizeof t);
    double sum = 0.0;
    for (int i=1; i<n+d; ++i) {
        if (i < n) {
            t[i] += sum*ONE;
            sum += p[i];
        } else {
            t[2*n-i] += sum*ONE;
        }
        if (i > d) {
            sum -= p[i-d];
        }
    }
    memcpy(p, t, sizeof t);
}
class BouncingDiceGame {
	public:
	double winProbability(int n, int d, int x, int y) {
        memset(p1, 0, sizeof p1);
        p1[x] = 1.0;
        memset(p2, 0, sizeof p2);
        p2[y] = 1.0;
        ONE = 1.0/d;
        
        double A = 1.0;
        double B = 1.0;
        double sol = 0.0;
        for (int iter=0; iter<n; ++iter) {
            advance(p1, n, d);
            advance(p2, n, d);
            sol += B * p1[n];
            A -= p1[n];
            B -= p2[n];
        }

        return sol + A*B*ONE/(1-(1-ONE)*(1-ONE));
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arg1 = 6; int Arg2 = 1; int Arg3 = 1; double Arg4 = 0.5417251215862328; verify_case(0, Arg4, winProbability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 2; int Arg2 = 1; int Arg3 = 1; double Arg4 = 0.6090494791666666; verify_case(1, Arg4, winProbability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 100; int Arg1 = 20; int Arg2 = 1; int Arg3 = 10; double Arg4 = 0.49158887163174947; verify_case(2, Arg4, winProbability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 5; int Arg2 = 9; int Arg3 = 1; double Arg4 = 0.6943018666666667; verify_case(3, Arg4, winProbability(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    BouncingDiceGame ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
